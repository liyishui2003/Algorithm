//单调栈从右往左扫一遍
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>sta;
        int n = temperatures.size();
        vector<int>ans;
        for(int i = n - 1;i >= 0;i--){
            while(!sta.empty() &&  temperatures[sta.top()] <= temperatures[i] ){
                sta.pop();
            }
            if(sta.empty() == true)  ans.push_back(0);
            else ans.push_back(sta.top());
            sta.push(i);
        }
        reverse(ans.begin(),ans.end());
        for(int i = 0;i < n;i++){
            if(ans[i]) ans[i] = ans[i] - i;
        }
        return ans;
    }
};
