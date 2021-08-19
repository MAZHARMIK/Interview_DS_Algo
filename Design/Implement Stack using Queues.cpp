/*
    Company Tags  : Bloomberg
    Leetcode Link : https://leetcode.com/problems/implement-stack-using-queues/
*/

//Approach-1 (Using dequeq)
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

//Approach-2 (Using 2 queues with O(n) pop)
class MyStack {
public:
    queue<int> que;
    int topEl = -1;
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        topEl = x;
        que.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        queue<int> tempQue;
        int size       = que.size();
        int last       = -1;
        int secondLast = -1;
        while(size > 0) {
            int x = que.front();
            que.pop();
            if(size > 1)
                tempQue.push(x);
            secondLast = last;
            last = x;
            size--;
        }
        que   = tempQue;
        topEl = secondLast;
        return last;
    }
    
    /** Get the top element. */
    int top() {
        return topEl;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }
};

//Approach-3 (Using single queue with O(n) push)
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
