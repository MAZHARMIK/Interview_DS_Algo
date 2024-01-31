/*                                           Scroll Down For JAVA code also                                 */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=aDQeF8Izv5I
    Company Tags                : Jio, Amazon, Airtle, Swiggy
    GFG Link                    : https://www.geeksforgeeks.org/problems/reverse-a-stack/1
*/


/************************************************************ C++ ************************************************************/
//Approach-1 (Using O(n) Auxiliary Space (we took extra one temp stack))
//Simply write a story like recursion and trust it
//Time : O(n^2)
//Space : O(n) Auxiliary Space (we took extra one temp stack)
class Solution{
public:
    void Reverse(stack<int> &St){
        if(St.empty()) {
            return;
        }
        
        int top = St.top();
        St.pop();
        Reverse(St); //I am hoping my Reverse function will reverse the remaining stack

        //Now I need to push top at the bottom of the stack
        stack<int> temp;
        while(!St.empty()) {
            temp.push(St.top());
            St.pop();
        }
      
        St.push(top); //push at bottom
        //Now push remaining elements
        while(!temp.empty()) {
            St.push(temp.top());
            temp.pop();
        }
    }
};



//Approach-2 (Using O(1) Auxiliary Space)
//Simply write a story like recursion and trust it
//Time : O(n^2)
//Space : O(1) Auxiliary Space
class Solution{
public:

    void insertAtBottom(stack<int>& St, int element) {
        if(St.empty()) {
            St.push(element);
            return;
        }
        
        int cur_top_el = St.top();
        St.pop();
        insertAtBottom(St, element);
        St.push(cur_top_el);
    }

    void Reverse(stack<int> &St){
        if(St.empty()) {
            return;
        }
        int top = St.top();
        St.pop();
        
        Reverse(St);
        insertAtBottom(St, top);
    }
};


/************************************************************ JAVA ************************************************************/
//Approach-1 (Using O(n) Auxiliary Space (we took extra one temp stack))
//Simply write a story like recursion and trust it
//Time : O(n^2)
//Space : O(n) Auxiliary Space (we took extra one temp stack)
class Solution
{ 
    static void reverse(Stack<Integer> stack) {
        if (stack.isEmpty()) {
            return;
        }

        int top = stack.pop();
        reverse(stack); // Recursively reverse the remaining stack

        // Move the top element to the bottom of the stack
        Stack<Integer> temp = new Stack<>();
        while (!stack.isEmpty()) {
            temp.push(stack.pop());
        }

        stack.push(top); // Push the top element at the bottom

        // Push back the remaining elements
        while (!temp.isEmpty()) {
            stack.push(temp.pop());
        }
    }
}


//Approach-2 (Using O(1) Auxiliary Space)
//Simply write a story like recursion and trust it
//Time : O(n^2)
//Space : O(1) Auxiliary Space
class Solution
{   
    public static void insertAtBottom(Stack<Integer> St, int element) {
        if (St.isEmpty()) {
            St.push(element);
            return;
        }

        int curTopElement = St.pop();
        insertAtBottom(St, element);
        St.push(curTopElement);
    }
    
    static void reverse(Stack<Integer> St) {
        if (St.isEmpty()) {
            return;
        }
        
        int top = St.pop();
        reverse(St);
        insertAtBottom(St, top);
    }
}
