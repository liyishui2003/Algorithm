/*
经典双指针+滑动窗口，o(n+m)的做法是用一个变量valid维护现在合法的字符的数目，在临界区加或者减一下
*/
class Solution {
public:
    string minWindow(string s, string t) {
        int cnt[105] = {0};
        int lt = t.length(), ls = s.length();
        for(int i = 0;i < lt;i++){
            cnt[t[i] - 'A'] ++;
        }
        int need = 0;
        for(int i = 0;i < 100;i++)
            need += (cnt[i] != 0);

        int valid = 0,j = -1,ret = INT_MAX,pos = -1;
        int count[105] = {0};
        for(int i = 0;i < ls && j < ls;){
            while(valid < need && j < ls){
                j++;
                if(j == ls) break;
                count[s[j] - 'A']++;
                if(count[s[j] - 'A'] == cnt[s[j] - 'A']) valid++;
            }
            if(valid == need){
                if(j - i + 1 < ret){
                    ret = j - i + 1;
                    pos = i;
                }
            }
            count[s[i] - 'A']--;
            if(count[s[i] - 'A'] == cnt[s[i] - 'A'] - 1) valid--;
            i++; 
        }
        string S = "";
        if(ret != INT_MAX){
            for(int i = pos;i <= pos + ret - 1;i++){
                S.push_back(s[i]);
            }
            return S;
        }
        else return "";
    }
};
