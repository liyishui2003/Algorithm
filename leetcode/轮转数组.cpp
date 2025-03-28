//成环的个数是gcd(n,k)挺有意思的，要去猜每一轮遍历的元素个数是lcm(n,k)/k
class Solution {
public:
    void move(vector<int>& nums,int k,int at){
        int pre = nums[at],go,val,flag = at,cnt = 0;
        while(1){
            val = pre;
            go = (at+k)%nums.size();
            pre = nums[go];
            nums[go] = val;
            at = go;
            //cout<<at<<" "<<flag<<'\n';
            if(at == flag) {
                break;
            }
        }
    }
    void rotate(vector<int>& nums, int k) {
        /*
        0 -> 3 -> 6
        1 -> 4 -> 0
        2 -> 5 -> 1
        */
        int step = k;
        k %= nums.size();
        k = gcd(k,nums.size());
        for(int i = 0;i < k;i++){
            move(nums,step,i);
        }
    }
};
