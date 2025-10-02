/*     Scroll below to see JAVA code also    */
/*
      MY YOUTUBE VIDEO ON THIS Qn : 
      Company Tags                : will update later
      Leetcode Link               : https://leetcode.com/problems/water-bottles-ii
*/


/********************************************************************** C++ ********************************************************/
//Approach-1 Simple Simulation
//T.C : O(root(numBottles))
//S.C : O(1)
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty = numBottles;

        int drank = numBottles;

        while(empty >= numExchange) {
            empty -= numExchange;

            drank++;

            empty++;

            numExchange++;
        }

        return drank;
    }
};



//Approach-2 (Maths derivation - Using Sridharacharya formula)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        return numBottles + ((-2*numExchange + 3 + sqrt(4*numExchange*numExchange+8*numBottles - 12 * numExchange + 1))/2);
    }
};




/********************************************************************** JAVA ********************************************************/
//Approach-1 Simple Simulation
//T.C : O(root(numBottles))
//S.C : O(1)
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty = numBottles;
        int drank = numBottles;

        while(empty >= numExchange) {
            empty -= numExchange;
            drank++;
            empty++;
            numExchange++;
        }

        return drank;
    }
};



//Approach-2 (Maths derivation - Using Sridharacharya formula)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        return numBottles + ((-2*numExchange + 3 + sqrt(4*numExchange*numExchange + 8*numBottles - 12*numExchange + 1))/2);
    }
};
