class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            if(nums[0]==1) return 1;
            else return 0;
        }
        int last = 0;
        int ans = 0;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[last]){
                if(nums[i]==0){
                    ans = max(ans,i-last);
                }
                last = i;
            }
            if(i==n-1){
                if(nums[i]==1){
                    ans = max(ans,i-last+1);
                }
            }
        }
        return ans;
    }
};
