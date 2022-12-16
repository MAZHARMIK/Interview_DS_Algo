/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=V1vqtGW0X0Y
      Company Tags                : Google, Amazon, Microsoft, Meta 
      Leetcode Link               : https://leetcode.com/problems/implement-queue-using-stacks/
      GfG Link                    : https://practice.geeksforgeeks.org/problems/queue-using-stack/1
*/

class MyQueue {
public:
    
    stack<int> input;
    stack<int> output;
    int peekEl = -1;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        if(input.empty()) {
            peekEl = x;
        }
        input.push(x); //ye to har baar karna hai
    }
    //amortized O(1)
    int pop() {
        if(output.empty()) {
            //input -> output O(n)
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        
        int val = output.top(); //O(1)
        output.pop();
        return val;
    }
    
    int peek() {
        if(output.empty())
            return peekEl;
        
        return output.top();
    }
    
    bool empty() {
        if(input.empty() && output.empty())
            return true;
        
        return false;
    }
};
