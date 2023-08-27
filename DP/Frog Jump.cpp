/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=l9E-ZcbFhDg
      Company Tags                : Amazon, Google, Meta
      Leetcode Link               : https://leetcode.com/problems/frog-jump/
*/

**************************************** C++ ****************************************
//Approach-1 (Recursion + Memo) - T.C : O(N^2)
class Solution {
public:
    int n;
    unordered_map<int, int> mp;
    int t[2001][2001];
    
    bool solve(vector<int>& stones, int curr_stone_index, int prevJump) {
        if(curr_stone_index == n-1)
            return true;
        
        bool result = false;
        
        if(t[curr_stone_index][prevJump] != -1)
            return t[curr_stone_index][prevJump];
        
        for(int nextJump = prevJump-1; nextJump <= prevJump+1; nextJump++) {
            
            if(nextJump > 0) {
                int next_stone = stones[curr_stone_index] + nextJump;
                
                if(mp.find(next_stone) != mp.end()) {
                    result = result || solve(stones, mp[next_stone], nextJump);
                }
            }
            
        }
        
        return t[curr_stone_index][prevJump] = result;
        
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
    boolean solve(int[] stones, int curr_stone_index, int prevJump) {
        if(curr_stone_index == n-1)
            return true;
        
        boolean result = false;
        
        if(t[curr_stone_index][prevJump] != -1)
            return t[curr_stone_index][prevJump] == 1;
        
        for(int nextJump = prevJump-1; nextJump <= prevJump+1; nextJump++) {
            
            if(nextJump > 0) {
                int next_stone = stones[curr_stone_index] + nextJump;
                
                if(mp.containsKey(next_stone)) {
                    result = result || solve(stones, mp.get(next_stone), nextJump);
                }
            }
            
        }
        
        t[curr_stone_index][prevJump] = (result ? 1 :0);
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
