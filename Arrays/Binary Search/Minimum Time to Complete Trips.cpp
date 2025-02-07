/*        Scroll below to see JAVA code as well        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=tUCVupA0lAc
    Company Tags                : Google, PhonePe, Meesho (SDE-2 Role, Year - 2025)
    Leetcode Link               : https://leetcode.com/problems/minimum-time-to-complete-trips/
*/

//Brute Force - Simply check for each time (1, 2, 3...) if that will be able to satisfy totalTrips. This will cause TLE
/************************************************************ C++ ************************************************************************/
//Approach - Using Binary Search - O(n * log(totalTrips * m)) -> where m = minimum time in the given array
//T.C : O(log(min(time) * totalTrips))
//S.C : O(1)
class Solution {
public:
    bool possible(vector<int>& time, long long givenTime, int totalTrips) {
        long long actualTrips = 0;
        
        for(int &t : time) {
            actualTrips += givenTime/t;
        }
        
        return actualTrips >= totalTrips;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        
        long long l = 1;
        long long r = (long long) *min_element(begin(time), end(time)) * totalTrips;
        
        while(l < r) {
            
            long long mid_time = l + (r - l)/2;
            
            if(possible(time, mid_time, totalTrips)) {
                r = mid_time;
            } else {
                l = mid_time + 1;
            }
            
        }
        
        return l;
        
    }
};



/************************************************************ JAVA ************************************************************************/
//Approach - Using Binary Search - O(n * log(totalTrips * m)) -> where m = minimum time in the given array
//T.C : O(log(min(time) * totalTrips))
//S.C : O(1)
class Solution {
    public long minimumTime(int[] time, int totalTrips) {
        long left = 1;
        long right = (long) Arrays.stream(time).min().getAsInt() * totalTrips;
        
        while (left < right) {
            long mid = left + (right - left) / 2;
            
            if (possible(time, mid, totalTrips)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }

    private boolean possible(int[] time, long givenTime, int totalTrips) {
        long actualTrips = 0;
        
        for (int t : time) {
            actualTrips += givenTime / t;
            if (actualTrips >= totalTrips) {
                return true;  // Early exit if we already have enough trips
            }
        }
        
        return actualTrips >= totalTrips;
    }
}
