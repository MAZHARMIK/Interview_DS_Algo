/*    Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS QN : https://www.youtube.com/watch?v=oJiw9087awQ
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/robot-return-to-origin
*/

/*************************************************************************** C++ ***************************************************************************/
//Approach (simple simulation)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;

        for(char &ch : moves) {
            if(ch == 'U')       y++;
            else if(ch == 'D')  y--;
            else if(ch == 'L')  x--;
            else if(ch == 'R')  x++;
        }

        return x == 0 && y == 0;
    }
};

/*************************************************************************** JAVA ***************************************************************************/
//Approach (simple simulation)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public boolean judgeCircle(String moves) {
        int x = 0;
        int y = 0;

        for(char ch : moves.toCharArray()) {
            if(ch == 'U')       y++;
            else if(ch == 'D')  y--;
            else if(ch == 'L')  x--;
            else if(ch == 'R')  x++;
        }

        return x == 0 && y == 0;
    }
}
