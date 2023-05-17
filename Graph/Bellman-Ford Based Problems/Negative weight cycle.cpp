/*
    MY YOUTUBE VIDEO ON THIS Qn : <soon>
    Company Tags                : Amazon, Microsoft, Cisco (Generally asked as a follow up qn of Dijkstra's Algorithm)
    GfG Link                    : https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1
*/

class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int> result(n, 1e8);
        
        for(int c = 1; c<=n; c++) {
            
            for(auto &edge : edges) {
                
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if(result[u] + w < result[v]) {
                    if(c == n)
                        return 1;
                    result[v] = result[u] + w;
                }
                
            }
            
        }
        
        return 0;
	}
};
