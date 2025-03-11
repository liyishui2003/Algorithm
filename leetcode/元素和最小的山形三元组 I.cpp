//前后缀分解，三元组一般考虑枚举中间值
const int N = 55;
int pre[N],suf[N];
class Solution {
public:
    int minimumSum(vector<int>& nums) {
        
        int n = nums.size();
        pre[1]=nums[0];
        for(int i=2;i<=n;i++){
            pre[i]=min(pre[i-1],nums[i-1]);
        }
        suf[n]=nums[n-1];
        for(int i=n-1;i>=1;i--){
            suf[i]=min(suf[i+1],nums[i-1]);
        }
        int ans=INT_MAX;
        for(int i=2;i<n;i++){
            if(pre[i-1]<nums[i-1]&&suf[i+1]<nums[i-1]){
                ans=min(ans,nums[i-1]+pre[i-1]+suf[i+1]);
            }
        }
        if(ans==INT_MAX) return -1;
        else return ans;
    }
};
