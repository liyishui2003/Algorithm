#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int a[N];
struct node{ int val,cnt; };
void solve(){
	int n;cin>>n;for(int i=1;i<=n;i++) cin>>a[i];
	int mex=0;
	vector<int>vis(n+5);
	deque<node>q;
	int ans=0,out=0;
	for(int i=1;i<=n;i++){
		vis[a[i]]=1;
		while(vis[mex]) mex++;
		ans+=mex;
		if(q.empty()) {
			q.push_back((node){mex,1});
		}
		else {
			if(mex==q.back().val) {
				node tmp=q.back();
				q.pop_back();
				tmp.cnt++;
				q.push_back(tmp);
			}
			else q.push_back((node){mex,1});
		}
	}
	out=max(out,ans);
	for(int i=1;i<=n;i++){
		node tmp=q.front();q.pop_front();
		ans-=tmp.val;
		tmp.cnt--;
		if(tmp.cnt) q.push_front(tmp);
		int tot=0;
		while(!q.empty()&&q.back().val>a[i]){
			node tmp=q.back();
			tot+=tmp.cnt;
			ans-=tmp.cnt*tmp.val;
			q.pop_back();
		}
		q.push_back((node){a[i],tot});
		q.push_back((node){n,1});
		ans+=a[i]*tot+n;
		out=max(out,ans);
	}
	cout<<out<<endl;
}
signed main(){
	//freopen("lys.in","r",stdin);
	int t;cin>>t;while(t--) solve();
}
