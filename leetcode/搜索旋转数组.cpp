class Solution {
public:
    int search(vector<int>& arr, int target) {
        int l = 0,r = arr.size() - 1;
        //special judge
        if(arr[0] == target) return 0;
        if(r == 0){
            if(arr[0] == target) return 0;
            else return -1;
        }
        // now len >= 2
        while(arr[r] == arr[l]) r--;
        while(l + 1 <= r && arr[l + 1] == arr[l]) {
            l++;
        }
        // remove the begin and end
        int L = l,R = r;
        int ans = -1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(arr[mid] >= arr[0]){
                ans = mid;
                l = mid + 1;;
            }
            else r = mid - 1;
        }
        // now ans == the turnning point
        int left = L, right = ans, ret = -1;
        // begin binary serch on the left part and right part
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] >= target) {
                right = mid - 1;
                ret = mid;
            } else {
                left = mid + 1;
            }
        }
        if(ret != -1 && arr[ret] == target) return ret;
        left = ans + 1,right = R,ret = -1;
        while(left <= right){
            int mid = (left + right) / 2;
            if (arr[mid] >= target) {
                right = mid - 1;
                ret = mid;
            } else {
                left = mid + 1;
            }
        }
        if(ret != -1 && arr[ret] == target) return ret;
        return -1;
    }
};
