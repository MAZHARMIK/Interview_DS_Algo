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
//Approach (storing diff in Map) - (For Case-3, I used pair(diffAB, diffAC) in map for avoiding TLE in Java)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {

    static class Pair {
        int d1, d2;

        Pair(int d1, int d2) {
            this.d1 = d1;
            this.d2 = d2;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof Pair)) return false;
            Pair p = (Pair) o;
            return d1 == p.d1 && d2 == p.d2;
        }

        @Override
        public int hashCode() {
            return 31 * d1 + d2;
        }
    }

    public int longestBalanced(String s) {

        char[] c = s.toCharArray();
        int n = c.length;

        int res = 0;

        //Case-1
        int cur = 1;

        for (int i = 1; i < n; i++) {
            if (c[i] == c[i - 1]) {
                cur++;
            } else {
                res = Math.max(res, cur);
                cur = 1;
            }
        }
        res = Math.max(res, cur);

        //Case-2
        res = Math.max(res, find2(c, 'a', 'b'));
        res = Math.max(res, find2(c, 'a', 'c'));
        res = Math.max(res, find2(c, 'b', 'c'));

        
        //Case-3
        int ca = 0, cb = 0, cc = 0;

        Map<Pair, Integer> mp = new HashMap<>();

        for (int i = 0; i < n; i++) {

            if (c[i] == 'a') ca++;
            else if (c[i] == 'b') cb++;
            else cc++;

            if(ca == cb && ca == cc)
                res = Math.max(res, ca+cb+cc);

            Pair key = new Pair(ca - cb, ca - cc);

            Integer prev = mp.get(key);
            if (prev != null) {
                res = Math.max(res, i - prev);
            } else {
                mp.put(key, i);
            }
        }

        return res;
    }

    private int find2(char[] c, char x, char y) {

        int n = c.length;
        int max_len = 0;

        int[] first = new int[2 * n + 1];
        Arrays.fill(first, -2);

        int clear_idx = -1;
        int diff = n;

        first[diff] = -1;

        for (int i = 0; i < n; i++) {

            if (c[i] != x && c[i] != y) {

                clear_idx = i;
                diff = n;
                first[diff] = clear_idx;

            } else {

                if (c[i] == x) diff++;
                else diff--;

                if (first[diff] < clear_idx) {
                    first[diff] = i;
                } else {
                    max_len = Math.max(max_len, i - first[diff]);
                }
            }
        }

        return max_len;
    }
}
