//要求复杂度优于nlog(n)，只要求前k个，这类问题通常考虑堆来维护前k个
//时间复杂度优化成nlog(k)
/*
另一个知识点是:
①
static bool cmp(Type m,Type n){
    //自定义排序
}
priority_queue<Type,vector<Type>,decltype(&cmp)> q(cmp);
②
emplce优于push，可以的话多写emplace
*/
typedef pair<int,int> PII;
class Solution {
public:
    static bool cmp(PII m,PII n){
        return m.second>n.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>cnt;
        for(auto v:nums){
            cnt[v]++;
        }

        priority_queue<PII,vector<PII>,decltype(&cmp)> q(cmp);
        for(auto v:cnt){
            if(q.size()==k){
                if(q.top().second<v.second){
                    q.pop();
                    q.push(make_pair(v.first,v.second));
                }
            }
            else q.push(make_pair(v.first,v.second));
        }
        vector<int>ret;
        while(!q.empty()){
            ret.emplace_back(q.top().first);
            q.pop();
        }
        return ret;
    }
};
