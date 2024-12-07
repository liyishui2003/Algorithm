#include<bits/stdc++.h>
using namespace std;
int n;
int ask(int c,int r){
	cout<<"? "<<c<<" "<<r<<'\n';
	fflush(stdout);
	int ret;cin>>ret;
	fflush(stdout);
	return ret;
}
int main(){
	cin>>n;
	fflush(stdout);
	int ans=ask(n,1);
	if(ans==n){
		cout<<"! "<<n<<" "<<1<<'\n';
		fflush(stdout);
	}
	else {
		int inv=ask(n-ans,1);
		cout<<"! "<<ans<<" "<<inv<<'\n';
		fflush(stdout);
	}
}
