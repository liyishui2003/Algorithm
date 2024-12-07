#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int maxSubArray(int nums[],int n) {
	if (n == 0) return 0;
	int dp[n+5];
	// base case
	// 第一个元素前面没有子数组
	dp[0] = nums[0];
	// 状态转移方程
	for (int i = 1; i < n; i++) {
		dp[i] = max(nums[i], nums[i] + dp[i - 1]);
	}
	// 得到 nums 的最大子数组
	int res = -(1e16);
	for (int i = 0; i < n; i++) {
		res = max(res, dp[i]);
	}
	return max(res,0*1ll);
}
int qpow(int a, int n)
{
	int ans = 1;
	while(n){
		if(n&1){
			ans = (ans * a) % mod;
		}
		a = (a * a) % mod;
		n >>= 1;
	}
	return ans;
}

void solve(){
	int n,k;cin>>n>>k;
	int a[n+5],sum=0;
	for(int i=0;i<n;i++) cin>>a[i],sum+=a[i],sum=(sum+mod*3)%mod;
	int x=maxSubArray(a,n);
	//cout<<sum<<" "<<x<<endl;
	sum+=x*( (qpow(2,k)-1+mod*3)%mod )%mod;
	sum=(sum+mod)%mod;
	cout<<sum<<endl;
}
signed main(){
	int t;cin>>t;while(t--) solve();
}
