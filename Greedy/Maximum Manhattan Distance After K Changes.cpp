/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=LjgDv-WeXfM
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes
*/


/************************************************************ C++ ************************************************/
//Approach (Iterating and finding best at each point of time)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maxDistance(string s, int k) {
        int maxMD = 0;

        int east = 0;
        int west = 0;
        int north = 0;
        int south = 0;

        for(int i = 0; i < s.length(); i++) {

            if(s[i] == 'E') east++;
            else if(s[i] == 'W') west++;
            else if(s[i] == 'N') north++;
            else if(s[i] == 'S') south++;

            int currMD = abs(east-west) + abs(north-south);

            int steps  = i+1;
            int wasted = steps - currMD;

            int extra = 0;
            if(wasted != 0) { //steps != currMD
                extra = min(2*k, wasted);
            }

            int finalCurrentMD = currMD + extra;

            maxMD = max(maxMD, finalCurrentMD);
        }

        return maxMD;
    }
};



/************************************************************ JAVA ************************************************/
//Approach (Iterating and finding best at each point of time)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int maxDistance(String s, int k) {
        int maxMD = 0;
        
        int east = 0, west = 0, north = 0, south = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (c == 'E') east++;
            else if (c == 'W') west++;
            else if (c == 'N') north++;
            else if (c == 'S') south++;

            int currMD = Math.abs(east - west) + Math.abs(north - south);

            int steps = i + 1;
            int wasted = steps - currMD;

            int extra = Math.min(2 * k, wasted);

            int finalCurrentMD = currMD + extra;

            maxMD = Math.max(maxMD, finalCurrentMD);
        }

        return maxMD;
    }
}
