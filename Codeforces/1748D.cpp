#include<bits/stdc++.h>
using namespace std;
int main(){
	for(int i=1;i<=100;i++)
		for(int j=i;j<=100;j+=i){
			cout<<i<<" "<<j<<endl;
			int tmpj=j,tmpi=i;
			while(tmpj) {
				cout<<(tmpj%2)<<" ";tmpj/=2;	
			}
			cout<<endl;
			while(tmpi) {
				cout<<(tmpi%2)<<" ";tmpi/=2;	
			}
			cout<<endl;
		}
}
