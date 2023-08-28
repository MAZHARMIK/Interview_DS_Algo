/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=LaBE0gNYCaM
    Company Tags                : Bloomberg
    Leetcode Link               : https://leetcode.com/problems/implement-stack-using-queues/
*/

//Approach-1 (Using 2 queues with O(n) pop)
class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());    q1.pop();
        }
        swap(q1, q2);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int result = top();
        q1.pop();
        return result;
    }
    
    /** Get the top element. */
    int top() {
        return q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
};

//Approach-2 (Using single queue with O(n) push)
class MyStack {
public:
    queue<int> que;
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
        for(int i = 0; i<que.size()-1; i++) {
            que.push(que.front());
            que.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = que.front();
        que.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return que.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }
};


//Approach-3 (Using dequeq)
class MyStack {
public:
    deque<int> deq;
    /** Initialize your data structure here. */
    MyStack() {
        deq.clear();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        return deq.push_back(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top = deq.back();
        deq.pop_back();
        return top;
    }
    
    /** Get the top element. */
    int top() {
        return deq.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return deq.empty();
    }
};
