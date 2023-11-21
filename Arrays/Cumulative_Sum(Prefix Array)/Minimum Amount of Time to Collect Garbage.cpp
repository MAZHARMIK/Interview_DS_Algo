/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=SGJMTu9SZHs
    Company Tags                : MICROSOFT
    Leetcode Link               : https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/
*/

/********************************************************** C++ **********************************************************/
//Approach (Using Simple counting and prefix sum for travel array)
//T.C : O(n*10) ~ O(n) because size of garbage[i] will be at most 10 as mentioned in contraint
//S.C : O(1)
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int time = 0;
        
        int n = garbage.size();
        
        int G = 0;
        int M = 0;
        int P = 0;
        
        int total = 0;
        
        for(int i = 0; i < n; i++) {
            
            for(int j = 0; j < garbage[i].length(); j++) {
                
                if(garbage[i][j] == 'M') {
                    M =  i;
                } else if(garbage[i][j] == 'P') {
                    P = i;
                } else {
                    G = i;
                }
                
                total++;
            }
        }
        
        //Precompute the time
        for(int i = 1; i < travel.size(); i++) {
            travel[i] += travel[i-1];
        }
        
        total += M > 0 ? travel[M-1] : 0;
        total += P > 0 ? travel[P-1] : 0;
        total += G > 0 ? travel[G-1] : 0;
        
        return total;
        
    }
};


/********************************************************** JAVA **********************************************************/
//Approach (Using Simple counting and prefix sum for travel array)
//T.C : O(n*10) ~ O(n) because size of garbage[i] will be at most 10 as mentioned in contraint
//S.C : O(1)
public class Solution {
    public int garbageCollection(String[] garbage, int[] travel) {
        int time = 0;

        int n = garbage.length;

        int G = 0;
        int M = 0;
        int P = 0;

        int total = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < garbage[i].length(); j++) {
                if (garbage[i].charAt(j) == 'M') {
                    M = i;
                } else if (garbage[i].charAt(j) == 'P') {
                    P = i;
                } else {
                    G = i;
                }
                total++;
            }
        }

        // Precompute the time
        for (int i = 1; i < travel.length; i++) {
            travel[i] += travel[i - 1];
        }

        total += M > 0 ? travel[M - 1] : 0;
        total += P > 0 ? travel[P - 1] : 0;
        total += G > 0 ? travel[G - 1] : 0;

        return total;
    }
}
