const int N = 1005;
const int mod = (int)1e9+7;
class Solution {
public:
    int dp[N][N];
    int numDistinct(string s, string t) {
        int ls = s.length(), lt = t.length();
        s = " " + s;
        t = " " + t;
        for(int i = 0;i < ls;i++) dp[i][0] = 1;
        for(int i = 1;i <= ls;i++){
            for(int j = 1;j <= lt;j++){
                if(s[i] == t[j]){
                    dp[i][j] += dp[i - 1][j - 1];
                    dp[i][j] %= mod;
                }
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= mod;
                //cout<<i<<" "<<j<<" "<<dp[i][j]<<'\n';
            }
        }
        return dp[ls][lt];
    }
};
