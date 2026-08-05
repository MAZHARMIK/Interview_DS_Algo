/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/remove-methods-from-project/description/
*/


/****************************************************************** C++ ******************************************************************/
//Approach-1 - Using BFS
//T.C : O(V+E) , V = number of nodes(methods), E = number of edges
//S.C : O(V+E), V = number of nodes(methods), E = number of edges
class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        //O(V+E), V = nodes , E = edges
        //graph - adjacency list
        vector<vector<int>> adj(n); //u -> {ngbr1, ngbr2} //O(V+E)
        vector<int> inDegree(n, 0); //O(V)
        vector<bool> suspicious(n, false);//O(V)

        for(auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        //BFS
        queue<int> que;
        que.push(k);
        suspicious[k] = true;

        while(!que.empty()) {
            int curr = que.front();
            que.pop();

            for(int &ngbr : adj[curr]) {
                inDegree[ngbr]--;
                if(!suspicious[ngbr]) {
                    que.push(ngbr);
                    suspicious[ngbr] = true;
                }
            }
        }

        vector<int> result;
        bool cannotRemove = false;
        
        for(int i = 0; i < n; i++) {
            if(suspicious[i] && inDegree[i] > 0) {
                cannotRemove = true;
                break;
            }

            if(!suspicious[i]) {
                result.push_back(i);
            }

        }

        if(cannotRemove) {
            vector<int> vec(n); //0, 1, 2,... n-1
            for(int i = 0; i < n; i++) {
                vec[i] = i;
            }
            return vec;
        }
        
        return result;


    }
};


//Approach-2 - Using DFS
//T.C : O(V+E) , V = number of nodes(methods), E = number of edges
//S.C : O(V+E), V = number of nodes(methods), E = number of edges
class Solution {
public:
    void dfs(int curr, vector<vector<int>>& adj, vector<int>& inDegree, vector<bool>& suspicious) {
        suspicious[curr] = true;
        for(int &ngbr : adj[curr]) {
            inDegree[ngbr]--;
            if(!suspicious[ngbr]) {
                dfs(ngbr, adj, inDegree, suspicious);
            }
        }
    }
    
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        //O(V+E), V = nodes , E = edges
        //graph - adjacency list
        vector<vector<int>> adj(n); //u -> {ngbr1, ngbr2} //O(V+E)
        vector<int> inDegree(n, 0); //O(V)
        vector<bool> suspicious(n, false);//O(V)
        for(auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }
        //DFS
        dfs(k, adj, inDegree, suspicious);
        
        vector<int> result;
        bool cannotRemove = false;
        
        for(int i = 0; i < n; i++) {
            if(suspicious[i] && inDegree[i] > 0) {
                cannotRemove = true;
                break;
            }
            if(!suspicious[i]) {
                result.push_back(i);
            }
        }
        if(cannotRemove) {
            vector<int> vec(n); //0, 1, 2,... n-1
            for(int i = 0; i < n; i++) {
                vec[i] = i;
            }
            return vec;
        }
        
        return result;
    }
};



/****************************************************************** JAVA ******************************************************************/
//Approach-1 - Using BFS
//T.C : O(V+E) , V = number of nodes(methods), E = number of edges
//S.C : O(V+E), V = number of nodes(methods), E = number of edges
class Solution {
    public List<Integer> remainingMethods(int n, int k, int[][] invocations) {
        //O(V+E), V = nodes , E = edges
        //graph - adjacency list
        List<List<Integer>> adj = new ArrayList<>(); //u -> {ngbr1, ngbr2} //O(V+E)
        for(int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        int[] inDegree = new int[n];        //O(V)
        boolean[] suspicious = new boolean[n]; //O(V)

        for(int[] edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            adj.get(u).add(v);
            inDegree[v]++;
        }

        //BFS
        Queue<Integer> que = new LinkedList<>();
        que.offer(k);
        suspicious[k] = true;

        while(!que.isEmpty()) {
            int curr = que.poll();

            for(int ngbr : adj.get(curr)) {
                inDegree[ngbr]--;
                if(!suspicious[ngbr]) {
                    que.offer(ngbr);
                    suspicious[ngbr] = true;
                }
            }
        }

        List<Integer> result = new ArrayList<>();
        boolean cannotRemove = false;

        for(int i = 0; i < n; i++) {
            if(suspicious[i] && inDegree[i] > 0) {
                cannotRemove = true;
                break;
            }

            if(!suspicious[i]) {
                result.add(i);
            }
        }

        if(cannotRemove) {
            List<Integer> vec = new ArrayList<>(); //0, 1, 2,... n-1
            for(int i = 0; i < n; i++) {
                vec.add(i);
            }
            return vec;
        }

        return result;
    }
}


//Approach-2 - Using DFS
//T.C : O(V+E) , V = number of nodes(methods), E = number of edges
//S.C : O(V+E), V = number of nodes(methods), E = number of edges
class Solution {
    public void dfs(int curr, List<List<Integer>> adj, int[] inDegree, boolean[] suspicious) {
        suspicious[curr] = true;
        for(int ngbr : adj.get(curr)) {
            inDegree[ngbr]--;
            if(!suspicious[ngbr]) {
                dfs(ngbr, adj, inDegree, suspicious);
            }
        }
    }

    public List<Integer> remainingMethods(int n, int k, int[][] invocations) {
        //O(V+E), V = nodes , E = edges
        //graph - adjacency list
        List<List<Integer>> adj = new ArrayList<>(); //u -> {ngbr1, ngbr2} //O(V+E)
        for(int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        int[] inDegree = new int[n];        //O(V)
        boolean[] suspicious = new boolean[n]; //O(V)

        for(int[] edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            adj.get(u).add(v);
            inDegree[v]++;
        }

        //DFS
        dfs(k, adj, inDegree, suspicious);

        List<Integer> result = new ArrayList<>();
        boolean cannotRemove = false;

        for(int i = 0; i < n; i++) {
            if(suspicious[i] && inDegree[i] > 0) {
                cannotRemove = true;
                break;
            }
            if(!suspicious[i]) {
                result.add(i);
            }
        }

        if(cannotRemove) {
            List<Integer> vec = new ArrayList<>(); //0, 1, 2,... n-1
            for(int i = 0; i < n; i++) {
                vec.add(i);
            }
            return vec;
        }

        return result;
    }
}
