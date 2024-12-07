#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6+5;
int a[N];
int extend_gcd(int a,int b,int &x,int &y){
    if(a==0&&b==0) return -1;
    if(b==0){
        x=1;y=0;return a;
    }
    int d=extend_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
void solve(){

    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    if(n==1){
        cout<<1<<" "<<1<<endl<<1<<endl;
        cout<<1<<" "<<1<<endl<<1<<endl;
        cout<<1<<" "<<1<<endl<<-(a[1]+2)<<endl;
        return;
    }
    int ans[n+5][2];

    for(int i=1;i<n;i++){
        int d=-a[i],x,y;
        extend_gcd(n,n-1,x,y);
        ans[i][0]=n*x*(-a[i]);ans[i][1]=(n-1)*y*(-a[i]);
    }
    cout<<1<<" "<<n<<endl;
    for(int i=1;i<n;i++) cout<<ans[i][0]<<" ";
    cout<<0<<endl;
    cout<<1<<" "<<n-1<<endl;
    for(int i=1;i<=n-1;i++) cout<<ans[i][1]<<" ";
    cout<<endl;
    cout<<n<<" "<<n<<endl;
    cout<<-a[n]<<endl;
}
signed main(){
    int t;
    t=1;
    while(t--){
        solve();
    }
}