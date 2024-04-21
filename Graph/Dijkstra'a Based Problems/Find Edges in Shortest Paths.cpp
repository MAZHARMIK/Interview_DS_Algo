/*    Scroll below to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/find-edges-in-shortest-paths/
*/

/**************************************************** C++ *******************************************/
//Using DIjkstra's
//T.C : O(n+E) , where n = number of vertices, E = number of edges
//S.C : O(n)
class Solution {
public:
    typedef long long ll;
    typedef pair<ll, ll> P;
    
    vector<int> getShortestPath(vector<vector<P>>& graph, int src, int n) {
        priority_queue<P, vector<P>, greater<P>> pq;
        
        vector<int> dist(n, INT_MAX);
        
        dist[src] = 0;
        
        pq.push({0, src});
        
        while(!pq.empty()) {

            ll  currWt   = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();


            for(auto adj: graph[currNode]) {
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
        vector<vector<P>> graph(n);
        
        for(auto edge: edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        
        vector<int> fromSrc = getShortestPath(graph, 0, n);
        vector<int> fromEnd = getShortestPath(graph, n - 1, n);         
           
        
        vector<bool> res(edges.size(), false);
        for(int i = 0 ; i < edges.size() ; i++) {  
            //          a         w         b
            //    src ----- (x) ----- (y) ----- dest

            // the edges are undirected, hence try both ways            
            // considering edges[i][0] to be x and edges[i][1] to be y
            ll distFromStart = fromSrc[edges[i][0]];
            ll distFromEnd = fromEnd[edges[i][1]];
            ll w = edges[i][2];
            
            if(distFromStart + distFromEnd + w == fromSrc[n - 1]) {
                res[i] = true;
                continue;
            }
            
            // considering edges[i][0] to be y and edges[i][1] to be x
            distFromStart = fromSrc[edges[i][1]];
            distFromEnd = fromEnd[edges[i][0]];
            
            if(distFromStart + distFromEnd + w == fromSrc[n - 1])
                res[i] = true;
        }
        
        return res;
    }
};



/**************************************************** JAVA *******************************************/
//Using DIjkstra's
//T.C : O(n+E) , where n = number of vertices, E = number of edges
//S.C : O(n)
import java.util.*;

class Solution {

    class Pair {
        long first;
        long second;
        
        Pair(long first, long second) {
            this.first = first;
            this.second = second;
        }
    }
    
    public long[] getShortestPath(List<List<Pair>> graph, int src, int n) {
        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> Long.compare(a.first, b.first));
        
        long[] dist = new long[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        
        dist[src] = 0;
        
        pq.offer(new Pair(0, src));
        
        while (!pq.isEmpty()) {
            long currWt = pq.peek().first;
            int currNode = (int) pq.peek().second;
            pq.poll();
            
            for (Pair adj : graph.get(currNode)) {
                int nextNode = (int) adj.first;
                long nextWt = adj.second;
                
                if (dist[nextNode] > currWt + nextWt) {
                    dist[nextNode] = currWt + nextWt;
                    pq.offer(new Pair(currWt + nextWt, nextNode));
                }
            }
        }
        
        return dist;
    }

    public boolean[] findAnswer(int n, int[][] edges) {
        List<List<Pair>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        
        for (int[] edge : edges) {
            graph.get(edge[0]).add(new Pair(edge[1], edge[2]));
            graph.get(edge[1]).add(new Pair(edge[0], edge[2]));
        }
        
        long[] fromSrc = getShortestPath(graph, 0, n);
        long[] fromEnd = getShortestPath(graph, n - 1, n);         
        
        boolean[] res = new boolean[edges.length];
        for (int i = 0; i < edges.length; i++) {  
            long distFromStart = fromSrc[edges[i][0]];
            long distFromEnd = fromEnd[edges[i][1]];
            long w = edges[i][2];
            
            if (distFromStart + distFromEnd + w == fromSrc[n - 1]) {
                res[i] = true;
                continue;
            }
            
            distFromStart = fromSrc[edges[i][1]];
            distFromEnd = fromEnd[edges[i][0]];
            
            if (distFromStart + distFromEnd + w == fromSrc[n - 1])
                res[i] = true;
        }
        
        return res;
    }
}

