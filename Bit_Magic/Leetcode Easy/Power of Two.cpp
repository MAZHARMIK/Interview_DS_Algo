/*                           Scroll down to see JAVA code also               */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=bVfA6_rDw4M
    Company Tags                : Google, Aodbe
    Leetcode Link               : https://leetcode.com/problems/power-of-two/
*/


/************************************************************************ C++ ************************************************************************/
//Approach-1 (Using normal division) - Can also wite iterative version
//T.C : O(log(n))
//S.C : O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        if(n == 1)
            return true;
        
        return n%2 == 0 && isPowerOfTwo(n/2);
    }
};

//Approach-2 (Using bit magic)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && ((n & (n - 1)) == 0);
    }
};

//Approach-2 (__builtin_popcount)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        
        return __builtin_popcount(n) == 1;
    }
};



/************************************************************************ JAVA ************************************************************************/
// Approach-1 (Using normal division) - Can also write iterative version
// T.C : O(log(n))
// S.C : O(1)
public class Solution {
    public boolean isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        if (n == 1)
            return true;

        return n % 2 == 0 && isPowerOfTwo(n / 2);
    }
}

// Approach-2 (Using bit magic)
// T.C : O(1)
// S.C : O(1)
public class Solution {
    public boolean isPowerOfTwo(int n) {
        return (n > 0) && ((n & (n - 1)) == 0);
    }
}

// Approach-3 (__builtin_popcount)
// T.C : O(1)
// S.C : O(1)
public class Solution {
    public boolean isPowerOfTwo(int n) {
        if (n <= 0)
            return false;

        return Integer.bitCount(n) == 1;
    }
}
