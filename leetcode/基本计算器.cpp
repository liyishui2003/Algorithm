//solution1：
/*
遇到括号展开递归，其它部分纯粹大模拟
*/
class Solution {
public:
    void ws(string& s,int& i){
        while(s[i] == ' ') i++;
    }
    void update(int& pre,int& ans,int& num,string& s,int& i){
        if(pre == 1) ans += num;
        else ans -= num;
        ws(s,i);
        if(s[i] == '+') pre = 1;
        if(s[i] == '-') pre = -1;
    }
    int calculate(string s) {
        int n = s.length(),ans = 0,sum = 0,pre = 1, i;
        for(i = 0;i < n;i++){
            ws(s,i);
            if(s[i] == '('){//deal with ( )
                sum++;
                int last = i;
                i++;
                while(sum > 0){
                    ws(s,i);
                    if(s[i] == '(') sum++;
                    if(s[i] == ')') sum--;
                    i++;
                    if(sum == 0 ) break;
                }
                sum = 0;
                int num = calculate(s.substr(last + 1,i - 1 - last));
                update(pre,ans,num,s,i);
            }
            ws(s,i);
            int num = 0;
            while(s[i] <= '9' && s[i] >= '0'){
                num = num * 10 + (s[i] - '0');
                i++;
            }
            update(pre,ans,num,s,i);
        }
        return ans;   
    }
};
/*
solution2:评论区的天才做法
*/
class Solution {
public:
    int calculate(string s) {
        stack<char> st; // 存储正负号
        int ans = 0, num = 0, op = 1;
        st.push(op);

        for (char c : s) {
            if (c == ' ') continue;
            else if (c >= '0') num = num * 10 - '0' + c;
            else {
                ans += op * num;
                num = 0;

                if (c == '+') op = st.top();
                else if (c == '-') op = -st.top();
                else if (c == '(') st.push(op); // 将括号前符号放入栈顶
                else st.pop();
            }
        }

        return ans + op * num;
    }
};
