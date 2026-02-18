/*   Scroll below to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : hhttps://www.youtube.com/watch?v=E1pLPxpvmeQ
    Company Tags                : Will udpate later
    Leetcode Link               : https://leetcode.com/problems/binary-number-with-alternating-bits
*/


/******************************************************* C++ *******************************************************/
//Approach-1 (Using shift operators and Xor operation)
//T.C : O(log(n))
//S.C : O(1)
class Solution {
public:
    bool hasAlternatingBits(int n) {
        bitset<32> b(n);
        int bits = log2(n);
        for(int i = 0; i<=bits; i++) {
            if(b[i] == b[i+1]) return false;
        }
        return true;
    }
};


//Approach-2 (Using shift operators and Xor operation)
//T.C : O(log(n))
//S.C : O(1)
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int currBit = n % 2;
        n /= 2;

        while (n > 0) {
            if (currBit == n % 2) 
                return false;
            
            currBit = n % 2;

            n /= 2;
        }
        
        return true;
    }
};


//Approach-3 (Using shift operators and Xor operation)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int result = n ^ (n >> 1);

        return (result & (result + 1)) == 0;
    }
};




/******************************************************* JAVA *******************************************************/
//Approach-1 (Using shift operators and Xor operation)
//T.C : O(log(n))
//S.C : O(1)
class Solution {
    public boolean hasAlternatingBits(int n) {
        String b = Integer.toBinaryString(n);

        for (int i = 0; i < b.length() - 1; i++) {
            if (b.charAt(i) == b.charAt(i + 1)) {
                return false;
            }
        }

        return true;
    }
}




//Approach-2 (Using shift operators and Xor operation)
//T.C : O(log(n))
//S.C : O(1)
class Solution {
    public boolean hasAlternatingBits(int n) {
        int currBit = n % 2;
        n /= 2;

        while (n > 0) {
            if (currBit == n % 2) {
                return false;
            }

            currBit = n % 2;
            n /= 2;
        }

        return true;
    }
}


//Approach-3 (Using shift operators and Xor operation)
//T.C : O(1)
//S.C : O(1)
class Solution {
    public boolean hasAlternatingBits(int n) {
        int result = n ^ (n >> 1); 
        return (result & (result + 1)) == 0;
    }
}
