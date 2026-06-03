/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=R94VBJJoqTU
    Company Tags                : will update later
    Leetcode-3633 Link          : https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-i/
    Leetcode-3635 Link          : https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-ii/
*/


/*********************************************************** C++ **************************************************/
//Approach-1 (Brute Force - Try all pairs)
//T.C : O(n*m)
//S.C : O(1)
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        int result = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                int land                = landStartTime[i] + landDuration[i];
                int pehleLand_FirWater  = max(land, waterStartTime[j]) + waterDuration[j];
                result                  = min(result, pehleLand_FirWater);

                int water              = waterStartTime[j] + waterDuration[j];
                int pehleWater_FirLand = max(water, landStartTime[i]) + landDuration[i];

                result = min(result, pehleWater_FirLand);
            }
        }

        return result;
    }
};


//Approach-2 (Greedy - Pick earliest finishing task first)
//T.C : O(n+m)
//S.C : O(1)
class Solution {
public:

    int findFinishTime(vector<int>& start1, vector<int>& duration1, vector<int>& start2, vector<int>& duration2) {

        int finish1 = INT_MAX;
        for (int i = 0; i < start1.size(); i++) {
            finish1 = min(finish1, start1[i] + duration1[i]);
        }

        int finish2 = INT_MAX;
        for (int i = 0; i < start2.size(); i++) {
            finish2 = min(finish2, max(finish1, start2[i]) + duration2[i]);
        }

        return finish2;
    }

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int pehleLand_FirWater = findFinishTime(landStartTime, landDuration, waterStartTime, waterDuration);

        int pehleWater_FirLand = findFinishTime(waterStartTime, waterDuration, landStartTime, landDuration);

        return min(pehleLand_FirWater, pehleWater_FirLand);
    }
};


/*********************************************************** JAVA **************************************************/
//Approach-1 (Brute Force - Try all pairs)
//T.C : O(n*m)
//S.C : O(1)
class Solution {
    public int earliestFinishTime(int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDuration) {

        int n = landStartTime.length;
        int m = waterStartTime.length;

        int result = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                int land               = landStartTime[i] + landDuration[i];
                int pehleLand_FirWater = Math.max(land, waterStartTime[j]) + waterDuration[j];
                result                 = Math.min(result, pehleLand_FirWater);

                int water              = waterStartTime[j] + waterDuration[j];
                int pehleWater_FirLand = Math.max(water, landStartTime[i]) + landDuration[i];

                result = Math.min(result, pehleWater_FirLand);
            }
        }

        return result;
    }
}


//Approach-2 (Greedy - Pick earliest finishing task first)
//T.C : O(n+m)
//S.C : O(1)
class Solution {

    private int findFinishTime(int[] start1, int[] duration1, int[] start2, int[] duration2) {

        int finish1 = Integer.MAX_VALUE;
        for (int i = 0; i < start1.length; i++) {
            finish1 = Math.min(finish1, start1[i] + duration1[i]);
        }

        int finish2 = Integer.MAX_VALUE;
        for (int i = 0; i < start2.length; i++) {
            finish2 = Math.min(finish2, Math.max(finish1, start2[i]) + duration2[i]);
        }

        return finish2;
    }

    public int earliestFinishTime(int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDuration) {
        int pehleLand_FirWater = findFinishTime(landStartTime, landDuration, waterStartTime, waterDuration);

        int pehleWater_FirLand = findFinishTime(waterStartTime, waterDuration, landStartTime, landDuration);

        return Math.min(pehleLand_FirWater, pehleWater_FirLand);
    }
}
