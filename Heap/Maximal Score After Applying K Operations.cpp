/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/maximal-score-after-applying-k-operations
*/

/************************************************************ C++ ************************************************************/
//Approach (standard heap approach)
//T.C : O(n + klogn)
//S.C : O(k)
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long sum = 0;

        priority_queue<int> pq(begin(nums), end(nums)); //First time creation of heap "heapify" is O(n)
        //Refer - https://stackoverflow.com/questions/9755721/how-can-building-a-heap-be-on-time-complexity
        //Or you can refer NPTEL video on Heap on youtube. 

        while(k--) {
            int maxEl = pq.top();
            pq.pop();

            sum += maxEl;
            maxEl = ceil(maxEl/3.0);
            pq.push(maxEl);
        }

        return sum;
    }
};


/************************************************************ JAVA ************************************************************/
//Approach (standard heap approach)
//T.C : O(nlogn + klogn)
//S.C : O(k)
import java.util.PriorityQueue;
import java.util.Collections;

class Solution {
    public long maxKelements(int[] nums, int k) {
        long sum = 0;
        
        // Use a max-heap (priority queue with reverse order)
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder()); //Java DOESN't provide heapify in O(n)
        for (int num : nums) {
            pq.add(num);
        }

        while (k-- > 0) {
            int maxEl = pq.poll();
            sum += maxEl;

            // Add back the updated element
            maxEl = (int) Math.ceil(maxEl / 3.0);
            pq.add(maxEl);
        }

        return sum;
    }
}
