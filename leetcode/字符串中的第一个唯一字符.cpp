/*
哈希表有计算hashcode和解决碰撞的开销，所以数据范围小时用数组会更好
*/

class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        int last[26];
        memset(last,-1,sizeof last);
        for(int i = n - 1;i >= 0;i--){
            if(last[s[i] - 'a'] == -1){
                last[s[i] - 'a'] = 1;
            }
            else last[s[i] - 'a']++;
        }
        for(int i = 0 ;i < n;i++){
            if(1 == last[s[i] - 'a']) return i;
        }
        return -1;
    }
};
