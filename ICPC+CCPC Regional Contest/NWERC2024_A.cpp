#include<bits/stdc++.h>
using namespace std;
struct node{
	string act;
	string com;
}f[100000];
bool cmp(node a,node b){
	return a.com<b.com;
}
void solve(){
	int n;cin>>n;
	getchar();
	for(int i=1;i<=n;i++){
		string s;
		getline(cin,s);
		int len=s.length(),pos=-1;
		for(int j=0;j<len;j++){
			if(s[j]<='Z'&&s[j]>='A'){
				pos=j;break;
			}
		}
		string tmp="";
		for(int j=pos;j<len;j++){
			tmp=tmp+s[j];
		}
		f[i].act=s;
		f[i].com=tmp;
	//	cout<<"i= "<<i<<'\n';
	//	cout<<s<<" "<<tmp<<'\n';
	}
	sort(f+1,f+n+1,cmp);
	for(int i=1;i<=n;i++) cout<<f[i].act<<'\n';
}
int main(){
	int t=1;
	while(t--){
		solve();
	}
}
