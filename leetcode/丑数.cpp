class Solution {
public:
    void div(int& n,int fac){
        while(n % fac == 0){
            n/=fac;
        }
    }
    bool isUgly(int n) {
        if(n <= 0) return false;
        div(n,2);
        div(n,3);
        div(n,5);
        return n == 1;
    }
};
