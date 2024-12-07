#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,a[N],b[N];
int check(int l){
    int cnt=0;
    for(int i=l+1;i<=n;i++){
        if(a[i]==a[i-l]) continue;
        b[++cnt]=abs(a[i]-a[i-l]);
    }
    int g=b[1];
    for(int i=1;i<=cnt;i++){
        g=__gcd(g,b[i]);
        if(g==1) return 0;
    }
    return 1;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    int up=sqrt(n);
    int ans=0;
    for(int i=1;i<=up;i++){
        if(n%i!=0) continue;
        if(check(i)) {
            ans++;
        }
        if(i*i!=n&&check(n/i)){
            ans++;
        }
    }
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}