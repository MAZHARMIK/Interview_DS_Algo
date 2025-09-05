/*     Scroll below to see JAVA code    */
/*
    MY YOUTUBE VIDEO ON THIS Qn                : 
    Company Tags                               : will soon update
    Leetcode Link                              : https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/description/
    
*/

/****************************************************** C++ **************************************************************/
//Approach-1 - Maths derivation
//T.C : O(log(num1)) upper bound
//S.C : O(1)
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int t = 0;

        while(true) {
            long long val = (long long)num1 - (long long)t * num2;

            if(val < 0)
                return -1;
            
            if(__builtin_popcountll(val) <= t && t <= val) {
                return t;
            }

            t++;
        }

        return -1;
    }
};


//Approach-2 - Maths derivation and finding strict bound of t
//T.C : O(log(num1)) upper bound
//S.C : O(1)
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {

        for(int t = 1; t <= 36; t++) {
            long long val = (long long)num1 - (long long)t * num2;

            if(val < 0)
                return -1;
            
            if(__builtin_popcountll(val) <= t && t <= val) {
                return t;
            }
        }

        return -1;
    }
};




/****************************************************** JAVA **************************************************************/
//Approach-1 - Maths derivation
//T.C : O(log(num1)) upper bound
//S.C : O(1)
class Solution {
    public int makeTheIntegerZero(int num1, int num2) {
        int t = 0;

        while (true) {
            long val = (long) num1 - (long) t * num2;

            if (val < 0)
                return -1;

            // Integer.bitCount() gives popcount in Java
            if (Long.bitCount(val) <= t && t <= val) {
                return t;
            }

            t++;
        }
    }
}

//Approach-2 - Maths derivation and finding strict bound of t
//T.C : O(log(num1)) upper bound
//S.C : O(1)
class Solution {
    public int makeTheIntegerZero(int num1, int num2) {

        for (int t = 1; t <= 36; t++) {
            long val = (long) num1 - (long) t * num2;

            if (val < 0)
                return -1;

            if (Long.bitCount(val) <= t && t <= val) {
                return t;
            }
        }

        return -1;
    }
}
