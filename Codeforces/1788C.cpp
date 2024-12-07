#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n+5],b[n+5],vis[n+5];
    for(int i=1;i<=n;i++) a[i]=i;

    int d=3*(n+1)/2;
    do  
    {  
           for(int i=1;i<=2*n;i++) vis[i]=0;
           for(int i=1;i<=n;i++) vis[i]=1;
           int tmp=d;
           int flag=1;
           for(int i=1;i<=n;i++){
               if(tmp<a[i]||vis[tmp-a[i]]) {
                  flag=0;break;
               }
               vis[tmp-a[i]]=1;
               b[i]=tmp-a[i];
               tmp++;
           }
           if(flag){
              for(int i=1;i<=n;i++) cout<<a[i]<<" "<<b[i]<<endl;
              cout<<endl<<endl;
           }
    }while(next_permutation(a+1,a+n+1));  
}