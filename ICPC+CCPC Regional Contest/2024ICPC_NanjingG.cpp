#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int rt,n;
int siz[maxn],w[maxn],vis[maxn];
vector<int>centroids,e[maxn];

int ask(int u,int v){
	cout<<"? "<<u<<" "<<v<<"\n";cout.flush();
	int ret;cin>>ret;return ret;
}
void ans(int x){
	cout<<"! "<<x<<"\n";cout.flush();
}

void dfs(int cur,int f){
	//cout<<"cur,f:"<<cur<<" "<<f<<"\n";
	siz[cur]=1;
	w[cur]=0;
	for(auto v:e[cur]){
		if(v==f || vis[v]) continue;
		dfs(v,cur);
		siz[cur]+=siz[v];
		w[cur]=max(w[cur],siz[v]);
	}
	w[cur]=max(w[cur],n-siz[cur]);
	//这里n记得要实时更新
	if(w[cur]<=n/2){
		centroids.push_back(cur);
	}
}
int cal(int cur,int f){
	int sz=1;
	for(auto v:e[cur]){
		if(v==f || vis[v]) continue;
		sz+=cal(v,cur);
	}
	return sz;
}
void solve(){
	cin>>n;
	
	for(int i=1;i<=n;i++) e[i].clear(),vis[i]=0;
	rt=1;

	for(int i=1;i<=n;i++){
		int l,r;cin>>l>>r;
		if(l) e[i].push_back(l),e[l].push_back(i);
		if(r) e[i].push_back(r),e[r].push_back(i);
	}
	
	int up=log2(n),isPri=0;
	for(int i=1;i<=up;i++){
		centroids.clear();
		dfs(rt,0);
		int g=centroids[0];
		vector<int>to;
		for(auto v:e[g]){
			if(vis[v]) continue;
			to.push_back(v);
		}
		int d=to.size();
		if(d==0){
			ans(g);isPri=1;break;
		}
		else if(d==1){//n=2
			int ret=ask(g,to[0]);
			if(ret==0) ans(g);
			else ans(to[0]);
			isPri=1;
			break;
		}
		else if(d==2){
			int ret=ask(to[0],to[1]);
			if(ret==1){
				ans(g);
				isPri=1;
				break;
			}
			rt=(ret==0)?to[0]:to[1];
			vis[g]=1;
			n=cal(rt,0);
		}
		else {
			int sz1=cal(to[0],g),sz2=cal(to[1],g),sz3=cal(to[2],g);
			int mi=min(sz1,min(sz2,sz3));
			if(sz2==mi){
				swap(sz2,sz1);
				swap(to[1],to[0]);
			}
			if(sz3==mi){
				swap(sz3,sz1);
				swap(to[2],to[0]);
			}
			//现在(sz1,to[0])是最小值
			int ret=ask(to[1],to[2]);
			if(ret==1){
				rt=g;
				vis[to[1]]=1;
				vis[to[2]]=1;
				n=cal(rt,0);
			}
			else {
				rt=(ret==0)?to[1]:to[2];
				vis[g]=1;
				n=cal(rt,0);
			}
		}
	}
	if(!isPri) ans(rt);
}
int main(){
	int t;cin>>t;
	while(t--){
		solve();
	}
}
