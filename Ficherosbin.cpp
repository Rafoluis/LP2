#include <bits/stdc++.h>
using namespace std;

struct A{
	int x;
	string str;
};

ostream & operator << (ostream & os, const A & cons){
	os << cons.x << "," << cons.str <<endl;
	return os;
}
istream & operator >> (istream & is, A & cons){
	is >> cons.x >> cons.str;
	return is;
}

void load_array(vector<A> & va,const char* file){
	A tmp;
	char *cop;
	size_t size_v;
	ifstream ff(file,ios::binary);
		while(ff.read((char*)&tmp.x,sizeof(int))){
			ff.read((char*) & size_v,sizeof(size_t));
			cop=new char[size_v+1];
			ff.read(cop,size_v);
			cop[size_v]=0;
			tmp.str=cop;
			va.push_back(tmp);
		}		
	ff.close();
}

void save_array(vector<A> & va, const char* file){
	size_t tmp;
	ofstream ff(file,ios::binary);
	for(int i=0;i<va.size();i++){
		ff.write((char*)&va[i].x,sizeof(int));
		tmp=va[i].str.size();
		ff.write((char*)&tmp,sizeof(size_t));
		ff.write(va[i].str.c_str(),va[i].str.size());
		
	}
	ff.close();
}

int main(){
	A a;
	vector<A> va;
	load_array(va,"out.bin");
	for(int i=0;i<va.size();i++){
		cout<<va[i]<<endl;
	}
	int i;
	cin >>i;
	while(i!=0){
		cin>>a;
		va.push_back(a);
		i--;
	}
	save_array(va,"out.bin");
	
	return 0;
}

