#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    string s;cin>>s;
    s=" "+s;
    int sum=0;
    for(int i=1;i<n;i++){
        int g=s[i]-'0',f=s[i+1]-'0';
        sum+=g*10+f;
    }
    if(n==2){
        if(!k) cout<<sum<<endl;
        else {
            if(s==" 11") cout<<sum<<endl;
            else if(s==" 01") cout<<sum<<endl;
            else if(s==" 10") cout<<1<<endl;
            else cout<<0<<endl;
        } 
    }
    else {
        int pos=-1;
        for(int i=1;i<=n;i++){
            if(s[i]=='1') {
                pos=i;break;
            }
        }
        int aft=-1;
        for(int i=n;i>=1;i--){
            if(s[i]=='1'){
                aft=i;break;
            }
        }
        if(aft==-1) {
            cout<<sum<<endl;
            return;
        }
        if(aft==pos){
            if(k>=n-pos&&pos!=n) sum-=10;
            else if(k>=pos-1&&pos!=1&&pos!=n) sum-=1;
        }
        else {
            swap(pos,aft);
            if(k>=n-pos&&pos!=n) {
                sum-=10;
                k-=(n-pos);
            }
            if(k>=aft-1&&aft!=1){
                sum-=1;
            }
        }
        cout<<sum<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}