class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //服了，哈希表认为是O(1)的，所以用哈希表整体扫一遍就是o(n)的
        unordered_set<int>s;
        for(auto v:nums){
            s.insert(v);
        }        
        int ret = 0;
        for(auto v:s){
            if(!s.count(v - 1)){

                int cur = v,tmp = 0;
                while(s.count(cur)){
                    cur ++;
                    tmp ++;
                }
                ret = max(ret,tmp);
            }
        }
        return ret;
    }
};
