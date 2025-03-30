class Solution {
public:
    //求右边第一个大于自己的数，见739每日温度
    vector<int> firstSmall(vector<int>& temperatures){
        stack<int>sta;
        vector<int>ans;
        int n = temperatures.size();
        for(int i = n - 1;i >= 0;i--){
            while(!sta.empty() &&  temperatures[sta.top()] <= temperatures[i] ){
                sta.pop();
            }
            if(sta.empty() == true)  ans.push_back(0);
            else ans.push_back(sta.top());
            sta.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>temperatures = heights;
        int n = temperatures.size();
        for(int i = 0;i < n;i++){
            temperatures[i] = -temperatures[i];
        }
        // r:右边第一个比自己小的
        vector<int>r = firstSmall(temperatures);
        reverse(temperatures.begin(),temperatures.end());
        // l:左边第一个比自己小的
        vector<int>l = firstSmall(temperatures);
        reverse(l.begin(),l.end());
        for(int i = 0 ;i < n; i++){
            if(l[i]) l[i] = n - 1 - l[i];
            else l[i] = -1;
        }
        int ret = 0;
        for(int i = 0;i < n;i++){
            int rightEdge = r[i];
            if(rightEdge == 0) rightEdge = n;
            int leftEdfe = l[i];
            ret = max(ret,heights[i] * max(1,(rightEdge - leftEdfe - 1)));
        }
        return ret;
    }
};
