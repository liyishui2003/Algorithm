/*
挺有意思的，考虑排序后挑cnt个最大的，如果已经为偶数直接返回
否则就调整一下，要么换前面最大的奇数进来，最小的偶数换进去；要么换前面最大的偶数进来，最小的偶数换进去
*/
class Solution {
public:
    int maximumScore(vector<int>& cards, int cnt) {
        int n = cards.size();
        sort(cards.begin(),cards.end());

        int sum = 0;
        int odd = 0,even = 0;
        int minodd = INT_MAX,mineven = INT_MAX;
        for(int i = n - 1;i >= n - 1 - cnt + 1;i--){
            sum += cards[i];
            if(cards[i] %2 == 0) mineven = min(mineven,cards[i]);
            else minodd = min(minodd,cards[i]);
        }
        if(sum % 2 == 0){
            return sum;
        }
        else {
            if( cnt == n ) return 0;
        }
        for(int i = 0;i < n - 1 - cnt + 1;i++){
            if(cards[i] %2 == 0) even = max(even,cards[i]);
            else odd = max(odd,cards[i]);
        }
        return max(sum - minodd + even,sum - mineven + odd);
    }
};
