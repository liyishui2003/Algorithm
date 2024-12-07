#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,m,k;
    cin>>n>>m>>k;

    // not enough
    if(k<n+m-2) {
        cout<<"NO"<<endl;return;
    }
    int del=k-(n+m-2);
    if((del%4)%2){
        cout<<"NO"<<endl;return;
    }

    char col[2];
    if((n-1)%2==0) {
        col[0]='B';col[1]='R';
    } 
    else {
        col[0]='R';col[1]='B';
    }

    cout<<"YES"<<endl;
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++) {
            if(i==n-1&&j==m-1)  cout<<col[(m+1)%2]<<" ";
            else cout<<"R ";
        }
        cout<<endl;
    }
    
    for(int i=1;i<m;i++) cout<<col[(i-1)%2]<<" ";
    cout<<endl;

    col[0]='B';col[1]='R';

    for(int i=1;i<=n-1;i++){
        cout<<col[(i-1)%2]<<" ";
        for(int j=2;j<=m;j++) {
            if(i==1&&j==2) cout<<"B ";
            else if(i==n-1&&j>=m-1){
                cout<<col[(m)%2]<<" ";
            }
            else cout<<"R ";
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