/*    Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn  : https://www.youtube.com/watch?v=11lCatB_H_A
    Company Tags                 : Google
    Leetcode Link                : https://leetcode.com/problems/power-of-three/description
*/


/********************************************************************* C++ *********************************************************************/
//Approach-1 (simply dividing and checking iteratively)
//T.C : O(log3(n))
//S.C : O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) {
            return false;
          
        while(n%3 == 0) {
            n /= 3;
        }
          
        return n == 1;  
    }
};


//Approach-2 (simply dividing and checking recursively)
//T.C : O(log3(n))
//S.C : O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) {
            return false;
        }
        else if(n == 1) {
            return true;
        }
        return n%3 == 0 && isPowerOfThree(n/3);  
    }
};



//Approach-3 (simply checking with largest valid power of 3)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
        //NOTE :  3^19 = 1162261467
    }
};



//Approach-4 (Using logarithms and checking if log base 3 of n is an integer)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }

        double logValue = log10(n) / log10(3);

        // Check if logValue is an integer
        return logValue == (int)logValue;
    }
};



/********************************************************************* JAVA *********************************************************************/
//Approach-1 (simply dividing and checking iteratively)
//T.C : O(log3(n))
//S.C : O(1)
class Solution {
    public boolean isPowerOfThree(int n) {
        if (n == 0) {
            return false;
        }
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
}



//Approach-2 (simply dividing and checking recursively)
//T.C : O(log3(n))
//S.C : O(1)
class Solution {
    public boolean isPowerOfThree(int n) {
        if (n == 0) {
            return false;
        } else if (n == 1) {
            return true;
        }
        return n % 3 == 0 && isPowerOfThree(n / 3);
    }
}




//Approach-3 (simply checking with largest valid power of 3)
//T.C : O(1)
//S.C : O(1)
class Solution {
    public boolean isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
        //NOTE :  3^19 = 1162261467
    }
}


//Approach-4 (Using logarithms and checking if log base 3 of n is an integer)
//T.C : O(1)
//S.C : O(1)
class Solution {
    public boolean isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }

        double logValue = Math.log10(n) / Math.log10(3);

        // Check if logValue is an integer
        return logValue == (int)logValue;
    }
}
