/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=9wrKWB1xDoY
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/minimize-xor
*/

/******************************************************** C++ ********************************************************/
//Approach-1 (Starting from num1 and then forming result)
//T.C : O(log(n))
//S.C : O(1)
class Solution {
public:
        //T.C : O(log(n))
        //S.C : O(1)
    bool isSet(int &x, int bit) {
        return x & (1 << bit);
    }

    bool setBit(int &x, int bit) {
        return x |= (1 << bit);
    }

    bool unsetBit(int &x, int bit) {
        return x &= ~(1 << bit);
    }

    int minimizeXor(int num1, int num2) {
        int x = num1;

        int requiredSetBitCount = __builtin_popcount(num2);
        int currSetBitCount = __builtin_popcount(x);

        int bit = 0; //position of bit
        if(currSetBitCount < requiredSetBitCount) {
            while(currSetBitCount < requiredSetBitCount) {
                if(!isSet(x, bit)) {
                    setBit(x, bit);
                    currSetBitCount++;
                }
                bit++;
            }
        } else if(currSetBitCount > requiredSetBitCount) {
            while(currSetBitCount > requiredSetBitCount) {
                if(isSet(x, bit)) {
                    unsetBit(x, bit);
                    currSetBitCount--;
                }
                bit++;
            }
        }

        return x;
    }
};


//Approach-2 (Directly build result)
//T.C : O(log(n))
//S.C : O(1)
class Solution {
public:
    bool isSet(int &x, int bit) {
        return x & (1 << bit);
    }

    bool setBit(int &x, int bit) {
        return x |= (1 << bit);
    }

    bool unsetBit(int &x, int bit) {
        return x &= ~(1 << bit);
    }

    bool isUnset(int x, int bit) {
        return (x & (1 << bit)) == 0;
    }

    int minimizeXor(int num1, int num2) {
        int x = 0;

        int requiredSetBitCount = __builtin_popcount(num2);

        for(int bit = 31; bit >= 0 && requiredSetBitCount > 0; bit--) {
            if(isSet(num1, bit)) {
                setBit(x, bit); //Or you can write x |= (1 << bit);
                requiredSetBitCount--;
            }
        }

        for(int bit = 0; bit < 32 && requiredSetBitCount > 0; bit++) {
            if(isUnset(num1, bit)) {
                setBit(x, bit); //Or you can write x |= (1 << bit);
                requiredSetBitCount--;
            }
        }

        return x;
        
    }
};
\

//Approach-3 (Starting from num1 and then forming result)
//T.C : O(30) ~ O(1)
//S.C : O(30) ~ O(1)

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        
        // calculate number of set bits in both num1 and num2
        int num1_setBits = __builtin_popcount(num1); // O(30)
        int num2_setBits = __builtin_popcount(num2); // O(30)

        if (num1_setBits == num2_setBits)
            return num1;

        int ans = 0;

        // O(30)
        char number[30]; // initializing number array to represent num1 in binary

        // representing num1 in binary
        int num1_copy = num1;
        int i = 29;
        while (num1_copy > 0) { // O(30)
            number[i] = num1_copy % 2 + '0';
            num1_copy >>= 1;
            i--;
        }
        // padding zeros to the left side
        while (i >= 0) { // O(30)
            number[i] = '0';
            i--;
        }
        // representation of num1 in binary finished

        if (num1_setBits < num2_setBits) { // fill '1' from LSB
            int k = num2_setBits - num1_setBits;
            int bit = 29;
            while (k > 0) { // O(30)
                if (number[bit] == '0') {
                    number[bit] = '1';
                    k--;
                }
                bit--;
            }

            bit = 29;
            int i = 0;
            while (bit >= 0) { // O(30)
                ans += ((number[bit] - '0') * pow(2, i));
                bit--;
                i++;
            }
            return ans;
        }
        // fill '1' from MSB
        int k = num2_setBits;
        int bit = 0;

        while (bit < 29 && k > 0) { // O(30)
            if (number[bit] == '1')
                k--;
            bit++;
        }

        while (bit <= 29) { // O(30)
            number[bit++] = '0';
        }

        // construct the answer
        bit = 29;
        i = 0;
        while (bit >= 0) { // O(30)
            ans += ((number[bit] - '0') * pow(2, i));
            bit--;
            i++;
        }
        return ans;
    }
};



/******************************************************** JAVA ********************************************************/
//Approach-1 (Starting from num1 and then forming result)
//T.C : O(log(n))
//S.C : O(1)
class Solution {

    public boolean isSet(int x, int bit) {
        return (x & (1 << bit)) != 0;
    }

    public int setBit(int x, int bit) {
        return x | (1 << bit);
    }

    public int unsetBit(int x, int bit) {
        return x & ~(1 << bit);
    }

    public int minimizeXor(int num1, int num2) {
        int x = num1;

        int requiredSetBitCount = Integer.bitCount(num2);
        int currSetBitCount = Integer.bitCount(x);

        int bit = 0;

        if(currSetBitCount < requiredSetBitCount) {
            while(currSetBitCount < requiredSetBitCount) {
                if(!isSet(x, bit)) {
                    x = setBit(x, bit);
                    currSetBitCount++;
                }
                bit++;
            }
        } else if(currSetBitCount > requiredSetBitCount) {
            while(currSetBitCount > requiredSetBitCount) {
                if(isSet(x, bit)) {
                    x = unsetBit(x, bit);
                    currSetBitCount--;
                }
                bit++;
            }
        }

        return x;
    }
}


//Approach-2 (Directly build result)
//T.C : O(log(n))
//S.C : O(1)
class Solution {

    public boolean isSet(int x, int bit) {
        return (x & (1 << bit)) != 0;
    }

    public int setBit(int x, int bit) {
        return x | (1 << bit);
    }

    public int unsetBit(int x, int bit) {
        return x & ~(1 << bit);
    }

    public boolean isUnSet(int x, int bit) {
        return (x & (1 << bit)) == 0;
    }

    public int minimizeXor(int num1, int num2) {
        int x = 0;

        int requiredSetBitCount = Integer.bitCount(num2);
        
        for(int bit = 31; bit >= 0 && requiredSetBitCount > 0; bit--) {
            if(isSet(num1, bit)) {
                x |= (1 << bit);
                requiredSetBitCount--;
            }
        }

        for(int bit = 0; bit < 32 && requiredSetBitCount > 0; bit++) {
            if(isUnSet(num1, bit)) {
                x |= (1 << bit);
                requiredSetBitCount--;
            }
        }
        
        return x;
    }
}
