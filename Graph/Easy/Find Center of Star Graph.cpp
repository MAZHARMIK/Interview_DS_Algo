/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Sp9kcIX0Ep0
    Company Tags                : MICROSOFT
    Leetcode Link               : https://leetcode.com/problems/find-center-of-star-graph
*/


/************************************************************************ C++ ********************************************************/
//Approach-1 (Using map)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int, int> degree;

        for(auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];

            degree[u]++;
            degree[v]++;
        }

        for(auto &it : degree) {
            int node = it.first;
            int deg  = it.second;

            if(deg == n)
                return node;
        }

        return -1;
    }
};


//Approach-2 (Constant time)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> first  = edges[0]; //{a, b}
        vector<int> second = edges[1]; //{c, a}

        if(first[0] == second[0] || first[0] == second[1]) {
            return first[0];
        }

        return first[1];

    }
};

/************************************************************************ JAVA ********************************************************/
//Approach-1 (Using map)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int findCenter(int[][] edges) {
        Map<Integer, Integer> degree = new HashMap<>();

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];

            degree.put(u, degree.getOrDefault(u, 0) + 1);
            degree.put(v, degree.getOrDefault(v, 0) + 1);
        }

        for (Map.Entry<Integer, Integer> entry : degree.entrySet()) {
            if (entry.getValue() == edges.length) {
                return entry.getKey(); // star graph center node
            }
        }

        return -1;
    }
}



//Approach-2 (Constant time)
//T.C : O(1)
//S.C : O(1)
class Solution {
    public int findCenter(int[][] edges) {
        int[] first = edges[0]; // {a, b}
        int[] second = edges[1]; // {c, a}

        if (first[0] == second[0] || first[0] == second[1]) {
            return first[0];
        }

        return first[1];
    }
}
