//直接维护序列，贪心修改
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>q;
        int n = nums.size();
        for(int i=0;i<n;i++){
            auto it=lower_bound(q.begin(),q.end(),nums[i]);
            if(it!=q.end()){
                *it = nums[i];
            }
            else q.push_back(nums[i]);
        }
        return q.size();
    }
};
