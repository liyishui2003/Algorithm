int dp[50][50],bit[15];
class Solution {
public:
    int dfs(int pos,int cnt1,int lead,int lim){
        if(pos == 0) return cnt1; 
        if(!lim && dp[pos][cnt1] != -1) return dp[pos][cnt1];
        int up = lim ? bit[pos] : 9,ans = 0;
        for(int i = 0;i <= up;i++){
            ans += dfs(pos - 1,cnt1 + (i == 1),lead && i == 0,lim && i == bit[pos]);
        }
        if(!lim) dp[pos][cnt1] = ans;
        return ans;
    }
    int countDigitOne(int n) {
        memset(dp,-1,sizeof dp);
        memset(bit,0,sizeof bit);
        while(n){
           bit[0]++;
           bit[bit[0]] = n%10;
           n /= 10; 
        }
        return dfs(bit[0],0,0,1);
    }
};
