#include<bits/stdc++.h>
using namespace std;
#define int long long
int _a[70],_b[70];
void solve(){
    int a,b,r;
    cin>>a>>b>>r;
    memset(_a,0,sizeof _a);
    memset(_b,0,sizeof _b);
    int cnt_a=0,cnt_b=0;
    if(a<b) swap(a,b);
    if(a==b){
        cout<<0<<endl;
        return;
    }
    else {
        int delta=a-b;
        while(a){
            _a[cnt_a]=a%2;
            cnt_a++;
            a>>=1;
        }
        while(b){
            _b[cnt_b]=b%2;
            cnt_b++;
            b>>=1;
        }
        int fitst=-1;
        for(int i=max(cnt_a,cnt_b);i>=0;i--){
            if(_a[i]==1&&_b[i]==0){
                if(r>=(long long)(pow(2,i))){
                    delta-=pow(2,i+1);
                    r-=(long long)(pow(2,i));
                }
            }
        }
        cout<<abs(delta)<<endl;
    }
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}