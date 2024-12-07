#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll bs=104514191911,bs2=99824435311;
int n;
ll ta[1005],ta2[1005];
map<ll,ll>vis,vis2;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        string a;
        cin>>a;
        ll hs=0,hs2=0;
        for(int j=0;j<a.size();j++){
            hs=(hs*10%bs+a[j]-'0')%bs;
            hs2=(hs2*10%bs2+a[j]-'0')%bs2;
        }
        ta[i]=hs;ta2[i]=hs2;
        ++vis[hs];++vis2[hs2];
    }
    ll res=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            res+=min(vis[ta[i]*ta2[j]%bs],vis[ta2[i]*ta[j]%bs2]);           
        }
    cout<<res<<endl;
}