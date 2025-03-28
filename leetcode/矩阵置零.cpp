/*
随机一个数出来当清零标记
*/
class Solution {
public:
    bool check(int val,vector<vector<int>>& matrix){
        int n = matrix.size(),m = matrix[0].size();
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++){
                if(val == matrix[i][j]){
                    return false;
                }
            }
        return true;
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();
        srand(time(0));
        int mex = rand();
        while(1){
            if(check(mex,matrix)) {
                break;
            }
            mex = rand();
        }
        /*
        1  2  3  4
        5  0  7  8
        0  10 11 12
        13 14 15 0
        */
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(matrix[i][j] == 0){
                    int tx = i,ty = j;
                    while(tx - 1 >= 0 && matrix[tx - 1][ty] != 0 ) {
                        tx--;
                        matrix[tx][ty] = mex;
                    }
                    tx = i,ty = j;
                    while(tx + 1 <= n - 1 && matrix[tx + 1][ty] != 0) {
                        tx++;
                        matrix[tx][ty] = mex;
                    }
                    tx = i,ty = j;
                    while(ty - 1 >= 0 && matrix[tx][ty - 1] != 0) {
                        ty--;
                        matrix[tx][ty] = mex;
                    }
                    tx = i,ty = j;
                    while(ty + 1 <= m - 1 && matrix[tx][ty + 1] != 0) {
                        ty++;
                        matrix[tx][ty] = mex;
                    }
                }
            }
        }

        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++){
                if(matrix[i][j] == mex){
                    matrix[i][j] = 0;
                }
            }
    }
};
