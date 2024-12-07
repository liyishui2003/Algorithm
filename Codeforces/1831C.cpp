#include<iostream>
using namespace std;
const int N=1e6+5;
int n,x[N],y[N],fa[N],cnt[N],f[N],book[N],use[N];
void init(){
    for(int i=1;i<=n;i++) f[i]=i;
}
int find(int x){
    if(x!=f[x]) return f[x]=find(f[x]);
    else return x;
}
void solve(){
    
    cin>>n;
    for(int i=1;i<=n;i++) fa[i]=x[i]=y[i]=cnt[i]=book[i]=use[i]=0;

    for(int i=1;i<n;i++){
        cin>>x[i]>>y[i];
        fa[y[i]]=x[i];
        cnt[y[i]]=i;
    }
    int ans=1;
    init();
    for(int i=1;i<=n;i++){
        if(cnt[fa[i]]>cnt[i]) {
            int f1=find(fa[i]),f2=find(i);
            if(f1!=f2){
                f[f2]=f1;
                use[fa[i]]=use[i]=1;
                cout<<i<<" #"<<endl;
            }
        }
    }

    for(int i=1;i<=n;i++) ans+=(f[i]==i && use[i] );
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}