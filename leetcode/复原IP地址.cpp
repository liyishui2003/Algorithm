class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.length();
        vector<string>ret;
        for(int i = 0;i < n;i++)
            for(int j = i + 1;j < n;j++)
                for(int k = j + 1;k + 1 < n;k++){
                        short len[4];
                        len[0] = i + 1,len[1] = j - i,len[2] = k - j,len[3] = n - 1 - k;
                        
                        bool flag = true;
                        
                        for(int _ = 0;_ <= 3;_++){
                            if(len[_] > 3)
                                flag = false;
                        }
                        if(!flag) continue;

                        string S[4];
                        S[0] = s.substr(0,len[0]);
                        S[1] = s.substr(i+1,len[1]);
                        S[2] = s.substr(j+1,len[2]);
                        S[3] = s.substr(k+1,len[3]);

                        for(int _ = 0;_ <= 3;_++){
                            int x = stoi(S[_]);
                            if(x > 255 || x < 0)
                                flag = false;
                        }

                        if(!flag) continue;
                        if(s[0] == '0' && len[0] > 1 ) flag = false;
                        if(s[i+1] == '0' && len[1] > 1) flag = false;
                        if(s[j+1] == '0' && len[2] > 1) flag = false;
                        if(s[k+1] == '0' && len[3] > 1) flag = false;

                        if(flag) {
                            string add = "";
                            add = S[0]+"."+S[1]+"."+S[2]+"."+S[3];
                            ret.push_back(add);
                        }
                    }
        return ret;
    }
};
