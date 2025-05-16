/*         Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=6-GbDuhOOdc
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/count-days-without-meetings
*/


/**************************************************** C++ ****************************************************/
//Approach (Simple sorting based on starting point)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();

        sort(begin(meetings), end(meetings));

        int result = 0;
        int start = 0;
        int end = 0;

        for(auto &meet : meetings) {
            if(meet[0] > end) {
                result += meet[0] - end - 1;
            }

            end = max(end, meet[1]);
        }

        if(days > end) {
            result += days-end;
        }

        return result;
    }
};


/**************************************************** JAVA ****************************************************/
//Approach (Simple sorting based on starting point)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
    public int countDays(int days, int[][] meetings) {
        Arrays.sort(meetings, (a, b) -> Integer.compare(a[0], b[0]));
        
        int result = 0;
        int end = 0;
        
        for (int[] meet : meetings) {
            if (meet[0] > end) {
                result += meet[0] - end - 1;
            }
            end = Math.max(end, meet[1]);
        }
        
        if (days > end) {
            result += days - end;
        }
        
        return result;
    }
}
