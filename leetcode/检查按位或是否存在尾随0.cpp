class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int n = nums.size();
        int even = 0;
        for(int i = 0;i < n;i++){
            even += nums[i] % 2 == 0;
        }
        return even >= 2;
    }
};
