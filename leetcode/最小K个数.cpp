/*
快速排序也能做
*/

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        priority_queue<int,vector<int>,less<int>>q;
        int n = arr.size();
        for(int i = 0;i < n;i++){
            if(q.size() < k) q.push(arr[i]);
            else { 
                if(!q.empty() && q.top() > arr[i]){
                    q.pop();
                    q.push(arr[i]);
                }
            }
        }
        vector<int>ret;
        while(!q.empty()) ret.push_back(q.top()),q.pop();
        return ret;
    }
};
