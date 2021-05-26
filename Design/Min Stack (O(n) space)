/*
    Company Tags  :  Paytm, VMWare, Flipkart, Amazon, Microsoft, Snapdeal, FactSet
    Leetcode Link : https://leetcode.com/problems/min-stack/
    If interviews asks you to add popMin(), then you'll have to use a different technique for O(1) implementation
    See, Max Stack for this.
*/

class MinStack {
public:
    stack<int> s;
    stack<int> ss;
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if(ss.empty() || (ss.top() >= x))
            ss.push(x);
    }
    
    void pop() {
        int top = s.top();
        s.pop();
        if(top == ss.top())
            ss.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return ss.top();
    }
};
