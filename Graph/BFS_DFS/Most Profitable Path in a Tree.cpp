/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=uJiDHHChF58
    Company Tags                : Intuit
    Leetcode Link               : https://leetcode.com/problems/most-profitable-path-in-a-tree
*/



/****************************************************************** C++ ******************************************************************/
//Approach-1 (DFS for Bob and DFS for Alice)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> bobMap;
    int aliceIncome;
    bool DFSBob(int curr, int t, vector<bool>&  visited) {
        visited[curr] = true;
        bobMap[curr] = t;

        if(curr == 0) { //reached target
            return true;
        }

        for(auto &ngbr : adj[curr]) {
            if(!visited[ngbr]) {
                if(DFSBob(ngbr, t+1, visited) == true) {
                    return true;
                }
            }
        }

        bobMap.erase(curr);
        return false;
    }

    void DFSAlice(int curr, int t, int income, vector<bool>& visited, vector<int>& amount) {
        visited[curr] = true;

        if(bobMap.find(curr) == bobMap.end() || t < bobMap[curr]) {
            income += amount[curr];
        } else if(t == bobMap[curr]) {
            income += (amount[curr]/2);
        }


        if(adj[curr].size() == 1 && curr != 0) { //leaf node
            aliceIncome = max(aliceIncome, income);
        }

        /*
            {1} -> (2, 3)
            2 -> 1
            3 -> 1,....
            (1) ---- (2)
             |
             |
             (3)------.....
        */

        for(int &ngbr : adj[curr]) {
            if(!visited[ngbr]) {
                DFSAlice(ngbr, t+1, income, visited, amount);
            }
        }

    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size(); //n nodes (0 to n-1)

        aliceIncome = INT_MIN;
        for(vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //DFS on Bob for finding time to reach each node till 0
        int time = 0;
        vector<bool> visited(n, false);
        DFSBob(bob, time, visited);
        
        int income = 0;
        visited.assign(n, false);
        DFSAlice(0, 0, income, visited, amount);

        return aliceIncome;
    }
};


//Approach-2 (DFS for Bob and BFS for Alice)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> bobMap;
    int aliceIncome;
    bool DFSBob(int curr, int t, vector<bool>&  visited) {
        visited[curr] = true;
        bobMap[curr] = t;

        if(curr == 0) { //reached target
            return true;
        }

        for(auto &ngbr : adj[curr]) {
            if(!visited[ngbr]) {
                if(DFSBob(ngbr, t+1, visited) == true) {
                    return true;
                }
            }
        }

        bobMap.erase(curr);
        return false;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size(); //n nodes (0 to n-1)

        aliceIncome = INT_MIN;
        for(vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //DFS on Bob for finding time to reach each node till 0
        int time = 0;
        vector<bool> visited(n, false);
        DFSBob(bob, time, visited);
        
        int income = 0;
        visited.assign(n, false);

        //BFS se karunga
        queue<vector<int>> que;
        //{node, time, income}
        que.push({0, 0, 0});
        
        while(!que.empty()) {
            int curr = que.front()[0];
            int t = que.front()[1];
            int income = que.front()[2];

            que.pop();

            if(bobMap.find(curr) == bobMap.end() || bobMap[curr] > t) {
                income += amount[curr];
            } else if(t == bobMap[curr]) {
                income += (amount[curr])/2;
            }

            if(adj[curr].size() == 1 && curr != 0) {
                aliceIncome = max(aliceIncome, income);
            }

            for(int &ngbr : adj[curr]) {
                if(!visited[ngbr]) {
                    que.push({ngbr, t+1, income});
                }
            }

            visited[curr] = true;
        }

        return aliceIncome;
    }
};



/****************************************************************** C++ ******************************************************************/
//Approach-1 (DFS for Bob and DFS for Alice)
//T.C : O(n)
//S.C : O(n)
class Solution {
    Map<Integer, List<Integer>> adj = new HashMap<>();
    Map<Integer, Integer> bobMap = new HashMap<>();
    int aliceIncome;

