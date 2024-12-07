#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c[30],ans[N],vis[N];
int out=0,n,k;
string a,b;
void check(){
        for(int i=1;i<=n;i++){
                if(a[i]!=b[i]){
                    int id=a[i]-'a';
                    if(vis[id]) ans[i]=0;
                    else ans[i]=1;
                }
                else ans[i]=0;
        }
        ans[0]=1;
        ans[n+1]=1;
        int tmp=0,last=-1;
        for(int i=1;i<=n;i++){
            if(ans[i]==0&&ans[i-1]==1){
                last=i;
            }
            if(ans[i]==0&&ans[i+1]==1){
                int len=i-last+1;
                tmp+=len*(len-1)/2+len;
            }
        }
        out=max(out,tmp);
}
void dfs(int at,int selec,int k,int cnt){
    if(selec==k+1) {
        check(); 
        return;
    }
    if(at==cnt+1) return;
    if(selec+1<=k){
        vis[c[at]]=1;
        dfs(at+1,selec+1,k,cnt);
    }
    vis[c[at]]=0;
    dfs(at+1,selec,k,cnt);
}
void solve(){
    cin>>n>>k;
    cin>>a>>b;
    a=" "+a;
    b=" "+b;
    int cnt=0,mp[30]={0};

    for(int i=1;i<=n;i++){
        int id=a[i]-'a';
        if(mp[id]==0){
            mp[id]=1;
            c[++cnt]=id;
        }
    }

    k=min(k,cnt);
    check();
    dfs(1,0,k,cnt);
    cout<<out<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}