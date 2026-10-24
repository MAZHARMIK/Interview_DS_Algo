/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=RK9v3tuy8X4
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/count-days-spent-together/description/
*/


/*********************************************************** C++ **************************************************/
//Approach (Find Days and Find Overlap)
//T.C : O(1) , everything is of constant size
//S.C : O(1) , everything is of constant size
class Solution {
public:

    int findDayOfYear(const string& day, const vector<int>& cumMonthDays) {
        int month = stoi(day.substr(0, 2));
        int date  = stoi(day.substr(3));
        return cumMonthDays[month - 1] + date;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        vector<int> monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        vector<int> cumMonthDays(13, 0);
        cumMonthDays[1] = 31; //January
        for(int i = 1; i <= 12; i++) {
            cumMonthDays[i] = cumMonthDays[i-1] + monthDays[i-1];
        }

        int arriveAliceDay  = findDayOfYear(arriveAlice, cumMonthDays);
        int leaveAliceDay   = findDayOfYear(leaveAlice, cumMonthDays);
        int arriveBobDay    = findDayOfYear(arriveBob, cumMonthDays);
        int leaveBobDay     = findDayOfYear(leaveBob, cumMonthDays);

        //Now, just find the overlap
        int overLapDays = min(leaveAliceDay, leaveBobDay) - max(arriveAliceDay, arriveBobDay) + 1;

        return overLapDays < 0 ? 0 : overLapDays;
    }
};




/*********************************************************** JAVA **************************************************/
//Approach (Find Days and Find Overlap)
//T.C : O(1) , everything is of constant size
//S.C : O(1) , everything is of constant size
class Solution {

    private int findDayOfYear(String day, int[] cumMonthDays) {
        int month = Integer.parseInt(day.substring(0, 2));
        int date  = Integer.parseInt(day.substring(3));
        return cumMonthDays[month - 1] + date;
    }

    public int countDaysTogether(String arriveAlice, String leaveAlice, String arriveBob, String leaveBob) {
        int[] monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int[] cumMonthDays = new int[13];
        cumMonthDays[1] = 31; // January
        for (int i = 1; i <= 12; i++) {
            cumMonthDays[i] = cumMonthDays[i - 1] + monthDays[i - 1];
        }

        int arriveAliceDay = findDayOfYear(arriveAlice, cumMonthDays);
        int leaveAliceDay  = findDayOfYear(leaveAlice, cumMonthDays);
        int arriveBobDay   = findDayOfYear(arriveBob, cumMonthDays);
        int leaveBobDay    = findDayOfYear(leaveBob, cumMonthDays);

        // Now, just find the overlap
        int overlapDays = Math.min(leaveAliceDay, leaveBobDay) - Math.max(arriveAliceDay, arriveBobDay) + 1;

        return Math.max(overlapDays, 0);
    }
}
