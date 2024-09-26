//Leetcode Description Link: https://leetcode.com/problems/min-stack/?envType=problem-list-v2&envId=stack
//Time to solve: ~30 minutes
//Runtime: 23ms
//Time Complexity: O(1)

// **************************************************************************************

//Approach: Treat it like a linked list.

struct Node{ // create a node struct to hold input values.
public:
    int num; // node val
    Node* prev; // since stack, always previou values and never next values.
    Node(int x){ // initialize.
        num = x;
        prev = nullptr;
    }
};

class MinStack { // actual stack structure.

private: // keep track of top and min.
    Node* min;
    Node* topNode;

public:
    MinStack() { // create stack.
        min = nullptr;
        topNode = nullptr;

    }

    void push(int val) { // add val to stack.
        Node* newNode = new Node(val); // dynamically allocate mem.
        newNode->prev = topNode; // if top == nullptr, it still works. Set prev before changing top.
        topNode = newNode;

        if (min == nullptr || val <= min->num){ // set new min.
            Node* newMin = new Node(val); // separate linked list to track all mins.
            newMin->prev = min;
            min = newMin;
        }


    }

    void pop() {

        if (topNode->num == min->num){ // if min is popped, go to prev min in min stack.
            Node* tempMin = min;
            min = min->prev;
            delete tempMin;
        }

        Node* tempTop = topNode; // else go to normal stack.
        topNode = topNode->prev;
        delete tempTop;

    }

    int top() {
        return topNode->num; // return top.
    }

    int getMin() {
        return min->num; // return min.
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
