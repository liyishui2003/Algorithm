class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int wri = 0;
        int n = nums.size();
        for(int i = 1;i < n; i++){
            if(nums[wri] != nums[i]){
             //   cout<<wri<<" "<<nums[i]<<'\n';
                wri++;
                nums[wri] = nums[i];
            }
        }
        return wri + 1;
    }
};
