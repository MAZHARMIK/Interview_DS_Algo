/*        Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO IN THIS QN : https://www.youtube.com/watch?v=1KYzjryTRmg
    Company Tags  : LinkedIn
    Leetcode Link : https://leetcode.com/problems/design-a-stack-with-increment-operation/
*/


/***************************************************************** C++ *****************************************************************/
//Approach (Using Array + Lazy Propagation)
//T.C : push : O(1), pop : O(1), increment : O(1)
//S.C : O(maxSize)
class CustomStack {
public:
    vector<int> st;
    vector<int> increments;
    int n;

    CustomStack(int maxSize) {
        n = maxSize;
    }
    
    void push(int x) {
        if(st.size() < n) {
            st.push_back(x);
            increments.push_back(0);
        }
    }
    
    int pop() {
        if(st.size() == 0) {
            return -1;
        }

        int idx = st.size()-1; //top element index
        
        if(idx > 0) {
            increments[idx-1] += increments[idx];
        }

        int top_val = st[idx] + increments[idx];
        st.pop_back();
        increments.pop_back();
        
        return top_val;
    }
    
    void increment(int k, int val) {
        //Note that input might contain K which is greater than st.size()
        int idx = min(k, (int)st.size()) - 1;
        if (idx >= 0) {
            increments[idx] += val;
        }
    }
};


/***************************************************************** JAVA *****************************************************************/
//Approach (Using Array + Lazy Propagation)
//T.C : push : O(1), pop : O(1), increment : O(1)
//S.C : O(maxSize)
class CustomStack {
    private List<Integer> st;         // Stack to hold the elements
    private List<Integer> increments; // To hold the increment values
    private int maxSize;              // Maximum size of the stack

    public CustomStack(int maxSize) {
        this.maxSize = maxSize;
        st = new ArrayList<>();
        increments = new ArrayList<>();
    }
    
    public void push(int x) {
        if (st.size() < maxSize) {
            st.add(x);
            increments.add(0); // Initialize increment for the new element
        }
    }
    
    public int pop() {
        if (st.size() == 0) {
            return -1; // Stack is empty
        }

        int idx = st.size() - 1; // Top element index
        
        // Carry over the increment to the previous element
        if (idx > 0) {
            increments.set(idx - 1, increments.get(idx - 1) + increments.get(idx));
        }

        int topVal = st.get(idx) + increments.get(idx); // Get the value of the top element
        st.remove(idx); // Pop the top element
        increments.remove(idx); // Remove the corresponding increment
        
        return topVal; // Return the popped value
    }
    
    public void increment(int k, int val) {
        int idx = Math.min(k, st.size()) - 1; // Get the correct index
        if (idx >= 0) {
            increments.set(idx, increments.get(idx) + val); // Increment the bottom k elements
        }
    }
}
