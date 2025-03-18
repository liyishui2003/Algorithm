class Solution {
public:
    int sumBase(int n, int k) {
        int tot = 0;
        while(n){
            tot += n%k;
            n /= k;
        }
        return tot;
    }
};
