#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    map <string,double> tree;
    vector<string>ntree;
    string name="0";
    int ke=1;
    int cont=0;
    cin>>cont;
    getline(cin,name);
    getline(cin,name);
    while(cont!=0){
        while(ke!=0 && getline(cin,name))
		{
            if(name!="")
			{
                ntree.push_back(name);
            }
            else{
				ke=0;
			}
        }
        ke=1;
        double y=ntree.size();
        double x=(1/y)*(100);
        for(int i=0; i<ntree.size(); i++)
		{
            tree[ntree[i]]=tree[ntree[i]]+x;
        }
        for(auto p:tree)
		{
            cout<<p.first<<" ";
            printf("%.4lf", p.second);
            cout<<endl;
        }
        cont--;
        ntree.clear();
        tree.clear();
        if(cont>0)
		{
            cout<<endl;
        }
    }
    return 0;
}
