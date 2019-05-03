#include"string0.h"
#include"tstring.h"
#include<iostream>

int my_string::size_t(const char* text){
	int i=0;
	int strt=0;
	while(text[i++]!='\0') strt++;
	strt++;
	return strt;
}
my_string::my_string(const char* str){
	int	o=size_t(str);
	palabra=new char[o];
	for(int i=0;i<o;i++){
		palabra[i]=str[i];
	}
}
	
my_string::~my_string(){delete[] palabra;};
	
my_string::my_string(const my_string & str){
	int i=0;
	tam=0;
	while(str.palabra[i]){//por meda<io de str accedes a palabra
		i++;
		tam++;
	}
	palabra=new char(tam+1);
	for(int i=0;tam<i;i++){
		palabra[i]=str.palabra[i];
	}
}



int my_string::size_str(my_string tex){
	int i=0;
  	int t=0;
	while(tex.palabra[i]){
		t++;i++;
		}
	return t;
}


bool my_string::operator==(my_string & str){
	bool igual=true;
	if(size_str(palabra)!=size_str(str)){
		return false;
	}
	else{
		for(int i=0;i<size_str(palabra);i++){
			if(palabra[i]!=str.palabra[i]){
				igual = false;
			}
		}
	}
	return igual;
}



char & my_string::operator[](const int & i){
	return palabra[i];
}


my_string my_string::operator+(const my_string&str){
	int tamano_nuevo=size_str(palabra)+size_str(str);
	my_string palabra_nueva=new char[tamano_nuevo];
	for(int x=0;x<size_str(palabra);x++){
			palabra_nueva[x]=palabra[x];
		}
	int i=size_str(palabra);
	int x=0;
	while(x<tamano_nuevo){
		palabra_nueva[i]=str.palabra[x];
		x++;
		i++;
	}
	return palabra_nueva;
}


my_string & my_string::operator=(const my_string&str){
	for(int i=0;i<tam;i++){
		palabra[i]=str.palabra[i];
	}
	return *this;
}


bool my_string::operator<(const my_string&str){
	bool m=true;
	for(int i=0;i<size_str(palabra);i++){
		if(palabra[i]>str.palabra[i]){
			m=false;
		}
	}
	return m;
}



