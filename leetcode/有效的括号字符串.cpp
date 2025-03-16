/*
开一个变量表示未匹配的左括号数量(根据这个定义，前提是非负)的区间[l,r]
如果是(或者)显然区间整体都要变化一格
但*的存在使得区间可以往左往右扩展，因为我可以自由选择匹配或者不匹配
*/
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length(),cntl = 0;
        int l = 0,r = 0;    
        for(int i = 0;i < n;i++){
            if(s[i] == '('){
                l++,r++;
            }
            else if(s[i] == ')'){
                l = max(l - 1,0),r--;
            }
            else {
                l = max(l - 1,0),r++;
            }
            if( r < 0) return false;
        }
        return l == 0;
    }
};
