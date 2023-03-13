/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=0Z8lt7U_kiE
      Company Tags                : GOOGLE
      Leetcode Link               : https://leetcode.com/problems/satisfiability-of-equality-equations/
*/

class Solution {
public:
    
    vector<int> parent;
    vector<int> rank;
    
    int find(int i) {
        if(parent[i] != i)
            parent[i] = find(parent[i]);
        
        return parent[i];
    }
    
    void Union(int x, int y) {
        int p_x = find(x);
        int p_y = find(y);
        
        if(p_x != p_y) {
            if(rank[p_x] > rank[p_y]) {
                parent[p_y] = p_x;
            } else if(rank[p_y] > rank[p_x]) {
                parent[p_x] = p_y;
            } else {
                parent[p_x] = p_y;
                rank[p_y]++;
            }
        }
    }
    
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26);
        
        for(int i = 0; i<26; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
        
        for(string &s : equations) {
            if(s[1] == '=')
                Union(s[0]-'a', s[3]-'a');
        }
        
        for(string &s : equations) {
            if(s[1] == '!') {
                if(find(s[0]-'a') == find(s[3]-'a'))
                    return false;
            }
        }
        
        return true;
        
    }
};
