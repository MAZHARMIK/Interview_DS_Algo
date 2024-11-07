/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=9ZlMnn_N0QE
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero
*/

/******************************************************** C++ ********************************************************/
//Approach-1 (Using counter array)
//T.C : O(24*n) ~= O(n)
//S.C : O(24) ~= O(1)
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> count(24, 0);
        //count[i] = how many numbers have ith bit set

        int result = 0;

        for(int i = 0; i < 24; i++) { //O(24)

            for(int &num : candidates) { //O(n)
                if((num & (1 << i)) != 0) {
                    count[i]++;
                }
            }

            result = max(result, count[i]);

        }

        return result;
    }
};


//Approach-2 (without using counter array)
//T.C : O(24*n) ~= O(n)
//S.C : O(1)
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        //vector<int> count(24, 0); //O(24)
        //count[i] = how many numbers have ith bit set

        int result = 0;

        for(int i = 0; i < 24; i++) { //O(24)
            int count_ith = 0;

            for(int &num : candidates) { //O(n)
                if((num & (1 << i)) != 0) {
                    count_ith += 1;
                }
            }

            result = max(result, count_ith);

        }

        return result;
    }
};



/******************************************************** JAVA ********************************************************/
//Approach-1 (Using counter array)
//T.C : O(24*n) ~= O(n)
//S.C : O(24) ~= O(1)
class Solution {
    public int largestCombination(int[] candidates) {
        int[] count = new int[24];
        int result = 0;

        // Count how many numbers have the i-th bit set
        for (int i = 0; i < 24; i++) { // O(24)
            for (int num : candidates) { // O(n)
                if ((num & (1 << i)) != 0) {
                    count[i]++;
                }
            }
            result = Math.max(result, count[i]);
        }

        return result;
    }
}


//Approach-2 (without using counter array)
//T.C : O(24*n) ~= O(n)
//S.C : O(1)
class Solution {
    public int largestCombination(int[] candidates) {
        int result = 0;

        for (int i = 0; i < 24; i++) { // O(24)
            int countIth = 0;

            for (int num : candidates) { // O(n)
                if ((num & (1 << i)) != 0) {
                    countIth++;
                }
            }

            result = Math.max(result, countIth);
        }

        return result;
    }
}
