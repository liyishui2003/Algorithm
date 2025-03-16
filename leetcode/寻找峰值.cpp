class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 1, r = nums.size() - 1;
        vector<int>a = nums;
        if(r == 0) return 0;
        if(a[1] < a[0]) return 0;
        a.push_back(INT_MIN);
        while(l <= r){
            int mid = (l + r) >> 1;
            if(a[mid] <= a[0]) {
                r = mid - 1;
            }
            else {
                if(a[mid - 1] > a[mid]){
                    r = mid - 1;
                }
                else { //a[mid - 1] <= a[0]
                    if(a[mid + 1] < a[mid] ){
                        return mid;
                    }
                    else {
                        l = mid + 1;
                    }
                }
            }
        }
        return l;
    }
};
