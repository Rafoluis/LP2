#include<iostream>
#ifndef MATRIX_H
#define MATRIX_H

template<class T>
class Matrix{
	private:
		T** ptr;
		size_t n_rows,n_colms;
	public:
	~Matrix()
	Matrix(size_t nr=0 , size_t nc =0);
	Matrix(const matrix<T>&m);
	size_t g_rows(const Matrix<T>)const;
	size_t g_cols(const Matrix<T>)const;
	Matrix<T> operator + (const matrix<T> & m);
};

template<class T>
Matrix<T>::Matrix(size_t nr=0 , size_t nc =0){
	n_rows=nr;
	n_rows=nc;
	ptr=new T* [n_rows];
	for(int i=0;i<n_cols;i++){
		ptr=new T [i];
	}
}

template<class T>
Matrix<T>::Matrix(const matrix<T>&m){
		for(int i=0;i<n_rows;i++){
			for(int j=0;j<n_cols;j++){
				ptr[i][j]=m[i][j];
			}
		}
}

template<class T>
Matrix<T>::~Matrix(){
	for(int i=0;i<n_rows;i++){
		delete[]ptr[i];
	}
	delete[]ptr;
};

template<class T>
Matrix<T> operator + (const matrix<T> & m){
	if(g_rows(ptr)!=g_colms(m)){
		cout<<"different";
		throw;
	}
	else{
		newptr=new T* [n_rows];
		for(int i=0;i<n_rows;i++){
			for(int j=0;j<n_colms;j++){
				newptr[i][j]=new T[n_colms];
			}
		}
		for(int i=0;i<n_rows;i++){
			for(int j=0;j<n_colms;j++){
				newptr[i][j]=m.ptr[i][j]+ptr[i][j];
			}
		}
		return newptr;
	}
}

template<class T>
Matrix<T> operator * (const matrix<T> & m){
	
	//	for(int i=0;i<2;i++){
	/*	for(int j=0;j<1;j++){
			res[i][j]=0;
			for(int z=0;z<3;z++){
				res[i][j]=res[i][j]+(uno[i][z]*dos[z][j]);
			}
		}
	}
	*/
	
}



#include "Matrix.inl"

#endif
