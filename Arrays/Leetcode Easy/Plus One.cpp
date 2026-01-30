/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=mStAXMDK6xU
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/plus-one/
*/


/*********************************************************** C++ **************************************************/
//Approach (Simple follow Math Addition Principles)
//T.C : O(n) 
//S.C : O(1)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        int i = n-1; //Start from LSB like usual math addition

        while(i >= 0) {
            if(digits[i] < 9) {
                digits[i] += 1;
                return digits;
            }

            //else we did get 9
            digits[i] = 0; //9+1 = 10
            i--;
        }

        digits.insert(begin(digits), 1); //1 is the carry forwarded till the end

        return digits;


    }
};


/*********************************************************** Java **************************************************/
//Approach (Simple follow Math Addition Principles)
//T.C : O(n) 
//S.C : O(1)
class Solution {
    public int[] plusOne(int[] digits) {
        int n = digits.length;

        int i = n - 1; // start from LSB like normal addition

        while (i >= 0) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            // digit was 9
            digits[i] = 0;
            i--;
        }

        // carry reached beyond the most significant digit
        int[] result = new int[n + 1];
        result[0] = 1;
        return result;
    }
}
