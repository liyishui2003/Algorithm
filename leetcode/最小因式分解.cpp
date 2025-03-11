class Solution {
    int div(int& num,int x){
        int ans=0;
        while(num%x==0){
            cout<<num<<endl;
            num/=x;ans++;
        }
        return ans;
    }
public:
    int smallestFactorization(int num) {
        
        /*
        因数只能有
        2 3 5 7
        考虑2和3怎么拼接
        3个2凑8 消2个
        2个2凑4 消1个
        2个3凑9 消1个
        1个3+1个2凑6 消1个
        策略：尽量凑8，尽量凑9
        剩下的：
        0,1,2个2 和 0,1个3
        若有3，和2凑6得6，或者得26，如果不凑则43不优
        若没3，无所谓啦，2自己组合
        */
        int _2=0,_3=0,_5=0,_7=0;
        _2=div(num,2);
        _3=div(num,3);
        _5=div(num,5);
        _7=div(num,7);
        if(num!=1) return 0;
        vector<int>dig;
        for(int i=1;i<=_5;i++) dig.push_back(5);
        for(int i=1;i<=_7;i++) dig.push_back(7);
        for(int i=1;i<=_2/3;i++) dig.push_back(8);
        _2%=3;
        for(int i=1;i<=_3/2;i++) dig.push_back(9);
        _3%=2;
        if(_3){
            if(_2==0){
                dig.push_back(3);
            }
            else {
                dig.push_back(6);
                _2--;
                if(_2) dig.push_back(2);
            }
        }
        else {
            if(_2==0) {}
            else if(_2==1) dig.push_back(2);
            else dig.push_back(4);
        }
        sort(dig.begin(),dig.end());
        unsigned long long ans=0;
        for(auto v:dig){
            ans=ans*10+v;
            if(ans>=(1ll<<31)) return 0;
        }
        if(!ans) ans=1;
        return ans;
    }
};
