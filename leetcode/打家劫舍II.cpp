const int N = 105;
int dp[N];
class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        dp[0] = nums[0];
        for(int i = 1;i < n;i++){
            if(i - 2 >= 0){
                dp[i] = max(dp[i - 1],dp[i - 2] + nums[i]);
            }
            else dp[i] = dp[i - 1];
        }
        int ret = dp[n - 2];
        dp[0] = 0;
        dp[1] = nums[1];
        for(int i = 2;i < n;i++){
            dp[i] = max(dp[i - 1],dp[i - 2] + nums[i]);
        }
        ret = max(ret,dp[n - 1]);
        return ret;
    }
};
