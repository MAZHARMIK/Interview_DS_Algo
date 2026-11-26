/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/stone-removal-game/
*/

/*********************************************************** C++ **************************************************/
//Approach-1 Simulation
//T.C : O(1) 
//S.C : O(1)
class Solution {
public:
    bool canAliceWin(int n) {
        int take = 10;
        int steps = 0;

        while (n >= take) {
            n -= take;
            take--;
            steps++;
        }

        return steps % 2 == 1;
    }
};



//Approach-2 Maths
//T.C : O(1) 
//S.C : O(1)
class Solution {
public:
    bool canAliceWin(int n) {
        int k = (21 - sqrt(441 - 8*n)) / 2;

        return k%2 == 1; //odd : ALice wins
    }
};



/*********************************************************** JAVA **************************************************/
//Approach-1 Simulation
//T.C : O(1) 
//S.C : O(1)
class Solution {
    public boolean canAliceWin(int n) {
        int take = 10;
        int steps = 0;

        while (n >= take) {
            n -= take;
            take--;
            steps++;
        }

        return steps % 2 == 1;
    }
}



//Approach-2 Maths
//T.C : O(1) 
//S.C : O(1)
class Solution {
    public boolean canAliceWin(int n) {
        int k = (int) ((21 - Math.sqrt(441 - 8 * n)) / 2);

        return k % 2 == 1; //odd : Alice wins
    }
}
