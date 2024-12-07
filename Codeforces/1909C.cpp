#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int vis[N],l[N],r[N],c[N],k[N];
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)    cin>>l[i];
    for(int i=1;i<=n;i++)    cin>>r[i];
    for(int i=1;i<=n;i++)    cin>>c[i];
    sort(l+1,l+n+1);
    sort(r+1,r+n+1);
    sort(c+1,c+n+1);


    int p = 1;
    stack<int> s;
    for (int i = 1; i <= n; ++i) {
        while (p <= n && l[p] < r[i] ) {
            s.push(l[p]);
            ++p;
        }
        k[i] = r[i] - s.top();
        s.pop();
    }
    sort(k+1,k+n+1);
    long long ans=0;
    for(int i=1;i<=n;i++) ans=ans+1ll*k[i]*c[n-i+1];
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}