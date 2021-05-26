/*
    Company Tags  :  Paytm, VMWare, Flipkart, Amazon, Microsoft, Snapdeal, FactSet
    Leetcode Link : https://leetcode.com/problems/min-stack/
    If interviews asks you to add popMin(), then you'll have to use a different technique for O(1) implementation
    See, Max Stack for this.
*/

typedef long long ll;
class MinStack {
public:

    stack<pair<ll, ll>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push({val, val});
        } else {
            ll temp = min((ll)val, st.top().second);
            st.push({val, temp});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
