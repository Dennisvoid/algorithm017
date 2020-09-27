/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> s;
    vector<int> min_s;
    int pt;
    MinStack() {
        pt = -1;
    }
    
    void push(int x) {
        pt++;
        if (pt >= s.size()) {
            s.resize(s.size() + 1);
            min_s.resize(min_s.size() + 1);
        }
        s[pt] = x;
        if (pt == 0)
            min_s[pt] = x;
        else 
            min_s[pt] = min(x,min_s[pt - 1]);
    }
    
    void pop() {
        if (pt == -1) return;
        pt--;
    }
    
    int top() {
        if (pt != -1) 
            return s[pt];
        else return INT_MIN;
    }
    
    int getMin() {
        if (pt != -1)
            return min_s[pt];
        else return INT_MIN;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

