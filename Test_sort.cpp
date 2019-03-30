#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<cstring>


using namespace std;

int* TA;
int* TB;
int N=100000;

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
void bubble_sort(int*A, int n){
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

void selection_sort(int*A, int n){
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

void insertion_sort(int*A, int n){
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

int main(){
	srand(time(NULL));
	int*A=new int[N];
	TA=new int[N];
	TB=new int[N];
	fun_sort sort[3]={bubble_sort,selection_sort,insertion_sort};
	
	for(int n=100;n<=N;n*=10){
		
		for(int i=0;i<n;i++){
			A[i]=rand()%n;
		}
		cout<<n<<" ";
		for(int s=0;s<3;s++){
			if(!test_sort(sort[s],A,n)){
				cout<<"FAIL\n";
				return 0;
			}
		}
		cout<<endl;
	}
	delete[]TA;
	delete[]TB;
}
