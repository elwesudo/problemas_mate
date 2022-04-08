#include <iostream>
#include <vector>

using namespace std;

int main(){
	std::vector<int>  factorial;
	int extra1, extra2=0, j=1, k, i, suma=0;
	factorial.resize(j);
	factorial[0]=1;
	for(i=1; i<101; i++){
		for(k=0; k<j; k++){
			extra1 = factorial[k] * i;
			extra1 += extra2;
			if(extra1>9){
				factorial[k] = extra1%10;
				factorial.resize(factorial.size() + 2);
				extra2 = extra1/10;
				if(k+1==j){
					j++;
				}
				factorial.resize(j);
			}else{
				factorial[k] = extra1;
				extra2 = 0;
			}
		}
	}
	for(i=factorial.size(); i > -1; i--){
		cout<<factorial[i];
		suma += factorial[i];
	}
	cout<<endl<<suma<<endl;
}
