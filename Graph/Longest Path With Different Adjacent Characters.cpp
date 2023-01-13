/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=EA8dP63iVPk
    Company Tags                : Microsoft
    Leetcode Link               : https://leetcode.com/problems/longest-path-with-different-adjacent-characters/ 
    Similar Qn in Tree          : Binary Tree Maximum Path Sum - YouTube  : https://www.youtube.com/watch?v=Op6YFcs8R9M
                                                                 Leetcode : https://leetcode.com/problems/binary-tree-maximum-path-sum/
*/


//DFS - (Similar to Binary Tree Maximum Path Sum)
class Solution {
public:
    
    int result;
    
    int DFS(unordered_map<int, vector<int>> &adj, int curr, int parent, string& s) {
        
        int longest = 0;
        int second_longest = 0;
        
        for(int &child : adj[curr]) {
            if(child == parent)
                continue;
            
            int child_longest_length = DFS(adj, child, curr, s);
            
            if(s[child] == s[curr])
                continue;
            
            if(child_longest_length > second_longest)
                second_longest = child_longest_length;
            
            if(second_longest > longest)
                swap(longest, second_longest);
        }
        
        int koi_ek_acha     = max(longest, second_longest) + 1; //Why this 1 ? Because including the curr node itself
        
        int only_root_acha  = 1; //only curr node is valid, rest children have duplicate character
        
        int neeche_hi_milgaya_answer = longest + second_longest + 1;
        
        
        
        result = max({result, neeche_hi_milgaya_answer, koi_ek_acha, only_root_acha});
        
        return max(koi_ek_acha, only_root_acha);
        
    }
    
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        result = 0;
        unordered_map<int, vector<int>> adj;
        
        for(int i = 1; i<n; i++) {
            int u = i;
            int v = parent[i];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        DFS(adj, 0, -1, s);
        
        return result;
    }
};
