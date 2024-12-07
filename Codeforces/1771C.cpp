#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int cnt=0,prime[N],a[N],vis[N];
void getPrime(int n){
    
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            prime[++cnt]=i;
        }
        for(int j=1;j<=cnt&&prime[j]*i<=n;j++){
            vis[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
}
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    int flag=0;
    map<int,int>mp;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=cnt&&prime[j]<=a[i];j++){
            if(a[i]%prime[j]==0){
                mp[prime[j]]++;
                if(mp[prime[j]]>=2) flag=1;
                while(a[i]%prime[j]==0) a[i]/=prime[j];
            }
        }

        if(a[i]>1){
                mp[a[i]]++;
                if(mp[a[i]]>=2) flag=1;
        }
    }

    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main(){
    getPrime(N-5);

  //  for(int i=1;i<=10;i++) cout<<prime[i]<<" ";
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}