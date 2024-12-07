#include<bits/stdc++.h>
using namespace std;
#define int long long
int const N=2e5+10;
int a[N],f[N][20],lg[N];
inline int query(int l,int r){
    int p=lg[r-l+1];
    return min(f[l][p],f[r-(1<<p)+1][p]);
}
signed main(){
    int t;cin>>t;
    while (t--){
        int n;cin>>n;
        for (int i=1;i<=n;++i) cin>>a[i],a[i]-=i,f[i][0]=a[i];
        for (int j=1;j<=19;++j)
            for (int i=1;i+(1<<(j-1))<=n;++i)
                f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        lg[0]=lg[1]=0;
        for (int i=2;i<=n;++i) lg[i]=lg[i>>1]+1;
        int ans=0;
        for (int i=1;i<=n;++i){
            int l=i,r=n;
            while (l<r){
                if (l+1==r){if (query(i,r)+i-1>=0) l=r;break;}
                int mid=(l+r)>>1;
                if (query(i,mid)+i-1>=0) l=mid;
                else r=mid-1;
            }
            ans+=(l-i+1);
        }
        cout<<ans<<'\n';
    }
    return 0;
}