    boolean DFSBob(int curr, int t, boolean[] visited) {
        visited[curr] = true;
        bobMap.put(curr, t);

        if (curr == 0) { // reached target
            return true;
        }

        for (int ngbr : adj.getOrDefault(curr, new ArrayList<>())) {
            if (!visited[ngbr]) {
                if (DFSBob(ngbr, t + 1, visited)) {
                    return true;
                }
            }
        }

        bobMap.remove(curr);
        return false;
    }

    void DFSAlice(int curr, int t, int income, boolean[] visited, int[] amount) {
        visited[curr] = true;

        if (!bobMap.containsKey(curr) || t < bobMap.get(curr)) {
            income += amount[curr];
        } else if (t == bobMap.get(curr)) {
            income += (amount[curr] / 2);
        }

        if (adj.getOrDefault(curr, new ArrayList<>()).size() == 1 && curr != 0) { // leaf node
            aliceIncome = Math.max(aliceIncome, income);
        }

        /*
            {1} -> (2, 3)
            2 -> 1
            3 -> 1,....
            (1) ---- (2)
             |
             |
             (3)------.....
        */

        for (int ngbr : adj.getOrDefault(curr, new ArrayList<>())) {
            if (!visited[ngbr]) {
                DFSAlice(ngbr, t + 1, income, visited, amount);
            }
        }
    }

    public int mostProfitablePath(int[][] edges, int bob, int[] amount) {
        int n = amount.length; // n nodes (0 to n-1)
        aliceIncome = Integer.MIN_VALUE;

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }

        // DFS on Bob for finding time to reach each node till 0
        int time = 0;
        boolean[] visited = new boolean[n];
        DFSBob(bob, time, visited);

        int income = 0;
        Arrays.fill(visited, false);
        DFSAlice(0, 0, income, visited, amount);

        return aliceIncome;
    }
}


//Approach-2 (DFS for Bob and BFS for Alice)
//T.C : O(n)
//S.C : O(n)
class Solution {
    Map<Integer, List<Integer>> adj = new HashMap<>();
    Map<Integer, Integer> bobMap = new HashMap<>();
    int aliceIncome;

    boolean DFSBob(int curr, int t, boolean[] visited) {
        visited[curr] = true;
        bobMap.put(curr, t);

        if (curr == 0) { // reached target
            return true;
        }

        for (int ngbr : adj.getOrDefault(curr, new ArrayList<>())) {
            if (!visited[ngbr]) {
                if (DFSBob(ngbr, t + 1, visited)) {
                    return true;
                }
            }
        }

        bobMap.remove(curr);
        return false;
    }

    public int mostProfitablePath(int[][] edges, int bob, int[] amount) {
        int n = amount.length; // n nodes (0 to n-1)
        aliceIncome = Integer.MIN_VALUE;

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }

        // DFS on Bob for finding time to reach each node till 0
        int time = 0;
        boolean[] visited = new boolean[n];
        DFSBob(bob, time, visited);

        int income = 0;
        Arrays.fill(visited, false);

        // BFS se karunga
        Queue<int[]> que = new LinkedList<>();
        // {node, time, income}
        que.add(new int[]{0, 0, 0});

        while (!que.isEmpty()) {
            int[] front = que.poll();
            int curr = front[0];
            int t = front[1];
            int inc = front[2];

            if (!bobMap.containsKey(curr) || bobMap.get(curr) > t) {
                inc += amount[curr];
            } else if (t == bobMap.get(curr)) {
                inc += (amount[curr] / 2);
            }

            if (adj.getOrDefault(curr, new ArrayList<>()).size() == 1 && curr != 0) {
                aliceIncome = Math.max(aliceIncome, inc);
            }

            for (int ngbr : adj.getOrDefault(curr, new ArrayList<>())) {
                if (!visited[ngbr]) {
                    que.add(new int[]{ngbr, t + 1, inc});
                }
            }

            visited[curr] = true;
        }

        return aliceIncome;
    }
}
