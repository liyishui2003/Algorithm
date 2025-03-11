//二分+哈希，哈希的部分可以用字符串编码算法优化，最优解应该是sam
const int N = 3e4+5;
typedef unsigned long long ull;
int n;
ull p[N],h[N];
ull get(int l,int r){
    return h[r]-h[l-1]*p[r-l+1];
}
bool check(int x){
    map<ull,int>mp;
    mp.clear();
    for(int i=x;i<=n;i++){
        ull hash = get(i-x+1,i);
        if(mp.find(hash)!=mp.end())  return true;
        else mp[hash]=1;
    }
    return false;
}
class Solution {
public:
    string longestDupSubstring(string s) {
        n = s.length();
        s=" "+s;
        p[0]=1;
        for(int i=1;i<=n;i++){
            p[i]=p[i-1]*97;
            h[i]=h[i-1]*97+s[i]-'a';
        }
        int l=1,r=n-1,ans=-1;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        if(ans==-1) return "";
        map<ull,int>mp;
        for(int i=ans;i<=n;i++){
            ull hash = get(i-ans+1,i);
            if(mp.find(hash)!=mp.end()) {
                string ret="";
                for(int j=i-ans+1;j<=i;j++){
                    ret=ret+s[j];
                }
                return ret;
            }
            else mp[hash]=1;
        }
        return "";
    }
};
