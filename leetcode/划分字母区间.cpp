/*
跳跃游戏的拼接版
*/
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        int last[26];
        for(int i = 0;i < 26;i++) last[i] = n;
        for(int i = n - 1;i >= 0;i--){
            int a = s[i] - 'a';
            if(last[a] == n) last[a] = i;
        }
        vector<int>ret;
        int Last = 0,end = 0,to = 0;
        for(int i = 0;i < n;i++){
            if(i <= to){
                to = max(to,last[s[i] - 'a']);
            }
            else {
                ret.push_back(i - Last);
                Last = i;
                to = last[s[i] - 'a'];
            }
        }
        ret.push_back(n - Last);
        return ret;
    }
};
