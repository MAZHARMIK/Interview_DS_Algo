/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-operations-to-sort-a-string
*/


/**************************************************************** C++ ****************************************************************/
//Approach (Cases)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        if(is_sorted(begin(s), end(s)))
            return 0;
        
        if(n == 2) {
            return -1;
        }

        char min_char = *min_element(begin(s), end(s));
        char max_char = *max_element(begin(s), end(s));

        if(s[0] == min_char || s[n-1] == max_char)
            return 1;

        char max_mid = *max_element(begin(s)+1, end(s)-1);
        char min_mid = *min_element(begin(s)+1, end(s)-1);

        if(s[0] > max_mid && s[n-1] < min_mid) {
            return 3;
        }

        return 2;
    }
};


/**************************************************************** Java ****************************************************************/
//Approach (Cases)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int minOperations(String s) {
        int n = s.length();
        char[] arr = s.toCharArray();

        boolean sorted = true;
        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[i - 1]) {
                sorted = false;
                break;
            }
        }
        if (sorted) {
            return 0;
        }

        if (n == 2) {
            return -1;
        }

        char minChar = arr[0];
        char maxChar = arr[0];
        for (int i = 1; i < n; i++) {
            minChar = (char) Math.min(minChar, arr[i]);
            maxChar = (char) Math.max(maxChar, arr[i]);
        }

        if (arr[0] == minChar || arr[n - 1] == maxChar) {
            return 1;
        }

        char minMid = arr[1];
        char maxMid = arr[1];
        for (int i = 2; i < n - 1; i++) {
            minMid = (char) Math.min(minMid, arr[i]);
            maxMid = (char) Math.max(maxMid, arr[i]);
        }

        if (arr[0] > maxMid && arr[n - 1] < minMid) {
            return 3;
        }

        return 2;
    }
}
