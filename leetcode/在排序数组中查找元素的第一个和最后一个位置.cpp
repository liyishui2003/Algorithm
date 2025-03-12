//思路是找到第一个小于target的和第一个大于target的，两边夹一下就是target
//注意判断target小于最小值和大于最大值的情况
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0,r = nums.size()-1,ans = -1;
        int n = nums.size();
        vector<int>ret;
        ret.push_back(-1);ret.push_back(-1);
        if(!n) {
            return ret;
        }
        while(l <= r){
            int mid = (l+r)>>1;
            if(nums[mid] < target){
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        //ans eq the mx num that less then target
        //deal with if target < nums[0]
        if(ans == -1 && nums[0] != target){
            return ret;
        }
        //deal with if target > nums[n-1]
        if(ans == n-1 && nums[n-1] != target){
            return ret;
        }
        ans++;
        if(nums[ans] != target){
            return ret;
        }
        ret[0] = ans;
        l = 0,r = n - 1,ans = n;
        while(l <= r){
            int mid = (l+r)>>1;
            if(nums[mid] > target){
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        if(ans == n){ //not found -> target is the max number in arr
            ret[1] = n - 1;
        }
        else ret[1] = ans - 1;
        return ret;
    }
};
