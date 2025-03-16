class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        int n1 = nums1.size();
        for(int i = 0;i < n1;i++){
            mp[nums1[i]] = 1;
        }
        int n2 = nums2.size();
        vector<int> ret;
        for(int i = 0;i < n2;i++){
            if(mp[nums2[i]] == 1) {
                ret.push_back(nums2[i]);
                mp[nums2[i]] = 2;
            }
        }
        return ret;
    }
};
