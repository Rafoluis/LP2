#include<iostream>
#include<vector>
#include<string>
#include <bits/stdc++.h>
using namespace std;

struct A{
	int x;
	string str;
};
	ostream & operator << (ostream & os, A & cons){
		os << cons.x << "," << cons.str <<endl;
		return os;
	}
	istream & operator >> (istream & is, A & cons){
		is >> cons.x >> "," >> cons.str;
		return is;
	}
	
	void load_array(vector<A> & va, char i [],int cont){
		ifstream file(i,ios::binary);
			va.resize(cont);
			for(int i=0,i<cont;i++){
				file.read((char*) & va[i],sizeof(A));
			}		
		file.close();
	}
		
	void save_array(vector<A> & va, char i [],int cont){
		ifstream file(i,ios::binary);
		for(int i=0;i<va.size(),i++){
			file.write((char*)& va[i],sizeof(A));
		file.close();
		}
	}
	void read_array();
	

int main(){
	A a;
	vector<A> va;
	while(cin>>a){
		va.push_back(a);
	}
	save_array(va,"out.bin");
	load_array(va,"out.bin",va.size());
}

