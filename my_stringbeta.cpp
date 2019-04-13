#include<iostream>
using namespace std;
//Daniela Vilquez
//Rafael Corzo

class my_string{
	private:
		char * palabra;
		int tam;
	public:
		
		int tamstr(const char* text){
			int i=0;
			int strt=0;
			while(text[i++]!='\0') strt++;
			strt++;
			return strt;
		}
		my_string(const char* str=NULL){
			int	o=tamstr(str);
			palabra=new char[o];
			for(int i=0;i<o;i++)palabra[i]=str[i];
		}	
		~my_string(){delete[] palabra;};	
		my_string(const my_string &str){
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
		
		
		
		int tamano(my_string tex){
			int i=0;
	  	  	int t=0;
			while(tex.palabra[i]){t++;i++;}
			return t;
		}
		
		
		bool operator==(my_string&str){
			bool igual=true;
			if(tamano(palabra)!=tamano(str)){
				return false;
			}
			else{
				for(int i=0;i<tamano(palabra);i++){
					if(palabra[i]!=str.palabra[i]){
						igual = false;
					}
				}
			}
			return igual;
		}
	
	
	
		char & operator[](const int&i){
			return palabra[i];
		}
		
		
		my_string operator+(const my_string&str){
			int tamano_nuevo=tamano(palabra)+tamano(str);
			my_string palabra_nueva=new char[tamano_nuevo];
			for(int x=0;x<tamano(palabra);x++){
					palabra_nueva[x]=palabra[x];
				}
			int i=tamano(palabra);
			int x=0;
			while(x<tamano_nuevo){
				palabra_nueva[i]=str.palabra[x];
				x++;
				i++;
			}
			return palabra_nueva;
		}
		
		
		my_string&operator=(const my_string&str){
			for(int i=0;i<tam;i++){
				palabra[i]=str.palabra[i];
			}
			return *this;
		}
		
		
		bool operator<(const my_string&str){
			bool m=true;
			for(int i=0;i<tamano(palabra);i++){
				if(palabra[i]>str.palabra[i]){
					m=false;
				}
			}
			return m;
		}
		
		
		
		bool operator>(const my_string&str){
			bool m=true;
			for(int i=0;i<tamano(palabra);i++){
				if(palabra[i]<str.palabra[i]){
					m=false;
				}
			}
			return m;
		}
		
		friend ostream&operator<<(ostream&os,const my_string&str){
			return os << str.palabra;
		}
		friend istream&operator>>(istream&is,const my_string&str){
			return is>>str.palabra;
		}
	
};


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

