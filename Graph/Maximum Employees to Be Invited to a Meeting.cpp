/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting
*/


/************************************************************ C++ ************************************************/
//Approach - Using BFS and Cycle Checks
//T.C : ~O(n)
//S.C : ~O(n)
class Solution {
public:

    int BFS(int start, unordered_map<int, vector<int>>& adj, vector<bool>& visited) {
        queue<pair<int, int>> que; //{node, path length}
        que.push({start, 0});
        int maxDistance = 0;

        while(!que.empty()) {
            auto[currNode, dist] = que.front();
            que.pop();

            for(auto &ngbr : adj[currNode]) {
                if(!visited[ngbr]) {
                    visited[ngbr] = true;
                    que.push({ngbr, dist+1});
                    maxDistance = max(maxDistance, dist+1);
                }
            }
        }

        return maxDistance;
    }

    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        unordered_map<int, vector<int>> adj;

        for(int i = 0; i < n; i++) {
            int u = i;
            int v = favorite[i];
            // u --> v
            adj[v].push_back(u); //reversed graph - so that we can find the path length after traversal
        }

        int longestCycleEmplCount = 0;
        int happyCoupleEmplCount  = 0; //cycle length = 2 waalo se kitna milpaega total

        vector<bool> visited(n, false);

        for(int i = 0; i < n; i++) {

            if(!visited[i]) {
                //{node, abtak ka node count}
                unordered_map<int, int> mp;

                int currNode      = i;
                int currNodeCount = 0;

                while(!visited[currNode]) { //until cycle is not detected
                    visited[currNode] = true;
                    mp[currNode] = currNodeCount;

                    int nextNode = favorite[currNode]; //favorite node of curr node
                    currNodeCount += 1;

                    if(mp.count(nextNode)) { //already visited hai ye. Matlab cycle detect hogaya hai
                        int cycleLength = currNodeCount - mp[nextNode];
                        longestCycleEmplCount = max(longestCycleEmplCount, cycleLength);

                        if(cycleLength == 2) { //happy couple case
                            //currNode <-> nextNode = 2 nodes
                            vector<bool> visitedNodes(n, false);
                            visitedNodes[currNode] = true;
                            visitedNodes[nextNode] = true;
                            happyCoupleEmplCount += 2 + BFS(currNode, adj, visitedNodes) + BFS(nextNode, adj, visitedNodes);
                        }
                        break;
                    }
                    currNode = nextNode;
                }
            }
        }

        return max(happyCoupleEmplCount, longestCycleEmplCount);

    }
};




/************************************************************ JAVA ************************************************/
//Approach - Using BFS and Cycle Checks
//T.C : ~O(n)
//S.C : ~O(n)
class Solution {
    public int BFS(int start, Map<Integer, List<Integer>> adj, boolean[] visited) {
        Queue<int[]> queue = new LinkedList<>(); // {node, path length}
        queue.add(new int[]{start, 0});
        int maxDistance = 0;

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int currNode = current[0];
            int dist = current[1];

            for (int neighbor : adj.getOrDefault(currNode, new ArrayList<>())) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.add(new int[]{neighbor, dist + 1});
                    maxDistance = Math.max(maxDistance, dist + 1);
                }
            }
        }

        return maxDistance;
    }

    public int maximumInvitations(int[] favorite) {
        int n = favorite.length;
        Map<Integer, List<Integer>> adj = new HashMap<>();

        // Build reversed graph
        for (int i = 0; i < n; i++) {
            int u = i;
            int v = favorite[i];
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }

        int longestCycleEmplCount = 0;
        int happyCoupleEmplCount = 0;

        boolean[] visited = new boolean[n];

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                Map<Integer, Integer> mp = new HashMap<>();
                int currNode = i;
                int currNodeCount = 0;

                while (!visited[currNode]) { // Until cycle is not detected
                    visited[currNode] = true;
                    mp.put(currNode, currNodeCount);

                    int nextNode = favorite[currNode]; // Favorite node of currNode
                    currNodeCount++;

                    if (mp.containsKey(nextNode)) { // Cycle detected
                        int cycleLength = currNodeCount - mp.get(nextNode);
                        longestCycleEmplCount = Math.max(longestCycleEmplCount, cycleLength);

                        if (cycleLength == 2) { // Happy couple case
                            boolean[] visitedNodes = new boolean[n];
                            visitedNodes[currNode] = true;
                            visitedNodes[nextNode] = true;
                            happyCoupleEmplCount += 2 + BFS(currNode, adj, visitedNodes) + BFS(nextNode, adj, visitedNodes);
                        }
                        break;
                    }
                    currNode = nextNode;
                }
            }
        }

        return Math.max(happyCoupleEmplCount, longestCycleEmplCount);
    }
}
