//经典bfs求连通块，没懂为什么我的时空不是最优的
const int dx[5]={0,0,-1,1};
const int dy[5]={-1,1,0,0};
class Solution {
public:
    int vis[305][305];
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(),m  =grid[0].size();
        int ans = 0;
        memset(vis,0,sizeof vis);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    ans++;
                    queue<pair<int,int>>q;
                    q.push(make_pair(i,j));
                    while(!q.empty()){
                        auto u = q.front();
                        q.pop();
                        for(int i = 0;i < 4;i++){
                            int tx = u.first + dx[i],ty = u.second + dy[i];
                            if(tx <0 || tx >= n || ty < 0 || ty >= m) continue;
                            if(grid[tx][ty] == '0' ||vis[tx][ty]) continue;
                            vis[tx][ty] = 1;
                            q.push(make_pair(tx,ty));
                        }
                    }
                }
            }
        }
        return ans;
    }
};
