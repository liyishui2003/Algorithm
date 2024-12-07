#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],ans[N];
void solve(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i],ans[i]=0;

    int tmp=0,pos=-1;
    for(int i=n;i>=1;i--){
        if(a[i]>tmp) {
            tmp++;ans[i]=1;
        }
        else ans[i]=1;
        if(tmp==q) {
            pos=i;break;
        }
    }

    for(int i=1;i<pos;i++) if(tmp>=a[i]) ans[i]=1;
    for(int i=1;i<=n;i++) cout<<ans[i];
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}