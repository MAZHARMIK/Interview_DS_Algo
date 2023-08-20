/*
      MY YOUTUBE VIDEO ON THIS Qn : 
      Company Tags                : <Soon>
      Leetcode Link               : https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/
*/

//Using Topological sort of items and groups
class Solution {
public:
    vector<int> topoSort(unordered_map<int, vector<int>>& adj, vector<int>& indegree)  {
	    queue<int> que;

	    //1. Fill que, indegree with 0
	    for(int i = 0; i < adj.size(); i++) {
	        if(indegree[i] == 0) {
	            que.push(i);
	        }
	    }
	    
	    //2. Simple BFS
	    vector<int> result;
	    while(!que.empty()) {
	        int u = que.front();
	        result.push_back(u);
	        que.pop();
	        
	        for(int &v : adj[u]) {
	            indegree[v]--;
	            
	            if(indegree[v] == 0) {
	                que.push(v);
	            }
	            
	        }
	    }
	    
	    return result.size() == adj.size() ? result : vector<int>();
	}
    
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {

        //Step-1 (assign group numbers to all)
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                group[i] = m++;
            }
        }
        
        //Step-2 (Make itemGraph and itemIndegree) - For Topological Sorting
        unordered_map<int, vector<int>> itemGraph;
        vector<int> itemIndegree(n, 0);
        for (int i = 0; i < n; ++i) {
            itemGraph[i] = vector<int>();
        }
        
        //Step-3 (Make groupGraph and groupIndegree) - For Topological Sorting
        unordered_map<int, vector<int>> groupGraph;
        vector<int> groupIndegree(m, 0);
        for (int i = 0; i < m; ++i) {
            groupGraph[i] = vector<int>();
        }
        
        //Step-4 (Fill itemGraph, itemIndegree, groupGraph, groupIndegree)
        
        for (int i = 0; i < n; i++) {
            
            for (int prev : beforeItems[i]) {
                
                itemGraph[prev].push_back(i);
                itemIndegree[i]++;
                
                if (group[i] != group[prev]) {
                    int prevItemGroup = group[prev];
                    int currItemGroup = group[i];
                    
                    groupGraph[prevItemGroup].push_back(currItemGroup);
                    groupIndegree[currItemGroup]++;
                }
            }
        }
        
        //Step-5 (Call TopoSort for both Graphs)
        vector<int> itemOrder  = topoSort(itemGraph, itemIndegree);
        vector<int> groupOrder = topoSort(groupGraph, groupIndegree);
        
        if (itemOrder.empty() || groupOrder.empty()) {
            return vector<int>();
        }
        
        unordered_map<int, vector<int>> groupToItemsInOrder;
        for (int item : itemOrder) {
            int itemGroup = group[item];
            groupToItemsInOrder[itemGroup].push_back(item);
        }
        
        vector<int> result;
        for (int group : groupOrder) {
            result.insert(result.end(), groupToItemsInOrder[group].begin(), groupToItemsInOrder[group].end());
        }
        
        return result;
    }
};
