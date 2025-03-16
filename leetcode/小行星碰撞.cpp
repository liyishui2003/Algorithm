const int N = 1e4+5;
class Solution {
public:
    int use[N];
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> r;
        int n = asteroids.size();
        for(int i = 0;i < n;i++){
            if(asteroids[i] < 0){
                int flag = true;
                while(!r.empty() && asteroids[r.back()] < abs(asteroids[i])){
                    r.pop_back();
                }
                if(!r.empty()) {
                    if(asteroids[r.back()] == abs(asteroids[i])) {
                        r.pop_back();
                    }
                }
                else {
                    use[i] = 1;
                }
            }
            else {
                r.push_back(i);
            }
        }
        for(auto v:r){
            use[v] = 1;
        }
        vector<int> ret;
        for(int i = 0;i < n;i++){
            if(use[i] == 1){
                ret.push_back(asteroids[i]);
            }
        }    
        return ret;
    }
};
