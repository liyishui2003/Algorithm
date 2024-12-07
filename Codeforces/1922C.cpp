#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
typedef long long ll;
const ll inf=1e15;
ll sum[N],sum2[N],c[N],a[N];
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    a[0]=a[n+1]=inf;
    sum[0]=sum2[n+1]=0;
    for(int i=1;i<n;i++){
        if( abs(a[i+1]-a[i]) < abs(a[i-1]-a[i]) ){
            c[i]=a[i+1]-a[i]-1;//how many saved
        }
        else c[i]=0;
        sum[i]=sum[i-1]+c[i];
    }
    for(int i=n;i>1;i--){
        if( abs(a[i-1]-a[i]) < abs(a[i+1]-a[i]) ){
            c[i]=a[i]-a[i-1]-1;
        }
        else c[i]=0;
        sum2[i]=sum2[i+1]+c[i];
    }
    int m;cin>>m;
    while(m--){
        int x,y;cin>>x>>y;
        if(x<y) {
            cout<<a[y]-a[x]-(sum[y-1]-sum[x-1])<<endl;
        }
        else {
            cout<<a[x]-a[y]-(sum2[y+1]-sum2[x+1])<<endl;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}