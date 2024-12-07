#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],L[N],pa[N],val[N];
int n,q,tot=0;
int find(int x){
	if(x!=pa[x]) return pa[x]=find(pa[x]);
	else return x;
}
void merge(int a,int b){
	int fa=find(a),fb=find(b);
	if(fa>fb) swap(fa,fb);
	pa[fa]=fb;
}
void solve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) pa[i]=i;
	stack<int>s;
	for(int i=n;i>=1;i--){
		while(!s.empty( )&&a[s.top( )]<=a[i]){
			s.pop( );
		}
		if(s.empty( )) L[i]=n+1;
		else L[i]=s.top( );
		s.push(i);
	}
	while(q--){
		char op;cin>>op;
		if(op=='+'){
			int l,x;cin>>l>>x;
		//	cout<<"666= "<<'\n';
			int to=find(l);// the right most
		//	cout<<"666"<<'\n';
			while(x&&to<=n){
				to=find(to);
				int d=min(a[to]-val[to],x);
				val[to]+=d;
				x-=d;
				tot+=d;
				if(a[to]==val[to]) {
					merge(to,l);
					to=L[to];
				}
			//	cout<<"to= "<<to<<'\n';
			}
		}
		else {
			int l;cin>>l;
			cout<<val[l]<<'\n';
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;
	while(t--){
		solve();
	}
}

