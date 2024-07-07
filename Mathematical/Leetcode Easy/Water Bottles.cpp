/*    Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn  : https://www.youtube.com/watch?v=v2D_v3llC98
    Company Tags                 : AMAZON
    Leetcode Link                : https://leetcode.com/problems/water-bottles
*/


/********************************************************************* C++ *********************************************************************/
//Approach-1 (Simple simulation)
//T.C : O(numBottles)
//S.C : O(1)
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int consumed = 0;

        while(numBottles >= numExchange) {

            consumed   += numExchange;
            numBottles -= numExchange;

            numBottles += 1;

        }

        return consumed + numBottles;
    }
};


//Approach-2 (Improvement on Approach-1)
//T.C : O(log_numExchange_(numBottles))
//S.C : O(1)
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int consumed = numBottles;
        int emptyBottles = numBottles;

        while(emptyBottles >= numExchange) {
            int extraFullBottles = emptyBottles / numExchange;

            int remain = emptyBottles % numExchange;

            consumed += extraFullBottles;

            emptyBottles = remain + extraFullBottles;
        }

        return consumed;
    }
};


//Approach-3 (Using maths)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles + (numBottles-1) / (numExchange-1);
    }
};


/********************************************************************* JAVA *********************************************************************/
//Approach-1 (Simple simulation)
//T.C : O(numBottles)
//S.C : O(1)
//Approach-1 (Simple simulation)
//T.C : O(numBottles)
//S.C : O(1)
class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        int consumed = 0;

        while (numBottles >= numExchange) {
            consumed += numExchange;
            numBottles -= numExchange;

            numBottles += 1;
        }

        return consumed + numBottles;
    }
}


//Approach-2 (Improvement on Approach-1)
//T.C : O(log_numExchange_(numBottles))
//S.C : O(1)
class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        int consumed = numBottles;
        int emptyBottles = numBottles;

        while (emptyBottles >= numExchange) {
            int extraFullBottles = emptyBottles / numExchange;
            int remain = emptyBottles % numExchange;

            consumed += extraFullBottles;
            emptyBottles = remain + extraFullBottles;
        }

        return consumed;
    }
}


//Approach-3 (Using maths):
//T.C : O(1)
//S.C:  O(1)
class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        return numBottles + (numBottles - 1) / (numExchange - 1);
    }
}
