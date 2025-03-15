const int N = 20+5;
int dp[N][N];
class Solution {
public:
    bool isMatch(string s, string p) {
        int lenS = s.length(),lenP = p.length();
        s = " " + s;
        p = " " + p;
        memset(dp,0,sizeof dp);
        dp[0][0] = 1;
        for(int i = 2;i <= lenP;i+=2){
            if(p[i] != '*') break;
            else dp[0][i] = 1;
        }
        for(int i = 1;i <= lenS;i++)
            for(int j = 1;j <= lenP;j++){
                if(p[j] != '.' && p[j] != '*') {
                    if(p[j] == s[i]) dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j] == '.'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    if(p[j-1] == '.' || p[j-1] == s[i]){//能匹配上
                        if(j >= 2) dp[i][j] |= dp[i-1][j-2] | dp[i][j-2];
                        //i-1表示s[i]一定要在这里首次匹配上(1个)，i表示不和p[j-1,j]匹配(0个)
                        dp[i][j] |= dp[i-1][j];//一定要在这里匹配上且连续匹配
                    }
                    else { //p[j-1] == 'a-z' and p[j] == *
                        if(p[j-1] != s[i]){ // 匹配不上，.*这样的组合就没用，只能指望j-2
                            if(j >= 2 ) dp[i][j] |= dp[i][j-2];
                        }
                    }
                }
            }
        if(dp[lenS][lenP])  return true;    
        else return false;
    }
};
