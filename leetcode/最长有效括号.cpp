/*
很妙的dp，考虑当前括号如果是")"，要和谁匹配
*/
const int N = (int)3e4+5;
int dp[N];
class Solution {
public:
    int longestValidParentheses(string s) {
        memset(dp,0,sizeof dp);
        int n = s.length();
        s = " "+s;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(s[i]==')'){
                if(s[i-1]=='(') {
                    dp[i] = dp[i-2]+2;
                }
                else { // "))"
                    if(s[i-dp[i-1]-1]=='('){
                        cout<<"i="<<i<<" dp[i-1]="<<dp[i-1]<<" i-dp[i-1]-1="<<i-dp[i-1]-1<<endl;
                        dp[i] = dp[i-dp[i-1]-2]+dp[i-1]+2;
                    }
                }
            }
            else dp[i]=0;
            cout<<i<<" "<<dp[i]<<endl;
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
