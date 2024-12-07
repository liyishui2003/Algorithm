#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int sum[N],l0[N],r1[N];
void solve(){
    int n,k;
    cin>>n>>k;
    string s;cin>>s;
    s=" "+s;
    s[0]=0;
    for(int i=1;i<=n;i++){
        //left most zero
        if(s[i]=='0') l0[i]=i;
        else l0[i]=l0[i-1];
        sum[i]=sum[i-1]+(s[i]=='1');
    }
    for(int i=n;i>=1;i--){
        if(s[i]=='1')  r1[i]=i;
        else r1[i]=r1[i+1];
    }
    set<pair<int,int>>q;
    int flag=0;
    while(k--){
        int l,r;cin>>l>>r;
        int sum_1=sum[r]-sum[l-1];
        if(sum[r]-sum[r-sum_1]==sum_1) {
            flag=1;
            continue;
        }
        q.insert({r1[l],l0[r]});
    }
    cout<<flag+q.size()<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
