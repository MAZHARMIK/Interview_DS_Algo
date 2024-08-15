/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=sYHJEPs9sSE
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/lemonade-change
*/


/*************************************************************** C++ ********************************************************/
//Simply Simulation
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten  = 0;


        for(int &bill : bills) {
            if(bill == 5) {
                five++;
            } else if(bill == 10) { //return 5$ to customer
                if(five > 0) {
                    five--;
                    ten++;
                } else {
                    return false;
                }
            } else if(five > 0 && ten > 0) { //return 15$ to customer
                five--;
                ten--;
            } else if(five >= 3) { //5, 5, 5
                five -= 3;
            } else {
                return false;
            }
        }

        return true;
    }
};


/*************************************************************** JAVA ********************************************************/
//Simply Simulation
//T.C : O(n)
//S.C : O(1)
class Solution {
    public boolean lemonadeChange(int[] bills) {
        int five = 0;
        int ten  = 0;

        for (int bill : bills) {
            if (bill == 5) {
                five++;
            } else if (bill == 10) { // return $5 to customer
                if (five > 0) {
                    five--;
                    ten++;
                } else {
                    return false;
                }
            } else if (five > 0 && ten > 0) { // return $15 to customer
                five--;
                ten--;
            } else if (five >= 3) { // $5, $5, $5
                five -= 3;
            } else {
                return false;
            }
        }

        return true;
    }
}
