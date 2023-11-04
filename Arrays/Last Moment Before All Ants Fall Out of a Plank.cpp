/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=JaJkEI-0zdI
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/
*/

/******************************************************** C++ **********************************************/
//T.C : O(m+n)
//S.C : O(1)
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int result = 0;
        
        for(int &x : left) {
            result = max(x, result);
        }
        
        for(int &x : right) {
            result = max(result, n-x);
        }
        
        return result;
    }
};


/******************************************************** JAVA **********************************************/
//T.C : O(m+n)
//S.C : O(1)
public class Solution {
    public int getLastMoment(int n, int[] left, int[] right) {
        int result = 0;

        for (int x : left) {
            result = Math.max(x, result);
        }

        for (int x : right) {
            result = Math.max(result, n - x);
        }

        return result;
    }
}



