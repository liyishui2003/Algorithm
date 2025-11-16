#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+5;
int n,a[maxn],d[maxn],flag,root;
vector<int>e[maxn];
vector<pair<int,int>>out;
void dfs(int u,int f){//返回继承的点
	
	vector<int>child;
	vector<int>ex;
	for(auto v:e[u]){
		if(v==f) continue;
		dfs(v,u);
		if(a[v]==v){
			child.push_back(v);
		}
		else ex.push_back(a[v]);
	}
	int szchi=child.size();
	int szex=ex.size();
	for(int i=0;i<szchi;i+=2){
		if(i==szchi-1) break;
		out.push_back(make_pair(child[i],child[i+1]));
	}
	for(int i=0;i<szex;i+=2){
		if(i==szex-1) break;
		out.push_back(make_pair(ex[i],ex[i+1]));
	}
	/*
	cout<<"u= "<<u<<"\n";
	cout<<"child: ";
	for(auto v:child){
	cout<<v<<" ";
	}
	cout<<"\n";
	
	cout<<"ex: ";
	for(auto v:ex){
	cout<<v<<" ";
	}
	cout<<"\n";
	*/
	if(u!=root){
		if(szchi%2==1) {
			if(szex%2==1){
				out.push_back(make_pair(ex[szex-1],child[szchi-1]));
				a[u]=u;
			}
			else a[u]=child[szchi-1];
		}
		else {
			if(szex%2==1) a[u]=ex[szex-1];
			else a[u]=u;
		}	
	}
	else {
		if(szchi%2==1){
			if(szex%2==1){
				out.push_back(make_pair(ex[szex-1],child[szchi-1]));
			}
			else {
				flag=0;
			}
		}
		else {
			if(szex%2==1){
				out.push_back(make_pair(ex[szex-1],1));
			}
		}
	}
	
	//cout<<u<<" extend:"<<a[u]<<"\n";
}
void solve(){
	cin>>n;
	
	/*
	int n,a[maxn],flag;
	vector<int>e[maxn];
	vector<pair<int,int>>out;
	*/
	out.clear();
	flag=1;
	for(int i=1;i<=n;i++) e[i].clear(),d[i]=0;
	
	for(int i=1;i<=n-1;i++){
		int u,v;cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
		d[u]++,d[v]++;
	}
	for(int i=1;i<=n;i++){
		if(d[i]%2==0){
			root=i;
			dfs(i,0);
			cout<<out.size()<<"\n";
			for(auto v:out){
				cout<<v.first<<" "<<v.second<<"\n";
			}
			return ;
		}
	}
	
	cout<<-1<<"\n";
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		//TODO
		solve();
	}
}
/*
3
4
1 2
2 3
2 4
7
1 2
1 3
1 4
4 5
4 6
4 7
6
1 2
2 3
2 4
1 5
5 6

3
6
1 2
1 4
1 3
3 5
3 6
8
1 2
2 3
2 4
1 5
1 6
6 7
6 8
15
1 2
1 3
2 6
6 7
6 8
6 9
3 4
3 5
5 11
5 12
12 13
12 14
12 15
11 10

1
10
1 2
2 3
1 4
1 5
5 8
7 8
8 9
8 10
4 6
*/
