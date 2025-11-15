/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/count-the-number-of-substrings-with-dominant-ones
*/


/**************************************************************** C++ ****************************************************************/
//Approach (Improving the brute force by skipping index j wherever possible)
//T.C : Worst case O(n^2), but since we skip indices we get O(n*sqrt(n))
//S.C : O(n)
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();

        vector<int> cumCountOne(n, 0);
        cumCountOne[0] = (s[0] == '1') ? 1 : 0;

        for(int i = 1; i < n; i++) {
            cumCountOne[i] = cumCountOne[i-1] + ((s[i] == '1') ? 1 : 0);
        }

        //[i...j] = cumCountOne[j] - cumCountOne[i-1];

        int result = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {

                int oneCount  = cumCountOne[j] - (i - 1 >= 0 ? cumCountOne[i-1] : 0);
                int zeroCount = (j - i + 1) - oneCount;

                if((zeroCount * zeroCount) > oneCount) {
                    //skip j to avoid waste indices
                    int wasteIndices = (zeroCount * zeroCount) - oneCount;
                    j += wasteIndices - 1;
                } else if((zeroCount * zeroCount) == oneCount) {
                    result += 1;
                } else { //(zeroCount * zeroCount) < oneCount
                    //[i....j] is a valid substring
                    result += 1;

                    //try to see how much j can shift to right until substring remains dominant
                    int k = sqrt(oneCount) - zeroCount;
                    int next = j + k;

                    if(next >= n) { //out of bound, means all indices are valid
                        result += (n - j - 1);
                        break; //early break
                    } else {
                        result += k;
                    }

                    j = next;
                }
            }
        }

        return result;

    }
};




/**************************************************************** JAVA ****************************************************************/
//Approach (Improving the brute force by skipping index j wherever possible)
//T.C : Worst case O(n^2), but since we skip indices we get O(n*sqrt(n))
//S.C : O(n)
class Solution {
    public int numberOfSubstrings(String s) {

        int n = s.length();
        int[] cumCountOne = new int[n];

        // Build prefix sum of ones
        cumCountOne[0] = (s.charAt(0) == '1') ? 1 : 0;
        for (int i = 1; i < n; i++) {
            cumCountOne[i] = cumCountOne[i - 1] + (s.charAt(i) == '1' ? 1 : 0);
        }

        int result = 0;

        for (int i = 0; i < n; i++) {

            for (int j = i; j < n; j++) {

                int oneCount = cumCountOne[j] - (i > 0 ? cumCountOne[i - 1] : 0);
                int zeroCount = (j - i + 1) - oneCount;

                int z2 = zeroCount * zeroCount;

                if (z2 > oneCount) {
                    // Skip several j's
                    int waste = z2 - oneCount;
                    j += waste - 1;

                } else if (z2 == oneCount) {
                    result++;

                } else { // z2 < oneCount
                    result++;

                    int k = (int) Math.sqrt(oneCount) - zeroCount;
                    int next = j + k;

                    if (next >= n) {
                        result += (n - j - 1);
                        break;
                    } else {
                        result += k;
                    }

                    j = next;
                }
            }
        }

        return result;
    }
}
