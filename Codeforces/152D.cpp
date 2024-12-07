#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,a[N],vis[N];
int paint(int pos,queue<int> &q){
    if(pos>n||pos<1) return 0;
    if(vis[pos]==1) return 0;
    vis[pos]=1;
    q.push(pos);
    return 1;
}
int main(){
   cin>>n;
   for(int i=1;i<=n;i++){
     cin>>a[i];
   }

   if(a[1]==2) a[1]=1;
   if(a[n]==2) a[n]=1;
   queue<int>q;
   int ans=0;
   for(int i=1;i<=n;i++){
      if(a[i]==2){
        q.push(i);
        ans++;
        vis[i]=1;
      }
   }

   while(!q.empty()){
      int x=q.front();
      q.pop();
      if(a[x]==2){
         paint(x+1,q);
         paint(x-1,q);
      }
      else if(a[x]==1){
         if(paint(x+1,q)) {}
         else {
            paint(x-1,q);
         }
      }
   }

   int cnt=0;
   int sum_1=0,sum_0=0,dep_0=0;
   a[0]=0;
   for(int i=1;i<=n;i++){
     if(vis[i]) continue;
     if(a[i]==0){
        sum_0++;
        if( (i<n&&a[i+1]==1&&vis[i+1]==0) || (i>1&&a[i-1]==1&&vis[i-1]==0) ) dep_0++;
     }
     else {
        if(a[i-1]==0) sum_1++; 
     }
   }

   // cout<<sum_1<<" "<<sum_0<<" "<<dep_0<<endl;

    ans=ans+sum_1+(sum_0- min(dep_0,sum_1) );
    
    int lmost=-1,_2=0;
    for(int i=1;i<=n;i++){
        if(a[i]!=0) {
            if(lmost==-1) {
                lmost=i;
                if(a[i]==2) _2=1;
            }
            else {
                if(a[i]==2) {
                    if(_2==0) _2=1;
                    else ans--;
                }
            }
        }
        else lmost=-1,_2=0;
    }
    cout<<ans;
}