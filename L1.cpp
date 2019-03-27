#include<iostream>
using namespace std;

int p1(int a, int b);
void cont(int array[],int esi);
bool is_pal(char*str);
int pot(int num, int poe);
int poti(int numi, int poi);

int main(){
	int n1,n2;
	
	cout<<"Problema 1"<<endl;
	cin>>n1;
	cin>>n2;
	p1(n1,n2);
	cout<<endl;
	
	cout<<"Problema 2"<<endl;
	int valores[]={3,3,7,2,3,4,4,10,6};
	int k;
	cin>>k;
	cont(valores,k);
	cout<<endl;
	
	cout<<"Problema 3"<<endl;
	cout<<"Ingresar una palabra de 5 caracteres"<<endl;
	char*word = new char [5];
	int i = 0;
	char z;
	while(i<5){
		cin>>z;
		word[i]=z;
		i++;
	}
	
	cout << is_pal(word);
	cout<<endl;
	delete[] word;
	
	cout<<"Problema 4"<<endl;
	int a,b;
	cin>>a;
	cin>>b;
	cout<<pot(a,b)<<endl;
	cout<<poti(a,b)<<endl;
	
	
	return 0;
}
int p1(int a, int b){
	
	a=a+b;
	b=a-b;
	a=a-b;
	
	cout <<a<<endl<<b;
	return 0;
}

void cont(int array[],int esi){
	int n=0;
	int menor= array[0];
	int con=0;
	//while(array [n])n++;
	n=9;
	for(int i=0;i<n;i++){
			if(menor>array[i]){
				menor=array[i];
			}
	}
	while(true){
		for(int i=0;i<n;i++){
			if(array[i]==menor){
			con++;
			break;
			}
		}
			
		if(esi>con){
			menor++;
		}
		else
		break;	
	}
	cout<<menor<<endl;
	
}

bool is_pal(char*str){
	int i,j;
	i=j=0;
	while(str[j])j++;j--;
	while(i<j){
		if(str[i++]!=str[j--]){
			return 0;
		}
		return 1;
	}
}

int pot(int num,int poe){
	
	if(poe==2){
		return num*num;
	}
	else if(poe%2>0){
		return num*pot(num,poe-1);
	}
	else{
		return pot(num*num,poe/2);
	}
		
}

int poti(int numi,int poi){
	int total=1;
	while(poi!=1){
		if(poi%2!=0){
			total=total*numi;
			poi--;
		}
		else{
			numi=numi*numi;
			poi=poi/2;			
		}
	}
	return  total*numi;
}


