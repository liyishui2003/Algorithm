/*
状压直接送走
*/
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        int mx = (1 << 9);
        vector<vector<int>>ans;
        for(int i = 0;i < mx;i++){
            vector<int>ret;
            int sum = 0;
            for(int j = 0;j <= 8;j++){//分别映射0到8
                if((i >> j) & 1) {
                    ret.push_back(j + 1);
                    sum += j + 1;
                }
            }
            if(sum == n && ret.size() == k) {
                ans.push_back(ret);
            }
        }
        return ans;
    }
};
