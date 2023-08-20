/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Uu03ktYBWMY
      Company Tags                : <Soon>
      Leetcode Link               : https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/
*/


/*
Time Complexity - 
We fill the itemGraph and groupGraphs by traversing on each item and beforeItems causing O(n^2) in worst case. 
After that, Since we call Topological Sort for : 
1) itemGraph - O(n + edges) 
2) Group Graph - O(m + edges) 

Then, we run for loop ok itemOrder - O(n) 
Then we run for loop on groupOrder - O(m) 
Then at the end we make result - O(n)
After summing up all, the biggest term is O(n^2) 
Hence worst case TC = O(n^2) Hope this helps. 
I will definitely cover TC in my videos further Thanks a lot ❤️😇
*/
**************************************** C++ ****************************************
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


**************************************** JAVA ****************************************
class Solution {
    public int[] sortItems(int n, int m, int[] group, List<List<Integer>> beforeItems) {
        
        //Starting steps (assigning groups to loners)
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                group[i] = m++;
            }
        }
        
        //Step-1 (Make itemGraph and itemIndegree)
        Map<Integer, List<Integer>> itemGraph = new HashMap<>();
        int[] itemIndegree = new int[n];
        for (int i = 0; i < n; ++i) {
            itemGraph.put(i, new ArrayList<>());
        }
        
        //Step-2 (Make groupGraph and groupIndegree)
        Map<Integer, List<Integer>> groupGraph = new HashMap<>();
        int[] groupIndegree = new int[m];
        for (int i = 0; i < m; ++i) {
            groupGraph.put(i, new ArrayList<>());
        }
        
        //Fill those graphs and indegrees
        for (int i = 0; i < n; i++) {
            
            for (int prev : beforeItems.get(i)) {
                
                itemGraph.get(prev).add(i);
                itemIndegree[i]++;
                
                if (group[i] != group[prev]) {
                    int prevItemGroup = group[prev];
                    int currItemGroup = group[i];
                    
                    groupGraph.get(prevItemGroup).add(currItemGroup);  //prevItemGroup ----> currItemGroup
                    groupIndegree[currItemGroup]++;
                }
                
            }
        }
        
        //step - TopoSort call
        List<Integer> itemOrder  = topoSort(itemGraph, itemIndegree);
        List<Integer> groupOrder = topoSort(groupGraph, groupIndegree);
        

        Map<Integer, List<Integer>> groupToItemsInOrder = new HashMap<>();
        for (Integer item : itemOrder) {
            int itemGroup = group[item];
            groupToItemsInOrder.computeIfAbsent(itemGroup, k -> new ArrayList<>()).add(item);
        }
        
        List<Integer> answerList = new ArrayList<>();
        for (int groupIndex : groupOrder) {
            answerList.addAll(groupToItemsInOrder.getOrDefault(groupIndex, new ArrayList<>()));
        }
        
        return answerList.stream().mapToInt(Integer::intValue).toArray();
    }
    
    private List<Integer> topoSort(Map<Integer, List<Integer>> adj, int[] indegree) {
        
        Queue<Integer> que = new LinkedList<>();
        for (int i = 0;i<indegree.length;i++) {
            if (indegree[i] == 0) {
                que.add(i);
            }
        }
        
        List<Integer> result = new ArrayList<>();
        while (!que.isEmpty()) {
            Integer curr = que.remove();
            result.add(curr);
            
            for (Integer v : adj.get(curr)) {
                indegree[v]--;
                
                if (indegree[v] == 0) {
                    que.add(v);
                }
            }
        }

        return result.size() == adj.size() ? result : new ArrayList<>();
    }
}
