//异位词的本质有两种：1.排完序一样 2，字符出现次数一样，从这两个角度去哈希即可。
class Solution {
public:
    unordered_map<string,int>mp;
    int getId(vector<int> a){
        string tmp = "";
        for(int i = 0;i < 26;i++){
            tmp = tmp + to_string(a[i]);
            tmp = tmp + "#";
        }
        if(mp.find(tmp) == mp.end()){
            int sz = mp.size();
            mp[tmp] = sz+1;
        }
        return mp[tmp];
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<int>belong[10005];
        int id = 0;
        for(auto v:strs){
            int l = v.length();
            vector<int>cnt(26);
            for(int i = 0;i < l;i++){
                cnt[v[i]-'a']++;
            }
            belong[getId(cnt)].push_back(id);
            id++;
        }
        vector<vector<string>>ret;
        for(int i = 1;i <= mp.size();i++){

            vector<string>tmp;
            for(auto v:belong[i]){
                tmp.push_back(strs[v]);
            }
            ret.push_back(tmp);
        }        
        return ret;
    }
};
