#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
       int a,b;cin>>a>>b;
       if(a==1||b==1) {
         cout<<"YES"<<endl;
         continue;
       }
       int ok=(a<=b);
       for(int i=2;i<=sqrt(a);i++){
          if(a%i!=0) continue;
          if(i<=b || a/i<=b ) ok=1;
       }

       if(ok) cout<<"NO"<<endl;
       else cout<<"YES"<<endl;
    }
    
}