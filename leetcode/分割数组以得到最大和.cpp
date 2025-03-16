//求最大值这里可以再倒叙枚举优化一下，边算dp值边更新最大值，就不用O(N^2)预处理了
class Solution {
public:
    long long dp[505],mx[505][505];
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(mx,0,sizeof mx);
        int n = arr.size();

        for(int i = 0;i < n;i++){
            mx[i][i] = arr[i];
            for(int j = i + 1;j < n;j++){
                mx[i][j] = max(mx[i][j - 1],1ll*arr[j]);
            }
        }

        for(int i = 1;i <= n;i++)
            dp[i] = -1e13;
        dp[0] = 0;

        for(int i = 1;i <= n;i++){
            for(int j = i - 1;j >= 0 && i - (j + 1) + 1 <= k;j--){
                dp[i] = max(dp[i],dp[j] + (i - (j + 1) + 1) * mx[j + 1 - 1][i - 1]);
            }
        }
        return dp[n];
    }
};
