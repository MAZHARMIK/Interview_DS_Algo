/*     Scroll below to see JAVA code    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/count-the-hidden-sequences
*/


/****************************************************** C++ **************************************************************/
//Approach - Using Maths for counting total possible shifts
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int curr = 0; //a[0] first element of hidden sequence
        int minVal = 0;
        int maxVal = 0;

        for(int &d : differences) {
            curr = curr + d;

            minVal = min(minVal, curr);
            maxVal = max(maxVal, curr);

            if((upper - maxVal) - (lower - minVal) + 1 <= 0) {
                return 0;
            }
        }

        return (upper - maxVal) - (lower - minVal) + 1;

    }
};


/****************************************************** JAVA **************************************************************/
//Approach - Using Maths for counting total possible shifts
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int numberOfArrays(int[] differences, int lower, int upper) {
        int curr = 0; // Simulates building the array starting from a[0] = 0
        int minVal = 0;
        int maxVal = 0;

        for (int d : differences) {
            curr += d;
            minVal = Math.min(minVal, curr);
            maxVal = Math.max(maxVal, curr);

            if ((upper - maxVal) - (lower - minVal) + 1 <= 0) {
                return 0;
            }
        }

        return (upper - maxVal) - (lower - minVal) + 1;
    }
}
