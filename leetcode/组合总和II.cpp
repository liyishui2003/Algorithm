/*
搜索+剪枝
*/
class Solution {
public:
    map<int,int>cnt,add;
    vector<int>seq;
    vector<vector<int>>ret;
    void dfs(int pos,int rest){
        if(rest == 0){
            ret.push_back(seq);
            return ;
        }
        if(pos == cnt.size() || rest < cnt[pos]) return ;
        int sz = add[cnt[pos]];
        sz = min(sz,rest / cnt[pos]);
        for(int i = 0;i <= sz;i++){
            dfs(pos + 1,rest - i * cnt[pos]);
            seq.push_back(cnt[pos]);
        }
        for(int i = 0;i <= sz;i++){
            seq.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        for(auto v:candidates){
            add[v]++;
        }
        int Cnt = 0; 
        for(auto v:add){
            cnt[Cnt] = v.first;
            Cnt++;
        }
        dfs(0,target);
        return ret;

    }
};
