//总和可求，分割的实质是取出一些数使得其和=sum/2，经典背包dp
const int N =2e4+5;
int dp[N];
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0;i < n;i++) sum = sum +nums[i];
        if(sum % 2) return false;
        
        memset(dp,0,sizeof dp);
        dp[0] = 1;
        dp[nums[0]] = 1;
        for(int i = 1;i < n;i++){
            for(int j = sum / 2;j >= nums[i]; j--){
                dp[j] |= dp[j - nums[i]];
            }
        }
        return dp[sum / 2];
    }
};
