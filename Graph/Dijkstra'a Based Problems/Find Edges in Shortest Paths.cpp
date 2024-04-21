/*    Scroll below to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/find-edges-in-shortest-paths/
*/

/**************************************************** C++ *******************************************/
//Using Dijkstra's
//T.C : O(n+E) , where n = number of vertices, E = number of edges
//S.C : O(n)
class Solution {
public:
    typedef long long ll;
    typedef pair<ll, ll> P;
    
    vector<int> getShortestPath(vector<vector<P>>& adj, int src, int n) {
        priority_queue<P, vector<P>, greater<P>> pq;
        
        vector<int> dist(n, INT_MAX);
        
        dist[src] = 0;
        
        pq.push({0, src});
        
        while(!pq.empty()) {

            ll  currWt   = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();


            for(auto adj: adj[currNode]) {
                int nextNode = adj.first;
                ll nextWt = adj.second;

                if(dist[nextNode] > currWt + nextWt) {
                    dist[nextNode] = currWt + nextWt;
                    pq.push({currWt + nextWt, nextNode});
                }
            }

        }
        
        return dist;
    }

    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        int E = edges.size();
        
        vector<vector<P>> adj(n);
        
        for(auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<int> fromSrc = getShortestPath(adj, 0, n);
        vector<int> fromEnd = getShortestPath(adj, n - 1, n);         
           
        
        vector<bool> res(E, false);
        for(int i = 0 ; i < E ; i++) {  

            ll distFromStart = fromSrc[edges[i][0]];
            ll distFromEnd = fromEnd[edges[i][1]];
            ll w = edges[i][2];
            
            if(distFromStart + distFromEnd + w == fromSrc[n - 1]) {
                res[i] = true;
                continue;
            }
            
            distFromStart = fromSrc[edges[i][1]];
            distFromEnd = fromEnd[edges[i][0]];
            
            if(distFromStart + distFromEnd + w == fromSrc[n - 1])
                res[i] = true;
        }
        
        return res;
    }
};




/**************************************************** JAVA *******************************************/
//Using Dijkstra's
//T.C : O(n+E) , where n = number of vertices, E = number of edges
//S.C : O(n)
import java.util.*;

class Solution {
    static class Pair implements Comparable<Pair> {
        long first;
        long second;

        public Pair(long first, long second) {
            this.first = first;
            this.second = second;
        }

        public int compareTo(Pair other) {
            return Long.compare(this.first, other.first);
        }
    }

    public int[] getShortestPath(List<List<Pair>> adj, int src, int n) {
        PriorityQueue<Pair> pq = new PriorityQueue<>(Comparator.comparingLong(p -> p.first));

        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);

        dist[src] = 0;

        pq.offer(new Pair(0, src));

        while (!pq.isEmpty()) {
            long currWt = pq.peek().first;
            int currNode = (int) pq.peek().second;
            pq.poll();

            for (Pair next : adj.get(currNode)) {
                int nextNode = (int) next.first;
                long nextWt = next.second;

                if (dist[nextNode] > currWt + nextWt) {
                    dist[nextNode] = (int) (currWt + nextWt);
                    pq.offer(new Pair(currWt + nextWt, nextNode));
                }
            }
        }

        return dist;
    }

    public boolean[] findAnswer(int n, int[][] edges) {
        int E = edges.length;

        List<List<Pair>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj.get(u).add(new Pair(v, w));
            adj.get(v).add(new Pair(u, w));
        }

        int[] fromSrc = getShortestPath(adj, 0, n);
        int[] fromEnd = getShortestPath(adj, n - 1, n);

        boolean[] res = new boolean[E];
        for (int i = 0; i < E; i++) {
            int distFromStart = fromSrc[edges[i][0]];
            int distFromEnd = fromEnd[edges[i][1]];
            int w = edges[i][2];

            if (distFromStart + distFromEnd + w == fromSrc[n - 1]) {
                res[i] = true;
                continue;
            }

            distFromStart = fromSrc[edges[i][1]];
            distFromEnd = fromEnd[edges[i][0]];

            if (distFromStart + distFromEnd + w == fromSrc[n - 1]) {
                res[i] = true;
            }
        }

        return res;
    }
}
