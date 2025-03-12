//一个串的最长回文子序列等价于它和反串的最长公共子序列
class Solution {
public:
    int dp[1005][1005];
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        int n = s.length();
        s=" "+s;
        t=" "+t;
        // cbbd
        // dbbc
        int ans = 1;
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++){
                if(s[i] == t[j]){
                    dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
                }
                dp[i][j] = max(dp[i][j],dp[i-1][j]);
                dp[i][j] = max(dp[i][j],dp[i][j-1]);
                ans=max(ans,dp[i][j]);
        }
        return ans;
    }
};
