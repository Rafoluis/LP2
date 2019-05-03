#include<cassert>
template<class T>
size_t Matrix<T>::g_rows(const Matrix<T> & m)const{
	return n_rows;
}
template<class T>
size_t Matrix<T>::g_colms(const Matrix<T> & m)const{
	return n_colms;
}

template<class T>
Matrix<T>::Matrix(size_t nr,size_t nc){
	n_rows=nr;
	n_colms=nc;
	ptr=new T [n_rows*n_colms];
}

template<class T>
Matrix<T>::Matrix(const Matrix<T> & m){
    n_rows=m.n_rows;
    n_colms=m.n_colms;
    ptr= new T[n_rows*n_colms];
    for(int i=0;i<n_rows;i++){
        for(int j=0;j<n_colms;j++){
            ptr[j*n_rows+i]=m.ptr[j*m.n_rows+i];
        }
    }
}

template<class T>
Matrix<T>::~Matrix(){
	delete[]ptr;
};

template<class T>
Matrix<T> Matrix<T>::operator + (const Matrix<T> & m){
	assert(n_rows==m.n_rows);
	assert(n_colms==m.n_colms);
	Matrix<T>newptr(n_rows,n_colms);
	for(int i=0;i<n_rows;i++){
		for(int j=0;j<n_colms;j++){
			newptr[j*n_rows+i]=ptr[j*n_rows+i]+m.ptr[j*n_rows+i];
		}
	}
	return newptr;
}

template<class T>
Matrix<T> Matrix<T>::operator * (const Matrix<T> & m){
	assert(n_colms==m.n_rows);
	Matrix<T>rest(n_rows,m.n_colms);
	for(int i=0;i<n_rows;i++){
		for(int j=0;j<rest.n_colms;j++){
			rest.ptr[j*n_rows+i]=0;
			for(int z=0;z<n_colms;z++){
				rest.ptr[j*n_rows+i]=rest.ptr[j*n_rows+i]+ptr[j*n_rows+i]*m.ptr[j*n_rows+i];
			}
		}
	}
	return rest;
}

template<class T>
T & Matrix<T>::operator()(size_t i, size_t j){
	assert(i<n_rows);
	assert(j<n_colms);
	return ptr[j+n_rows+i];
}

template<class T>
Matrix<T> & Matrix<T>::operator << (T m){
	if(r<n_rows){
		ptr[c*n_rows+r]=m;
		if(c<n_colms){
			c++;
		}
		else{
			r++;
			c=0;
		}
	}
	return *this;
}

template<class T>
ostream & operator << (ostream & os,const Matrix<T> & inf){
    for(int i=0; i<inf.n_rows; i++){
        for(int j=0;j<inf.n_colms;j++){
            os<<inf.ptr[j*inf.n_rows+i]<<" ";
        }
        os<<endl;
    }
    return os;
}



