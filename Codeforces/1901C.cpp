#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
void solve(){
    int n;cin>>n;
    int mx=-INT_MAX,mi=INT_MAX;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        mx=max(a[i],mx);
        mi=min(mi,a[i]);
    }
    if(mx==mi) {
        cout<<0<<endl;return;
    }
    int delta=log2(mx-mi)+1;
    cout<<delta<<endl;
    if(delta<=n){
        
        for(int i=1;i<=delta;i++){
            int out;
            if(mx%2 == mi%2){
                out=0;
            }
            else {
                if(mx%2==1){
                    out=0;
                }
                else out=1;
            }
            cout<<out<<" ";
            mx=(mx+out)/2,mi=(mi+out)/2;
        }
        cout<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}