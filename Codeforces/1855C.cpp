#include<bits/stdc++.h>
using namespace std;
int a[50],b[50];
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int mx_p=0,mx_n=0;
    for(int i=1;i<=n;i++) {
        if(a[i]>=0) {
            mx_p=max(mx_p,abs(a[i]));
        }
        else mx_n=max(mx_n,abs(a[i]));
    }

    int pos_p=0,pos_n=0;
    for(int i=1;i<=n;i++){
        if(a[i]>=0&&a[i]==mx_p) pos_p=i;
        else if(a[i]<0&&a[i]==-mx_n) pos_n=i;
    }

    // test_positive
    for(int i=0;i<=5;i++){
        vector<pair<int,int>>ans;
        for(int j=1;j<=n;j++) b[j]=a[j];
        for(int j=1;j<=i;j++) b[pos_p]*=2,ans.push_back({pos_p,pos_p});

        for(int j=1;j<=n;j++){
            if(b[j]<0) {
                b[j]+=b[pos_p]; 
                ans.push_back({j,pos_p});
            }
        }
        int flag=1;
        for(int j=1;j<=n;j++) {
            if(b[j]<0) flag=0;
        }
        if(!flag) continue;
        for(int j=2;j<=n;j++){
            if(b[j]<b[j-1]) {
                b[j]+=b[j-1];
                ans.push_back({j,j-1});
            }
        }

        if(ans.size()<=31) {
            cout<<ans.size()<<endl;
            for(auto v:ans){
                cout<<v.first<<" "<<v.second<<endl;
            }
            return ;
        }
    } 

    // test neg
    for(int i=0;i<=5;i++){
        vector<pair<int,int>>ans;
        for(int j=1;j<=n;j++) b[j]=a[j];
        for(int j=1;j<=i;j++) b[pos_n]*=2,ans.push_back({pos_n,pos_n});

        for(int j=1;j<=n;j++){
            if(b[j]>0) {
                b[j]+=b[pos_n]; 
                ans.push_back({j,pos_n});
            }
        }

        int flag=1;
        for(int j=1;j<=n;j++) {
            if(b[j]>0) flag=0;
        }
        if(!flag) continue;

        for(int j=n;j>=2;j--){
            if(b[j]<b[j-1]) {
                b[j-1]+=b[j];
                ans.push_back({j-1,j});
            }
        }

        if(ans.size()<=31) {
            cout<<ans.size()<<endl;
            for(auto v:ans){
                cout<<v.first<<" "<<v.second<<endl;
            }
            return ;
        }
    } 
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}