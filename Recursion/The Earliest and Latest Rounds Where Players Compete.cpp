/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=NnfyGypen1w
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete
*/


/************************************************************ C++ ******************************************************/
//Approach : (Recursion)
//T.C : T(n) = n^2 * T(n/2) -> Homework for you. Comment in the video your solution
//S.C : No extra space taken (ignoring the system recursion space)
class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        int left = firstPlayer; //P1
        int right = secondPlayer; //P2

        if(left == n - right + 1) {
            return {1, 1};
        }

        if(left > n - right + 1) {
            int temp = n - left + 1;
            left = n - right + 1;
            right = temp;
        }

        int minRound  = n;
        int maxRound  = 1;
        int nextRoundPlayersCount = (n+1)/2;
        if(right <= nextRoundPlayersCount) { //Case-1 both on the same side
            int countLeft = left-1;
            int midCount  = right - left - 1;

            for(int survivorsLeft = 0; survivorsLeft <= countLeft; survivorsLeft++) {
                for(int survivorsMid = 0; survivorsMid <= midCount; survivorsMid++) {
                    int pos1 = survivorsLeft+1;
                    int pos2 = pos1 + survivorsMid + 1;
                    vector<int> tempResult = earliestAndLatest(nextRoundPlayersCount, pos1, pos2);

                    minRound = min(minRound, tempResult[0]+1);
                    maxRound  = max(maxRound, tempResult[1]+1);
                }
            }
        } else { //case - 2 both on opposite end
            int fightsRight = n - right + 1;
            int countLeft = left - 1;
            int midCount = fightsRight - left - 1;
            int remainMidCount = right - fightsRight - 1;

            for(int survivorsLeft = 0; survivorsLeft <= countLeft; survivorsLeft++) {
                for(int survivorsMid = 0; survivorsMid <= midCount; survivorsMid++) {
                    int pos1 = survivorsLeft + 1;
                    int pos2 = pos1 + survivorsMid + (remainMidCount+1)/2 + 1;

                    vector<int> tempResult = earliestAndLatest(nextRoundPlayersCount, pos1, pos2);

                    minRound = min(minRound, tempResult[0]+1);
                    maxRound  = max(maxRound, tempResult[1]+1);
                }
            }
        }
        return {minRound, maxRound};
    }
};


/************************************************************ JAVA *******************************************************/
//Approach : (Recursion)
//T.C : T(n) = n^2 * T(n/2) -> Homework for you. Comment in the video your solution
//S.C : No extra space taken (ignoring the system recursion space)
class Solution {
    public int[] earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        int left = firstPlayer; //P1
        int right = secondPlayer; //P2

        if (left == n - right + 1) {
            return new int[]{1, 1}; // Return a new int array initialized with values.
        }

        if (left > n - right + 1) {
            int temp = n - left + 1;
            left = n - right + 1;
            right = temp;
        }

        int minRound = n;
        int maxRound = 1;
        int nextRoundPlayersCount = (n + 1) / 2;

        if (right <= nextRoundPlayersCount) { //Case-1 both on the same side
            int countLeft = left - 1;
            int midCount = right - left - 1;

            for (int survivorsLeft = 0; survivorsLeft <= countLeft; survivorsLeft++) {
                for (int survivorsMid = 0; survivorsMid <= midCount; survivorsMid++) {
                    int pos1 = survivorsLeft + 1;
                    int pos2 = pos1 + survivorsMid + 1;
                    int[] tempResult = earliestAndLatest(nextRoundPlayersCount, pos1, pos2); // Recursive call returns an int array.

                    minRound = Math.min(minRound, tempResult[0] + 1); // Access array elements using [].
                    maxRound = Math.max(maxRound, tempResult[1] + 1); // Access array elements using [].
                }
            }
        } else { //case - 2 both on opposite end
            int fightsRight = n - right + 1;
            int countLeft = left - 1;
            int midCount = fightsRight - left - 1;
            int remainMidCount = right - fightsRight - 1;

            for (int survivorsLeft = 0; survivorsLeft <= countLeft; survivorsLeft++) {
                for (int survivorsMid = 0; survivorsMid <= midCount; survivorsMid++) {
                    int pos1 = survivorsLeft + 1;
                    int pos2 = pos1 + survivorsMid + (remainMidCount + 1) / 2 + 1;

                    int[] tempResult = earliestAndLatest(nextRoundPlayersCount, pos1, pos2); // Recursive call returns an int array.

                    minRound = Math.min(minRound, tempResult[0] + 1); // Access array elements using [].
                    maxRound = Math.max(maxRound, tempResult[1] + 1); // Access array elements using [].
                }
            }
        }
        return new int[]{minRound, maxRound}; // Return a new int array initialized with values.
    }
}
