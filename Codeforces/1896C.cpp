#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct node{
    int v,id;
}a[N],b[N];
bool cmp(node a,node b){
    return a.v<b.v;
}
int ans[N],c[N];
void solve(){
    int n,x;
    cin>>n>>x;
    for(int i=1;i<=n;i++) {
        cin>>a[i].v;a[i].id=i;
    }
    for(int i=1;i<=n;i++) {
        cin>>b[i].v;b[i].id=i;
        c[i]=b[i].v;
    }
    sort(a+1,a+n+1,cmp);sort(b+1,b+n+1,cmp);
    int l=1,r=n,cnt=0;
    for(int i=n;i>=1;i--){
        if(i<l) break;
        while( b[r].v>a[i].v && r>=1 ){
           // cout<<b[r].v<<" "<<a[i].v<<endl;
           // cout<<a[l].id<<" "<<b[r].id<<endl;
            ans[a[l].id]=b[r].id;
            l++;
            r--;
        }
        // cout<<i<<" "<<l<<" "<<r<<endl;
        ans[a[i].id]=b[r].id;// hey~ find b[r].v<a[i].v
        r--;
        cnt++;
    }
    if(cnt<x|| (cnt-x)%2!=0 ) {
        cout<<"NO"<<endl;
        return ;
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=(cnt-x)/2;i++){
        
    }
   for(int i=1;i<=n;i++) cout<<c[ans[i]]<<" ";

    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}