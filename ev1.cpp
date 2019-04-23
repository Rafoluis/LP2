#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<cstring>
using namespace std;
int* TA;
int* TB;
int cont=0;
int const N=100000;
int  a[N];

typedef void(*fun_sort)(int*A, int n);

bool test_sort(fun_sort sort, const int*A, int n){
	memcpy(TA,A,sizeof(int)*n);
	memcpy(TB,A,sizeof(int)*n);
	
	clock_t t=clock();
	sort(TA,n);
	float time=float(clock()-t)/CLOCKS_PER_SEC;
	std::sort(TB,TB+n);
	
	for(int i=0;i<n;i++){
		if(TA[i]!=TB[i])return false;
	}
	cout<<time<<" ";
	return true;
}

void merge(int*A,int i,int m,int j){
	int b=i,d=m+1,c=0;
	while(b<=m && d<=j){
		if(A[b]>=A[d]){
			a[c]=A[d];
			d++;
			c++;
			cont++;
		}
		else{
			a[c]=A[b];
			b++;
			c++;
			cont++;
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
	
	merge(A,i,m,j);
}

void merge_sort(int*A, int n)
{
	merge_sort(A, 0,n-1);
}

int main(){
	srand(time(NULL));
	int*A=new int[N];
	TA=new int[N];
	TB=new int[N];
	fun_sort sort[1]={merge_sort};
	
	for(int n=100;n<=N;n*=10){
		
		for(int i=0;i<n;i++){
			A[i]=rand()%n;
		}
		cout<<n<<" ";
		for(int s=0;s<1;s++){
			if(!test_sort(sort[s],A,n)){
				cout<<"FAIL\n";
				return 0;
			}
		}
		cout<<endl;
		cout<<cont;
	}
	delete[]TA;
	delete[]TB;
}
