#include<bits/stdc++.h>
using namespace std;
#define int long long
int _a[70],_b[70];
void solve(){
    int a,b,r;
    cin>>a>>b>>r;
    memset(_a,0,sizeof _a);memset(_b,0,sizeof _b);
    if(a==b){
        cout<<0<<endl;
        return ;
    }
    int cnt_a=0,cnt_b=0;
    int aa=a,bb=b;
    while(aa){
        _a[cnt_a]=aa%2;
        cnt_a++;
        aa>>=1;
    }
    while(bb){
        _b[cnt_b]=bb%2;
        cnt_b++;
        bb>>=1;
    }
    if(a<b) swap(a,b);
    if(a>b){
        int first=-1;
        for(int i=max(cnt_a,cnt_b);i>=0;i--){
            if(_a[i]==1&&_b[i]==0){
                {
                    if(first==-1) first=i;
                }
            }
        }
        int ans2=a-b;
        int rr=r;
        for(int i=first-1;i>=0;i--){
            if(_a[i]==1&&_b[i]==0){
                if(r>= (1ll<<i) ){
                    r-=(1ll<<i);
                    ans2-=( 1ll<<(i+1) );
                }
            }
        }
        if(rr-(1ll<<first)>=0){
            int ans1=a-b-( 1ll<<(first+1) );
            rr-=(1ll<<first);
            for(int i=first-1;i>=0;i--){
                if(_a[i]==0&&_b[i]==1){
                    if(rr>= (1ll<<i) ){
                        rr-= (1ll<<i) ;
                        ans1+= (1ll<<(i+1)) ;
                    }
                }
            }
            ans2=min(abs(ans2),abs(ans1));
        }
        cout<<abs(ans2)<<endl;
    }
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}