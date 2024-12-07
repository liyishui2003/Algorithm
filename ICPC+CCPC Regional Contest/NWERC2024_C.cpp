#include<bits/stdc++.h>
using namespace std;
#define int long long
struct point{
	int x,y;
}p[100000];
int cnt=0,w[25][25],pa[100000],use[100000],ans=LONG_LONG_MAX;
struct edge{
	int u,v,w;
}e[1000005];
int dis(point a,point b){
	return abs(a.x-b.x)+abs(a.y-b.y);
}
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int find(int x){
	//cout<<"x= "<<x<<'\n';
	if(pa[x]==x) return x;
	else return pa[x]=find(pa[x]);
}
void check(){
	//cout<<"check ing"<<'\n';
	point q[100];
	int n=5;
	for(int i=1;i<=5;i++)
		q[i]=p[i];
	for(int i=1;i<=cnt;i++){
		if(use[i]) {
			++n;
			q[n]=p[i];
		}
	}
	int num=0;
	//cout<<"check ing 1"<<'\n';
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
		//	cout<<i<<"  "<<j<<'\n';
			num++;
			e[num]=(edge){i,j,dis(q[i],q[j])};
		}
	}
	sort(e+1,e+num+1,cmp);
	for(int i=1;i<=n;i++){
		pa[i]=i;
	}
	//cout<<"check ing 2"<<'\n';
	int tot=0;
	memset(w,0x3f3f3f3f,sizeof w);
	for(int i=1;i<=num;i++){
		int fa=find(e[i].u),fb=find(e[i].v);
		if(fa==fb) continue;
		tot+=e[i].w;
		w[e[i].u][e[i].v]=e[i].w;
		pa[fa]=fb;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(w[i][k]+w[k][j]<w[i][j])
					w[i][j]=w[i][k]+w[k][j];
	}
	
	int flag=1;
	for(int i=1;i<=5;i++){
		for(int j=1;j<i;j++){
			if(w[i][j]!=dis(q[i],q[j])) flag=0;
		}
	}
	if(flag) ans=min(ans,tot);
}
void dfs(int u){
	if(u==cnt+1){
	//	cout<<"cnt= "<<cnt<<'\n';
		check();
		return;
	}
	//cout<<"u= "<<u<<'\n';
	use[u]=1;
	dfs(u+1);
	use[u]=0;
	dfs(u+1);
}
signed main(){
	int lef=INT_MAX,rig=-,up,bot;
	for(int i=1;i<=5;i++){
		cin>>p[i].x>>p[i].y;
	}
	for(int i=1;i<=5;i++){
		for(int j=1;j<i;j++){
			cnt++;
			p[cnt].x=p[i].x;
			p[cnt].y=p[j].y;
			cnt++;
			p[cnt].x=p[j].x;
			p[cnt].y=p[i].y;
		}
	}
	dfs(1);
	cout<<ans;
}
