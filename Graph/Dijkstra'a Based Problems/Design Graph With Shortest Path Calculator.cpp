/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=EPvZsimuqwM
    Company Tags                : will update soon.
    Leetcode Link               : https://leetcode.com/problems/design-graph-with-shortest-path-calculator
*/


/******************************************************** C++ ********************************************************/
//Approach-1 (Using Dijkstra's Algorithm)
//T.C : Dijkatra's called M times - O(M * ElogV)
class Graph {
public:
    unordered_map<int, vector<pair<int, int>>> adj;
    int N;
    vector<int> result;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    Graph(int n, vector<vector<int>>& edges) {
        N = n;
        for(auto &vec : edges) {
            int u    = vec[0];
            int v    = vec[1];
            int cost = vec[2];
            
            adj[u].push_back({v, cost});
        }
    }
    
    void addEdge(vector<int> edge) {
        int u    = edge[0];
        int v    = edge[1];
        int cost = edge[2];
            
        adj[u].push_back({v, cost});
    }
    
    int shortestPath(int node1, int node2) {

		vector<int> result(N, INT_MAX);

		result[node1] = 0;
		pq.push({0, node1});

		while(!pq.empty()) {

		    int d  = pq.top().first;
		    int node = pq.top().second;
		    pq.pop();

		    for(auto &vec : adj[node]) {

			int adjNode = vec.first;
			int dist    = vec.second;

			if(d + dist < result[adjNode]) {

			    result[adjNode] = d + dist;
			    pq.push({d+dist, adjNode});

			}

		    }

		}
        
        return result[node2] == INT_MAX ? -1 : result[node2];
    }
};

//Approach-2 (Using Floyd Warshal Algorithm because it helps to find multi Source Shortest Path)
//Code - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Floyd%20Warshall/Design%20Graph%20With%20Shortest%20Path%20Calculator.cpp

/******************************************************** JAVA ********************************************************/
//Approach-1 (Using Dijkstra's Algorithm)
//T.C : Dijkatra's called M times - O(M * ElogV)
class Graph {
    Map<Integer, List<Node>> adj;
    int N;
    int[] result;
    PriorityQueue<Node> pq;

    public Graph(int n, int[][] edges) {
        N = n;
        adj = new HashMap<>();
        result = new int[N];
        Arrays.fill(result, Integer.MAX_VALUE);
        pq = new PriorityQueue<>(Comparator.comparingInt(node -> node.cost));

        for (int[] vec : edges) {
            int u = vec[0];
            int v = vec[1];
            int cost = vec[2];

            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(new Node(v, cost));
        }
    }

    public void addEdge(int[] edge) {
        int u = edge[0];
        int v = edge[1];
        int cost = edge[2];

        adj.computeIfAbsent(u, k -> new ArrayList<>()).add(new Node(v, cost));
    }

    public int shortestPath(int node1, int node2) {
        Arrays.fill(result, Integer.MAX_VALUE);
        result[node1] = 0;
        pq.offer(new Node(node1, 0));

        while (!pq.isEmpty()) {
            int node = pq.peek().node;
            int d = pq.poll().cost;

            for (Node vec : adj.getOrDefault(node, Collections.emptyList())) {
                int adjNode = vec.node;
                int dist = vec.cost;

                if (d + dist < result[adjNode]) {
                    result[adjNode] = d + dist;
                    pq.offer(new Node(adjNode, d + dist));
                }
            }
        }

        return result[node2] == Integer.MAX_VALUE ? -1 : result[node2];
    }

    static class Node {
        int node;
        int cost;

        public Node(int node, int cost) {
            this.node = node;
            this.cost = cost;
        }
    }
}


//Approach-2 (Using Floyd Warshal Algorithm because it helps to find multi Source Shortest Path)
//Code - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Floyd%20Warshall/Design%20Graph%20With%20Shortest%20Path%20Calculator.cpp
