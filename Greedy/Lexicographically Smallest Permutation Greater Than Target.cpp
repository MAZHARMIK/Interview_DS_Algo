/*         Scroll down to see JAVA code also                    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Twj2DyUrDH4
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/lexicographically-smallest-permutation-greater-than-target/description/
*/


/********************************************************************* C++ ****************************************************************/
//Approach (Greedy + backtracking)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    string result = "";

    bool solve(string& curr, vector<int>& count, string& target, int i, bool greater) {
        if(i == target.length()) {
            if(greater) {
                result = curr;
                return true;
            }
            return false;
        }

        for(char ch = 'a'; ch <= 'z'; ch++) {
            if(count[ch-'a'] == 0)
                continue;
            
            if(greater == false && ch < target[i])
                continue;
            

            curr.push_back(ch);
            count[ch-'a']--;

            bool isGreater = greater || ch > target[i];

            if(solve(curr, count, target, i+1, isGreater)) {
                return true;
            }

            curr.pop_back();
            count[ch-'a']++;
        }

        return false;
    }

    string lexGreaterPermutation(string s, string target) {
        vector<int> count(26, 0);

        for(char &ch : s)
            count[ch-'a']++;
        
        string curr;

        solve(curr, count, target, 0, false);

        return result;
    }
};



/********************************************************************* JAVA ****************************************************************/
//Approach (Greedy + backtracking)
//T.C : O(n)
//S.C : O(n)
class Solution {
    String result = "";

    boolean solve(StringBuilder curr, int[] count, String target, int i, boolean greater) {
        if (i == target.length()) {
            if (greater) {
                result = curr.toString();
                return true;
            }
            return false;
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (count[ch - 'a'] == 0)
                continue;

            if (greater == false && ch < target.charAt(i))
                continue;

            curr.append(ch);
            count[ch - 'a']--;

            boolean isGreater = greater || ch > target.charAt(i);

            if (solve(curr, count, target, i + 1, isGreater)) {
                return true;
            }

            curr.deleteCharAt(curr.length() - 1);
            count[ch - 'a']++;
        }

        return false;
    }

    public String lexGreaterPermutation(String s, String target) {
        int[] count = new int[26];

        for (char ch : s.toCharArray())
            count[ch - 'a']++;

        StringBuilder curr = new StringBuilder();

        solve(curr, count, target, 0, false);

        return result;
    }
}
