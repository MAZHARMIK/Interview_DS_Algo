/*         Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=gX3dCYnHpug
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/maximize-subarrays-after-removing-one-conflicting-pair
*/


/********************************************************************** C++ **********************************************************************/
//Approach (Greedily maximizing the extra gains)
//T.C : O(n+p), p = total number of conflicting points, n = total points
//S.C : O(n)
#define ALL(x) begin(x), end(x)
class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        long long valid = 0;

        
        vector<vector<int>> conflictingPoints(n+1);
        //conflictingPoints[i] = {points which confliuct with i}

        for(auto &p : conflictingPairs) { //O(C)
            //(a, b)
            int a = min(p[0], p[1]);
            int b = max(p[0], p[1]);

            conflictingPoints[b].push_back(a); //{1,2,a,,,,b}
        }

        int maxConflict = 0;
        int secondMaxConflict = 0;

        vector<long long> extra(n+1, 0);
        //extra[i] = number of extra subarrays by removing the conflicting point i

        //O(n+P)
        //O(n)
        for(int end = 1; end <= n; end++) { //visiting each point and treating them as subarray ending at this point
            //total subarrays ending at this point 'end'
            
            //O(P)
            for(int &u : conflictingPoints[end]) { //check all conflicting points of end
                if(u >= maxConflict) {
                    secondMaxConflict = maxConflict;
                    maxConflict = u;
                } else if(u > secondMaxConflict) {
                    secondMaxConflict = u;
                }
            }

            valid += end - maxConflict;
            extra[maxConflict] += maxConflict - secondMaxConflict;
        }


        return valid + *max_element(ALL(extra)); //you could also write valid + *max_element(begin(extra), end(extra))
    }
};



/********************************************************************** JAVA **********************************************************************/
//Approach (Greedily maximizing the extra gains)
//T.C : O(n+p), p = total number of conflicting points, n = total points
//S.C : O(n)
class Solution {
    public long maxSubarrays(int n, int[][] conflictingPairs) {
        long valid = 0;

        // conflictingPoints[i] = list of points which conflict with i
        List<List<Integer>> conflictingPoints = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            conflictingPoints.add(new ArrayList<>());
        }

        // Build the conflicting points list
        for (int[] p : conflictingPairs) { 
            int a = Math.min(p[0], p[1]);
            int b = Math.max(p[0], p[1]);
            conflictingPoints.get(b).add(a);
        }

        int maxConflict = 0;
        int secondMaxConflict = 0;

        // extra[i] = number of extra subarrays by removing the conflicting point i
        long[] extra = new long[n + 1];

        // Process each end point of subarrays
        for (int end = 1; end <= n; end++) {
            // Check all conflicting points of 'end'
            for (int u : conflictingPoints.get(end)) {
                if (u >= maxConflict) {
                    secondMaxConflict = maxConflict;
                    maxConflict = u;
                } else if (u > secondMaxConflict) {
                    secondMaxConflict = u;
                }
            }
            // Count valid subarrays ending at 'end'
            valid += end - maxConflict;
            // Add extra subarrays count
            extra[maxConflict] += maxConflict - secondMaxConflict;
        }

        // Find the maximum value in extra array
        long maxExtra = 0;
        for (long val : extra) {
            if (val > maxExtra) {
                maxExtra = val;
            }
        }

        return valid + maxExtra;
    }
}
