//前缀和+分类讨论，击败96%
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // [x,y],任意两边之和大于第三边 -> 最小两边大于第三边
        // 第三边的范围为[两边中最大值，两边和-1]
        int sum[2005],cnt[2005];
        memset(cnt,0,sizeof cnt);
        memset(sum,0,sizeof sum);
        int n = nums.size();
        for(int i = 0;i < n;i++){
            sum[nums[i]]++;
        }
        for(int i = 1;i < 2001;i++)
            sum[i] = sum[i-1] + sum[i];
        int ans = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0;i < n;i++){
            cnt[nums[i]]++;
            for(int j = i + 1;j < n;j++){
                if(nums[i] == 0 || nums[j] == 0 || nums[i] == nums[j]) continue;
                int l = max(nums[i],nums[j]) + 1,r = nums[i] + nums[j] - 1;
                if(l > r) continue;
                int mx = max(nums[i],nums[j]);
                //ans += sum[mx] - sum[mx - 1] - (nums[i] == mx) - (nums[j] == mx);
                ans += sum[r] - sum[l - 1];
            }
        }
        n = unique(nums.begin(),nums.end()) - nums.begin();
        for(int i = 0;i < n;i++){
            if(nums[i] == 0 ) continue;
            int tot = cnt[nums[i]] * (cnt[nums[i]] - 1) / 2;
            int l,r;
            int x = nums[i];
            l = 1,r = x - 1;
            if(l <= r) ans += tot * (sum[r] - sum[l - 1]);
            l = x + 1,r = 2 * x -1;
            if(l <= r) ans += tot * (sum[r] - sum[l - 1]);
        }
        for(int i = 0;i < n;i++){
            if(nums[i] == 0) continue;
            ans += cnt[nums[i]] * (cnt[nums[i]] - 1) * (cnt[nums[i]] - 2) / 6;
        }
        return ans;
    }
};
