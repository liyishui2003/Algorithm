#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int cnt[N],g[N];
int need(int x){

    int f=1;
    for(int i=x;i>=0;i--){
        if(g[i]){
            int d=min(g[i],f);
            g[i]-=d;
            f-=d;
            f*=2;
            if(!f) {
                return 1;
            } 
        }
        else f*=2;
    }
    return 0;
}
int main(){
    int m;
    cin>>m;
    while(m--){
        int op,v;cin>>op>>v;
        if(op==1){
            cnt[v]++;
        }
        else {
            int bit=0,b[40]={0};
            while(v){
                b[bit]=v%2;
                v>>=1;
                bit++;
            }
            int flag=1;
            for(int i=0;i<=32;i++) g[i]=cnt[i];
            for(int i=32;i>=0;i--){
                if(b[i]==0) continue;
                if(!need(i)) flag=0;
            }

            if(flag) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}