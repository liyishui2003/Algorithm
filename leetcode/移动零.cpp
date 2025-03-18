class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int wri = 0;
        for(int i = 0;i < n;i++){
            if(nums[i] == 0){
                continue;
            }
            else {
                nums[wri] = nums[i];
                if(i != wri) nums[i] = 0;
                wri++;
            }
        }
    }
};
