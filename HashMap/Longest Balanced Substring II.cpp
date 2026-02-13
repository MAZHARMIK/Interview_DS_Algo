/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/longest-balanced-substring-ii/
*/


/************************************************************ C++ *****************************************************/
//Approach (storing diff in Map)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int helper(string&s, int ch1, int ch2) {
        int n = s.length();
        unordered_map<int, int> diffMap;
        int maxL = 0;
        int count1 = 0;
        int count2 = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] != ch1 && s[i] != ch2) {
                diffMap.clear();
                count1 = 0;
                count2 = 0;
                continue;
            }

            if(s[i] == ch1)
                count1++;
            if(s[i] == ch2)
                count2++;

            if(count1 == count2) {
                maxL = max(maxL, count1+count2);
            }

            int diff = count1 - count2;
            if(diffMap.count(diff)) {
                maxL = max(maxL, i - diffMap[diff]);
            } else {
                diffMap[diff] = i;
            }
        }
        
        return maxL;
    }

    int longestBalanced(string s) {
        int n    = s.length();
        int maxL = 0;

        //Case-1
        //"aaaa"
        int count = 1; //s[0]
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]) {
                count++;
            } else {
                maxL = max(maxL, count);
                count = 1;
            }
        }
        maxL = max(maxL, count);

        //Case-2
        maxL = max(maxL, helper(s, 'a', 'b'));
        maxL = max(maxL, helper(s, 'a', 'c'));
        maxL = max(maxL, helper(s, 'b', 'c'));


        //Case-3
        int countA = 0;
        int countB = 0;
        int countC = 0;
        unordered_map<string, int> diffMap;

        for(int i = 0; i < n; i++) {
            if(s[i] == 'a')
                countA++;
            if(s[i] == 'b')
                countB++;
            if(s[i] == 'c')
                countC++;

            if(countA == countB && countA == countC) {
                maxL = max(maxL, countA+countB+countC);
            }

            int diffAB = countA - countB;
            int diffAC = countA - countC;

            string key = to_string(diffAB) + "_" + to_string(diffAC); //log(n) digits

            if(diffMap.count(key)) {
                maxL = max(maxL, i - diffMap[key]);
            } else {
                diffMap[key] = i;
            }
        }

        return maxL;

    }
};



/************************************************************ JAVA *****************************************************/
//Approach (storing diff in Map)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {

    private int helper(String s, char ch1, char ch2) {
        int n = s.length();
        Map<Integer, Integer> diffMap = new HashMap<>();
        int maxL = 0;
        int count1 = 0;
        int count2 = 0;

        for (int i = 0; i < n; i++) {

            char ch = s.charAt(i);

            if (ch != ch1 && ch != ch2) {
                diffMap.clear();
                count1 = 0;
                count2 = 0;
                continue;
            }

            if (ch == ch1) count1++;
            if (ch == ch2) count2++;

            if (count1 == count2) {
                maxL = Math.max(maxL, count1 + count2);
            }

            int diff = count1 - count2;

            if (diffMap.containsKey(diff)) {
                maxL = Math.max(maxL, i - diffMap.get(diff));
            } else {
                diffMap.put(diff, i);
            }
        }

        return maxL;
    }

    public int longestBalanced(String s) {

        int n = s.length();
        int maxL = 0;

        // Case 1: All same characters (e.g. "aaaa")
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (s.charAt(i) == s.charAt(i - 1)) {
                count++;
            } else {
                maxL = Math.max(maxL, count);
                count = 1;
            }
        }
        maxL = Math.max(maxL, count);

        // Case 2: Any two characters balanced
        maxL = Math.max(maxL, helper(s, 'a', 'b'));
        maxL = Math.max(maxL, helper(s, 'a', 'c'));
        maxL = Math.max(maxL, helper(s, 'b', 'c'));

        // Case 3: All three characters balanced
        int countA = 0;
        int countB = 0;
        int countC = 0;

        Map<String, Integer> diffMap = new HashMap<>();

        for (int i = 0; i < n; i++) {

            char ch = s.charAt(i);

            if (ch == 'a') countA++;
            if (ch == 'b') countB++;
            if (ch == 'c') countC++;

            if (countA == countB && countA == countC) {
                maxL = Math.max(maxL, countA + countB + countC);
            }

            int diffAB = countA - countB;
            int diffAC = countA - countC;

            String key = diffAB + "_" + diffAC;

            if (diffMap.containsKey(key)) {
                maxL = Math.max(maxL, i - diffMap.get(key));
            } else {
                diffMap.put(key, i);
            }
        }

        return maxL;
    }
}
