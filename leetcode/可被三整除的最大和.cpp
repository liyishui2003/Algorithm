//同余背包，设dp[i][j]为考虑了前i个，选出的数%3=j的最大元素和，转移方程就是经典背包
const int N = 4e4+5;
int dp[N][3];
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i < n;i++)
            for(int j = 0;j < 3;j++)
                dp[i][j] = -INT_MAX;

        int ans = 0;
        dp[0][nums[0]%3] = nums[0];
        dp[0][0] = max(dp[0][0],0);
        for(int i = 1;i < n;i++){
            int mod = nums[i]%3;
            for(int j = 0;j < 3;j++){
                int old = (j - mod + 3)%3;
                dp[i][j] = max(dp[i-1][j],dp[i-1][old] + nums[i]);
                if(j == 0) ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
