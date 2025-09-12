/*    Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn  : 
    Company Tags                 : will update later
    Leetcode Link                : https://leetcode.com/problems/vowels-game-in-a-string
*/


/********************************************************************* C++ *********************************************************************/
//Approach (Simple math)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool doesAliceWin(string s) {

        for(char &ch : s) {
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                return true;
            }
        }

        return false;
    }
};



/********************************************************************* JAVA *********************************************************************/
//Approach (Simple math)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public boolean doesAliceWin(String s) {
        for (char ch : s.toCharArray()) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                return true;
            }
        }
        return false;
    }
}
