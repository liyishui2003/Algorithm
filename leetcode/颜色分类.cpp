/*
想到双指针还不够，想到相遇的边界也不够，精髓在于遇到2要不断交换，得搭一个while+swap，不然很难写。
0的情况往前换即可，0和2都照顾好了就不用管1，因为剩下的就是。
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int writeR = 0;
        for(int i = 0 ;i <= r;i++){
            while(i <= r && nums[i] == 2){
                swap(nums[i],nums[r]);
                r--;
            }
            if(nums[i] == 0){
                swap(nums[i],nums[l]);
                ++l;
            }
        }
    }
};
