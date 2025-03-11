int dp[1005][1005];
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(),m = text2.length();
        text1 = " "+text1;
        text2 = " "+text2;
        memset(dp,0,sizeof dp);
        int ret = 0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
                dp[i][j]=max(dp[i][j],dp[i][j-1]);
                if(text1[i]==text2[j]){
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
                ret = max(ret,dp[i][j]);
            }
        }
        return ret;
    }
};
