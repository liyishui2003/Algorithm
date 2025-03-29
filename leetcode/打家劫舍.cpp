const int N  = 105;
int dp[N],sum[N];
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        memset(dp,0,sizeof dp);
        int ans = max(nums[0],nums[1]);
        dp[1] = nums[0];
        dp[2] = nums[1];
        sum[1] = dp[1];
        sum[2] = max(dp[1],dp[2]);
        //dp[i]表示以i为结尾一定要偷窃的答案
        //sum[i]表示前缀最大值
        for(int i = 3 ;i <= n;i++){
            dp[i] = max(dp[i - 1],sum[i - 2] + nums[i - 1]);
            sum[i] = max(sum[i - 1],dp[i]);
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};
