/*
      MY YOUTUBE VIDEO ON THIS Qn : 
      Company Tags                : GOOGLE
      Leetcode Link               : https://leetcode.com/problems/shortest-path-visiting-all-nodes/
*/

/********************************************************* C++ *******************************************************/
class Solution {
public:
    
    typedef pair<int, int> P;
    
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        
        if(n == 1 || n == 0)
            return 0;
        
        queue<P> que;
        
        set<P> vis;
        //Instead of set, you can also use : vector<vector<bool>> visited(n, vector<bool>(finalState, false));
        //Just like done in Java code below

        int allVisitedState = (1 << n) - 1; // if all nodes visited then
            
        for(int i = 0; i < n; i++) {
            int maskValue = (1 << i);
            
            que.push({i, maskValue});
            
            vis.insert({i, maskValue});
        }
        
        int result = 0;
        
        // Implementing BFS
        while(!que.empty())  {
            
            int N = que.size();
            result++;
            while(N--) {
                
                auto curr = que.front();
                que.pop();
                
                int currNode = curr.first;
                int currMask = curr.second;
                
                for(auto &adj: graph[currNode]) {
                    int nextMask = currMask | (1 << adj);
                    
                    if(nextMask == allVisitedState)
                        return result;
                    
                    if(vis.find({adj, nextMask}) == vis.end()) {
                        vis.insert({adj, nextMask});
                        que.push({adj, nextMask});                      
                    }
                }  
            }
        }

        return -1;
    }
};


/********************************************************* JAVA *******************************************************/
class Solution {
	public int shortestPathLength(int[][] graph) {
        int n = graph.length;
        
		if(n == 1 || n == 0)
			return 0;
        
        int allVisitedState = (1 << n) - 1;
        Queue<int []> que = new LinkedList<>();
        
		int [][] visited = new int [n][allVisitedState+1];

		for(int i=0; i<graph.length; i++) {
			que.add(new int [] {i, 1 << i});
            visited[i][(1 << i)] = 1;  
		}



		int shortestPath = 0;
		while(!que.isEmpty()){
			int size = que.size();
			shortestPath++;
			for(int i=0; i<size; i++){
                
				int [] curr  = que.poll();
				int currNode = curr[0];
				int currMask = curr[1];
                
				for(int adj : graph[currNode]){
					int nextMask = currMask | (1 << adj);

					if(visited[adj][nextMask] == 1)
                        continue;
                    
                    if(nextMask == allVisitedState)
						return shortestPath;
                    
                    visited[adj][nextMask] = 1;
					que.add(new int [] {adj, nextMask});
				}
			}
		}
		return -1;
	}
}
