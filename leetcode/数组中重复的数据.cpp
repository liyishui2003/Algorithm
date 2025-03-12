.//非常巧妙，考虑数据范围和下标是一一对应的关系，用下标做key存东西，具体的操作是把下标对应的数标记成负数。
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i = 0; i < n;i++) {
            int x = abs(nums[i]);
            if(nums[x-1] > 0){
                nums[x-1] = -nums[x-1];
            }
            else ans.push_back(x);
        }
        return ans;
    }
};
