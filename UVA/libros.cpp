#include<iostream>
using namespace std;

void insertion_sort(int* A, int n){
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
	int lib;
	int i=0;
	int mitotal;
	int total;
	int menor;
	int k;
	bool print;
	cin>>lib;
	int* precio= new int[lib];
	
	while(i<=lib-1){
		cin>>precio[i];
		i++;
	}
	for(int i=0;i<lib;i++){
		total=precio[i]+precio[i++];
	}
	cin>>mitotal;
	
	insertion_sort(precio,lib);
	int mn=precio[0], mx=precio[lib-1];
	 for(int i=0;i<lib;i++){
            k=i+1;
        while((precio[i]+precio[k])<=mitotal&&k<lib){
        if(mx-mn>precio[k]-precio[i]&&precio[k]+precio[i]==mitotal){
            mx=precio[k];mn=precio[i];}
        k++;
		}
		k=i+1;
		if(precio[i]+precio[k]>mitotal && mx+mn==mitotal){
            break;
            cout<<"Peter should buy books whose prices are "<< mn <<" and " << mx<<endl;

            print=false;
		}
		else{
            cout<<"Peter should buy books whose prices are "<< mn <<" and " << mx<< "."<<endl;
            cout<<endl;
		}
	}

}
