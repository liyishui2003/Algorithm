#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	srand(time(0));
	int n=100;
	for(int i=1;i<=n;i++){
		s=s+char(97+(rand()%26));
	}
	cout<<s<<'\n';
	string tmp;
	tmp=s;
	while(1){
		string odd="";
		string even="";
		for(int i=0;i<n;i+=2) 
			odd=odd+s[i];
		for(int i=0;i<n;i+=2) 
			even=even+s[i];
		s=odd+even;
		cout<<s<<'\n';
		if(s==tmp) break;
	}	
}
