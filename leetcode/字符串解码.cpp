class Solution {
public:
    string decodeString(string s) {
        string ret = "";
        int n = s.length();
        int num = 0;
        for(int i = 0;i < n;){
            if(s[i] <= 'z' && s[i] >= 'a'){
                ret.push_back(s[i]);
                i++;
            }
            else {
                if(s[i] == '['){
                    int j = i + 1,cnt = 1;
                    while(1){
                        if(s[j] == '['){
                            cnt++;
                        }
                        else if(s[j] == ']'){
                            cnt--;
                        }
                        if(cnt == 0){
                            break;   
                        }
                        j++;
                    }
                    for(int _ = 1;_ <= num;_++){
                        ret = ret + decodeString(s.substr(i + 1,j - 1 - (i + 1) + 1));
                    }
                    i = j + 1;
                    num = 0;
                }
                else num = num * 10 + s[i]-'0',i++;
            }
        }
        return ret;
    }
};
