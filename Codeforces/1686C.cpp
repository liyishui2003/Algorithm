#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],b[N];
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    
    if(n%2==1) {
        cout<<"NO"<<endl;
        return;
    }
    sort(a+1,a+n+1);
    for(int i=1,p=n/2+1;i<=n;i+=2,p++){
        b[i]=a[p];
    }
    for(int i=2,p=2;i<=n;i+=2,p++){
        b[i]=a[p];
    }
    
    b[n]=a[1];
    b[n+1]=b[1];
    b[0]=b[n];
    int flag=1;
    for(int i=1;i<=n;i++){
        if( (b[i-1]<b[i]&&b[i]>b[i+1]) || (b[i-1]>b[i]&&b[i+1]>b[i]) ) {}
        else flag=0;
    }
    if(!flag) cout<<"NO"<<endl;
    else {
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++) cout<<b[i]<<" ";
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