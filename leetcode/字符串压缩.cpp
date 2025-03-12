class Solution {
    void update(string& ret,int& num,char& c){
        ret.push_back(c);
        char tmp[5];
        snprintf(tmp,sizeof(tmp),"%d",num);
        int len = strlen(tmp);
        for(int j = 0;j < len;j++){
            ret.push_back(tmp[j]);
        }
    }
public:
    string compressString(string S) {
        int n =S.length();
        string ret = "";
        int cur = 1,num = 1;
        char c = S[0];
        for(;cur < n;cur++){
            if(S[cur]!=c) //end
            {
                update(ret,num,c);
                num = 1;
                c = S[cur];
            }
            else num++;
        }
        update(ret,num,c);
        int newLen = ret.length();
        if(newLen < n)  return ret;
        else return S;
    }
};
