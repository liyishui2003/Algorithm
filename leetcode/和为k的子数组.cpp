/*
哈希表+前缀和
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int l = nums.size();
        mp[0]++;
        int sufSum = 0;//前缀和
        int ans = 0;
        for(int i = 0;i < l;i++){
            sufSum += nums[i];
            int need = sufSum-k;
            ans += mp[need];
            mp[sufSum]++;
        }
        return ans;
    }
};
