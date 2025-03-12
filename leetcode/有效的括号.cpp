//和常规括号匹配一样，注意判断栈为空的情况
class Solution {
public:
    bool isValid(string s) {
        stack<char>sta;
        int n = s.length();
        for(int i = 0;i < n;i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                sta.push(s[i]);
            }    
            else {
                if(s[i] == ')'){
                    if(sta.empty() || sta.top() != '(') return false;
                    sta.pop();
                }
                else if(s[i] == '}'){
                    if(sta.empty() || sta.top() != '{') return false;
                    sta.pop();
                }
                else if(s[i] == ']'){
                    if(sta.empty() || sta.top() != '[') return false;
                    sta.pop();
                }
            }
        }
        return sta.empty() == true;
    }
};
