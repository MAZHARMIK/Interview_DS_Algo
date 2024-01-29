/*                                             SCROLL BELOW FOR JAVA CODE ALSO                                         */
/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=V1vqtGW0X0Y
      Company Tags                : Google, Amazon, Microsoft, Meta 
      Leetcode Link               : https://leetcode.com/problems/implement-queue-using-stacks/
      GfG Link                    : https://practice.geeksforgeeks.org/problems/queue-using-stack/1
*/


/************************************************************************ C++ ************************************************************************/
//T.C : push - O(1), pop - Amortized O(1) , peek() - O(1), empty() - O(1)
//S.C : O(n)
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


/************************************************************************ JAVA ************************************************************************/
//T.C : push - O(1), pop - Amortized O(1) , peek() - O(1), empty() - O(1)
//S.C : O(n)
class MyQueue {
    private Stack<Integer> input;
    private Stack<Integer> output;
    private int peekEl;

    public MyQueue() {
        input = new Stack<>();
        output = new Stack<>();
        peekEl = -1;
    }

    public void push(int x) {
        if (input.empty()) {
            peekEl = x;
        }
        input.push(x);
    }

    // Amortized O(1)
    public int pop() {
        if (output.empty()) {
            // Transfer elements from input to output (O(n))
            while (!input.empty()) {
                output.push(input.pop());
            }
        }

        int val = output.pop();
        return val;
    }

    public int peek() {
        if (output.empty()) {
            return peekEl;
        }

        return output.peek();
    }

    public boolean empty() {
        return input.empty() && output.empty();
    }
}
