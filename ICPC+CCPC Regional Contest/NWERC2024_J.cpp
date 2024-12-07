#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N],b[N],r[N];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>r[i];
	}
	for(int i=1;i<=n;i++){
		int ret=1000100;
		for(int j=1;j<=n;j++){
			if(i==j||r[j]<r[i]) continue;
			int d=(a[i]-a[j])*(a[i]-a[j])+(b[i]-b[j])*(b[i]-b[j]);
			d=sqrt(d);
			ret=min(ret,d);
		}
		ret=min(ret,r[i]);
		cout<<ret<<'\n';
	}
}
