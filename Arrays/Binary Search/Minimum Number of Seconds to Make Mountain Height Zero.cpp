/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero
*/



/****************************************************************** C++ ******************************************************************/
//Approach (Binary search on answer)
//T.C : O(n * log(Tmax * mountainHeight^2), where Tmax = maximum time among all workers in the input, n = length of workerTimes
//S.C : O(1)
class Solution {
public:
    typedef long long ll;

    bool Check(ll mid, vector<int>& workerTimes, int mH) {
        ll h = 0;

        for(int &t : workerTimes) {
            h += (ll)(sqrt(2.0 * mid/t + 0.25) - 0.5);

            if(h >= mH) {
                return true;
            }
        }

        return h >= mH;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int maxTime = *max_element(begin(workerTimes), end(workerTimes));
        ll l = 1;
        ll r = (ll)maxTime * mountainHeight * (mountainHeight+1)/2;

        ll result = 0;

        while(l <= r) {
            ll mid = l + (r-l)/2;

            if(Check(mid, workerTimes, mountainHeight)) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return result;
    }
};



/****************************************************************** JAVA ******************************************************************/
//Approach (Binary search on answer)
//T.C : O(n * log(Tmax * mountainHeight^2), where Tmax = maximum time among all workers in the input, n = length of workerTimes
//S.C : O(1)
class Solution {
    private boolean check(long mid, int[] workerTimes, int mH) {
        long h = 0;

        for (int t : workerTimes) {
            h += (long)(Math.sqrt(2.0 * mid / t + 0.25) - 0.5);

            if (h >= mH) {
                return true;
            }
        }

        return h >= mH;
    }

    public long minNumberOfSeconds(int mountainHeight, int[] workerTimes) {
        int maxTime = 0;
        for (int t : workerTimes) 
            maxTime = Math.max(maxTime, t);

        long l = 1;
        long r = (long) maxTime * mountainHeight * (mountainHeight + 1) / 2;

        long result = 0;

        while (l <= r) {
            long mid = l + (r - l) / 2;

            if (check(mid, workerTimes, mountainHeight)) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return result;
    }
}
