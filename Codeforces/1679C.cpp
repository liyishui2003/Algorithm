#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int c[2][N];
int n,q;
int lowbit(int x){ return x&(-x); }
void add(int id,int val,int d){
    while(id<=n){
        c[d][id]+=val;
        id+=lowbit(id);
    }
}
int query(int id,int d){
    int ans=0;
    while(id){
        ans+=c[d][id];
        id-=lowbit(id);
    }
    return ans;
}
void solve(){
    cin>>n>>q;
    for(int i=1;i<=n;i++) c[0][i]=0,c[1][i]=0;
    for(int i=1;i<=q;i++){
        int t;cin>>t;
        if(t==1){
            int x,y;cin>>x>>y;
            add(x,1,0);
            add(y,1,1);
        }
        else if(t==2){
            int x,y;cin>>x>>y;
            add(x,-1,0);
            add(y,-1,0);
        }
        else {
            int flag=1;
            int x,y,x2,y2;cin>>x>>y>>x2>>y2;
            int s1=query(x2,0)-query(x-1,0);
            int s2=query(y2,1)-query(y-1,1);
            cout<<"## "<<s1<<" "<<s2<<endl;
            if(s1+s2==0) cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }
    }
}
int main(){
    int t;
    t=1;
    while(t--){
        solve();
    }
}