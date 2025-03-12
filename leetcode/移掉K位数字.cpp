/*
单调栈,注意判断：
①强制删k个，如果删不够要不断移除单调栈的top()
②n==k的情况特判
③可能有前导0
*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int n = num.length(),cnt = 0,pos = -1;
        if( n == k ) return "0";
        stack<int>s;
        s.push(0);
        for(int i = 1;i < n;i++){
            while(!s.empty() && num[i] < num[s.top()]){
                s.pop();
                cnt++;
                if(cnt == k) break;
            }
            s.push(i);
            pos = i;
            if(cnt == k) break;
        }
        string ret = "";
        for(int i = pos + 1;i < n;i++){
            s.push(i);
        }
        while(cnt < k){
            s.pop();
            cnt++;
        }
        while(!s.empty()){
            ret.push_back(num[s.top()]);
            s.pop();
        }
        reverse(ret.begin(),ret.end());
        pos = -1;
        for(auto v:ret){
            pos++;
            if(v != '0') break;
        }
        return ret.substr(pos);
    }
};
