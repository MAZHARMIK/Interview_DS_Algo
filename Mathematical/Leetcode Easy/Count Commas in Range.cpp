/*    Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn  : 
    Company Tags                 : Will update later
    Leetcode Link                : https://leetcode.com/problems/count-commas-in-range
*/


/********************************************************************* C++ *********************************************************************/
//Approach-1 (Simple simulation)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int countCommas(int n) {
        int result = 0;
        for (int num = 1; num <= n; num++) {
            if (num > 999) {
                result += 1;
            }
        }

        return result;
    }
};



//Approach-2 (Simple observation)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    int countCommas(int n) {
        return max(n-999, 0);
    }
};



/********************************************************************* JAVA *********************************************************************/
//Approach-1 (Simple simulation)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int countCommas(int n) {
        int result = 0;
        for (int num = 1; num <= n; num++) {
            if (num > 999) {
                result += 1;
            }
        }

        return result;
    }
}

//Approach-2 (Simple observation)
//T.C : O(1)
//S.C : O(1)
class Solution {
    public int countCommas(int n) {
        return Math.max(n - 999, 0);
    }
}
