//手模一下发现不考虑符号的话肯定数值肯定是越大越好，不要有0。符号就用维护最小值最大值来处理。
const int N = 2e4+5;
int mi[N],mx[N];
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        mi[0] = nums[0];
        mx[0] = nums[0];
        int ans = mi[0];
        for(int i = 1;i < n ;i++){
            if(nums[i - 1] == 0) {
                mi[i] = nums[i];
                mx[i] = nums[i];
            }
            else {
                mi[i] = min(mi[i - 1] * nums[i],mx[i - 1] * nums[i]);
                mx[i] = max(mi[i - 1] * nums[i],mx[i - 1] * nums[i]);
                mi[i] = min(mi[i], nums[i]);
                mx[i] = max(mx[i], nums[i]);
            }
            ans = max(ans,mx[i]);
        }
        return ans;
    }
};
