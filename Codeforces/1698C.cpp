#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
void solve(){
    int n;
    cin>>n;
    long long sum=0;
    for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];

    int cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++){
        if(a[i]>0) cnt1++;
        if(a[i]<0) cnt2++;
    }

    if(n==3){
        long long s=a[1]+a[2]+a[3];
        if(s==a[1]||s==a[2]||s==a[3]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        return;
    }
    if(cnt1==2&&cnt2==2){
        int flag=1;
        for(int i=1;i<=n;i++){
            if(a[i]){
                if(sum-a[i]==a[i]||sum==a[i]) {}
                else flag=0; 
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else if(cnt1==2&&cnt2==1) cout<<"NO"<<endl;
    else if(cnt1==1&&cnt2==2) cout<<"NO"<<endl;
    else if(cnt1==1&&cnt2==1) {
        if(sum==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else if(cnt1==1||cnt2==1) cout<<"YES"<<endl;
    else {
        if(!cnt1 && !cnt2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}