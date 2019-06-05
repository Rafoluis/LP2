#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	vector<int>green;
	vector<int>blue;
	int N=0,B=0,SG=0,SB=0;
	cin>>N;
	cin>>B>>SG>>SB;
	cout<<SG;
	cout<<SB<<endl;
	for (int i = 0 ; i < SG ; i++)
	{
		int G;
		cin>>G;
		green.push_back(G);
	}
    for (int i = 0 ; i < SB; i++)
	{
    	int B;
		cin>>B;
		blue.push_back(B);
	}
	sort(green.begin(),green.end());
	sort(blue.begin(),blue.end());
	
	while(B != 0){
		int i=SG-1;
		int j=SB-1;
		if(green[i]>blue[j])
		{
			green[i]=green[i]-blue[j];
			blue[j]=0;
		}
		else if(green[i]<blue[i])
		{
			blue[j]=blue[j]-green[i];
			green[i]=0;
		}
		else{
			green[i]=0;
			blue[j]=0;
		}
		B--;
		i--;
		j--;
		sort(green.begin(),green.end());
		sort(blue.begin(),blue.end());	
	}
	
	int TG;
	int TB;
	for (int i = 0 ; i < SG ; i++)
	{
		TG=green[i]+green[i+1];
	}
    for (int i = 0 ; i < SB; i++)
	{
    	TB=blue[i]+blue[i+1];
	}
	if(TG<TB){
		cout<<"green wins"<<endl;
		for(int i=0;i<SG;i++){
			if(green[i]==0)
				i++;
			cout<<green[i]<<endl;
		}
	}
	if(TB<TG){
		cout<<"blue wins"<<endl;
		for(int i=0;i<SB;i++){
			if(blue[i]==0)
				i++;
			cout<<blue[i]<<endl;
		}
	}
	return 0;
}
