/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=UNdKJgW-TsU
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests
*/


/*********************************************************** C++ **************************************************/
//Approach (Min Heap)
//T.C : O(klogk + n*logk + k) ~= O(nlogk)
//S.C : O(k)
class Solution {
public:
    typedef pair<int, int> P; //{finishTime, serverId}

    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available_servers;
        for(int i = 0; i < k; i++) {
            available_servers.insert(i); //k * log(k)
        }

        priority_queue<P, vector<P>, greater<P>> busyServers;

        vector<int> countRequests(k, 0);

        //Total requests = n
        //T.C = n * log(k)
        for(int i = 0; i < arrival.size(); i++) {
            int time = arrival[i];

            while(!busyServers.empty() && busyServers.top().first <= time) {
                int server = busyServers.top().second;

                busyServers.pop();

                available_servers.insert(server);
            }

            int target = i%k;

            auto it = available_servers.lower_bound(target);

            if(it == available_servers.end()) { //wrap around
                it = available_servers.begin();
            }

            if(available_servers.empty()) {
                continue; //no servers available. Drop the current request
            }

            int targetServer = *it;

            available_servers.erase(it); //because this server is going to be busy

            busyServers.push({time + load[i], targetServer});

            countRequests[targetServer]++;

        }

        int maxNumberOfRequests = *max_element(begin(countRequests), end(countRequests)); //O(k)

        vector<int> result;

        for(int i = 0; i < k; i++) {
            if(countRequests[i] == maxNumberOfRequests) {
                result.push_back(i);
            }
        }

        return result;
    }
};



/*********************************************************** JAVA **************************************************/
//Approach (Min Heap)
//T.C : O(klogk + n*logk + k) ~= O(nlogk)
//S.C : O(k)
import java.util.*;

class Solution {
    public List<Integer> busiestServers(int k, int[] arrival, int[] load) {
        TreeSet<Integer> availableServers = new TreeSet<>();
        for (int i = 0; i < k; i++) {
            availableServers.add(i); // k * log(k)
        }

        // Min-heap: {finishTime, serverId}
        PriorityQueue<int[]> busyServers = new PriorityQueue<>(
            (a, b) -> a[0] != b[0] ? Integer.compare(a[0], b[0])
                                   : Integer.compare(a[1], b[1])
        );

        int[] countRequests = new int[k];

        // Total requests = n
        // T.C = n * log(k)
        for (int i = 0; i < arrival.length; i++) {
            int time = arrival[i];

            while (!busyServers.isEmpty() && busyServers.peek()[0] <= time) {
                int server = busyServers.poll()[1];
                availableServers.add(server);
            }

            if (availableServers.isEmpty()) {
                continue; // no servers available. Drop the current request
            }

            int target = i % k;

            // smallest available server >= target
            Integer targetServer = availableServers.ceiling(target);

            if (targetServer == null) { // wrap around
                targetServer = availableServers.first();
            }

            availableServers.remove(targetServer); // this server is going to be busy

            busyServers.offer(new int[]{time + load[i], targetServer});

            countRequests[targetServer]++;
        }

        int maxNumberOfRequests = 0;
        for (int c : countRequests) {
            maxNumberOfRequests = Math.max(maxNumberOfRequests, c); // O(k)
        }

        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            if (countRequests[i] == maxNumberOfRequests) {
                result.add(i);
            }
        }

        return result;
    }
}
