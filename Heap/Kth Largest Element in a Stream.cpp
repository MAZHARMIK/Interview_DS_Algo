/*     Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=3Bge5OCcXUk
    Company Tags                : Amazon
    Leetcode Qn Link            : https://leetcode.com/problems/kth-largest-element-in-a-stream/
*/


/*************************************************************** C++ ***************************************************************/
//Approach - (Using min-heap)
//T.C : O(n*logK)
//S.C : O(K)
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int &x : nums) {
            pq.push(x);
            
            if(pq.size() > k)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        
        if(pq.size() > K)
            pq.pop();
        
        return pq.top();
    }
};



/*************************************************************** JAVA ***************************************************************/
//Approach - (Using min-heap)
//T.C : O(n*logK)
//S.C : O(K)
class KthLargest {
    private PriorityQueue<Integer> pq;
    private int K;

    public KthLargest(int k, int[] nums) {
        K = k;
        pq = new PriorityQueue<>(K);

        for (int num : nums) {
            pq.offer(num);
            if (pq.size() > K) {
                pq.poll();
            }
        }
    }

    public int add(int val) {
        pq.offer(val);
        if (pq.size() > K) {
            pq.poll();
        }
        return pq.peek();
    }
}
