/*   Scroll below to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/smallest-number-with-all-set-bits
*/


/******************************************************* C++ *******************************************************/
//Approach-1 (Simple looping till we get result)
//T.C : O(result - n), where result = (next power of 2 > n) - 1
//S.C : O(1)
class Solution {
public:
    bool isAllBitsSet(int x) {
        return (x & (x+1)) == 0;
    }
    int smallestNumber(int n) {
        int result = n;

        while(!isAllBitsSet(result)) {
            result++;
        }

        return result;
    }
};



//Approach-2 (Using properties of power of 2)
//T.C : O(log2(n))
//S.C : O(1)
class Solution {
public:
    int smallestNumber(int n) {
        int result = 1;

        while(result < n) {
            result = 2*result + 1;
        }

        return result;
    }
};



//Approach-3 (constant time but using same power of 2 property)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    int smallestNumber(int n) {
        int bits = log2(n) + 1;

        return (1 << bits) - 1;
    }
};



/******************************************************* JAVA *******************************************************/
//Approach-1 (Simple looping till we get result)
//T.C : O(result - n), where result = (next power of 2 > n) - 1
//S.C : O(1)
class Solution {
    public boolean isAllBitsSet(int x) {
        return (x & (x + 1)) == 0;
    }

    public int smallestNumber(int n) {
        int result = n;

        while (!isAllBitsSet(result)) {
            result++;
        }

        return result;
    }
}



//Approach-2 (Using properties of power of 2)
//T.C : O(log2(n))
//S.C : O(1)
class Solution {
    public int smallestNumber(int n) {
        int result = 1;

        while (result < n) {
            result = 2 * result + 1;
        }

        return result;
    }
}



//Approach-3 (constant time but using same power of 2 property)
//T.C : O(1)
//S.C : O(1)
class Solution {
    public int smallestNumber(int n) {
        int bits = (int)(Math.log(n) / Math.log(2)) + 1;
        return (1 << bits) - 1;
    }
}
