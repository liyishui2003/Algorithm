//思路同数组中重复的数据，也是用自带的nums数组+下标+正负号做标记
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i < n;i++){
            int x = abs(nums[i]);
            if(nums[x-1]>0) nums[x-1] = -nums[x-1];
        }
        vector<int> ret;
        for(int i = 1;i <= n;i++){
            if(nums[i-1]>0) ret.push_back(i);
        }
        return ret;
    }
};
