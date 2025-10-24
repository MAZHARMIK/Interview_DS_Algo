/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=MLXm_hhOTmc
    Company Tags                : Adobe
    Leetcode Link               : https://leetcode.com/problems/next-greater-numerically-balanced-number
*/


/************************************************************ C++ *****************************************************/
//Approach-1 (Doing simulation)
//T.C : O(L-n), where L = 1224444
//S.C : O(1)
class Solution {
public:

    bool balanced(int num) {
        vector<int> freq(10);
        while(num > 0) {
            int digit = num%10;
            freq[digit]++;
            num /= 10;
        }

        for(int d = 0; d < 10; d++) {
            if(freq[d] != 0 && freq[d] != d)
                return false;
        }
        
        return true;

    }

    int nextBeautifulNumber(int n) {
        for(int num = n+1; num <= 1224444; num++) {
            if(balanced(num)) {
                return num;
            }
        }

        return -1;
    }
};


//Approach-2 (Binary search on preciomputed list of balanced numbers)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    vector<int> balancedList{
        1,      22,     122,    212,    221,    333,    1333,   3133,   3313,
        3331,   4444,   14444,  22333,  23233,  23323,  23332,  32233,  32323,
        32332,  33223,  33232,  33322,  41444,  44144,  44414,  44441,  55555,
        122333, 123233, 123323, 123332, 132233, 132323, 132332, 133223, 133232,
        133322, 155555, 212333, 213233, 213323, 213332, 221333, 223133, 223313,
        223331, 224444, 231233, 231323, 231332, 232133, 232313, 232331, 233123,
        233132, 233213, 233231, 233312, 233321, 242444, 244244, 244424, 244442,
        312233, 312323, 312332, 313223, 313232, 313322, 321233, 321323, 321332,
        322133, 322313, 322331, 323123, 323132, 323213, 323231, 323312, 323321,
        331223, 331232, 331322, 332123, 332132, 332213, 332231, 332312, 332321,
        333122, 333212, 333221, 422444, 424244, 424424, 424442, 442244, 442424,
        442442, 444224, 444242, 444422, 515555, 551555, 555155, 555515, 555551,
        666666, 1224444};

    int nextBeautifulNumber(int n) {
        return *upper_bound(begin(balancedList), end(balancedList), n);
    }
};




//Approach-3 (Bakctracking)
//T.C : O(9^d), d = number of digits of n
//S.C : O(1)
class Solution {
public:
    vector<int> digitCount{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int backtrack(int n, int curr, int count) {
        if(count == 0) {
            for(int digit = 1; digit <= 9; digit++) {
                if(digitCount[digit] != 0 && digitCount[digit] != digit) {
                    return 0;
                }
            }

            return curr > n ? curr : 0;
        }

        int result = 0;

        for(int digit = 1; digit <= 9; digit++) {
            if(digitCount[digit] > 0 && digitCount[digit] <= count) {
                digitCount[digit]--;
                result = backtrack(n, curr*10+digit, count-1);
                digitCount[digit]++;
            }

            if(result != 0) {
                break;
            }
        }

        return result;
    }

    int nextBeautifulNumber(int n) {
        int numDigits = to_string(n).length();

        int result = backtrack(n, 0, numDigits);
        if(result == 0) {
            result = backtrack(n, 0, numDigits+1);
        }

        return result;
    }
};




/************************************************************ JAVA *****************************************************/
//Approach-1 (Doing simulation)
//T.C : O(L-n), where L = 1224444
//S.C : O(1)
class Solution {
    public boolean balanced(int num) {
        int[] freq = new int[10];
        while (num > 0) {
            int digit = num % 10;
            freq[digit]++;
            num /= 10;
        }
        for (int d = 0; d <= 9; d++) {
            if (freq[d] != 0 && freq[d] != d) {
                return false;
            }
        }
        return true;
    }

    public int nextBeautifulNumber(int n) {
        for (int num = n + 1; num <= 1224444; num++) {
            if (balanced(num)) {
                return num;
            }
        }
        return -1;
    }
}


//Approach-2 (Binary search on preciomputed list of balanced numbers)
//T.C : O(1)
//S.C : O(1)
class Solution {
    public int nextBeautifulNumber(int n) {
        int[] balancedList = {
            1, 22, 122, 212, 221, 333, 1333, 3133, 3313,
            3331, 4444, 14444, 22333, 23233, 23323, 23332, 32233, 32323,
            32332, 33223, 33232, 33322, 41444, 44144, 44414, 44441, 55555,
            122333, 123233, 123323, 123332, 132233, 132323, 132332, 133223,
            133232, 133322, 155555, 212333, 213233, 213323, 213332, 221333,
            223133, 223313, 223331, 224444, 231233, 231323, 231332, 232133,
            232313, 232331, 233123, 233132, 233213, 233231, 233312, 233321,
            242444, 244244, 244424, 244442, 312233, 312323, 312332, 313223,
            313232, 313322, 321233, 321323, 321332, 322133, 322313, 322331,
            323123, 323132, 323213, 323231, 323312, 323321, 331223, 331232,
            331322, 332123, 332132, 332213, 332231, 332312, 332321, 333122,
            333212, 333221, 422444, 424244, 424424, 424442, 442244, 442424,
            442442, 444224, 444242, 444422, 515555, 551555, 555155, 555515,
            555551, 666666, 1224444
        };

        int idx = Arrays.binarySearch(balancedList, n);
        if (idx < 0) idx = -idx - 1; 
        else idx++;
        return balancedList[idx];
    }
}



//Approach-3 (Bakctracking)
//T.C : O(9^d), d = number of digits of n
//S.C : O(1)
class Solution {
    private int[] digitCount = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    private int backtrack(int n, int curr, int count) {
        if (count == 0) {
            for (int digit = 1; digit <= 9; digit++) {
                if (digitCount[digit] != 0 && digitCount[digit] != digit) {
                    return 0;
                }
            }
            return curr > n ? curr : 0;
        }

        int result = 0;
        for (int digit = 1; digit <= 9; digit++) {
            if (digitCount[digit] > 0 && digitCount[digit] <= count) {
                digitCount[digit]--;
                result = backtrack(n, curr * 10 + digit, count - 1);
                digitCount[digit]++;
            }
            if (result != 0) break;
        }
        return result;
    }

    public int nextBeautifulNumber(int n) {
        int numDigits = String.valueOf(n).length();

        int result = backtrack(n, 0, numDigits);
        if (result == 0) {
            result = backtrack(n, 0, numDigits + 1);
        }

        return result;
    }
}
