/*    Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS QN : https://www.youtube.com/watch?v=YIbkt9kDXJY
    Company Tags                : will add later
    Leetcode Link               : https://leetcode.com/problems/find-the-k-th-character-in-string-game-i
*/

/*************************************************************************** C++ ***************************************************************************/
//Approach-1 (Simulation)
//T.C : O(k)
//S.C : O(k)
class Solution {
public:

    char kthCharacter(int k) {
        int idx = k-1;
        string result = "a";

        while(result.length() < k) {
            int n = result.length();
            for(int i = 0; i < n; i++) {
                char ch = result[i] == 'z' ? 'a' : result[i]+1;
                result.push_back(ch);
            }
        }

        return result[idx];
    }
};


//Approach-2 (bit observation to find shift)
//T.C : O(log(k-1))
//S.C : O(1)
class Solution {
public:
    char kthCharacter(int k) {
        int shift = __builtin_popcount(k-1);

        return 'a' + shift;
    }
};



/*************************************************************************** JAVA ***************************************************************************/
//Approach-1 (Simulation)
//T.C : O(k)
//S.C : O(k)
class Solution {
    public char kthCharacter(int k) {
        int idx = k - 1;
        StringBuilder result = new StringBuilder();
        result.append('a');

        while(result.length() < k) {
            int n = result.length();
            for(int i = 0; i < n; i++) {
                char ch = result.charAt(i) == 'z' ? 'a' : (char)(result.charAt(i) + 1);
                result.append(ch);
            }
        }

        return result.charAt(idx);
    }
}


//Approach-2 (bit observation to find shift)
//T.C : O(log(k-1))
//S.C : O(1)
class Solution {
    public char kthCharacter(int k) {
        int shift = Integer.bitCount(k - 1);
        return (char)('a' + shift);
    }
}
