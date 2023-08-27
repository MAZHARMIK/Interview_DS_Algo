/*
      MY YOUTUBE VIDEO ON THIS Qn : 
      Company Tags                : 
      Leetcode Link               : 
*/

**************************************** C++ ****************************************
//Approach-1 (Recursion + Memo) - T.C : O(N^2)
class Solution {
public:
    int n;
    unordered_map<int, int> mp;
    int t[2001][2001];
    
    bool solve(vector<int>& stones, int curr_stone_position, int prevJump) {
        if(curr_stone_position == n-1)
            return true;
        
        bool result = false;
        
        if(t[curr_stone_position][prevJump] != -1)
            return t[curr_stone_position][prevJump];
        
        for(int nextJump = prevJump-1; nextJump <= prevJump+1; nextJump++) {
            
            if(nextJump > 0) {
                int next_stone_position = stones[curr_stone_position] + nextJump;
                
                if(mp.find(next_stone_position) != mp.end()) {
                    result = result || solve(stones, mp[next_stone_position], nextJump);
                }
            }
            
        }
        
        return t[curr_stone_position][prevJump] = result;
        
    }
    
    bool canCross(vector<int>& stones) {
        
        if(stones[1] != 1)
            return false;
        
        n = stones.size();
        for(int i = 0; i<n; i++) {
            mp[stones[i]] = i;
        }
        
        memset(t, -1, sizeof(t));
        
        return solve(stones, 0, 0);
    }
};

//Approach-2 (Soon comming - BOTTOM UP)


**************************************** JAVA ****************************************
//Approach-1 (Recursion + Memo) - T.C : O(N^2)
class Solution {
    HashMap<Integer, Integer> mp = new HashMap<>();
    int t[][] = new int[2001][2001];
    int n;
    
    boolean solve(int[] stones, int curr_stone_position, int prevJump) {

        if (curr_stone_position == n - 1) {
            return true;
        }
        
        // If this subproblem has already been calculated, return it.
        if (t[curr_stone_position][prevJump] != -1) {
            return t[curr_stone_position][prevJump] == 1;
        }
        
        boolean result = false;
        
        for(int nextJump = prevJump-1; nextJump <= prevJump+1; nextJump++) {
            
            if(nextJump > 0) {
                int next_stone_position = stones[curr_stone_position] + nextJump;
                
                if(mp.containsKey(next_stone_position)) {
                    result = result || solve(stones, mp.get(next_stone_position), nextJump);
                }
            }
            
        }

        
        t[curr_stone_position][prevJump] = (result ? 1 :0);
        return result;
    }
    
    public boolean canCross(int[] stones) {
        n = stones.length;
        if(stones[1] != 1)
            return false;
        
        for (int i = 0 ; i < stones.length; i++) {
            mp.put(stones[i], i);
        }
        
        //Mark all states as -1 to denote they're not calculated.
        for (int i = 0; i < 2000; i++) {
            Arrays.fill(t[i], -1);
        }
        
        return solve(stones, 0, 0);
    }
}
