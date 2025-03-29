//直接摩尔投票法送走
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1,most = nums[0];
        int n = nums.size();
        for(int i = 1;i < n;i++){
            if(nums[i] != most){
                cnt --;
            }
            else cnt++;
            if(cnt == 0){
                cnt = 1;
                most = nums[i];
            }
        }
        return most;
    }
};
