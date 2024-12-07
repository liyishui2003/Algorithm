#include<bits/stdc++.h>
using namespace std;
int main(){
	
	for(int i=0;i<=50;i++)
		for(int j=0;j<=50;j++)
			for(int k=0;k<=50;k++)
				for(int p=0;p<j;p++){
					if( ((i^j)<(k^p)) && ((i^p)>=(k^j)) ){
						cout<<i<<" "<<j<<" "<<k<<" "<<p<<endl;
					}
				}
}
