/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=7wGJ1nevpnc
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
*/

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> indegree(n, false);
        
        for(auto &edge : edges) {
            
            int u = edge[0];
            int v = edge[1];
            
            indegree[v] = true;
        }
        
        vector<int> result;
        
        for(int i = 0; i<n; i++) {
            if(indegree[i] == false)
                result.push_back(i);
        }
        
        return result;
    }
};
