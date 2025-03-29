class Solution {
public:

    int findMin(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int l=0,r=nums.size()-1,ans=-1;
        while(l<=r){
            int mid=(l+r)>>1;
            if(nums[mid]>=nums[0]){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        int mi = nums[0];
        if( ans != -1 && ans <= nums.size() - 2) mi = min(mi,nums[ans + 1]);
        return mi;
    }
};
