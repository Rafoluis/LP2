#include <iostream>
#include "string_0.h"
using namespace std;

int main(){
    my_string y("hola");
    my_string z("mama");
    my_string d=y+z;
    if(y<z){
    	cout<<"menor";
	}
	else{
		cout<<"mayor";
	}
	//if(y>z){
    //	cout<<"mayor";
	//}
	//else{
//		cout<<"menor";
//	}
	if(y==z){
		cout<<"igual";
	}
	else{
		cout<<"diferente";
	}
    return 0;
}


