class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0;i < n;i++){
            int to = min(i + n / 4,n);
            if(arr[to] == arr[i]){
                return arr[i];
            }
        }
        return 0;
    }
};

//一个更优的解法是考虑这25%必然是连续&至少占据四分之一长，所以必然会覆盖四分点，枚举每个四分点nums[i]并统计nums[i]出现次数即可
