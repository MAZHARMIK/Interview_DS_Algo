/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=0pnrbej1_xM
    Company Tag                 : Directi
    Leetcode Link               : https://leetcode.com/problems/find-the-winner-of-an-array-game/
*/

/******************************************************** C++ ********************************************************/
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int maxEl = *max_element(begin(arr), end(arr));
        
        if(k >= n)
            return maxEl;
        
        
        int winner     = arr[0];
        int wins       = 0;
        
        for(int i = 1; i<n; i++) {
            
            if(winner > arr[i]) {
                wins++;
            } else {
                winner = arr[i];
                wins   = 1;
            }
            
            if(wins == k || winner == maxEl) {
                return winner;
            }
            
        }
        
        return winner;
        
    }
};



/******************************************************** JAVA ********************************************************/
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int getWinner(List<Integer> arr, int k) {
        int n = arr.size();
        int maxEl = arr.stream().mapToInt(Integer::intValue).max().orElse(Integer.MIN_VALUE);
        
        if(k >= n) {
            return maxEl;
        }
        
        int winner = arr.get(0);
        int wins = 0;
        
        for(int i = 1; i < n; i++) {
            if(winner > arr.get(i)) {
                wins++;
            } else {
                winner = arr.get(i);
                wins = 1;
            }
            
            if(wins == k || winner == maxEl) {
                return winner;
            }
        }
        
        return winner;
    }
}
