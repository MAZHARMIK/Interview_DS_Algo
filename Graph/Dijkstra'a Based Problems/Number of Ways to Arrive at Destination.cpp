/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=F_jnqx14idY
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/number-of-ways-to-arrive-at-destination
*/


/************************************************************ C++ ************************************************/
//Approach (Using Dijkstra's Algorithm)
//T.C : O(((V+E)*log(V))
//S.C : O(V+E)
class Solution {
public:
    typedef pair<long long, int> P;
    const int M = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {

        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto &road : roads) {
            int u    = road[0];
            int v    = road[1];
            int time = road[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<long long> result(n, LLONG_MAX);
        vector<int> pathCount(n, 0);

        result[0] = 0;
        pathCount[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            long long currTime = pq.top().first;
            int currNode       = pq.top().second;
            pq.pop();

            //if (currTime > result[currNode]) continue;

            for (auto &vec : adj[currNode]) {
                int adjNode  = vec.first;
                int roadTime = vec.second;

                if (currTime + roadTime < result[adjNode]) {
                    result[adjNode] = currTime + roadTime;
                    pathCount[adjNode] = pathCount[currNode];
                    pq.push({result[adjNode], adjNode});
                } else if (currTime + roadTime == result[adjNode]) {
                    pathCount[adjNode] = (pathCount[adjNode] + pathCount[currNode]) % M;
                }
            }
        }
        
        return pathCount[n - 1];
    }
};


/************************************************************ JAVA ************************************************/
//Approach (Using Dijkstra's Algorithm)
//T.C : O(((V+E)*log(V))
//S.C : O(V+E)
class Solution {
    private static final int MOD = 1_000_000_007;
    
    public int countPaths(int n, int[][] roads) {
        Map<Integer, List<int[]>> adj = new HashMap<>();
        for (int i = 0; i < n; i++) {
            adj.put(i, new ArrayList<>());
        }
        
        for (int[] road : roads) {
            int u = road[0], v = road[1], time = road[2];
            adj.get(u).add(new int[]{v, time});
            adj.get(v).add(new int[]{u, time});
        }
        
        PriorityQueue<long[]> pq = new PriorityQueue<>(Comparator.comparingLong(a -> a[0]));
        long[] result = new long[n];
        int[] pathCount = new int[n];
        Arrays.fill(result, Long.MAX_VALUE);
        
        result[0] = 0;
        pathCount[0] = 1;
        pq.offer(new long[]{0, 0});
        
        while (!pq.isEmpty()) {
            long[] curr = pq.poll();
            long currTime = curr[0];
            int currNode = (int) curr[1];
            
            if (currTime > result[currNode]) continue;
            
            for (int[] neighbor : adj.get(currNode)) {
                int adjNode = neighbor[0];
                int roadTime = neighbor[1];
                
                if (currTime + roadTime < result[adjNode]) {
                    result[adjNode] = currTime + roadTime;
                    pathCount[adjNode] = pathCount[currNode];
                    pq.offer(new long[]{result[adjNode], adjNode});
                } else if (currTime + roadTime == result[adjNode]) {
                    pathCount[adjNode] = (pathCount[adjNode] + pathCount[currNode]) % MOD;
                }
            }
        }
        
        return pathCount[n - 1];
    }
}
