/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ig4llTdg6_E
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers
*/

/*********************************************************** C++ **************************************************/
//Approach-1 (Brute Force - Try all possible numbers fro 1 to n-1 for a and thne b = n-a)
//T.C : O(n*logn)
//S.C : O(1)
class Solution {
public:

    bool check(int num) {
        while(num) {
            if(num%10 == 0) {
                return false;
            }

            num /= 10;
        }   

        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        for(int a = 1; a <= n-1; a++) {
            int b = n-a;

            if(check(a) && check(b)) {
                return {a, b};
            }
        }

        return {};
    }
};



//Approach-2 (Fixing each digit and forming a and b digit by digit)
//T.C : O(logn)
//S.C : O(1)
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a = n;
        int b = 0;
        int placeValue = 1;

        //a+b == n
        while(n > 1) {
            int take = 1;

            if(n%10 == 1) {
                take = 2;
            }

            a = a - take*placeValue;
            b = b + take*placeValue;

            n = (n-take)/10; //moving to next digit

            placeValue *= 10;
        }

        return {a, b};

        
    }
};



/*********************************************************** JAVA **************************************************/
// Approach-1 (Brute Force - Try all possible numbers from 1 to n-1 for a and then b = n-a)
// T.C : O(n * logn)
// S.C : O(1)
class Solution {
    private boolean check(int num) {
        while (num > 0) {
            if (num % 10 == 0) {
                return false;
            }
            num /= 10;
        }
        return true;
    }

    public int[] getNoZeroIntegers(int n) {
        for (int a = 1; a <= n - 1; a++) {
            int b = n - a;
            if (check(a) && check(b)) {
                return new int[]{a, b};
            }
        }
        return new int[]{}; // just a fallback
    }
}


// Approach-2 (Fixing each digit and forming a and b digit by digit)
// T.C : O(logn)
// S.C : O(1)
class Solution {
    public int[] getNoZeroIntegers(int n) {
        int a = n;
        int b = 0;
        int placeValue = 1;

        while (n > 1) {
            int adjust = 1;

            // If the last digit is 1, subtracting 1 would make 'a' have a zero → avoid
            if (n % 10 == 1) {
                adjust = 2;
            }

            a -= adjust * placeValue;
            b += adjust * placeValue;

            n = (n - adjust) / 10; // move to next digit
            placeValue *= 10;
        }

        return new int[]{a, b};
    }
}
