const int N = 1e4+5;
int dp[N];
class Solution {
public:
    int numSquares(int n) {
        memset(dp,0x3f3f3f3f,sizeof dp);
        dp[0] = 0;
        for(int i = 1; i <= n ;i++){
            for(int j = sqrt(i);j >= 1;j--){
                dp[i] = min(dp[i - j * j] + 1,dp[i]);
            }
        }
        return dp[n];
    }
};
