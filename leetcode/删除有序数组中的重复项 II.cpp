class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        int write = 1,cnt = 1;
        for(int i = 1;i < n;i++){
            if(nums[i] == nums[i - 1]){
                cnt++;
            }
            else cnt = 1;
            if(cnt <= 2){
                nums[write] = nums[i];
                write++;
            }
        }
        return write;
    }
};
