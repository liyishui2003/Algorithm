#include<bits/stdc++.h>
using namespace std;
int f[50];
int find(int x){
	if(f[x]!=x) return f[x]=find(f[x]);
	else return x;
}
void solve(){
	string s1,s2,s3;
	cin>>s1>>s2>>s3;
	int l1=s1.length(),l2=s2.length(),l3=s3.length();
	if(l1!=l2){
		cout<<"NO"<<"\n";
		return;
	}
	if(l1!=l3){
		cout<<"YES"<<"\n";
		return;
	}
	for(int i=0;i<=30;i++) f[i]=i;
	for(int i=0;i<l1;i++){
		int a=s1[i]-'a',b=s2[i]-'a';
		int fa=find(a),fb=find(b);
		f[fa]=fb;
		/*cout<<"merge:"<<"\n";
		cout<<i<<" "<<a<<" "<<b<<"\n";
		cout<<fa<<" "<<fb<<"\n";
		*/
	}
	for(int i=0;i<l3;i++){
		int a=s1[i]-'a',b=s3[i]-'a';
		int fa=find(a),fb=find(b);
		/*
		cout<<i<<" "<<a<<" "<<b<<"\n";
		cout<<fa<<" "<<fb<<"\n";
		*/
		if(fa!=fb) {
			cout<<"YES"<<"\n";
			return;
		}
	}
	cout<<"NO"<<"\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		//TODO
		solve();
	}
}
