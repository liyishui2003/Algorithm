class Solution {
public:
    int maxSales(vector<int>& sales) {
        if(sales.size() == 0) return 0;
        int mi = min(0,sales[0]),sum = sales[0];
        int n = sales.size(),ret = sales[0];
        for(int i = 1;i < n;i++){
            sum += sales[i];
            int mx = sum - mi;
            ret = max(ret,mx);
            mi = min(mi,sum);
        }
        return ret;
    }
};
