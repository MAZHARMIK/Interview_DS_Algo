/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/palindromic-path-queries-in-a-tree/
*/


/**************************************************************** C++ ****************************************************************/
//Approach (Segment Tree + Binary Lifting for LCA + Euler Tour)
//T.C : O((n + q) log n)
//      Preprocessing: DFS O(n), Binary Lifting table O(n log n), Segment Tree build O(n)
//      Each update: 2 point updates O(log n)
//      Each query: LCA O(log n) + 2 prefix XOR queries O(log n)
//S.C : O(n log n)
//      Binary Lifting table O(n log n), Euler Tour + Segment Tree O(n), adj list O(n), recursion stack O(n)
class Solution {
public:
    unordered_map<int, vector<int>> adj;
    int n;
    vector<int> tin, tout, eulerTour;
    int time;

    vector<int> segmentTree;

    vector<vector<int>> ancestorTable;
    vector<int> depth;
    int cols;

    void dfs(int node, int parent, int d, string& s) {
        depth[node] = d;
        ancestorTable[node][0] = parent;

        tin[node] = time;
        eulerTour[time] = (1 << (s[node] - 'a')); //"a" = 001, "b" = 0101 : Entering
        time++;

        for(int &child : adj[node]) {
            if(child == parent) {
                continue;
            }
            dfs(child, node, d+1, s);
        }

        tout[node] = time;
        eulerTour[time] = (1 << (s[node] - 'a')); //Leaving
        time++;
    }

    // Segment Tree : Build (For XOR)
    void buildSegmentTree(int i, int l, int r, vector<int>& nums) {
        if(l == r) {
            segmentTree[i] = nums[l];
            return;
        }

        int mid = l + (r-l)/2;
        buildSegmentTree(2*i+1, l, mid, nums);
        buildSegmentTree(2*i+2, mid+1, r, nums);
        segmentTree[i] = segmentTree[2*i+1] ^ segmentTree[2*i+2];
    }

    //Segment Tree : Point update (Xor)
    void updateSegTree(int index, int val, int i, int l, int r) {
        if(l == r) {
            segmentTree[i] = val;
            return;
        }

        int mid = l + (r-l)/2;
        if(index <= mid) {
            updateSegTree(index, val, 2*i+1, l, mid);
        } else {
            updateSegTree(index, val, 2*i+2, mid+1, r);
        }

        segmentTree[i] = segmentTree[2*i+1] ^ segmentTree[2*i+2];
    }

    //Segment Tree : Search Query (Xor)
    int querySegmentTree(int start, int end, int i, int l, int r) {
        if(l > end || r < start) {
            return 0;
        }

        if(l >= start && r <= end) {
            return segmentTree[i];
        }

        int mid = l + (r-l)/2;
        return querySegmentTree(start, end, 2*i+1, l,    mid) ^
               querySegmentTree(start, end, 2*i+2, mid+1, r);
    }

    // Binary Lifting Code for building ancestorTable
    void buildAncestorTable() {
        for(int j = 1; j < cols; j++) {
            for(int node = 0; node < n; node++) {
                if(ancestorTable[node][j-1] != -1) {
                    ancestorTable[node][j] = ancestorTable[ ancestorTable[node][j-1] ][j-1];
                }
            }
        }
    }

    //get LCA using Binary Lifting
    int getLCA(int u, int v) {
        if(depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];
        for(int j = 0; j < cols; j++) {
            if(diff & (1 << j)) {
                u = ancestorTable[u][j];
            }
        }

        if(u == v) 
            return u;

        for(int j = cols - 1; j >= 0; j--) {
            if(ancestorTable[u][j] != ancestorTable[v][j]) {
                u = ancestorTable[u][j];
                v = ancestorTable[v][j];
            }
        }

        return ancestorTable[u][0];
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        eulerTour.assign(2*n, 0); //Sees each node at inTime and outTime

        //root = 0
        time = 0;
        cols = log2(n) + 1;
        ancestorTable.assign(n, vector<int>(cols, -1));
        
        dfs(0, -1, 0, s);


        //Build Segment Tree for the array - eulerTour -> size = 2*n
        int N = 2*n; //size of eulerTour array
        segmentTree.resize(4*N, 0);
        buildSegmentTree(0, 0, N-1, eulerTour);
        
        buildAncestorTable();

        vector<bool> result;

        for(string &q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;

            if(type == "update") { //update ui c
                int node;
                char c;

                ss >> node >> c;

                int charValue = (1 << (c - 'a'));
                s[node] = c;
                updateSegTree(tin[node], charValue, 0, 0, 2*n-1);
                updateSegTree(tout[node], charValue, 0, 0, 2*n-1);
            } else { //query ui vi
                int u, v;

                ss >> u >> v;

                int lcaNode = getLCA(u, v);
                char ch = s[lcaNode];
                int charValue = (1 << (ch - 'a'));

                int mask = querySegmentTree(0, tin[u], 0, 0, 2*n-1) ^
                           querySegmentTree(0, tin[v], 0, 0, 2*n-1) ^
                           charValue;
                
                result.push_back((mask & (mask-1)) == 0);       
            }
        }
        return result;

    }
};



