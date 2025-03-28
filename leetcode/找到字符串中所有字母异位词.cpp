//显然满足条件的串的必要条件是长度和串p相等，直接暴力枚举会超时。滑动窗口本质上优化了"每次都截取一段字串出来"这一过程
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int lp = p.length();
        int cnt[26]={0};
        for(int i = 0;i < lp;i++){
            cnt[p[i]-'a']++;
        }
        int valid = 0,ls = s.length(),sum[26]={0};
        for(int i = 0;i < 26;i++){
            valid += (cnt[i] == 0);
        }
        int r = -1;
        vector<int>ret;
        //cout<<"valid= "<<valid<<'\n';
        for(int l = 0;l < ls;l++){
            while(r - l + 1 < lp && r + 1 <ls) {
                r++;
            //    cout<<s[r]<<" "<<s[r]-'a'<<endl;
                sum[s[r]-'a']++;
                if(sum[s[r]-'a'] == cnt[s[r]-'a']) valid++;
                if(sum[s[r]-'a'] == cnt[s[r]-'a'] + 1) valid--;
            }
            //cout<<l<<" "<<valid<<'\n';
            if(valid == 26){
                ret.push_back(l);
            }
            sum[s[l]-'a']--;
            if(sum[s[l]-'a'] == cnt[s[l]-'a']) valid++;
            if(sum[s[l]-'a'] == cnt[s[l]-'a'] - 1) valid--;
        }
        return ret;
    }
};
