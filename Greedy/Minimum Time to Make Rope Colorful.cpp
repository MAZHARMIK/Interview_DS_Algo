/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=_xNrzKfORNA
    Company Tags                : <soon will update>
    Leetcode Link               : https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
*/

/************************************************************************ C++ ************************************************************************************/
//Approach - Greedily moving ahead
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        
        int time    = 0;
        int prevMax = 0;
        
        for(int i = 0; i<n; i++) {
            
            if(i > 0 && colors[i] != colors[i-1]) {
                prevMax = 0;
            }
            
            
            
            int curr = neededTime[i];
            
            time += min(prevMax, curr); //greedily
            
            prevMax = max(prevMax, curr);
            
        }
        
        return time;
    }
};



/************************************************************************ JAVA ************************************************************************************/
//Approach - Greedily moving ahead
//T.C : O(n)
//S.C : O(1)
public class Solution {
    public int minCost(String colors, int[] neededTime) {
        int n = colors.length();
        
        int time = 0;
        int prevMax = 0;
        
        for (int i = 0; i < n; i++) {
            
            if (i > 0 && colors.charAt(i) != colors.charAt(i - 1)) {
                prevMax = 0;
            }

            int curr = neededTime[i];
            
            // Greedily select the minimum between prevMax and curr
            time += Math.min(prevMax, curr);
            
            // Update prevMax to the maximum between prevMax and curr
            prevMax = Math.max(prevMax, curr);
        }
        
        return time;
    }
}
