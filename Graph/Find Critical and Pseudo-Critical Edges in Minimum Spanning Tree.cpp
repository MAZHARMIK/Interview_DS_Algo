/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=gDPh7gsK3F8
      Company Tags                : Amazon, Meta
      Leetcode Link               : https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/
*/

***************************************** C++ *****************************************
//Using Union Find + Kruskal's. T.C : ElogE + E*@ + E*E*@ - Explained in the video above
class Solution {
public:
    int N;
    class UnionFind {
        public:
            vector<int> parent;
            vector<int> rank;

            UnionFind(int n) {
                parent.resize(n);
                rank.resize(n, 0);
                for (int i = 0; i < n; i++) {
                    parent[i] = i;
                }
            }    
        
            int find (int x) {
                if (x == parent[x]) 
                    return x;

                return parent[x] = find(parent[x]);
            }

            void Union (int x, int y) {
                int x_parent = find(x);
                int y_parent = find(y);

                if (x_parent == y_parent) 
                    return;

                if(rank[x_parent] > rank[y_parent]) {
                    parent[y_parent] = x_parent;
                } else if(rank[x_parent] < rank[y_parent]) {
                    parent[x_parent] = y_parent;
                } else {
                    parent[x_parent] = y_parent;
                    rank[y_parent]++;
                }
            }
    };
    
    int Kruskal(vector<vector<int>> &vec, int skip_edge, int force_edge) {

        int sum = 0;
        UnionFind uf(N);
        
        if(force_edge != -1) {
            uf.Union(vec[force_edge][0], vec[force_edge][1]);
            sum += vec[force_edge][2];
        }
        
        for(int i=0; i < vec.size(); i++) {
            
            if(i == skip_edge)
                continue;
            
            int u  = vec[i][0];
            int v  = vec[i][1];
            int wt = vec[i][2];
            
            int parent_u = uf.find(u);
            int parent_v = uf.find(v);
            
            if(parent_u != parent_v) {
                uf.Union(u, v);
                sum += wt;
            }
            
        }

        //Check if all vertices are included in MST
        for(int i = 0; i < N; i++) {
            if(uf.find(i) != uf.find(0))
                return INT_MAX;
        }
        
        return sum;
    }
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        N = n;
        
        //since for kruskal's algo, we will sort our input by edge weight.
        //But since we need to return the index in the last
        for(int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }
        
        auto comparator = [&](auto &v1, auto &v2) {
            return v1[2] < v2[2];
        };
        //Now sort based on weight
        //O(ElogE)
        sort(edges.begin(), edges.end(), comparator);
        
        
        //Find MST now
        //Find MST weight using union-find
        //O(E*@)
        int MST_WEIGHT = Kruskal(edges, -1, -1);
        
        vector<int> critical, pseudo_critical;


      //O(E*E*@)
        for(int i = 0; i < edges.size(); i++) {
          
            if(Kruskal(edges, i, -1) > MST_WEIGHT) //Skipping ith edge
                critical.push_back(edges[i][3]); 
            
            else if(Kruskal(edges, -1, i) == MST_WEIGHT) // Force add ith edge
                pseudo_critical.push_back(edges[i][3]);
        }

        return {critical, pseudo_critical};
        
    }
};


//Approach-2 (Better Kruskal's Function)
/*
If you remember, in the Kruskal's Function, in the end we checked if the graph was connected and wrote a for loop to check that as shown below : 
for(int i = 0; i<N; i++) {   
            if(uf.find(i) != uf.find(0))
                return INT_MAX;
 }

BUT BUT BUT, we can also directly check if the total edges we made from Union is equal to (V-1). 
Remember, in MST, there must be V vertices and must have (V-1) edges.
So, in Kruskal's function, whenever you do Union, just count the edges you draw.

So, simply replace the for loop with : 
if(edgesConnected != N-1)
            return INT_MAX;

Full code below :
*/
class Solution {
public:
    int N;
    class UnionFind {
        public:
            vector<int> parent;
            vector<int> rank;

            UnionFind(int n) {
                parent.resize(n);
                rank.resize(n, 0);
                for (int i = 0; i < n; i++) {
                    parent[i] = i;
                }
            }    
        
            int find (int x) {
                if (x == parent[x]) 
                    return x;

                return parent[x] = find(parent[x]);
            }

            bool Union (int x, int y) {
                int x_parent = find(x);
                int y_parent = find(y);

                if (x_parent == y_parent) 
                    return false;

                if(rank[x_parent] > rank[y_parent]) {
                    parent[y_parent] = x_parent;
                } else if(rank[x_parent] < rank[y_parent]) {
                    parent[x_parent] = y_parent;
                } else {
                    parent[x_parent] = y_parent;
                    rank[y_parent]++;
                }
                return true;
            }
    };
    
