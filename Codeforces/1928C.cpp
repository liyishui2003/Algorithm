#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
ll c[N],n,b,x;
ll calc(ll k){
    ll ans=0;
    for(int i=1;i<=n;i++){
        ll r=c[i]%k,g=c[i]/k,h=(c[i]-1)/k+1;
        ll t=k-r;
        ans+=t*g*g*(t-1)/2+r*h*h*(r-1)/2+t*g*r*h;
    }
    return ans*b-(k-1)*x;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>b>>x;
        ll l=1,r=n;
        for(int i=1;i<=n;i++) cin>>c[i],r=max(r,c[i]);
        while(l < r) {
            ll lmid = l + (r - l) / 3;
            ll rmid = r - (r - l) / 3;
            if(calc(lmid) <= calc(rmid))	l = lmid + 1;
            else r = rmid - 1;
        }
        printf("%lld\n", max(calc(l), calc(r)));
    }
}