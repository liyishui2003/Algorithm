class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi = prices[0], n = prices.size();
        int ret = 0;
        for(int i = 1;i < n;i++){
            ret = max(ret,prices[i] - mi);
            mi = min(mi,prices[i]);
        }
        return ret;
    }
};