    int Kruskal(vector<vector<int>> &vec, int skip_edge, int add_edge) {

        int sum = 0;
        
        UnionFind uf(N);
        int edgesConnected = 0;
        
        if(add_edge != -1) {
            uf.Union(vec[add_edge][0], vec[add_edge][1]);
            sum += vec[add_edge][2];
            edgesConnected++;
        }
        
        //E
        
        for(int i = 0; i<vec.size(); i++) {
            
            if(i == skip_edge)
                continue;
            
            int u  = vec[i][0];
            int v  = vec[i][1];
            int wt = vec[i][2];
            //O(@)
            int parent_u = uf.find(u);
            int parent_v = uf.find(v);
            
            if(parent_u != parent_v) {
                uf.Union(u, v);
                edgesConnected++;
                sum += wt;
            }
            
        }

        if(edgesConnected != N-1)
            return INT_MAX;
        
        return sum;
    }
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        N = n;
        for(int i = 0; i<edges.size(); i++) {
            edges[i].push_back(i);  
        }
        
        auto lambda = [&](vector<int>& vec1, vector<int>& vec2) {
            return vec1[2] < vec2[2];
        };
        //ElogE
        sort(begin(edges), end(edges), lambda);
        
        
        int MST_WEIGHT = Kruskal(edges, -1, -1);

        vector<int> critical;
        vector<int> pseudo_critical;
        
        
        //E*E*@
        for(int i = 0; i<edges.size(); i++) {
            
            if(Kruskal(edges, i, -1) > MST_WEIGHT) { //skipping ith edge
                critical.push_back(edges[i][3]);
            }
            
            else if(Kruskal(edges, -1, i) == MST_WEIGHT) { //Force add this ith edge
                pseudo_critical.push_back(edges[i][3]);
            }
            
        }
        
        
        return {critical, pseudo_critical};
        
    }
};



************************************* JAVA ********************************************
class Solution {
    int N;
    
    public int Kruskal(int[][] vec, int skip_edge, int add_edge) {

        int sum = 0;

        UnionFind uf = new UnionFind(N);
        int edgesConnected = 0;
        
        if(add_edge != -1) {
            uf.Union(vec[add_edge][0], vec[add_edge][1]);
            sum += vec[add_edge][2];
            edgesConnected++;
        }
        

        for(int i = 0; i<vec.length; i++) {
            
            if(i == skip_edge)
                continue;
            
            int u  = vec[i][0];
            int v  = vec[i][1];
            int wt = vec[i][2];
            //O(@)
            int parent_u = uf.find(u);
            int parent_v = uf.find(v);
            
            if(parent_u != parent_v) {
                uf.Union(u, v);
                edgesConnected++;
                sum += wt;
            }
            
        }

        if(edgesConnected != N-1)
            return Integer.MAX_VALUE;
        
        return sum;
    }
    
    public List<List<Integer>> findCriticalAndPseudoCriticalEdges(int n, int[][] edges) {
        N = n;
        
        int m = edges.length;
        int[][] newEdges = new int[m][4];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < 3; j++) {
                newEdges[i][j] = edges[i][j];
            }
            newEdges[i][3] = i;
        }

        // Sort edges based on weight
        Arrays.sort(newEdges, Comparator.comparingInt(edge -> edge[2]));

        // Find MST weight using union-find
        int MST_WEIGHT = Kruskal(newEdges, -1, -1);

        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < 2; i++) {
            result.add(new ArrayList<>());
        }

        // Check each edge for critical and pseudo-critical
        for (int i = 0; i < m; i++) {
            
            if(Kruskal(newEdges, i, -1) > MST_WEIGHT) { //skipping ith edge
                result.get(0).add(newEdges[i][3]);
            }
            
            else if(Kruskal(newEdges, -1, i) == MST_WEIGHT) { //Force add this ith edge
                result.get(1).add(newEdges[i][3]);
            }
            
        }

        return result;
    }
    
    class UnionFind {
        int[] parent;
        int[] rank;

        public UnionFind(int n) {
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++) {
                    parent[i] = i;
                    rank[i] = 0;
            }
        }

        int find (int x) {
            if (x == parent[x]) 
                return x;

            return parent[x] = find(parent[x]);
        }

        public void Union(int x, int y) {
            int x_parent = find(x);
            int y_parent = find(y);

            if (x_parent == y_parent) 
                return;

            if(rank[x_parent] > rank[y_parent]) {
                parent[y_parent] = x_parent;
            } else if(rank[x_parent] < rank[y_parent]) {
                parent[x_parent] = y_parent;
            } else {
                parent[x_parent] = y_parent;
                rank[y_parent]++;
            }

        }
    }
}
