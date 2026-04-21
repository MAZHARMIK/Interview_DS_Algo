/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=r0s0BtmTxWk
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations
*/


/************************************************************ C++ ************************************************/
//Approach - (DSU + map)
//T.C : O(n + m*alpha(n)), alpha(n) = inverse Ackermann function.
//S.C : O(n)
class Solution {
public:
    //DSU using rank and path compression
    vector<int> rank;
    vector<int> parent;

    // Find with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void Union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return;

        // Union by rank
        if (rank[rootX] < rank[rootY]) {
            swap(rootX, rootY);
        }

        parent[rootY] = rootX;

        if (rank[rootX] == rank[rootY]) {
            rank[rootX]++;
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();

        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        //Union of allowedSwaps
        for(auto &vec : allowedSwaps) { //O(m*alpha)
            Union(vec[0], vec[1]);
        }

        unordered_map<int, unordered_map<int, int>> groupFreq;

        for(int i = 0; i < n; i++) { //O(n*alpha)
            int curr = source[i];

            int parent = find(i); //group
            groupFreq[parent][curr]++;
        }

        int hammingDistance = 0;
        for(int i = 0; i < n; i++) {
            int parent = find(i); //group
            
            if(groupFreq[parent][target[i]] > 0) {
                groupFreq[parent][target[i]]--;
            } else {
                hammingDistance++;
            }
        }

        return hammingDistance;
    }
};



/************************************************************ JAVA ************************************************/
//Approach - (DSU + map)
//T.C : O(n + m*alpha(n)), alpha(n) = inverse Ackermann function.
//S.C : O(n)
class Solution {
    int[] parent;
    int[] rank;

    // Find with path compression
    public int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Union by rank
    public void union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return;

        if (rank[rootX] < rank[rootY]) {
            int temp = rootX;
            rootX = rootY;
            rootY = temp;
        }

        parent[rootY] = rootX;

        if (rank[rootX] == rank[rootY]) {
            rank[rootX]++;
        }
    }

    public int minimumHammingDistance(int[] source, int[] target, int[][] allowedSwaps) {
        int n = source.length;

        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // Union of allowedSwaps
        for (int[] edge : allowedSwaps) {
            union(edge[0], edge[1]);
        }

        // group -> (value -> freq)
        Map<Integer, Map<Integer, Integer>> groupFreq = new HashMap<>();

        for (int i = 0; i < n; i++) {
            int root = find(i);

            groupFreq.putIfAbsent(root, new HashMap<>());
            Map<Integer, Integer> freqMap = groupFreq.get(root);

            freqMap.put(source[i], freqMap.getOrDefault(source[i], 0) + 1);
        }

        int hammingDistance = 0;

        for (int i = 0; i < n; i++) {
            int root = find(i);
            Map<Integer, Integer> freqMap = groupFreq.get(root);

            if (freqMap.getOrDefault(target[i], 0) > 0) {
                freqMap.put(target[i], freqMap.get(target[i]) - 1);
            } else {
                hammingDistance++;
            }
        }

        return hammingDistance;
    }
}
