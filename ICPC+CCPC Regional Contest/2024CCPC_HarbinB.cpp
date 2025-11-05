#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6+5;
int n;
const double pi = 3.1415926535897;
const double eps=1e-9;
int dcmp(double x){
	return (fabs(x)<=eps)?0:(x<0?-1:1);
}
struct Point{
	double x,y;
	Point(double X=0,double Y=0){x=X,y=Y;}
	double operator ^ (const Point b) const{
		return x*b.y - y*b.x;
	}
};
struct Vector{
	double x,y;
	Vector(double X=0,double Y=0){x=X,y=Y;}
};
inline Vector operator-(Point x,Point y){// 点-点=向量
	return Vector(x.x-y.x,x.y-y.y);
}
inline double cross(Vector x,Vector y){ // 向量叉积
	return x.x*y.y-x.y*y.x;
}
inline double operator*(Vector x,Vector y){ // 向量叉积
	return cross(x,y);
}
inline double len(Vector x){ // 向量模长
	return sqrt(x.x*x.x+x.y*x.y);
}


int stk[N];
bool used[N];
vector<Point> ConvexHull(Point* poly, int n){ // Andrew算法求凸包
	int top=0;
	sort(poly+1,poly+n+1,[&](Point x,Point y){
		return (x.x==y.x)?(x.y<y.y):(x.x<y.x);
	});
	stk[++top]=1;
	for(int i=2;i<=n;i++){
		while(top>1&&dcmp((poly[stk[top]]-poly[stk[top-1]])*(poly[i]-poly[stk[top]]))<=0){
			used[stk[top--]]=0;
		}
		used[i]=1;
		stk[++top]=i;
	}
	int tmp=top;
	for(int i=n-1;i;i--){
		if(used[i]) continue;
		while(top>tmp&&dcmp((poly[stk[top]]-poly[stk[top-1]])*(poly[i]-poly[stk[top]]))<=0){
			used[stk[top--]]=0;
		}
		used[i]=1;
		stk[++top]=i;
	}
	vector<Point> a;
	for(int i=1;i<=top;i++){
		a.push_back(poly[stk[i]]);
	}
	return a;
}
struct Line{
	Point x;Vector y;
	Line(Point X,Vector Y){x=X,y=Y;}
	Line(Point X,Point Y){x=X,y=Y-X;}
};
inline double DistanceToLine(Point P,Line x){// 点到直线的距离
	Vector v1=x.y, v2=P-x.x;
	return fabs(cross(v1,v2))/len(v1);
}
Point poly[N],poly_in[N];
double dis(Point a,Point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>poly[i].x>>poly[i].y;
	}
	
	vector<Point>a=ConvexHull(poly,n);// 外凸包
	int m=0;
	for(int i=1;i<=n;i++){
		if(used[i]==true) continue;
		m++;
		poly_in[m]=poly[i];
	}
	if(m==0){//内凸包不存在
		cout<<-1<<'\n';
		return;
	}
	vector<Point>b=ConvexHull(poly_in,m);// 内凸包
	int sza=a.size(),szb=b.size();
	/*
	cout<<"==a=="<<"\n";
	for(auto v:a){
		cout<<v.x<<" "<<v.y<<'\n';
	}
	cout<<"==b=="<<"\n";
	for(auto v:b){
		cout<<v.x<<" "<<v.y<<'\n';
	}
	*/
	
	double sum = 0;
	for(int i = 0; i < sza ; i++){
		sum += (a[i]^a[(i+1)%sza]);
	}
	sum=fabs(sum);
	if(szb==0){
		cout<<-1<<'\n';
		return;
	}
	else if(szb==1||szb==2){
		int mi=LONG_LONG_MAX;
		for(int i=0;i<sza-1;i++){
			Line l=Line(a[i],a[i+1]);
			for(int j=0;j<szb;j++){
				double tmp=DistanceToLine(b[j],l);
				tmp=tmp*dis(a[i],a[i+1]);
				/*
				cout<<"("<<a[i].x<<","<<a[i].y<<") ("<<a[i+1].x<<","<<a[i+1].y<<")"<<'\n';
				cout<<"b[j]= "<<b[j].x<<" "<<b[j].y<<'\n';
				cout<<tmp<<'\n';
				*/
				if(tmp<mi){
					mi=tmp;
				}	
			}
		}
		sum-=mi;
		cout<<sum<<'\n';
		return;	
	}
	// copy b
	for(int i=0;i<szb;i++){
		b.push_back(b[i]);
	}
	for(int i=0;i<szb;i++){
		b.push_back(b[i]);
	}
	szb*=2;
	int pos=-1;
	double mi=LONG_LONG_MAX,ans;
    // 双指针
	Line sta=Line(a[0],a[1]);
	for(int i=0;i<szb;i++){
		double tmp=DistanceToLine(b[i],sta);
		if(tmp<mi){
			mi=tmp;pos=i;
		}
	}
	ans=DistanceToLine(b[pos],sta)*dis(a[0],a[1]);
	for(int i=1;i<sza-1;i++){
		Line l=Line(a[i],a[i+1]);
		while(DistanceToLine(b[pos],l)>=DistanceToLine(b[pos+1],l)){
			pos++;
		}
	//	cout<<"a[i]="<<a[i].x<<" "<<a[i].y<<" <-> "<<a[i+1].x<<" "<<a[i+1].y<<'\n';
	//	cout<<"b[pos]="<<b[pos].x<<" "<<b[pos].y<<'\n';
		ans=min(ans,DistanceToLine(b[pos],l)*dis(a[i],a[i+1]));
	}
	sum-=ans;
	cout<<sum<<'\n';
	/*
	int stk[N];
	bool used[N];
	*/
	for(int i=1;i<=n;i++) stk[i]=used[i]=0;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();	
	}
	
	return 0;
}


