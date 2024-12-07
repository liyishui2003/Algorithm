#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,q,cnt=0;cin>>n>>q;
    vector<int>a[65],l[65];
    int t=0;
    a[0].push_back(0);
    l[0].push_back(0);
    for(int i=1;i<=n;i++){
        int b,x;cin>>b>>x;
        if(b==1) {
            a[cnt].push_back(x);
            l[cnt].push_back(t+1);
            t++;
        }
        else {
            cnt++;
            a[cnt].push_back(0);
            l[cnt].push_back(t*(x+1));
            t*=(x+1);
        }
    }
    cnt++;a[cnt].push_back(0);l[cnt].push_back(t*2);
    for(int i=1;i<=q;i++){
        int k;cin>>k;
        int flag=1;
        vector<int>ans;
        for(int i=cnt-1;i>=0&&flag;i--){
            if(k>=l[i][0]&& k<=l[i+1][0]){
                int last=a[i].size()-1;
                int len=l[i][last];
                k%=len;if(!k) k=len;
                cout<<" :: "<<k<<" "<<len<<" "<<l[i][0]<<endl;
                if(i==0){
                    ans.push_back(a[i][k]);
                    cout<<i<<" # "<<k<<" "<<a[i][k]<<endl;
                    flag=0;
                    break;
                }
                if (k<=l[i][0]) continue;
                
                    k%=l[i][0];
                    if(!k) k=l[i][0];
                    ans.push_back(a[i][k]);
                    cout<<i<<" # "<<k<<" "<<a[i][k]<<endl;
                    flag=0;
                
            }
        }
            for (auto v:ans) cout<<v<<" ";
            cout<<endl;
    }
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}