#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
#define int long long
struct point{
	double x,y;
}p[N];
int n;
double prex[N],prey[N],sufx[N],sufy[N];
double q(point a,point b){
	return 1.0*a.x*b.y-1.0*a.y*b.x;
}
double getarea(){
	double sum = 0;
	for(int i = 1; i <= n ; i++){
		int nxt=(i+1);
		if(i==n) nxt=1;
		sum += q(p[i],p[nxt]);
	}
	return fabs(sum)/2;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>p[i].x>>p[i].y;
	
	for(int i=1;i<=n;i++){
		prex[i]=prex[i-1]+p[i].x;
		prey[i]=prey[i-1]+p[i].y;
	}
	for(int i=n;i>=1;i--){
		sufx[i]=sufx[i+1]+p[i].x;
		sufy[i]=sufy[i+1]+p[i].y;
	}
	__int128 ans=0;
	
	for(int i=1;i<=n;i++){
		point a,b;
		a.x=(i-1)*p[i].x-prex[i-1];
		a.y=(i-1)*p[i].y-prey[i-1];
		b.x=sufx[i+1]-(n-i)*p[i].x;
		b.y=sufy[i+1]-(n-i)*p[i].y;
		ans+=q(a,b);
	//	cout<<i<<" "<<q(a,b)<<'\n';
	}
	double fz=ans*1.0/2;
	double fm=getarea();
	double ret=fz/fm;
//	cout<<"the area= "<<fm<<'\n';
	cout<<fixed<<setprecision(10)<<ret;
}
