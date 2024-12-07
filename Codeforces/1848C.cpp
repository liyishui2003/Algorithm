#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],b[N],c[N];
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i],c[i]=abs(a[i]-b[i]);

    for(int i=1;i<=30;i++){
        cout<<"a ";
        for(int i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<endl<<"b ";
        for(int i=1;i<=n;i++) cout<<b[i]<<" ";
        cout<<endl<<"c ";
        for(int i=1;i<=n;i++) cout<<c[i]<<" ";
        cout<<endl;

        for(int i=1;i<=n;i++) c[i]=abs(a[i]-b[i]);
        for(int i=1;i<=n;i++) a[i]=b[i];
        for(int i=1;i<=n;i++) b[i]=c[i];
    }
}
int check(int x,int y){
    int c=abs(x-y);
    int cnt=0;
    while(1){
        if(x==0) {
            cout<<"end: "<<cnt<<endl;
            return cnt;
        }
        c=abs(x-y);
        x=y;
        y=c;
        cnt++;
    }
    return -1;
}
int main(){
    
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    
    vector<int>ans;
    for(int i=1;i<=n;i++){
        if(check(a[i],b[i])) ans.push_back(check(a[i],b[i]));
    }
    for(int i=1;i<=n;i++){
        int g=gcd(a[i],b[i]);
        cout<<(a[i]/g)/(b[i]/g)<<" ";
    }
    cout<<endl;
    for(auto v:ans){
        cout<<v<<" ";
    }
    cout<<endl;
    for(auto v:ans){
        cout<<v%3<<" ";
    }
    cout<<endl;
}