class Solution {
public:
    void ws(string& s,int& i){
        while(s[i] == ' ') i++;
    }
    int calculate(string s) {
        int n = s.length();
        stack<int>sta;
        int num = 0,last = 2,i = 0;
        ws(s,i);
        if(s[i] == '-') last = 3,i++;
        for(;i < n;){
            ws(s,i);//数字前可能有空格
            while(s[i] <= '9' && s[i] >= '0'){
                num = num * 10 + (s[i] - '0');
                i++;
            }
            ws(s,i);//数字后可能有空格
            if(last == 2){
                sta.push(num);
            }
            else if(last == 3){
                sta.push(-num);
            }
            else if(last == 0){
                int u = sta.top();
                sta.pop();
                sta.push(u * num);
            }
            else if(last == 1){
                int u = sta.top();
                sta.pop();
                sta.push(u / num);
            }
            //处理完数字和空格，接下来碰到的必定是运算符，存下来等处理完下一个数字再用
            if(s[i] == '*') last = 0;
            if(s[i] == '/') last = 1;
            if(s[i] == '+') last = 2;
            if(s[i] == '-') last = 3;
            i++;
            num = 0;
        }
        int tot = 0;
        while(!sta.empty()){
            tot += sta.top();
            sta.pop();
        }
        return tot;
    }
};
