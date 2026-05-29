/*    Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn  : https://www.youtube.com/watch?v=c5iHN8MI_JI
    Company Tags                 : META
    Leetcode Link                : https://leetcode.com/problems/count-odd-numbers-in-an-interval-range
*/


/********************************************************************* C++ *********************************************************************/
//Approach-1 - Brute Force
//T.C : O(high-low)
//S.C : O(1)
class Solution {
public:
    int countOdds(int low, int high) {
        int count = 0;
        low = low%2 ? low : low+1; //Make it odd

        for(int num = low; num <= high; num+=2) { //move to alternate numbers for odd
                count++;
        }

        return count;
    }
};

//Approach-2 (Simple maths)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    int countOdds(int low, int high) {
        // If low is even, make it odd.
        if(low%2 == 0)
            low++;
        
        if(high%2 == 0)
            high--;
  
        return (high-low)/2 + 1;
    }
};


//Approach-3 (Simple maths)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    int countOdds(int low, int high) {
        return (high+1)/2 - (low)/2;
    }
};



/********************************************************************* JAVA *********************************************************************/
//Approach-1 - Brute Force
//T.C : O(high-low)
//S.C : O(1)
class Solution {
    public int countOdds(int low, int high) {
        int count = 0;
        low = (low%2 == 1) ? low : low+1; //Make it odd

        for(int num = low; num <= high; num+=2) { //move to alternate numbers for odd
                count++;
        }

        return count;
    }
}

// Approach-2 (Simple maths)
// T.C : O(1)
// S.C : O(1)
class Solution {
    public int countOdds(int low, int high) {
        // If low is even, make it odd.
        if (low % 2 == 0)
            low++;

        if (high % 2 == 0)
            high--;

        // If after adjustments low > high, no odds exist
        if (low > high)
            return 0;

        return (high - low) / 2 + 1;
    }
}

// Approach-3 (Simple maths)
// T.C : O(1)
// S.C : O(1)
class Solution {
    public int countOdds(int low, int high) {
        return (high + 1) / 2 - (low / 2);
    }
}
