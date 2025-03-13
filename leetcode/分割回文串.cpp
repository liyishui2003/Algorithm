/*
搜索完判断方案是否合法时，可以再用记忆化搜索/动态规划来预处理s[l,r]是否为回文串。  
*/
class Solution {
public:
    int use[20];
    vector<vector<string>>ans;
    bool check(string& s){
        int n = s.length();
        for(int i = 0;i < n/2;i++){
            if(s[i] != s[n-i-1]) return false;
        }
        return true;
    }
    void dfs(int u,int n,string& s){
        if(u == n-1){
            use[u] = 1;
            vector<string> add;
            string tmp = "";
            for(int i = 0;i < n;i++){
                tmp = tmp + s[i];
                if(use[i] == 1){
                    if(check(tmp)){
                        add.push_back(tmp);
                        tmp="";
                    }
                    else return ;
                }
            }
            ans.push_back(add);
            return;
        }
        use[u] = 1;
        dfs(u+1,n,s);
        use[u] = 0;
        dfs(u+1,n,s);
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        dfs(0,n,s);
        return ans;
    }
};
