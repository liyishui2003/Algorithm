#include<bits/stdc++.h>
using namespace std;
char a[105][105],b[105][105];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++){
        cin>>a[i][j];
        b[i][j]='0';
     }

    if(a[1][1]=='1') {
        cout<<-1<<endl;
        return;
    }
    vector< pair< pair<int,int>,pair<int,int> > >ans;
    for(int i=1;i<=n;i++){
        for(int j=m;j>1;j--){
            if(b[i][j]!=a[i][j]) {
                if(a[i][j]=='1') {
                    ans.push_back({{i,j-1},{i,j}});
                    b[i][j]='1';b[i][j-1]='0';
                }
                else {
                    ans.push_back({{i,j},{i,j}});
                    b[i][j]='0';
                }
            }
        }
    }
    for(int i=n;i>=1;i--){
        if(b[i][1]!=a[i][1]){
           // cout<<"?>>"<<endl;
            if(a[i][1]=='1'){
                ans.push_back({{i-1,1},{i,1}});
                b[i][1]='1';b[i-1][1]='0';
            }
            else {
                ans.push_back({{i,1},{i,1}});
                b[i][1]='0';
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto v:ans){
        auto f1=v.first,f2=v.second;
        cout<<f1.first<<" "<<f1.second<<" "<<f2.first<<" "<<f2.second<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}