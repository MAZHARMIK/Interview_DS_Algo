/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=9UxjDEBt8Vg
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/maximum-candies-allocated-to-k-children
*/



/****************************************************************** C++ ******************************************************************/
//Approach-1 (Brute Force)
//T.C : O(n * maxC), maxC = maximum candy value
//S.C : O(1)
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();

        int maxC = 0;
        int total = 0;
        for(int i = 0; i < n; i++) {
            total += candies[i];
            maxC = max(maxC, candies[i]);
        }

        if(total < k) {
            return 0;
        }


        //Brute force try from maxC till 1
        for(int c = maxC; c >= 1; c--) {
            long long count = 0;

            for(int i = 0; i < candies.size(); i++) {
                count += candies[i]/c; //how many children can get c candies from this pile
            }
            if(count >= k) {
                return c;
            }
        }

        return 0;
    }
};



//Approach-2 (Binary Search on answer)
//T.C : O(n * log(maxC)), maxC = maximum candy value
//S.C : O(1)
class Solution {
public:
    bool canDistr(vector<int>& candies, int mid, long long k) {
        int n = candies.size();

        for(int i = 0; i < n; i++) {
            k -= candies[i]/mid;

            if(k <= 0) { //all children got mid candies
                return true; //Early return
            }
        }

        return k <= 0; //all children got the mid candies
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();

        int maxC = 0;
        long long total = 0;
        for(int i = 0; i < n; i++) {
            total += candies[i];
            maxC = max(maxC, candies[i]);
        }

        if(total < k) {
            return 0;
        }

        int l = 1;
        int r = maxC;
        int result = 0;
        while(l <= r) {
            int mid = l + (r-l)/2;

            if(canDistr(candies, mid, k)) {
                result = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        return result;
    }
};



/****************************************************************** Java ******************************************************************/
//Approach-1 (Brute Force)
//T.C : O(n * maxC), maxC = maximum candy value
//S.C : O(1)
class Solution {
    public int maximumCandies(int[] candies, long k) {
        int n = candies.length;

        int maxC = 0;
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += candies[i];
            maxC = Math.max(maxC, candies[i]);
        }

        if (total < k) {
            return 0;
        }

        // Brute force try from maxC till 1
        for (int c = maxC; c >= 1; c--) {
            long count = 0;

            for (int i = 0; i < candies.length; i++) {
                count += candies[i] / c; // how many children can get c candies from this pile
            }
            if (count >= k) {
                return c;
            }
        }

        return 0;
    }
}


//Approach-2 (Binary Search on answer)
//T.C : O(n * log(maxC)), maxC = maximum candy value
//S.C : O(1)
class Solution {
    private boolean canDistr(int[] candies, int mid, long k) {
        int n = candies.length;

        for (int i = 0; i < n; i++) {
            k -= candies[i] / mid;

            if (k <= 0) { // all children got mid candies
                return true; // Early return
            }
        }

        return k <= 0; // all children got the mid candies
    }

    public int maximumCandies(int[] candies, long k) {
        int n = candies.length;

        int maxC = 0;
        long total = 0;
        for (int i = 0; i < n; i++) {
            total += candies[i];
            maxC = Math.max(maxC, candies[i]);
        }

        if (total < k) {
            return 0;
        }

        int l = 1;
        int r = maxC;
        int result = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (canDistr(candies, mid, k)) {
                result = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return result;
    }
}
