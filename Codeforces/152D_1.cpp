#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],vis[N];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    
    if(a[1]==2) a[1]=1;
    if(a[n]==2) a[n]=1;

    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]==2&&vis[i]==0){
            ans+=1;
            vis[i]=1;
            int j=i-1;
            while(j>=1){
                vis[j]=1;
                if(!a[j]) break;
                j--;
            }
            j=i+1;
            while(j<=n){
                vis[j]=1;
                if(!a[j]) break;
                j++;
            }
        }
    }

   /*
   for(int i=1;i<=n;i++) cout<<vis[i]<<" ";
    cout<<endl;
    cout<<"ans: "<<ans<<endl;
   */ 

    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        if(a[i]==1){
            ans++;
            vis[i]=1;
            int flag=0;
            if(i>=2&&vis[i-1]==0&&a[i-1]==0) {
                vis[i-1]=1;
                flag=1;
            }
            int j=i+1;
            while(j<=n){
                if(!a[j]) break;
                vis[j]=1;
                j++;
            }
            if(!flag&&j<=n&&vis[j]==0&&a[j]==0) {
                vis[j]=1;
            }
        }
    }

/*
    for(int i=1;i<=n;i++) cout<<vis[i]<<" ";
    cout<<endl;
    cout<<"ans: "<<ans<<endl;
   // cout<<ans<<endl;
*/
    
    for(int i=1;i<=n;i++){
        ans+=1-vis[i];
    }

    cout<<ans;
}