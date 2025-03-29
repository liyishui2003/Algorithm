class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0,r = nums.size() - 1,ans = -1;
        while(l <= r){
            int mid = (l + r)>>1;
            if(nums[mid] <= target){
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        //ans 为 小于等于 target 的最大值
        if(ans == -1) return 0;
        if(nums[ans] == target) return ans;
        else return ans + 1;
    }
};
