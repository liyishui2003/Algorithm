//一眼滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        map<char,int>mp;
        int r = 0,ans = 0;
        for(int l = 0;l < n;l++){
            while(r < n && mp[s[r]] == 0){
                mp[s[r]]++;
                r++;
            }
            ans = max(ans,r - l);
            mp[s[l]]--;
        }
        return ans;
    }
};
