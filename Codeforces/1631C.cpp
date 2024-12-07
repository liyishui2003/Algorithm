#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i+=2){
        sum+=(i&(i+1));
    } 
    cout<<sum<<endl;
}
int main(){
 //   cout<<pow(2,16)<<endl;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}