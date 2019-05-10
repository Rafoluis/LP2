#include<iostream>
#include<cstring>
using namespace std;
int p[100000];
unsigned long long int prime(unsigned long long int n){
	int B[100000];
	memset(B,0,sizeof(int)*100000);
	B[0]=B[1]=1;
	unsigned long long int q=0;
	for(unsigned long long int i=3;i<n;i+=2){
		if(!B[i]){
			p[q++]=i;
			for(unsigned long long int j=i*i;j<n;j+=2*i){
				B[j]=1;
			}
		}
	}
	return q;
}

int main(){
	unsigned long long int val,a,b;
	int res;
	cin>>val;
	prime(val);
	for(int i=0;i<=val;i++){
		for(int j=prime(val);j>=0;j--){
			if(p[i]+p[j]==val && p[j]-p[i]>res){
				res=p[j]-p[i];
				a=p[i];
				b=p[j];
			}
		}
	}
	if(b==0){
		cout<<"Goldbach's conjecture is wrong."<<endl;
		return 0;
	}
	cout<<val<<"="<<a<<"+"<<b<<endl;
	return 0;
}
