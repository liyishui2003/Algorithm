class Solution {
public:
    void quickSort(vector<int>& nums,int left,int right){
        
        if(left >= right) return;
        
        int pivoIndex = left + rand()%(right - left + 1);
        int pivot = nums[pivoIndex];
        swap(nums[pivoIndex],nums[right]);
        
        int i = left;
        for(int j = left;j < right;j++){
            if(nums[j] < pivot){
                swap(nums[i],nums[j]);
                i++;
            }
        }

        swap(nums[i],nums[right]);

        quickSort(nums,left,i - 1);
        quickSort(nums,i + 1,right);
    }
    vector<int> sortArray(vector<int>& nums) {
        srand(time(0));
        quickSort(nums,0,nums.size() - 1);
        return nums;
    }
};
