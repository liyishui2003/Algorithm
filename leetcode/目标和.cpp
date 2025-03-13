//法一：转化题目为从n个数中挑若干个为正数并设这部分和为x，若干个为负数并设这部分和为y
//则有如下对应关系：
//x + y = sum,x - y = target，对减一下发现y = (sum-target)/2
//这就要求sum>=target，且它们的差值%2==0
//然后就是经典背包问题
const int  N = 1005;
class Solution {
public:
    int ans = 0;
    int dp[N];
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0;i < n;i++){
            sum = sum + nums[i];
        }
        if(sum < target) return 0;
        if((sum - target)%2) return 0;
        memset(dp,0,sizeof dp);
        dp[0] = 1;
        dp[nums[0]] += 1;
        for(int i = 1;i < n;i++){
            for(int j = (sum-target)/2;j >= nums[i];j--){
                dp[j] += dp[j-nums[i]];
            }
        }
        return dp[(sum-target)/2];
    }
};
//法二：n很小，暴力dfs
class Solution {
    void dfs(int u,int sum,int n,int target,vector<int>& nums){
        if(u == n){
            if(sum != target) {
                return;
            }
            ans++;
            return ;
        }
        dfs(u+1,sum+nums[u],n,target,nums);
        dfs(u+1,sum-nums[u],n,target,nums);
    }
public:
    int ans = 0;
    int findTargetSumWays(vector<int>& nums, int target) {
        ans = 0;
        dfs(0,0,nums.size(),target,nums);
        return ans;
    }
};
