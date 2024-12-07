#include <bits/stdc++.h>
using namespace std;

/* 省略快读快写，即下面的 qin、qout */

int n,m,a[100005];
vector<int> g[100005];
bool chk[100005];
struct Limit{ int x,y,z; }q[200005];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>q[i].x>>q[i].y>>q[i].z;
		if(q[i].x>q[i].y) swap(q[i].x,q[i].y);
	}
	for(int j=0;j<30;j++)
	{
		for(int i=1;i<=n;i++)
			chk[i]=false,g[i].clear();
		for(int i=1;i<=m;i++)
		{
			int x=q[i].x,y=q[i].y;
			bool v=q[i].z&(1<<j);
			if(x==y) a[x]|=v<<j,chk[x]=true;
			else if(v) g[x].push_back(y);
			else chk[x]=chk[y]=true;
		}
		for(int i=1;i<=n;i++)
		{
			bool fl=false;
			for(auto &k: g[i]) fl|=(!(a[k]&(1<<j)) && chk[k]);
			if(fl || (a[i]&(1<<j))) a[i]|=1<<j;
			else for(auto &k: g[i]) a[k]|=1<<j,chk[k]=true;
		}
	}
	for(int i=1;i<=n;i++)
		cout<<a[i];
	return 0;
}
