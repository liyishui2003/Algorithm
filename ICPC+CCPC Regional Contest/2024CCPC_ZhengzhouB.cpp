#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans,n,x,y,a[1005][1005],dis[10005][6][3];
struct node{
	int op;//0:往上 1:往下
	int num;//底面是哪个数
	int step;//走了多少步
	int i,j;//所在位置
	int a[4];//l,r,u,d 当前上下左右四个方向都是哪些数
};
node change(node u,int d){
	node ret;
	ret.op=u.op^1;
	ret.num=u.a[d];
	ret.step=u.step+1;
	ret.i=u.i,ret.j=u.j;
	if(d==0){ 
		ret.j--;
		u.a[0]=u.num;
		vector<int>tmp;
		for(int i=0;i<=3;i++){
			if(u.a[i]==-1) continue;
			tmp.push_back(u.a[i]);
		}
		if(ret.op==0) {//往上
			ret.a[0]=tmp[2];
			ret.a[1]=tmp[0];
			ret.a[3]=tmp[1];
			ret.a[2]=-1;
		}
		else {//往下
			ret.a[0]=tmp[2];
			ret.a[1]=tmp[0];
			ret.a[2]=tmp[1];
			ret.a[3]=-1;
		}
	}//l
	else if(d==1) {
		ret.j++;
		u.a[1]=u.num;
		vector<int>tmp;
		for(int i=0;i<=3;i++){
			if(u.a[i]==-1) continue;
			tmp.push_back(u.a[i]);
		}
		if(ret.op==0){
			ret.a[0]=tmp[1];
			ret.a[1]=tmp[2];
			ret.a[3]=tmp[0];
			ret.a[2]=-1;	
		}
		else {
			ret.a[0]=tmp[1];
			ret.a[1]=tmp[2];
			ret.a[2]=tmp[0];
			ret.a[3]=-1;	
		}
	}//r
	else if(d==2){
		ret.i--;
		ret.j=(ret.j/2-1)*2+1;
		//l,r,u,d
		ret.a[0]=u.a[0],ret.a[1]=u.a[1],ret.a[2]=u.a[2],ret.a[3]=u.a[3];
		ret.a[2]=u.num;
		swap(ret.a[2],ret.a[3]);
	}//u
	else if(d==3){
		ret.i++;
		ret.j=((ret.j+1)/2)*2;
		ret.a[0]=u.a[0],ret.a[1]=u.a[1],ret.a[2]=u.a[2],ret.a[3]=u.a[3];
		ret.a[3]=u.num;
		swap(ret.a[2],ret.a[3]);
	}//d
	return ret;
}
int getId(node u){
	return (u.i-1)*(u.i-1)+u.j;
}
void bfs(){
	queue<node>q;
	node sta=(node){0,4,0,1,1};
	sta.a[0]=1;sta.a[1]=3;sta.a[2]=-1;sta.a[3]=2;
	q.push(sta);
	for(int i=1;i<=10000;i++){
		for(int j=1;j<=4;j++)
			dis[i][j][0]=dis[i][j][1]=INT_MAX;
	}
	dis[1][4][0]=0;
	int cnt=0;
	ans=INT_MAX;
	while(!q.empty()){
		auto u=q.front();
		//cout<<"u= "<<u.i<<" "<<u.j<<" "<<u.num<<"\n";
		//cout<<"u.num,u.op:"<<u.num<<" "<<u.op<<"\n";
		//cout<<"[l,r,u,d]:"<<u.a[0]<<" "<<u.a[1]<<" "<<u.a[2]<<" "<<u.a[3]<<"\n"; 
		//cout<<"===\n";
		if(u.i==x && u.j==y){
			ans=min(ans,dis[getId(u)][u.num][u.op]);
			cnt++;
			if(cnt==10) break;
			continue;
		}
		q.pop();
		for(int i=0;i<=3;i++){
			if(u.a[i]==-1) continue;
			node to=change(u,i);
			//cout<<u.i<<" "<<u.j<<" "<<" to "<<to.i<<" "<<to.j<<"\n";
			if(to.num != a[to.i][to.j]) continue;
			if(dis[getId(to)][to.num][to.op]==INT_MAX){
			//	cout<<u.i<<" "<<u.j<<" "<<" to "<<to.i<<" "<<to.j<<"\n";
				dis[getId(to)][to.num][to.op]=u.step+1;
				q.push(to);
			}
		}
	}
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2*i-1;j++){
			cin>>a[i][j];
		}
	}
	cin>>x>>y;
	bfs();
	if(ans==INT_MAX){
		cout<<-1;
	}
	else cout<<ans;
}
int main(){
//ios_base::sync_with_stdio(false);
//	cin.tie(0);cout.tie(0);
	solve();
}
/*
4
4
1 2 3
4 3 2 1 4
1 2 3 4 1 2 3
4 4 
*/
