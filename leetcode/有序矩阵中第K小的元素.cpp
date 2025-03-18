/*
很神秘，上一道有序矩阵是双指针，往二分去想反而没有最优解
这一道涉及到第K小，经常往堆/二分去想，往双指针去想反而死活磕不出来
总之思路打开
*/
class Solution {
public:
    int check(vector<vector<int>>& matrix,int val,int k,int n){
        int i = n - 1,j = 0,tot = 0;
        /*
        1  5  9
        10 11 13
        12 13 15
        */
        while( i >= 0 && j < n){
            while(j + 1 < n && matrix[i][j + 1] <= val){
                j++;
            }
            //cout<<"[i,j]= "<<i<<" "<<j<<'\n';
            //cout<<val<<" "<<tot<<'\n';
            if(matrix[i][j] <= val) tot += j + 1;
            i--;
        }
        return tot >= k;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0],r = matrix[n - 1][n - 1];
        int ans = -1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(check(matrix,mid,k,n)){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};
