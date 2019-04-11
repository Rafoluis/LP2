#include<iostream>
using namespace std;
//Daniela Vilquez
//Rafael Corzo

class my_string{
	private:
		char*palabra;
		int tam;
	public:
		my_string(const char *str=NULL);
		my_string(const my_string &str){
			int i=0;
			tam=0;
			while(str.palabra[i]){//por medio de str accedes a palabra
				i++;
				tam++;
			}
			palabra=new char(tam+1);
			for(int i=0;tam<i;i++){
				palabra[i]=str.palabra[i];
			}
		}
		~my_string();
		int tamano(){return tam;}
		bool operator==(const my_string&str){
			bool igual=false;
			if(tamano()!=tam){
				return igual;
			}
			for(int i=0;i<tamano();i++){
				for(int j=0;j<tam;j++){
					if(palabra[i]!=str.palabra[i]){
						return igual;
					}
				}
			}
			return true;
		}
		char & operator[](const int&i){
			return palabra[i];
		}
		my_string&operator+(const my_string&str){
			int tamano_nuevo=tamano()+tam;
			my_string palabra_nueva=new char[tamano_nuevo];
			for(int i=0;i<tamano();i++){
					palabra_nueva[i]=palabra[i];
				}
			for(int i=tamano()+1;i<tamano_nuevo;i++){
				for(int j=0;j<tam;j++){
					palabra_nueva[i]=str.palabra[j];
				}
			}
		}
		my_string&operator=(const my_string&str){
			for(int i=0;i<tamano();i++){
				palabra[i]=str.palabra[i];
			}
			return *this;
		}
		
		//friend my_string&operator<<(ostream&os,const my_string&s){
		//	return os << s.name<<" "<< s.curso;
		//}
};

int main(){
	
}
