/*
观察下一个排列的本质：
找到最长的一段连续下降的后缀，记这段后缀的开头为pos
然后在后缀里找到最小的大于nums[pos - 1]的数，将其和nums[pos - 1]进行交换
最后反转后缀
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
/*
//      1 2 3 4 ..
//      1 2 3 5 ..
//      1 2 3 6 ..
另一个例子:
1 3 2
*/
        int n = nums.size(),pos = n - 1;
        if(n == 1) return;
        for(int i = n - 2;i >= 0;i--){
            if(nums[i + 1] <= nums[i]){
                pos = i;
            }
            else break;
        }
        /*
        1 2 4 6 5 3
        1 2 5 3 4 6
        */
        if(pos == 0){
            reverse(nums.begin(),nums.end());
            return;
        }
        int mx = n - 1;
        while(nums[mx] <= nums[pos - 1]){
            mx--;
        }
        swap(nums[pos - 1],nums[mx]);
        for(int i = pos,j = n - 1;i <= j ;i++,j--){
            swap(nums[i],nums[j]);
        }
    }
};
