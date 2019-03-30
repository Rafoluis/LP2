#include <iostream>
using namespace std;

void bubble_sort(int*A, int n);
void selection_sort(int*A, int n);
void insertion_sort(int*A, int n);
bool binary_search(int*A, int n, int x);
bool lineal_search(int*A, int n, int x);

int main(){
	int*array= new int [6];
	array[0]=9;
	array[1]=1;
	array[2]=3;
	array[3]=6;
	array[4]=8;
	array[5]=2;
	
	for(int i=0;i<=5;i++){
		cout<<array[i];
	}
	cout<<endl;
	
	
	bubble_sort(array,5);
	for(int i=0;i<=5;i++){
		cout<<array[i];
	}
	cout<<endl;
	
	selection_sort(array,5);
	for(int i=0;i<=5;i++){
		cout<<array[i];
	}
	cout<<endl;
	
	insertion_sort(array,5);
	for(int i=0;i<=5;i++){
		cout<<array[i];
	}
	cout<<endl;
	
	cout<<binary_search(array,5,6)<<endl;
	cout<<lineal_search(array,5,6)<<endl;

	return 0;
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

void bubble_sort(int*A, int n){
	int tmp;
	int i;	
	while (i<=n){
		for(int j=0;j<n;j++){
			if(A[j]>A[j+1]){
				tmp=A[j];
				A[j]=A[j+1];
				A[j+1]=tmp;
			}
		}
		i++;
	}
}

bool lineal_search(int*A, int n, int x){
	int i=0;
	while(i<=n){
		if(A[i]==x){
			return true;
		}
		i++;
	}
	return false;
}

bool binary_search(int*A, int n,int x){
	int i=0;
	int j=n-1;
	while(i<=j){
		int m=(i+j)/2;
		
		if(A[m]==x){
			return true;
		}
		if(A[m]>x){
			i=m+1;
		}
		else{
			j=m-1;
		}
		return false;
	}
}



