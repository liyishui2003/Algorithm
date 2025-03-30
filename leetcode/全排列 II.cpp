//水了一道题，正常应该是暴搜
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ret;
        sort(nums.begin(),nums.end());
        do {
            ret.push_back(nums);
        }
        while (std::next_permutation(nums.begin(), nums.end()));
        return ret;
    }
};
