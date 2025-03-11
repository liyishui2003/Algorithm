const int N = 1e4+5;
struct seg{
    int l,r;
}f[N];
bool cmp(seg a,seg b){
    if(a.l!=b.l) return a.l<b.l;
    else return a.r<b.r;
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for(int i=0,cnt=1;i<n;i++,cnt++){
            f[cnt]=(seg){intervals[i][0],intervals[i][1]};
        }

        sort(f+1,f+n+1,cmp);
        vector<vector<int>>ret;
        int L=f[1].l,R=f[1].r;
        for(int i=2;i<=n;i++){
            if(f[i].l>R) {
                vector<int>add;
                add.push_back(L);
                add.push_back(R);
                ret.push_back(add);
                L=f[i].l,R=f[i].r;
            }
            else {
                R=max(R,f[i].r);
            }
        }
        vector<int>add;
        add.push_back(L);
        add.push_back(R);
        ret.push_back(add);
        return ret;
    }
};
