/*   Scroll down to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/freedom-trail
*/


//Approach-1 (Recursion  + Memoization)
//T.C : Without Memoization : O(n^m), where n is the length of the ring string and m is the length of the key string. This is because for each character in the key, 
                             //the algorithm will explore all possible positions in the ring string recursively, without reusing any previous results.
        //With Memoization  : O(n^2 * m)
//S.C : O(101*101) ~ O(1)
class Solution {
public:
    int t[101][101];
    
    int countSteps(int curr, int next, int ringLength) {
        int stepsBetween = abs(curr - next);
        int stepsAround = ringLength - stepsBetween;
        return min(stepsBetween, stepsAround);
    }
    
    int solve(int ringIndex, int keyIndex, string& ring, string& key) {
        
        if (keyIndex == key.length()) {
            return 0;
        }
        
        if(t[ringIndex][keyIndex] != -1) {
            return t[ringIndex][keyIndex];
        }
        
        int result = INT_MAX;
        for (int i = 0; i < ring.length(); i++) {
            if (ring[i] == key[keyIndex]) {
                int totalSteps = countSteps(ringIndex, i, ring.length()) + 1 +
                                            solve(i, keyIndex + 1, ring, key);
                result = min(result, totalSteps);
            }
        }
        
        return t[ringIndex][keyIndex] = result;
    }
    
    int findRotateSteps(string ring, string key) {
        memset(t, -1, sizeof(t));
        return solve(0, 0, ring, key);
    }
};


//Approach-2 (Bottom Up)
//T.C : 
//S.C : 
