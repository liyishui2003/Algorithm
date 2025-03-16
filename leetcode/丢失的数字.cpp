class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(),flag = false,flagN = false;
        for(int i = 0;i < n;i++){
            int x = abs(nums[i]);
            if(x == n) {
                flagN = true;
                continue;
            }
            if(x == 0) flag = true;
            if(nums[x] >= 0){
                if(nums[x] > 0) nums[x] = -nums[x];
                else {
                    flag = true;
                    nums[x] = - x;
                }
            }
        }
        if(!flag) return 0;
        for(int i = 1;i < n;i++){
            if(nums[i] >= 0) return i;
        }
        return n;
    }
};
