/*
最开始往二分想以后，怎么优化都是nlog，有的路一旦走错了又没意识到，就永远回不去了。
最优解是O(N + M)，奇思妙想考虑从右上角出发，如果当前p[i][j] < target，说明整行都不行，i++
我们用到了行的性质，列同理 -> 如果当前p[i][j] > target，说明当前该列整列往下都不行，j--
*/
class Solution {
public:
    bool findTargetIn2DPlants(vector<vector<int>>& plants, int target) {
        /*
        2  3  6  8
        4  5  8  9
        5  9  10 12
        ->在行列都递增的数组中找target
        */
        if(plants.size() == 0) return false;
        if(plants[0].size() == 0 ) return false;
        int l = plants[0].size() - 1, r = 0;
        while(1){
            if(plants[r][l] == target){
                return true;
            }
            else if(plants[r][l] < target){
                r++;
            }
            else if(plants[r][l] > target){
                l--;
            }
            if(r >= plants.size()) return false;
            if(l < 0) return false;
        }
        return plants[r][l] == target; 
    }
};
