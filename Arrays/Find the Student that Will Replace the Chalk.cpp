/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=RG-vw6IzVuU
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk
*/


/************************************************************ C++ ************************************************/
//Approach-1 - Simulation (TLE)
//T.C : O(k/sum * n)
//S.C : O(1)
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        while(true) {
            for(int i = 0; i < chalk.size(); i++) {
                if(k < chalk[i]) {
                    return i;
                }
            }
        }

        return -1;
    }
};


//Approach-2 (Making use of remainder)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();

        long long totalChalkSum = 0; //Total chalks required in one iteration
        for(int &chalkReq : chalk) { //O(n)
            totalChalkSum += chalkReq;
        }

        //Number of full iteration possible = k/totalChalkSum

        int remainChalk = k%totalChalkSum;

        for(int i = 0; i < n; i++) { //O(n)
            if(remainChalk < chalk[i]) {
                return i;
            }

            remainChalk -= chalk[i];
        }

        return -1;
    }
};



/************************************************************ JAVA ************************************************/
//Approach-1 - Simulation (TLE)
//T.C : O(k/sum * n)
//S.C : O(1)
class Solution {
    public int chalkReplacer(int[] chalk, int k) {
        while (true) {
            for (int i = 0; i < chalk.length; i++) {
                if (k < chalk[i]) {
                    return i;
                }
                k -= chalk[i];
            }
        }
    }
}

//Approach-2 (Making use of remainder)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int chalkReplacer(int[] chalk, int k) {
        int n = chalk.length;

        // Calculate the total sum of chalk required in one iteration
        long totalChalkSum = 0;
        for (int chalkReq : chalk) {
            totalChalkSum += chalkReq;
        }

        // Calculate the remaining chalk after full iterations
        int remainChalk = (int)(k % totalChalkSum);

        // Find the first student who cannot complete their required chalk usage
        for (int i = 0; i < n; i++) {
            if (remainChalk < chalk[i]) {
                return i;
            }
            remainChalk -= chalk[i];
        }

        return -1; // In theory, this line should never be reached
    }
}
