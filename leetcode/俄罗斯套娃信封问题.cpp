const int N = 1e5+5;
struct node{
    int w,h;
}f[N];
bool cmp(node a,node b){
    if(a.w!=b.w){
        return a.w<b.w;
    }
    else return a.h>b.h;
}
int dp[N];
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size(),cnt=0,ans=0;
        for(int i=0;i<n;i++){
            cnt++;
            f[cnt]=(node){envelopes[i][0],envelopes[i][1]};//w,h
        }
        sort(f+1,f+cnt+1,cmp);
        vector<int> q;
        for(int i=1;i<=cnt;i++){

            int x = f[i].h;
            auto it = lower_bound(q.begin(), q.end(), x);
            if (it == q.end()) {
                q.push_back(x);
            } else {
                *it = x;
            }
    
        }
        return q.size();
    }
};
