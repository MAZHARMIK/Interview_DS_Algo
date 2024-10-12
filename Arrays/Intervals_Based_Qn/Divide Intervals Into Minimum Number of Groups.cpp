/*         Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=aelafJoNaD0
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups
*/


/**************************************************** C++ ****************************************************/
//Approach (Simply sorting and using heap)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));

        priority_queue<int, vector<int>, greater<int>> pq; //stores end point of groups

        for(vector<int>& interval : intervals) {
            int start = interval[0];
            int end   = interval[1];

            if(!pq.empty() && pq.top() < start) {
                pq.pop();
            }
            pq.push(end);
        }

        return pq.size();
    }
};


//APPROACH-2 (Line Sweep Algorithm)
//Please let me know in comment section (youtube video above) if you all want to study "Line Sweep Algorithm"
//Based on the bulk of comments/support for this topis, I will make a detailed playlist on "Line Sweep Algorithm" 
//THANK YOU



/**************************************************** JAVA ****************************************************/
//Approach (Simply sorting and using heap)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
    public int minGroups(int[][] intervals) {
        // Sort intervals based on the starting times
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));

        // Priority Queue (min-heap) to store the end points of the groups
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        // Iterate through the intervals
        for (int[] interval : intervals) {
            int start = interval[0];
            int end = interval[1];

            // If the top of the queue (smallest end time) is smaller than the current start time
            // we can merge the interval into an existing group, so we pop the earliest end time
            if (!pq.isEmpty() && pq.peek() < start) {
                pq.poll();
            }

            // Add the current interval's end time to the queue (new or updated group)
            pq.offer(end);
        }

        // The size of the priority queue will give the number of groups needed
        return pq.size();
    }
}


//APPROACH-2 (Line Sweep Algorithm)
//Please let me know in comment section (youtube video above) if you all want to study "Line Sweep Algorithm"
//Based on the bulk of comments/support for this topis, I will make a detailed playlist on "Line Sweep Algorithm" 
//THANK YOU
