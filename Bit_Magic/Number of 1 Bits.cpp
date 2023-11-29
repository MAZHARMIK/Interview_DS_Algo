/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=YOyajw-L0pc
    Company Tags                : Apple, Microsoft, Amazon
    Leetcode Link               : https://leetcode.com/problems/number-of-1-bits/
*/


/*************************************************************** C++ ***************************************************************/
//Approach-1 (Using simple right shift operator)
//T.C : O(1) - because the loop in the code iterates 32 times, which is a constant number regardless of the input n
//S.C : O(1)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        
        for(int i = 31; i>=0; i--) {
            if(((n >> i) & 1) == 1) {
                count++;
            }
        }
        
        return count;
    }
};

//Approach-2 (Using simple bit magic)
//T.C : O(k) -> Where k = number of set bits (1s) in input 'n'
//S.C : O(1)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        
        while(n) {
            n = (n&(n-1)); //This expression is used to turn off the rightmost set bit in n. This operation effectively removes one set bit in each iteration.
            count++;
        }
        
        return count;
    }
};

//Approach-3 (Using simple bit magic)
//T.C : O(log(n)) -> In each iteration, n is divided by 2 (n /= 2)
//S.C : O(1)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        
        while(n) {
            count += (n%2);
            n /= 2;
        }
        
        return count;
    }
};

//Approach-4 (using GCC built-in function)
//T.C : O(k) -> Where k = number of set bits (1s) in input 'n'
//S.C : O(1)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
};



/*************************************************************** JAVA ***************************************************************/
// Approach-1 (Using simple right shift operator)
// T.C : O(1) - because the loop in the code iterates 32 times, which is a constant number regardless of the input n
// S.C : O(1)
class Solution {
    public int hammingWeight(int n) {
        int count = 0;

        for (int i = 31; i >= 0; i--) {
            if (((n >> i) & 1) == 1) {
                count++;
            }
        }

        return count;
    }
}

// Approach-2 (Using simple bit magic)
// T.C : O(k) -> Where k = number of set bits (1s) in input 'n'
// S.C : O(1)
class Solution {
    public int hammingWeight(int n) {
        int count = 0;

        while (n != 0) {
            n = n & (n - 1); // This expression is used to turn off the rightmost set bit in n. This operation effectively removes one set bit in each iteration.
            count++;
        }

        return count;
    }
}

// Approach-3 (Using simple bit magic)
// T.C : O(log(n)) -> In each iteration, n is divided by 2 (n /= 2)
// S.C : O(1)
class Solution {
    public int hammingWeight(int n) {
        int count = 0;

        while (n != 0) {
            count += (n % 2);
            n /= 2;
        }

        return count;
    }
}

// Approach-4 (using built-in Java function)
// T.C : O(k) -> Where k = number of set bits (1s) in input 'n'
// S.C : O(1)
class Solution {
    public int hammingWeight(int n) {
        return Integer.bitCount(n);
    }
}
