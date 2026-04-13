/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=3zm-QWciVeI
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/description/
*/

/*********************************************************** C++ **************************************************/
//Approach (Simple simulation)
//T.C : O(n*L), L = average length of all the words
//S.C : O(1)
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n      = words.size();
        int result = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (words[i] == target) {
                int straightDist  = abs(i - startIndex);
                int circularDist  = n-straightDist;

                result = min({result, straightDist, circularDist});
            }
        }

        return result == INT_MAX ? -1 : result;
    }
};



/*********************************************************** JAVA **************************************************/
//Approach (Simple simulation)
//T.C : O(n*L), L = average length of all the words
//S.C : O(1)
class Solution {
    public int closestTarget(String[] words, String target, int startIndex) {
        int n = words.length;
        int result = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            if (words[i].equals(target)) {
                int straightDist = Math.abs(i - startIndex);
                int circularDist = n - straightDist;

                result = Math.min(result, Math.min(straightDist, circularDist));
            }
        }

        return result == Integer.MAX_VALUE ? -1 : result;
    }
}
