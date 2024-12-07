#include<bits/stdc++.h>
using namespace std;
void solve(){
     int n;
    cin>>n;
    int a[n+5];
    for(int i=0;i<n;i++) a[i]=i;
    do  
    {  
        int flag=1;
        for(int i=0;i<n;i++){
            int y=a[i]+i;
            if(sqrt(y)*sqrt(y)!=y){
                flag=0;
            }
        }
        if(flag) {
            for(int i=0;i<n;i++) cout<<a[i]<<" ";
            cout<<endl;
        }
    }while(next_permutation(a,a+n)); 
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    } 
}