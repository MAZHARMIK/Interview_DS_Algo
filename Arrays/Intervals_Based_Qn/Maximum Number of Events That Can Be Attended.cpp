/*         Scroll below to see JAVA code as well        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=7xa6JIuxAOo
    Company Tags                : Amazon, Google, Nutanix
    Leetcode Qn Link            : https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended
*/


/************************************************************************ C++ ************************************************************/
//Approach (Using Sorting and heap and greedily picking the ones ending earliest)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();

        sort(begin(events), end(events));

        priority_queue<int, vector<int>, greater<int>> pq; //min-heap
        int day = events[0][0]; //5
        int i   = 0;
        int count = 0; //result number of events attended

        while(!pq.empty() || i < n) {
            
            if(pq.empty()) {
                day = events[i][0];
            }

            while(i < n && events[i][0] == day) {
                pq.push(events[i][1]);
                i++;
            }

            if(!pq.empty()) {
                pq.pop(); //1 event attended on this day
                count++; //counting the result
            }

            day++;

            //skip those events whose endDay < day
            while(!pq.empty() && pq.top() < day) {
                pq.pop();
            }
        }

        return count;
    }
};



/************************************************************************ JAVA ************************************************************/
//Approach (Using Sorting and heap and greedily picking the ones ending earliest)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
    public int maxEvents(int[][] events) {
        int n = events.length;
        
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
        Arrays.sort(events, (a, b) -> Integer.compare(a[0], b[0]));
        int day = events[0][0];
        int i = 0;
        int count = 0; // Result number of events attended

        while(!pq.isEmpty() || i < n) {

            if(pq.isEmpty()) {
                day = events[i][0];
            }

            // Add all events that start on `day` to the min-heap
            while(i < n && events[i][0] == day) {
                pq.add(events[i][1]);
                i++;
            }

            if(!pq.isEmpty()) {
                pq.poll(); // Attend an event on this day
                count++; // Counting the result
            }

            day++;

            // Skip events whose end day is less than the current day
            while(!pq.isEmpty() && pq.peek() < day) {
                pq.poll();
            }
        }

        return count;
    }
}
