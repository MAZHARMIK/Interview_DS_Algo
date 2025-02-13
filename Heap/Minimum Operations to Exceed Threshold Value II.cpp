/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update later
    Leetcode Link               : https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii
*/

/************************************************************ C++ ************************************************************/
//Approach (Using Heap)
//T.C : Onlogn)
//S.C : O(n)
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> pq(begin(nums), end(nums)); //Heapify - log(n)

        int count = 0;

        while(!pq.empty() && pq.top() < k) {
            long smallest = pq.top(); //minimum
            pq.pop();

            long secondSmallest = pq.top(); //max
            pq.pop();

            pq.push(smallest*2 + secondSmallest);

            count++;
        }

        return count;

    }
};



/************************************************************ JAVA ************************************************************/
//Approach (Using Heap)
//T.C : Onlogn)
//S.C : O(n)
class Solution {
    public int minOperations(int[] nums, int k) {
        PriorityQueue<Long> pq = new PriorityQueue<>();
        
        // Add all elements to the priority queue
        for (int num : nums) {
            pq.add((long) num);
        }

        int count = 0;

        while (!pq.isEmpty() && pq.peek() < k) {
            long smallest = pq.poll();
            
            long secondSmallest = pq.poll(); 

            pq.add(smallest * 2 + secondSmallest); // Push the new value back to the heap
            count++;
        }

        return count;
    }
}
