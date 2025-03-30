/*
很奇妙的图论题~
i->nums[i]建图后，转化成链表判环问题，用快慢指针求解。
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int slow = 0,fast = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
