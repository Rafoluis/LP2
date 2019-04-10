#include <iostream>
using namespace std;
int main() {
	int k, lista[12],count = 0;
	while (cin>>k) {
	    if(k==0)return 0;

        if (count++){
            cout<<endl;
   		}
		for (int i = 0; i < k; i++){
			cin>>lista[i];
		for (int a = 0; a < k - 5; a++){
			for (int b = a + 1; b < k - 4; b++){
				for (int c = b + 1; c < k - 3; c++){
					for (int d = c + 1; d < k - 2; d++){
						for (int e = d + 1; e < k - 1; e++){
							for (int f = e + 1; f < k; f++){
                                cout<<lista[a]<<" "<<lista[b]<<" "<<lista[c]<<" "<<lista[d]<<" "<<lista[e]<<" "<<lista[f]<<endl;
                        	}
						}
					}
				}
			}
		}
	}
}
	return 0;
}
