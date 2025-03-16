class Solution {
public:
    int maxPower(string s) {
        int n = s.length();
        int last = 0,ans = 1;
        for(int i = 1;i < n;i++){
            if(s[i] != s[i-1]){
                ans = max(ans,i - last);
                last = i;
            }
            else if( i == n - 1){
                ans = max(ans, i - last + 1);
            }
        }
        return ans;
    }
};
