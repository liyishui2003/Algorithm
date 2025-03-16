class Solution {
public:
    bool canJump(vector<int>& nums){
       int to = nums[0];
       int n = nums.size();
       for(int i = 0;i < n;i++){
           if(i <= to){
               to = max(to,i + nums[i]);
               if(to >= n - 1) return true;
           }
       }
       return false;
    }
};
