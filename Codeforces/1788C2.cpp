#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    if(n%2==0){
        cout<<"No"<<endl;
        return;
    }
    if(n==1){
        cout<<"Yes"<<endl;
        cout<<1<<" "<<2<<endl;
        return;
    }
    else if(n==3){
        cout<<"Yes"<<endl;
        cout<<1<<" "<<6<<endl;
        cout<<3<<" "<<5<<endl;
        cout<<4<<" "<<2<<endl;
    }
    else cout<<"No"<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}