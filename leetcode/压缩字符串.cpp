//要求不使用额外空间，双指针原地压缩就好了，显然写指针永远跟不上读指针
class Solution {
public:
    void update(vector<char>& chars,int& num,int& wri,char& c){
        chars[wri]=c;
        if(num != 1){
            char tmp[5];
            snprintf(tmp,sizeof(tmp),"%d",num);
            int len = strlen(tmp);
            for(int j = 0;j < len;j++){
                wri++;
                chars[wri]=tmp[j];
            }
        }
    }
    int compress(vector<char>& chars) {
        int n =chars.size();
        int cur = 1,wri = 0,num = 1;
        char c = chars[0];
        for(;cur < n;cur++){
            if(chars[cur]!=c) //end
            {
                update(chars,num,wri,c);
                wri++;
                num = 1;
                c = chars[cur];
            }
            else num++;
        }
        update(chars,num,wri,c);
        wri++;
        return wri;
    }
};
