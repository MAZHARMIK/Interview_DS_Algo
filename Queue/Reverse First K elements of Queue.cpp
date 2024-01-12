/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=2fA9-uhVliY
    Company Tags                : Amazon
    GfG Link                    : https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1
*/

/****************************************************** C++ ******************************************************/
//Approach (Usingh stack to reverse efficiently)
//T.C : O(n)
//S.C : O(k)
class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        
        int remaining = q.size() - k; //2
        stack<int> st;
        while(k--) {
            st.push(q.front());
            q.pop();
        }
        
        while(!st.empty()) {
            q.push(st.top());
            st.pop();
        }
        
        while(remaining--) {
            q.push(q.front());
            q.pop();
        }
        
        return q;
    }
};


/****************************************************** JAVA ******************************************************/
/*
  Above C++ code if you convert it to JAVA, it's giving TLE in last test case.
  So, I tried using array and reverse it instead of using stack. It passed
*/
//Approach (Usingh stack to reverse efficiently)
//T.C : O(n)
//S.C : O(k)
import java.util.LinkedList;
import java.util.Queue;
import java.util.Vector; // Replaced ArrayList with Vector

class GfG {
    // Function to reverse first k elements of a queue.
    public Queue<Integer> modifyQueue(Queue<Integer> q, int k) {
        Vector<Integer> vec = new Vector<>();
        
        int remaining = q.size() - k;
        
        while(k > 0) {
            vec.add(q.peek());
            q.remove();
            k--;
        }
        
        Collections.reverse(vec);
        
        for(int i = 0; i < vec.size(); i++) {
            q.add(vec.get(i));
        }
        
        while(remaining > 0) {
            q.add(q.peek());
            q.remove();
            remaining--;
        }
        
        return q;
    }
}
