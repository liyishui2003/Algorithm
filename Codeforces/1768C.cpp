#include <bits/stdc++.h>
using namespace std;

// 快读

using LL=long long;
using LD=long double;
using UI=unsigned int;
using ULL=unsigned long long;

int T,n,a[200005],p1[200005],p2[200005];
vector<int> pos[200005];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) pos[i].clear();
		for(int i=1;i<=n;i++) cin>>a[i],pos[a[i]].push_back(i);
		bool fl=true;
		queue<int> q;
		for(int i=n;i>=1;i--)
		{
			if(pos[i].size()>2) { fl=false;break; }
			if(pos[i].empty())
			{
				if(q.empty()) { fl=false;break; }
				int j=q.front();
				p2[pos[j].front()]=i;
				p1[pos[j].back()]=i;
				q.pop();
			}
			else
			{
				p1[pos[i].front()]=i;
				p2[pos[i].back()]=i;
				if(pos[i].size()>1) q.push(i);
			}
		}
		if(!fl) { cout<<"NO\n";continue; }
		cout<<"YES\n";
		for(int i=1;i<=n;i++) cout<<p1[i]<<' ';
		cout<<'\n';
		for(int i=1;i<=n;i++) cout<<p2[i]<<' ';
		cout<<'\n';
	}
	return 0;
}