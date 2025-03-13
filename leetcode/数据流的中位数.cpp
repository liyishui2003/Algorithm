/*
涉及到中位数的一般考虑堆或者二分
*/
class MedianFinder {
private:
    
public:
//q1维护<=中位数的数，按从大到小排序
    priority_queue<int,vector<int>,less<int>>q1;
//q2维护>中位数的数，按从大到小排序
    priority_queue<int,vector<int>,greater<int>>q2;
    int tot = 0;
    MedianFinder() {   
    }
    void addNum(int num) {
        tot++;
        if(tot == 1){
            q1.push(num);
        }
        else {
            if(num<=q1.top()){
                q1.push(num);
            }
            else q2.push(num);
        }

        if(tot%2 == 0){
            while(q1.size() != q2.size()){
                if(q1.size() > q2.size()){
                    int u = q1.top();
                    q1.pop();
                    q2.push(u);
                }
                else {
                    int u = q2.top();
                    q2.pop();
                    q1.push(u);
                }
            }
        }
        else {
            while(q1.size()-1 != q2.size()){
                if(q1.size()-1 > q2.size()){
                    int u = q1.top();
                    q1.pop();
                    q2.push(u);
                }
                else {
                    int u = q2.top();
                    q2.pop();
                    q1.push(u);
                }
            }
        }
    }
    
    double findMedian() {
        if(tot %2 == 0){
            return (q1.top()+q2.top())/2.0;
        }
        else return q1.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
