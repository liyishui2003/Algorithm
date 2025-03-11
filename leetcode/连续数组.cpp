const int N = 1e5+5;
int num1[N],num2[N];
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        for(int i=1;i<=n;i++){
            num1[i]=num1[i-1];
            num2[i]=num2[i-1];
            if(nums[i-1]==1) num1[i]++;
            else num2[i]++;
        }

        unordered_map<int,int>mp;
        mp[0]=0;
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(mp.find(num1[i]-num2[i]) != mp.end()){
                ans = max(ans,i - mp[num1[i] - num2[i]]);
            }
            else {
                mp[num1[i]-num2[i]] = i;
            }
        }
        return ans;
    }
};
