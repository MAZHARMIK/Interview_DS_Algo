/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/sum-of-sortable-integers
*/


/**************************************************************** C++ ****************************************************************/
//Approach (Using KMP)
//T.C: O(n log n + n · M), where M is the number of divisors of n
//S.C: O(n)
class Solution {
public:

    //KMP Start
    void computeLPS(vector<int>& pattern, vector<int>& lps) {
        int M = pattern.size();
        int len = 0;
        lps[0] = 0;

        int i = 1;
        while (i < M) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    bool search(vector<int>& pat, vector<int>& txt) {
        int N = txt.size();
        int M = pat.size();

        vector<int> lps(M, 0);
        computeLPS(pat, lps);

        int i = 0; // index for text
        int j = 0; // index for pattern

        while (i < N) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }

            if (j == M) {
                return true; // pattern found , return true
            } else if (i < N && pat[j] != txt[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false;
    }
    //KMP End

    // Is vec1 a cyclic rotation of vec2 ,  then, vec1 occurs in vec2+vec2
    bool isRotation(vector<int>& vec1, vector<int>& vec2) {
        vector<int> txt = vec2;
        txt.insert(end(txt), begin(vec2), end(vec2)); // vec2 + vec2
        return search(vec1, txt);
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(begin(sorted), end(sorted));

        int result = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool valid = true;
            for (int start = 0; start < n; start += k) {
                vector<int> vec1(begin(nums) + start, begin(nums) + start + k);
                vector<int> vec2(begin(sorted) + start, begin(sorted) + start + k);

                if (!isRotation(vec1, vec2)) {
                    valid = false;
                    break;
                }
            }
            if (valid)
                result += k;
        }
        return result;
    }
};




/**************************************************************** JAVA ****************************************************************/
//Approach (Using KMP)
//T.C: O(n log n + n · M), where M is the number of divisors of n
//S.C: O(n)
//T.C: O(n log n + n · M), where M is the number of divisors of n
//S.C: O(n),
class Solution {

    //KMP Start
    void computeLPS(int[] pattern, int[] lps) {
        int M = pattern.length;
        int len = 0;
        lps[0] = 0;

        int i = 1;
        while (i < M) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    boolean search(int[] pat, int[] txt) {
        int N = txt.length;
        int M = pat.length;

        int[] lps = new int[M];
        computeLPS(pat, lps);

        int i = 0; // index for text
        int j = 0; // index for pattern

        while (i < N) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }

            if (j == M) {
                return true; // pattern found , return true
            } else if (i < N && pat[j] != txt[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false;
    }
    //KMP End

    // Is vec1 a cyclic rotation of vec2 ,  then, vec1 occurs in vec2+vec2
    boolean isRotation(int[] vec1, int[] vec2) {
        int[] txt = new int[vec2.length * 2];
        System.arraycopy(vec2, 0, txt, 0, vec2.length);
        System.arraycopy(vec2, 0, txt, vec2.length, vec2.length); // vec2 + vec2
        return search(vec1, txt);
    }

    public int sortableIntegers(int[] nums) {
        int n = nums.length;
        int[] sorted = nums.clone();
        java.util.Arrays.sort(sorted);

        int result = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            boolean valid = true;
            for (int start = 0; start < n; start += k) {
                int[] vec1 = java.util.Arrays.copyOfRange(nums, start, start + k);
                int[] vec2 = java.util.Arrays.copyOfRange(sorted, start, start + k);

                if (!isRotation(vec1, vec2)) {
                    valid = false;
                    break;
                }
            }
            if (valid)
                result += k;
        }
        return result;
    }
}
