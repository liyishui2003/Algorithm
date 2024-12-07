#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int N=1e6+5;
int a[N];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,q;cin>>n>>q;
	vector<int>cnt(1<<20);
	vector<vector<ll>>dp(20);
	ll sum=0;
	for(int i=1;i<=n;i++) cin>>a[i],cnt[a[i]]++,sum+=a[i];
	
	for(int i=0;i<20;i++)
		for(int j=0;j<(1<<20);j++)
			if(j>>i&1) cnt[j^(1<<i)]+=cnt[j];
	
	for(int i=0;i<20;i++){
		dp[i].resize(1<<20);
		for(int j=1;j<=n;j++){
			int mask=(1<<(i+1))-1; //末尾i位
			dp[i][a[j]]+=a[j]&mask;
		}
		for(int j=0;j<20;j++){
			for(int k=0;k<(1<<20);k++)
			 if(k>>j&1) dp[i][k^(1<<j)]+=dp[i][k];
		}
	}
	int mx=(1<<20)-1;
	while(q--){
		ll k;cin>>k;
		if( ( (k+sum) /n )>mx){
			cout<<(k+sum)/n<<endl;continue;
		}
		else{
			int ans=0;
			for(int i=19;i>=0;i--){
				int c1=cnt[ans];
				int c2=cnt[ans|(1<<i)];
				ll t=0;
				t+=1ll*(n-c1)*(1<<i);
				t+=1ll*(c1-c2)*(1<<i)-(dp[i][ans]-dp[i][ans|(1<<i)]);
				if(t<=k){
					k-=t;
					ans|= (1<<i);
				}
			}
			cout<<ans<<endl;
		}
	}
}
