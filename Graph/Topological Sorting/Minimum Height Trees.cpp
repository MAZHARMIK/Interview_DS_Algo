/*   Scroll down to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ZXANlaEuYvQ
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/minimum-height-trees/
*/

//NOTE : You can do a brute force to do DFS from each node treating them as root and keep finding the Height in every case. That will give TLE.

/**************************************************** C++ ********************************************/
//Using Topological Sorting
//T.C : O(V+E)
//S.C : O(V+E)
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
            return {0};
        
        vector<int> result;
        vector<int> indegree(n);
        map<int, vector<int>> adj;
        
        for(vector<int> vec:edges) {
            int u = vec[0];
            int v = vec[1];
            indegree[u]++;
            indegree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<int> que;
        for(int i = 0; i<n; i++) {
            if(indegree[i] == 1) //adding all leafs node so that we can remove them later
                que.push(i);
        }
        
        while(n > 2) {
            int size = que.size();
            n -= size; //removing nodes with indegreee 1
            
            while(size--) {
                int u = que.front();
                que.pop();
                for(int v:adj[u]) {
                    indegree[v]--;
                    if(indegree[v] == 1)
                        que.push(v);
                }
            }
        }
        
        while(!que.empty()) {
            result.push_back(que.front());
            que.pop();
        }
        return result;
    }
};



/**************************************************** JAVA **********************************************/
//Using Topological Sorting
//T.C : O(V+E)
//S.C : O(V+E)
class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        if (n == 1)
            return Collections.singletonList(0);
        
        List<Integer> result = new ArrayList<>();
        int[] indegree = new int[n];
        Map<Integer, List<Integer>> adj = new HashMap<>();
        
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            indegree[u]++;
            indegree[v]++;
            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }
        
        Queue<Integer> que = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 1) // adding all leaf nodes so that we can remove them later
                que.offer(i);
        }
        
        while (n > 2) {
            int size = que.size();
            n -= size; // removing nodes with indegree 1
            
            while (size-- > 0) {
                int u = que.poll();
                for (int v : adj.getOrDefault(u, Collections.emptyList())) {
                    indegree[v]--;
                    if (indegree[v] == 1)
                        que.offer(v);
                }
            }
        }
        
        while (!que.isEmpty()) {
            result.add(que.poll());
        }
        return result;
    }
}
