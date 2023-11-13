/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=uDbr-6svYKw
      Company Tags                : Uber
      Leetcode Link               : https://leetcode.com/problems/bus-routes/
*/


/******************************************* C++ *******************************************************/
//Approach- (Using BFS)
//T.C : O(m^2 * k) - m is the size of routes, and k is the maximum size of routes[i].
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }

        unordered_map<int, vector<int>> adj;
        
        for (int route = 0; route < routes.size(); route++) {
            for (auto stop : routes[route]) {
                adj[stop].push_back(route);
            }
        }

        queue<int> que;
        vector<bool> visited(501, false);
        
        for (auto route : adj[source]){
            que.push(route);
            visited[route] = true;
        }

        int busCount = 1;
        while (!que.empty()) {
            int size = que.size();

            while(size--) {
                int route = que.front();
                que.pop();

                
                for (auto &stop: routes[route]) {
                    
                    if (stop == target) {
                        return busCount;
                    }

                    
                    for (auto nextRoute : adj[stop]) {
                        if (!visited[nextRoute]) {
                            visited[nextRoute] = true;
                            que.push(nextRoute);
                        }
                    }
                }
            }
            busCount++;
        }
        return -1;
    }
};


/******************************************* JAVA *******************************************************/
//T.C : O(m^2 * k) - m is the size of routes, and k is the maximum size of routes[i].
//Approach- (Using BFS)
class Solution {
    public int numBusesToDestination(int[][] routes, int source, int target) {
        if (source == target) {
            return 0;
        }

        Map<Integer, List<Integer>> adj = new HashMap<>();
        // Create a map from the bus stop to all the routes that include this stop.
        for (int route = 0; route < routes.length; route++) {
            for (int stop : routes[route]) {
                // Add all the routes that have this stop.
                adj.computeIfAbsent(stop, k -> new ArrayList<>()).add(route);
            }
        }

        Queue<Integer> q = new LinkedList<>();
        boolean[] visited = new boolean[501];
        // Insert all the routes in the queue that have the source stop.
        for (int route : adj.getOrDefault(source, Collections.emptyList())) {
            q.add(route);
            visited[route] = true;
        }

        int busCount = 1;
        while (!q.isEmpty()) {
            int size = q.size();

            while (size-- > 0) {
                int route = q.poll();

                // Iterate over the stops in the current route.
                for (int stop : routes[route]) {
                    // Return the current count if the target is found.
                    if (stop == target) {
                        return busCount;
                    }

                    // Iterate over the next possible routes from the current stop.
                    for (int nextRoute : adj.getOrDefault(stop, Collections.emptyList())) {
                        if (!visited[nextRoute]) {
                            visited[nextRoute] = true;
                            q.add(nextRoute);
                        }
                    }
                }
            }
            busCount++;
        }
        return -1;
    }
}
