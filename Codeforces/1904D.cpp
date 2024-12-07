#include<bits/stdc++.h>
using namespace std;
// ta.mx  tb.mi
#define mid ((l+r)>>1)
#define ls (rt<<1) 
#define rs ((rt<<1)|1)
const int inf=998244353;
const int N=2e5+5;
int n;
struct node{
	int mx[N<<2],mi[N<<2];
	void up(int rt){
		mx[rt]=max(mx[ls],mx[rs]);mi[rt]=min(mi[ls],mi[rs]);
	}
	void build(int a[],int rt=1,int l=1,int r=n){
		if(l==r) {
			mx[rt]=mi[rt]=a[l];return;
		}
		build(a,ls,l,mid);build(a,rs,mid+1,r);up(rt);
	}
	int opp(int a,int b,int op){
		return (op==1) ? max(a,b): min(a,b);
	}
	int query(int ql,int qr,int op,int rt=1,int l=1,int r=n){
		if(ql>qr){
			return (op==1) ? -inf : inf;
		}
		if(ql<=l&&r<=qr){
			if(op==1) return mx[rt];else return mi[rt];
		}
		int tmp= (op==1) ? -inf : inf;
		if(ql<=mid) tmp=opp(query(ql,qr,op,ls,l,mid),tmp,op);
		if(qr>mid) tmp=opp(query(ql,qr,op,rs,mid+1,r),tmp,op);
		return tmp;
	}
}ta,tb;
int a[N],b[N];
void solve(){
	cin>>n;
	vector<int>pos[n+5];
	for(int i=1;i<=n;i++) cin>>a[i],pos[a[i]].push_back(i);
	for(int i=1;i<=n;i++) cin>>b[i];
	ta.build(a);tb.build(b);
	//cout<<666<<endl;
	int flag=1;
	for(int i=1;i<=n&&flag;i++){
		if(a[i]>b[i]) flag=0;
		else if(a[i]==b[i]) continue;
	    else {
			if(pos[b[i]].size()==0) flag=0;
			else if(pos[b[i]].size()==1){
				int tmp= pos[b[i]][0];
			//	cout<<i<<" #"<<tmp<<endl;
				int l=tmp,r=i;
				if(l>r) swap(l,r);
				int mx=ta.query(l,r,1),mi=tb.query(l,r,0);
			//	cout<<mx<<" "<<mi<<endl;
				if(mx==b[i]&&mi>=b[i]) {}
				else flag=0;
			}
			else{
				int l_near=-1,l=0,r=pos[b[i]].size()-1;
				while(l<=r){
					if(pos[b[i]][mid]<i) l_near=mid,l=mid+1; else r=mid-1;
				}
				int ok=0;
				l_near=pos[b[i]][l_near];
				if(l_near!=-1){
					int mx=ta.query(l_near,i,1),mi=tb.query(l_near,i,0);
					if(mx==b[i]&&mi>=b[i]) ok=1;
				}
				int r_near=-1;
				l=0,r=pos[b[i]].size()-1;
				while(l<=r){
					if(pos[b[i]][mid]>i) r_near=mid,r=mid-1;else l=mid+1;
				}
				r_near=pos[b[i]][r_near];
				if(r_near!=-1){
					int mx=ta.query(i,r_near,1),mi=tb.query(i,r_near,0);
				//	cout<<"r:"<<mx<<" "<<mi<<endl;
					if(mx==b[i]&&mi>=b[i]) ok=1;
				}
				//cout<<"["<<l_near<<","<< r_near <<"]"<<endl;
				//cout<<ok<<endl;
				if(!ok) flag=0;
			}
		}
		// cout<<i<<" :"<<flag<<endl;
	}
	cout<< ((flag) ? "YES":"NO")<<endl;
}
int main(){
//	freopen("lys.in","r",stdin);
	int t;cin>>t;
	while(t--){
		solve();
	}
}
