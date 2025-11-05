#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
char act[N];
int v[N],s[N],a[5];
int q(char act,int e,int x){
	if(act=='+'){
		if(e>=x) return 0;
		return 1;
	}
	else {
		if(e>=x) return 2;
		return 3;
	}
}
pair<double,double> f(int tp,int fn,int fp,int tn){
	double tpr,fpr;
	tpr=1.0*tp/(1.0*tp+1.0*fn);
	fpr=1.0*fp/(1.0*tn+1.0*fp);
	return make_pair(fpr,tpr);
}
void solve(){
	int n;cin>>n;
	map<int,int>num,neg,pos;
	for(int i=1;i<=n;i++){
		cin>>act[i]>>v[i];
		num[v[i]]++;
		if(act[i]=='+') pos[v[i]]++;
		else neg[v[i]]++;
	}
	int cnt=0;
	for(auto it=num.begin();it!=num.end();it++){
		cnt++;s[cnt]=it->first;
	}
	for(int i=1;i<=n;i++){
		a[q(act[i],v[i],s[1])]++;
	}
	set<pair<double,double>>st;
	st.insert(f(a[0],a[1],a[2],a[3]));
//	cout<<"i= "<<1<<'\n';
//	cout<<"tp="<<a[0]<<" fn="<<a[1]<<" fp="<<a[2]<<" tn="<<a[3]<<'\n';
	for(int i=2;i<=cnt;i++){
		
		a[q('-',s[i-1],s[i-1])]-=neg[s[i-1]];
		a[q('+',s[i-1],s[i-1])]-=pos[s[i-1]];
		
		a[q('-',s[i],s[i-1])]-=neg[s[i]];
		a[q('+',s[i],s[i-1])]-=pos[s[i]];
		
		a[q('-',s[i-1],s[i])]+=neg[s[i-1]];
		a[q('+',s[i-1],s[i])]+=pos[s[i-1]];
		
		a[q('-',s[i],s[i])]+=neg[s[i]];
		a[q('+',s[i],s[i])]+=pos[s[i]];
		
		st.insert(f(a[0],a[1],a[2],a[3]));
//		cout<<"i= "<<i<<'\n';
//		cout<<"tp="<<a[0]<<" fn="<<a[1]<<" fp="<<a[2]<<" tn="<<a[3]<<'\n';
	}
	
	memset(a,0,sizeof a);
	for(int i=1;i<=n;i++){
		a[q(act[i],v[i],0)]++;
	}
	st.insert(f(a[0],a[1],a[2],a[3]));
	
	memset(a,0,sizeof a);
	for(int i=1;i<=n;i++){
		a[q(act[i],v[i],1000000000+5)]++;
	}
	st.insert(f(a[0],a[1],a[2],a[3]));
	
	double ans=0;
	double last_x=0,last_y=0;
	for(auto v:st){
//		cout<<(v.first)<<" "<<(v.second)<<'\n';
		ans+=(v.first-last_x)*last_y;
		last_x=v.first;last_y=v.second;
	}
	cout<<setprecision(15)<<ans<<'\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;
	while(t--){
		//TODO
		solve();
	}
}
/*
8
+ 34
+ 33
+ 26
- 34
- 38
+ 39
- 7
- 27
*/
