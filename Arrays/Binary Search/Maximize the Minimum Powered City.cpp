/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=CAvYhc74Eio
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/maximize-the-minimum-powered-city
*/



/****************************************************************** C++ ******************************************************************/
//Approach (Binary search along with Difference Array Technique for optimisation
//T.C : O(n * log(sum+k)), sum = sum of station values
//S.C : O(n)
class Solution {
public:

    bool check(long long mid, vector<long long>& diff, int r, int k, int n) {
        vector<long long> tempDiff = diff;

        long long cumSum = 0; //it will give power of a city at any point of time

        for(int i = 0; i < n; i++) {
            cumSum += tempDiff[i];

            if(cumSum < mid) {
                long long need = mid - cumSum;
                if(need > k) {
                    return false;
                }

                k -= need;
                cumSum += need; //gredily I had chosen to add station on the city which can cover more range

                //i......X.....i+2*r
                if(i + 2*r + 1 < n)
                    tempDiff[i+2*r+1] -= need; //applying difference array technique
            }
        }

        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();

        vector<long long> diff(n, 0);

        for(int i = 0; i < n; i++) {
            diff[max(0, i-r)] += stations[i];

            if(i + r + 1 < n)
                diff[i+r+1] -= stations[i];
        }

        long long left  = *min_element(begin(stations), end(stations));
        long long right = accumulate(begin(stations), end(stations), 0LL) + k;


        long long result = 0;

        //T.C : n * log(sum)
        while(left <= right) {
            long long mid = left + (right - left)/2;

            if(check(mid, diff, r, k, n)) {
                result = mid;
                left = mid+1;
            } else {
                right = mid-1;
            }
        }

        return result;
    }
};




/****************************************************************** JAVA ******************************************************************/
//Approach (Binary search along with Difference Array Technique for optimisation
//T.C : O(n * log(sum+k)), sum = sum of station values
//S.C : O(n)
class Solution {

    private boolean check(long mid, long[] diff, int r, long k, int n) {
        long[] tempDiff = Arrays.copyOf(diff, n);
        long cumSum = 0;

        for (int i = 0; i < n; i++) {
            cumSum += tempDiff[i];

            if (cumSum < mid) {
                long need = mid - cumSum;
                if (need > k) {
                    return false;
                }

                k -= need;
                cumSum += need;

                // apply difference array logic
                if (i + 2L * r + 1 < n) {
                    tempDiff[(int)(i + 2L * r + 1)] -= need;
                }
            }
        }
        return true;
    }

    public long maxPower(int[] stations, int r, int k) {
        int n = stations.length;
        long[] diff = new long[n];

        // Build difference array
        for (int i = 0; i < n; i++) {
            int left = Math.max(0, i - r);
            int right = i + r + 1;
            diff[left] += stations[i];
            if (right < n) diff[right] -= stations[i];
        }

        long left = Arrays.stream(stations).min().getAsInt();
        long right = Arrays.stream(stations).asLongStream().sum() + k;
        long result = 0;

        // Binary search
        while (left <= right) {
            long mid = left + (right - left) / 2;

            if (check(mid, diff, r, k, n)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
}
