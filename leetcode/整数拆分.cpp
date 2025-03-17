/*
写的背包，还有一种做法是枚举k然后均分，还有一种做法：只考虑2和3
最无敌的是数学分解了。
*/
const int N = 60;
int dig[N],dp[N][N];
class Solution {
public:
    int integerBreak(int n) {
        memset(dp,0,sizeof dp);
        dp[0][0] = 1;   
        int ans = 0;
        for(int i = 1;i <= n;i++){
            for(int k = 1;k <= i;k++)
                for(int j = 1;j <= i;j++){
                    dp[i][j] = max(dp[i][j],dp[i - k][j - 1] * k);
                    if(j >= 2) ans = max(ans,dp[i][j]);
                }
        }
        return ans;
    }
};
