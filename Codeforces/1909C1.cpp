#include<bits/stdc++.h>
using namespace std;
int t;
int n;
long long l[100010],r[100010],c[100010];
long long v[100010],ans=0;
int fa[100010];
inline int find(int k)
{
	if(k==fa[k]) return k;
	return fa[k]=find(fa[k]);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		cin>>n;
		for(register int i=1;i<=n;i++) cin>>l[i],fa[i]=i;
		for(register int i=1;i<=n;i++) cin>>r[i];
		for(register int i=1;i<=n;i++) cin>>c[i];
		sort(l+1,l+n+1),sort(r+1,r+n+1),sort(c+1,c+n+1);
		for(register int i=1;i<=n;i++)
		{
			int k=lower_bound(l+1,l+n+1,r[i])-l;
			k--;
			k=find(k);
			v[i]=r[i]-l[k];
            cout<<r[i]<<" "<<l[k]<<endl;
			fa[k]=k-1;
		}
		sort(v+1,v+n+1);
		for(register int i=1;i<=n;i++) ans+=v[i]*c[n-i+1];
		printf("%lld\n",ans),ans=0;
	}
	return 0;
}