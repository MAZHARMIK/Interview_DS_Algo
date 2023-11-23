/*
    MY YOUTUBE VIDEO ON THIS Qn : https://youtu.be/CeO0JEX4QAc?si=lb-UpnVKDMZgr4-8 (Theory video - Just use the theory and this problem will be super easy)
    Company Tags                : Will update soon.
    GfG Link                    : https://www.geeksforgeeks.org/problems/euler-circuit-in-a-directed-graph/1
*/

/******************************************************** C++ ****************************************************************/
//T.C : O(V)
//S.C : O(1)
class Solution {
public:
	bool isEularCircuitExist(int V, vector<int>adj[]){
	    vector<int> degree(V, 0);
	    
	    for(int i = 0; i<V; i++) {
	        
	        degree[i] = adj[i].size();
	        
	    }
	    
	    for(int i = 0; i<V; i++) {
	        if(degree[i] % 2 != 0) {
	            return false;
	        }
	    }
	    
	    return true;
	}
};



/******************************************************** JAVA ****************************************************************/
//T.C : O(V)
//S.C : O(1)
public class Solution {
    public boolean isEularCircuitExist(int V, List<Integer>[] adj) {
        int[] degree = new int[V];

        for (int i = 0; i < V; i++) {
            degree[i] = adj[i].size();
        }

        for (int i = 0; i < V; i++) {
            if (degree[i] % 2 != 0) {
                return false;
            }
        }

        return true;
    }
}
