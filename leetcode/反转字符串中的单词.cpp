/*
原地解法的关键在于先反转字符串，再双指针。
*/
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        reverse(s.begin(),s.end());
        int wri = 0,last = -1;
        for(int i = 0;i < n;i++){
            if(s[i] == ' '){
                if(last == -1) continue;
                if(wri != 0){
                    s[wri] = ' ';
                    wri++;
                }
                reverse(s.begin()+last,s.begin()+i);
                for(int j = last;j <= i-1;j++){
                    s[wri] = s[j];
                    wri++;
                }
                last = -1;
            }
            else {
                if(last == -1) {
                    last = i;
                }
                if(i == n-1){
                    if(wri != 0){
                        s[wri] = ' ';
                        wri++;
                    }
                    reverse(s.begin()+last,s.begin()+i+1);
                    for(int j = last;j <= i;j++){
                        s[wri] = s[j];
                        wri++;
                    }
                }
            }
        }
        return s.substr(0,wri);
    }
};
