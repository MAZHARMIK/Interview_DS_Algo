/*    Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn  : 
    Company Tags                 : will update later
    Leetcode Link                : https://leetcode.com/problems/vowels-game-in-a-string
*/


/********************************************************************* C++ *********************************************************************/
//Approach-1 (Simple math)
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


//Approach-2 (Using one liner STL)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool doesAliceWin(string s) {
        auto lambda = [](char ch) {
            return string("aeiou").find(ch) != string::npos;
        };

        return any_of(s.begin(), s.end(), lambda);
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


//Approach-2 (Using one liner JCF)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public boolean doesAliceWin(String s) {
        return s.chars().anyMatch(ch -> "aeiou".indexOf(ch) >= 0);
    }
}