/**************************************************************** JAVA ****************************************************************/
//Approach (Segment Tree + Binary Lifting for LCA + Euler Tour)
//T.C : O((n + q) log n)
//      Preprocessing: DFS O(n), Binary Lifting table O(n log n), Segment Tree build O(n)
//      Each update: 2 point updates O(log n)
//      Each query: LCA O(log n) + 2 prefix XOR queries O(log n)
//S.C : O(n log n)
//      Binary Lifting table O(n log n), Euler Tour + Segment Tree O(n), adj list O(n), recursion stack O(n)
class Solution {
    Map<Integer, List<Integer>> adj;
    int n;
    int[] tin, tout, eulerTour;
    int time;

    int[] segmentTree;

    int[][] ancestorTable;
    int[] depth;
    int cols;

    void dfs(int node, int parent, int d, char[] s) {
        depth[node] = d;
        ancestorTable[node][0] = parent;

        tin[node] = time;
        eulerTour[time] = (1 << (s[node] - 'a')); //"a" = 001, "b" = 010 : Entering
        time++;

        for (int child : adj.getOrDefault(node, new ArrayList<>())) {
            if (child == parent) {
                continue;
            }
            dfs(child, node, d + 1, s);
        }

        tout[node] = time;
        eulerTour[time] = (1 << (s[node] - 'a')); //Leaving
        time++;
    }

    // Segment Tree : Build (For XOR)
    void buildSegmentTree(int i, int l, int r, int[] nums) {
        if (l == r) {
            segmentTree[i] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;
        buildSegmentTree(2 * i + 1, l, mid, nums);
        buildSegmentTree(2 * i + 2, mid + 1, r, nums);
        segmentTree[i] = segmentTree[2 * i + 1] ^ segmentTree[2 * i + 2];
    }

    //Segment Tree : Point update (Xor)
    void updateSegTree(int index, int val, int i, int l, int r) {
        if (l == r) {
            segmentTree[i] = val;
            return;
        }

        int mid = l + (r - l) / 2;
        if (index <= mid) {
            updateSegTree(index, val, 2 * i + 1, l, mid);
        } else {
            updateSegTree(index, val, 2 * i + 2, mid + 1, r);
        }

        segmentTree[i] = segmentTree[2 * i + 1] ^ segmentTree[2 * i + 2];
    }

    //Segment Tree : Search Query (Xor)
    int querySegmentTree(int start, int end, int i, int l, int r) {
        if (l > end || r < start) {
            return 0;
        }

        if (l >= start && r <= end) {
            return segmentTree[i];
        }

        int mid = l + (r - l) / 2;
        return querySegmentTree(start, end, 2 * i + 1, l,       mid) ^
               querySegmentTree(start, end, 2 * i + 2, mid + 1, r);
    }

    // Binary Lifting Code for building ancestorTable
    void buildAncestorTable() {
        for (int j = 1; j < cols; j++) {
            for (int node = 0; node < n; node++) {
                if (ancestorTable[node][j - 1] != -1) {
                    ancestorTable[node][j] = ancestorTable[ancestorTable[node][j - 1]][j - 1];
                }
            }
        }
    }

    //get LCA using Binary Lifting
    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) {
            int temp = u;
            u = v;
            v = temp;
        }

        int diff = depth[u] - depth[v];
        for (int j = 0; j < cols; j++) {
            if ((diff & (1 << j)) != 0) {
                u = ancestorTable[u][j];
            }
        }

        if (u == v)
            return u;

        for (int j = cols - 1; j >= 0; j--) {
            if (ancestorTable[u][j] != ancestorTable[v][j]) {
                u = ancestorTable[u][j];
                v = ancestorTable[v][j];
            }
        }

        return ancestorTable[u][0];
    }

    public List<Boolean> palindromePath(int n, int[][] edges, String str, String[] queries) {
        this.n = n;
        char[] s = str.toCharArray();   // Java Strings are immutable, so use char[] to allow s[node] = c

        adj = new HashMap<>();
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }

        tin = new int[n];
        tout = new int[n];
        depth = new int[n];
        eulerTour = new int[2 * n]; //Sees each node at inTime and outTime

        //root = 0
        time = 0;
        cols = (31 - Integer.numberOfLeadingZeros(n)) + 1;   // same as log2(n) + 1
        ancestorTable = new int[n][cols];
        for (int[] row : ancestorTable) {
            Arrays.fill(row, -1);
        }

        dfs(0, -1, 0, s);


        //Build Segment Tree for the array - eulerTour -> size = 2*n
        int N = 2 * n; //size of eulerTour array
        segmentTree = new int[4 * N];
        buildSegmentTree(0, 0, N - 1, eulerTour);

        buildAncestorTable();

        List<Boolean> result = new ArrayList<>();

        for (String q : queries) {
            String[] parts = q.split(" ");
            String type = parts[0];

            if (type.equals("update")) { //update ui c
                int node = Integer.parseInt(parts[1]);
                char c = parts[2].charAt(0);

                int charValue = (1 << (c - 'a'));
                s[node] = c;
                updateSegTree(tin[node], charValue, 0, 0, 2 * n - 1);
                updateSegTree(tout[node], charValue, 0, 0, 2 * n - 1);
            } else { //query ui vi
                int u = Integer.parseInt(parts[1]);
                int v = Integer.parseInt(parts[2]);

                int lcaNode = getLCA(u, v);
                char ch = s[lcaNode];
                int charValue = (1 << (ch - 'a'));

                int mask = querySegmentTree(0, tin[u], 0, 0, 2 * n - 1) ^
                           querySegmentTree(0, tin[v], 0, 0, 2 * n - 1) ^
                           charValue;

                result.add((mask & (mask - 1)) == 0);
            }
        }
        return result;
    }
}
