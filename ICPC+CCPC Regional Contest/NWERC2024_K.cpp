#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int maxn=1e6;
double p[maxn];
int d[maxn][2],cnt=0,n,m,k,point[maxn],dis[maxn],vis[maxn],head[maxn];
struct node{
	double p;
	int dis;
}f[maxn];
bool cmp(node a,node b){
	return a.dis<b.dis;
}
double sum[maxn];
struct Edge{
	int to,w,nex;
}edge[maxn];
struct lys{
	int id,d;
	bool operator > (const lys tmp)const{
		return d>tmp.d;
	}
};
void add(int a,int b,int val){
	cnt++;edge[cnt].to=b;edge[cnt].w=val;edge[cnt].nex=head[a];head[a]=cnt;
}
priority_queue<lys,vector<lys>,greater<lys> > q;
void dij(int s){
	memset(dis,0x7f,sizeof(dis));
	memset(vis,0,sizeof vis);
	dis[s]=0;
	q.push((lys){s,0});
	while(!q.empty()){
		lys tmp=q.top();
		q.pop();
		if(vis[tmp.id]){continue;}
		vis[tmp.id]=1;
		for(int i=head[tmp.id];i;i=edge[i].nex){
			if(dis[edge[i].to]>dis[tmp.id]+edge[i].w){
				dis[edge[i].to]=dis[tmp.id]+edge[i].w;
				q.push((lys){edge[i].to,dis[edge[i].to]});
			}
		}
	}
}
signed main(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,c;cin>>u>>v>>c;
		add(u,v,c);
		add(v,u,c);
	}
	int flag=0;
	for(int i=1;i<=k;i++){
		cin>>point[i]>>p[i];
		if(p[i]==1) flag=1;
	}
	if(!flag){
		cout<<"impossible";
		return 0;
	}
	dij(1);
	for(int i=1;i<=n;i++)
		d[i][1]=dis[i];
	dij(n);
	for(int i=1;i<=n;i++)
		d[i][2]=dis[i];
	sum[0]=1;
	for(int i=1;i<=k;i++){
		f[i].p=p[i];
		f[i].dis=d[point[i]][1]+d[point[i]][2];
	}
	sort(f+1,f+k+1,cmp);
	double ans=0;
	for(int i=1;i<=k;i++){
		ans+=sum[i-1]*f[i].p*f[i].dis;
		sum[i]=sum[i-1]*(1-f[i].p);
	}
	cout<<fixed<<setprecision(10)<<ans;
}
