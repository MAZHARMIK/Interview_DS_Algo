/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=tOo5RX2pt0g
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-time-to-repair-cars
*/



/****************************************************************** C++ ******************************************************************/
//Approach (Binary Search on Answer)
//T.C : O(n * log(maxRank * cars * cars))
//S.C : O(1)
class Solution {
public:
    typedef long long ll;

    bool isPossible(vector<int>& ranks, ll mid, int cars) {
        ll carsFixed = 0;

        for(int i = 0; i < ranks.size(); i++) {
            carsFixed += sqrt(mid/ranks[i]); //ignoring this
        }

        return carsFixed >= cars;

    }

    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();

        ll l = 1;
        int maxR = *max_element(begin(ranks), end(ranks));
        ll r = 1LL * maxR * cars * cars;

        ll result = -1;
        //T.C: O(n * log(maxR*cars*cars));
        while(l <= r) { //log(maxR * cars * cars)
            ll mid = l + (r-l)/2;

            if(isPossible(ranks, mid, cars)) { //O(n)
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
//Approach (Binary Search on Answer)
//T.C : O(n * log(maxRank * cars * cars))
//S.C : O(1)
class Solution {
    private boolean isPossible(int[] ranks, long mid, int cars) {
        long carsRepaired = 0;
        for (int rank : ranks) {
            carsRepaired += Math.sqrt(1.0 * mid / rank);
        }
        return carsRepaired >= cars;
    }

    public long repairCars(int[] ranks, int cars) {
        long l = 1;
        long r = 1L * cars * cars * Arrays.stream(ranks).max().orElse(Integer.MIN_VALUE);
        
        while (l < r) {
            long mid = l + (r - l) / 2;
            if (isPossible(ranks, mid, cars))
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
}
