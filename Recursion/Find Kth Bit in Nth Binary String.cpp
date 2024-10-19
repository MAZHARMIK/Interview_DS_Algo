/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/find-kth-bit-in-nth-binary-string
*/


/************************************************************ C++ ************************************************/
//Approach - Recursion
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    char findKthBit(int n, int k) {
        
        if(n == 1) {
            return '0';
        }

        int length = (1 << n) - 1; //pow(2, n) - 1

        if(k < ceil(length/2.0)) {
            return findKthBit(n-1, k);
        } else if(k == ceil(length/2.0)) {
            return '1';
        } else {
            char ch = findKthBit(n-1, length-(k-1)); //handled reversed
            return (ch == '0') ? '1' : '0'; //handled flipped bit
        }

    }
};


/************************************************************ JAVA ************************************************/
//Approach - Recursion
//T.C : O(n)
//S.C : O(n)
class Solution {
    public char findKthBit(int n, int k) {
        // Base case: if n is 1, the sequence is just "0"
        if (n == 1) {
            return '0';
        }

        // Length of the sequence at level n: 2^n - 1
        int length = (1 << n) - 1;

        // If k is in the first half, recurse on the first half
        if (k < Math.ceil(length / 2.0)) {
            return findKthBit(n - 1, k);
        } 
        // If k is the middle bit, return '1'
        else if (k == Math.ceil(length / 2.0)) {
            return '1';
        } 
        // Otherwise, recurse on the mirrored second half
        else {
            char ch = findKthBit(n - 1, length - (k - 1)); // handle reversed
            return (ch == '0') ? '1' : '0'; // handle flipped bit
        }
    }
}
