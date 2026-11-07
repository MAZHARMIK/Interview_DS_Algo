/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/process-tasks-using-servers/description
*/

/*********************************************************** C++ **************************************************/
//Approach (2 Max Heaps)
//T.C : O((n+m)*logn)
//S.C : O(n)
class Solution {
public:
    typedef pair<int, int> P; //wt, idx
    typedef tuple<long, int, int> T; //finTime, wt, idx

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        //free servers (wt, idx)
        priority_queue<P, vector<P>, greater<P>> freeServers;

        ///Busy servers {fintTime, wt, idx}
        priority_queue<T, vector<T>, greater<T>> busyServers;

        for(int i = 0; i < n; i++) { //n
            freeServers.push({servers[i], i}); //log(n)
        }

        vector<int> result(m);

        for(int i = 0; i < m; i++) { //
            //Move busy servers to free servers if they are free by ith time
            //Busy Servers ---> Free Servers
            while(!busyServers.empty() && get<0>(busyServers.top()) <= i) {
                auto [finTime, wt, idx] = busyServers.top();
                busyServers.pop();
                freeServers.push({wt, idx});
            }

            //Free Servers ---> Busy Server

            if(freeServers.empty()) {
                auto [finTime, wt, idx] = busyServers.top();
                busyServers.pop();
                result[i] = idx;
                busyServers.push({finTime + tasks[i], wt, idx});
            } else { //Free Servers ---> Busy Server //(all servers move to busy for all tasks)
                auto [wt, idx] = freeServers.top();
                freeServers.pop();
                result[i] = idx;
                busyServers.push({i + tasks[i], wt, idx});
            }
        }
        //Tota m tasks * log(n) push/pop = Overall time compelxity of this entire for loop

        return result;
    }
};


/*********************************************************** C++ **************************************************/
//Approach (2 Max Heaps)
//T.C : O((n+m)*logn)
//S.C : O(n)
class Solution {
    public int[] assignTasks(int[] servers, int[] tasks) {
        int n = servers.length;
        int m = tasks.length;

        // free servers: {wt, idx}, smallest (wt, idx) first
        PriorityQueue<int[]> freeServers = new PriorityQueue<>(
            (a, b) -> a[0] != b[0] ? Integer.compare(a[0], b[0]) : Integer.compare(a[1], b[1])
        );

        // busy servers: {finTime, wt, idx}, smallest (finTime, wt, idx) first
        PriorityQueue<long[]> busyServers = new PriorityQueue<>(
            (a, b) -> {
                if (a[0] != b[0]) return Long.compare(a[0], b[0]);
                if (a[1] != b[1]) return Long.compare(a[1], b[1]);
                return Long.compare(a[2], b[2]);
            }
        );

        for (int i = 0; i < n; i++) {
            freeServers.add(new int[]{servers[i], i});
        }

        int[] result = new int[m];

        for (int i = 0; i < m; i++) {
            // Busy Servers ---> Free Servers
            while (!busyServers.isEmpty() && busyServers.peek()[0] <= i) {
                long[] cur = busyServers.poll();
                freeServers.add(new int[]{(int) cur[1], (int) cur[2]});
            }

            if (freeServers.isEmpty()) {
                // nobody free: wait for the earliest finishing server
                long[] cur = busyServers.poll();
                result[i] = (int) cur[2];
                busyServers.add(new long[]{cur[0] + tasks[i], cur[1], cur[2]});
            } else {
                // Free Servers ---> Busy Servers, starts right now at time i
                int[] cur = freeServers.poll();
                result[i] = cur[1];
                busyServers.add(new long[]{(long) i + tasks[i], cur[0], cur[1]});
            }
        }

        return result;
    }
}
