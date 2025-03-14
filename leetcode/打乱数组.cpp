/*
原理是Fisher-Yates 洗牌算法
算法的核心思想是从数组的末尾开始，随机选择一个位置并与当前位置交换，然后逐步向前移动。
证明：最开始每个元素被选中的概率是1/n，然后是1/(n-1)，再然后是1/(n-2)...
最后整个排列的概率就是1/n!
*/
class Solution {
public:
    vector<int>num,init;
    int n;
    Solution(vector<int>& nums) {
        num = init = nums;
        n = nums.size();
    }
    
    vector<int> reset() {
        num = init;
        return num;
    }
    
    vector<int> shuffle() {
        for (int i = n - 1; i > 0; i--) {
            // 生成一个 [0, i] 范围内的随机索引
            int j = rand() % (i + 1);
            // 交换 nums[i] 和 nums[j]
            std::swap(num[i], num[j]);
        }
        return num;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
