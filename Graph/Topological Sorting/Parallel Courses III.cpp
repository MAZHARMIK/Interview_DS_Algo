/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=743cYtf3DJI
    Company Tags                : Uber
    Leetcode Link               : https://leetcode.com/problems/parallel-courses-iii/
*/

/****************************************************** C++ ******************************************************/
//Approach-1 (Using Simple Topological sorting)
//T.C : O(V+E)
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);
        
        for(auto &vec : relations) {
            int u = vec[0] - 1;
            int v = vec[1] - 1;
            
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> que;
        vector<int> maxTime(n, 0); //maxTime[i] = maximum time taken by ith course to complete
        
        for(int i = 0; i<n; i++) {
            if(indegree[i] == 0) {
                que.push(i);
                maxTime[i] = time[i];
            }
        }
        
        while(!que.empty()) {
            
            int u = que.front();
            que.pop();
            
            for(int &v : adj[u]) {
                //Finishing time of v will depend on the maximum time of its pre-requisites
                maxTime[v] = max(maxTime[v], maxTime[u] + time[v]);
                indegree[v]--;
                if(indegree[v] == 0) {
                    que.push(v);
                }   
            }
        }
        
        return *max_element(begin(maxTime), end(maxTime));
    }
};

//Approach-2 (Using DFS Topological Sort) - Soon I will update here



/****************************************************** JAVA ******************************************************/
//Approach-1 (Using Simple Topological sorting)
//T.C : O(V+E)
class Solution {
    public int minimumTime(int n, int[][] relations, int[] time) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        int[] indegree = new int[n];
        int[] maxTime = new int[n];
        
        for (int[] vec : relations) {
            int u = vec[0] - 1;
            int v = vec[1] - 1;
            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            indegree[v]++;
        }
        
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                queue.offer(i);
                maxTime[i] = time[i];
            }
        }
        
        while (!queue.isEmpty()) {
            int u = queue.poll();
            List<Integer> neighbors = adj.getOrDefault(u, new ArrayList<>());
            for (int v : neighbors) {
                maxTime[v] = Math.max(maxTime[v], maxTime[u] + time[v]);
                indegree[v]--;
                if (indegree[v] == 0) {
                    queue.offer(v);
                }
            }
        }
        
        int result = 0;
        for (int i = 0; i < n; i++) {
            result = Math.max(result, maxTime[i]);
        }
        
        return result;
    }
}


//Approach-2 (Using DFS Topological Sort) - Soon I will update here
