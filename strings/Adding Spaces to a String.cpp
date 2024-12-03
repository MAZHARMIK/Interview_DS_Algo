/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=a_-iGNtoDD0
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/adding-spaces-to-a-string
*/


/**************************************************************** C++ ****************************************************************/
//Approach (Simple traversal using two pointers)
//T.C : O(m+n)
//S.C : O(1)
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int m = s.length();
        int n = spaces.size();

        string result = "";

        int j = 0; //to traverse in spaces vector
        for(int i = 0; i < m; i++) {
            if(j < n && i == spaces[j]) {
                result += " ";
                j++;
            }

            result += s[i];
        }

        return result;
    }
};



/**************************************************************** JAVA ****************************************************************/
//Approach (Simple traversal using two pointers)
//T.C : O(m+n)
//S.C : O(1)
class Solution {
    public String addSpaces(String s, int[] spaces) {
        int m = s.length();
        int n = spaces.length;

        StringBuilder result = new StringBuilder(); // Using StringBuilder for efficiency
        int j = 0; // Pointer to traverse the spaces array

        for (int i = 0; i < m; i++) {
            if (j < n && i == spaces[j]) {
                result.append(" ");
                j++;
            }
            result.append(s.charAt(i));
        }

        return result.toString();
    }
}
