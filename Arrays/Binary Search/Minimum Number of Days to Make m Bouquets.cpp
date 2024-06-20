/*    Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=erWfh_hBF80
    Company Tags                : AMAZON
    Leetcode Link               : https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets
*/

/*************************************************************** C++ ***************************************************************/
//Approach - Using "Binary Search on Answer"
//T.C : O(n * log(max_d)), n is the number of flowers and max_d is the highest value in the array bloomDay.
//S.C : O(1)
class Solution {
public:
    int getNumOfBouquets(vector<int>& bloomDay, int mid, int k) {
        int numOfBouquets = 0;
        int consecutive_count = 0;
        
        //Find count of consecutive flowers you can pick at mid day.
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                consecutive_count++;
            } else {
                consecutive_count = 0;
            }
            if (consecutive_count == k) {
                numOfBouquets++;
                consecutive_count = 0;
            }
        }
        return numOfBouquets;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int start_day = 0;
        int end_day   = *max_element(begin(bloomDay), end(bloomDay));

        int minDays = -1;

        while (start_day <= end_day) {
            int mid = start_day + (end_day - start_day)/2;

            if (getNumOfBouquets(bloomDay, mid, k) >= m) {
                minDays = mid;
                end_day = mid - 1;
            } else {
                start_day = mid + 1;
            }
        }

        return minDays;
    }
};



/*************************************************************** JAVA ***************************************************************/
//Approach - Using "Binary Search on Answer"
//T.C : O(n * log(max_d)), n is the number of flowers and max_d is the highest value in the array bloomDay.
//S.C : O(1)
class Solution {
    public int getNumOfBouquets(int[] bloomDay, int mid, int k) {
        int numOfBouquets = 0;
        int consecutiveCount = 0;
        
        // Find count of consecutive flowers you can pick at mid day.
        for (int i = 0; i < bloomDay.length; i++) {
            if (bloomDay[i] <= mid) {
                consecutiveCount++;
            } else {
                consecutiveCount = 0;
            }
            if (consecutiveCount == k) {
                numOfBouquets++;
                consecutiveCount = 0;
            }
        }
        return numOfBouquets;
    }

    public int minDays(int[] bloomDay, int m, int k) {
        // If it's impossible to get m bouquets
        if (bloomDay.length < m * k) {
            return -1;
        }

        int startDay = 1;
        int endDay = Arrays.stream(bloomDay).max().getAsInt();
        int minDays = -1;

        while (startDay <= endDay) {
            int mid = startDay + (endDay - startDay) / 2;

            if (getNumOfBouquets(bloomDay, mid, k) >= m) {
                minDays = mid;
                endDay = mid - 1;
            } else {
                startDay = mid + 1;
            }
        }

        return minDays;
    }
}
