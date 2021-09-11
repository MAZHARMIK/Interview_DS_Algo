/*
    Company Tags  : LinkedIn
    Frequency     : 12%
    Leetcode Link : https://leetcode.com/problems/max-stack/
    We can solve Min Stack in a similar way IF min stack requires PopMin()
    
    Since this is a Premimum qn, please find the Description below :
    
    Description :
    Design a max stack that supports push, pop, top, peekMax and popMax.

    push(x) -- Push element x onto stack.
    pop() -- Remove the element on top of the stack and return it.
    top() -- Get the element on the top.
    peekMax() -- Retrieve the maximum element in the stack.
    popMax() -- Retrieve the maximum element in the stack, and remove it. If you find more than one maximum elements, only remove the top-most one.
    
    Note:
    1) -1e7 <= x <= 1e7
    2) Number of operations won't exceed 10000.
    3) The last four operations won't be called when stack is empty.

*/

#include <list> //include this if compiler shows error like this :" list does not name a type "
class MaxStack {
public:
    list<int> dl; //We use doubly linked list for stack
    map<int, vector<list<int>::iterator>> mp; //direct access of max element
    /*
        Why ordered map ?
        Access of maximum element can be done in constant time (rbegin(mp)->first)
    */
    MaxStack() {
        dl.clear();
        mp.clear();
    }

    void push(int number) {
        dl.push_back(number);
        mp[number].push_back(--end(dl));
    }

    int pop() {
        int val = top();
        dl.pop_back();
        mp[val].pop_back();
        if(mp[val].empty()) {
            mp.erase(val);
        }
        return val;
    }

    int top() {
        return *(rbegin(dl));
    }
    
    int peekMax() {
        return rbegin(mp)->first;
    }
    
    int popMax() {
        int val = peekMax();
        auto it = mp[val].back();
        dl.erase(it); //you need to remove it from stack as well
        mp[val].pop_back();
        if(mp[val].empty()) {
            mp.erase(val);
        }
        return val;
    }
};
