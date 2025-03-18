const int N = 1e4+5;
int a[N],b[N],c[N];
class Solution {
public:
    string addStrings(string num1, string num2) {
        int l1 = num1.length(),l2 = num2.length();
        int tot = 0,L = max(l1,l2);
        for(int i = 0;i < L;i++){
            a[i] = b[i] = 0;
        }
        for(int i = 0;i < l1;i++){
            a[l1 - i - 1] = num1[i] - '0'; 
        }
        for(int i = 0;i < l2;i++){
            b[l2 - i - 1] = num2[i] - '0';
        }        
        for(int i = 0;i < L;i++){
            int sum = a[i] + b[i] + tot;
            c[i] = sum % 10;
            tot = sum / 10;
        }
        if(tot) {
            c[L] = 1;
            L++;
        }
        string ret = "";
        for(int i = L - 1;i >= 0 ;i--){
            ret.push_back(char((int)c[i] + '0'));
        }
        return ret;
    }
    /*
    654
    77
    ===
    335
    */
};
