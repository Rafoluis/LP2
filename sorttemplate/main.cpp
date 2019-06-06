#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int* TA;
int* TB;
int const N=100000;
int  a[N];

template<class T>
class Sort{
	private:
		
	public:
		virtual void sor(T*&A=NULL,int n=0);
		virtual ~Sort()=0;
};

template<class T>
class bubble:public Sort<T>{
	public:
		bubble(){
		}
		~bubble(){}
		void sor(T*A,int n){
			int tmp=0;
			while(n>=0){
				for(int j=0;j<n-1;j++){
					if(A[j]>A[j+1]){
					tmp=A[j];
					A[j]=A[j+1];
					A[j+1]=tmp;
					}
				}
				n--;
			}	
		}	
};		

template<class T>
class selection:public Sort<T>{
			private:
			public:
				selection(){
				}
				~selection(){}
				void sor(T*A,int n){
					int tmp;
					int less;
					for (int i=0;i<n;i++){
						less=i;
						for(int j=i+1;j<n;j++){
							if(A[j]<A[less]){
								less=j;
							}
						}
						tmp=A[i];
						A[i]=A[less];
						A[less]=tmp;
					}
				}
};

template<class T>
class insertion:public Sort<T>{
			private:
			public:
			insertion(){
			}
			~insertion(){}
			void sor(int*A, int n){
				int tmp,pos;
				for(int i=0;i<n;i++){
					pos=i;
					tmp=A[i];
					
					while((pos>0)&&(A[pos-1]>tmp)){
						A[pos]=A[pos-1];
						pos--;
					}
					A[pos]=tmp;
				}
			}
};

template<class T>
class merge:public Sort<T>{
			private:
			public:
			merge(){
			}
			~merge(){}
			void sor(int*A,int i,int m,int j){
				int b=i,d=m+1,c=0;
				while(b<=m && d<=j){
					if(A[b]>=A[d]){
						a[c]=A[d];
						d++;
						c++;
					}
					else{
						a[c]=A[b];
						b++;
						c++;
					}
				}
				while(b<=m) {
					a[c++]=A[b++];
				}
				while(d<=j) {
					a[c++]=A[d++];
				}
				memcpy(A+i,a,sizeof(int)*(j-i+1));	
			}
			void merge_sort(int*A, int i, int j){
				if(i==j)return;
				int m = (i+j)/2;
				merge_sort(A,i,m);
				merge_sort(A,m+1,j);
				sor(A,i,m,j);
			}
			void merge_sort(int*A, int n)
			{
				merge_sort(A, 0,n-1);
			}
};

bool test_sort(Sort<int>*x, const int*A , int n){
	memcpy(TA,A,sizeof(int)*n);
	memcpy(TB,A,sizeof(int)*n);
	clock_t t=clock();
	x->sor(TA,n);
	float time=float(clock()-t)/CLOCKS_PER_SEC;
	std::sort(TB,TB+n);
	
	for(int i=0;i<n;i++){
		if(TA[i]!=TB[i])return false;
	}
	cout<<time<<" ";
	return true;
}


int main(){
	srand(time(NULL));
	TA=new int[N];
	TB=new int[N];
	int*A=new int[N];
	vector<Sort<int>*>xd;
	xd.push_back(new bubble<int>);
	xd.push_back(new selection<int>);
	xd.push_back(new insertion<int>);
	xd.push_back(new merge<int>);
	for(int n=100;n<=N;n*=10){
		
		for(int i=0;i<n;i++){
			A[i]=rand()%n;
		}
		cout<<n<<" ";
		for(int s=0;s<4;s++){
			if(!test_sort(xd[s],A,n)){
				cout<<"FAIL\n";
				return 0;
			}
		}
		cout<<endl;
	}
	delete[]TA;
	delete[]TB;
	delete []A;
	return 0;
}
