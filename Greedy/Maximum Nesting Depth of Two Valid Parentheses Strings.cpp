/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://youtu.be/9TiOxPz4jOk
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/description/
*/


/*********************************************************** C++ **************************************************/
//Approach - Greedily divide depth in half
//T.C - O(n)
//S.C - O(1)
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> result(seq.size());
        int d = 0;

        for (int i = 0; i < seq.size(); i++) {
            if (seq[i] == '(') {
                d++;
                result[i] = d % 2 == 0 ? 0 : 1;
            } 
            else {
                result[i] = d % 2 == 0 ? 0 : 1;
                d--;
            }
        }

        return result;
    }
};
