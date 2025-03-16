/*
要求维护栈以及栈内最小元素
多开一个单调栈维护最小元素
最大同理
*/
class MinStack {
public:
    vector<int>mainSta,helpSta;
    MinStack() {
        mainSta.clear();
        helpSta.clear();
    }
    
    void push(int val) {
        mainSta.push_back(val);
        if(!helpSta.size()){
             helpSta.push_back(val);
        }
        else if(helpSta[helpSta.size()-1]>=val) 
            helpSta.push_back(val);
    }
    
    void pop() {
        int val=mainSta.back();
        mainSta.pop_back();
        if(helpSta.size()){
            if(helpSta[helpSta.size()-1]==val) 
                helpSta.pop_back();   
        }
    }
    
    int top() {
        return mainSta.back();
    }
    
    int getMin() {
        return helpSta.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
