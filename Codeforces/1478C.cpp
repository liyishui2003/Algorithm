#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int a=1;
    int ans=0;
    for(int i=1;i<=100;i++){
        a*=i;
        a%=1ll*10000000000000;
        ans+=a%(1000000000);
        ans%=1000000000;
        //cout<<i<<" #"<<(a%(1000000000))<<endl;
    }
    cout<<ans<<endl;
}