/*     Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    What is Meet In The Middle  : https://www.youtube.com/watch?v=NCr27WYjCH4
    Company Tags                : Will update later
    CSES Link                   : https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference
*/


/******************************************************************************* C++ ************************************************************************************************/
//Approach (Using MITM)
//T.C : O(n * 2^n)  where n = N/2  →  O(N * 2^(N/2))
//S.C : O(2^n)      where n = N/2  →  O(2^(N/2))
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int N = nums.size(); //2*n

        int S = accumulate(begin(nums), end(nums), 0);

        int n = N/2;

        int n1 = n; //left side
        int n2 = n; //right side

        //sumsLeft : size -> {subsetSums}
        unordered_map<int, vector<int>> sumsLeft;
        for(int mask = 0; mask < (1 << n1); mask++) {
            int s = 0; //subset sum
            int count = 0;

            for(int i = 0; i < n1; i++) {
                if(mask & (1 << i)) {
                    s += nums[i];
                    count++;
                }
            }
            sumsLeft[count].push_back(s);
        }

        //sumsRight : size -> {subsetSums}
        unordered_map<int, vector<int>> sumsRight;
        for(int mask = 0; mask < (1 << n2); mask++) {
            int s = 0; //subset sum
            int count = 0;

            for(int i = 0; i < n2; i++) {
                if(mask & (1 << i)) {
                    s += nums[n1+i];
                    count++;
                }
            }
            sumsRight[count].push_back(s);
        }

        //NOTE : Sorting a bucket of size b costs O(b log b). Time Complexity -  O(2^n · log(2^n)) = O(n · 2^n).
        for(int count = 0; count <= n2; count++) {
            //sumsRight[count] this is my vector of subset sum having subset of size count
            sort(begin(sumsRight[count]), end(sumsRight[count]));
        }

        int minValue = INT_MAX; //abs(2*s1 - S)

        for(int k = 0; k <= n1; k++) {
            int m = n-k; //left hand side me k elements hai to right hand side me n-k elements

            for(int leftSubSum : sumsLeft[k]) {
                int need = (S - 2*leftSubSum)/2;

                int low = lower_bound(begin(sumsRight[m]), end(sumsRight[m]), need) - begin(sumsRight[m]);

                if(low < sumsRight[m].size()) {
                    int rightSubSum = sumsRight[m][low];
                    minValue = min(minValue, abs(2*(leftSubSum + rightSubSum) - S));
                }

                if(low-1 >= 0) {
                    int rightSubSum = sumsRight[m][low-1];
                    minValue = min(minValue, abs(2*(leftSubSum + rightSubSum) - S));
                }
            }
        }

        return minValue;

    }
};



/******************************************************************************* JAVA ************************************************************************************************/
//Approach (Using MITM)
//T.C : O(n * 2^n)  where n = N/2  →  O(N * 2^(N/2))
//S.C : O(2^n)      where n = N/2  →  O(2^(N/2))
class Solution {
    public int minimumDifference(int[] nums) {
        int N = nums.length; //2*n
        int S = 0;
        for(int num : nums) S += num;
        int n = N/2;
        int n1 = n; //left side
        int n2 = n; //right side
        //sumsLeft : size -> {subsetSums}
        Map<Integer, List<Integer>> sumsLeft = new HashMap<>();
        for(int mask = 0; mask < (1 << n1); mask++) {
            int s = 0; //subset sum
            int count = 0;
            for(int i = 0; i < n1; i++) {
                if((mask & (1 << i)) != 0) {
                    s += nums[i];
                    count++;
                }
            }
            sumsLeft.computeIfAbsent(count, key -> new ArrayList<>()).add(s);
        }
        //sumsRight : size -> {subsetSums}
        Map<Integer, List<Integer>> sumsRight = new HashMap<>();
        for(int mask = 0; mask < (1 << n2); mask++) {
            int s = 0; //subset sum
            int count = 0;
            for(int i = 0; i < n2; i++) {
                if((mask & (1 << i)) != 0) {
                    s += nums[n1+i];
                    count++;
                }
            }
            sumsRight.computeIfAbsent(count, key -> new ArrayList<>()).add(s);
        }
        //NOTE : Sorting a bucket of size b costs O(b log b). Time Complexity -  O(2^n · log(2^n)) = O(n · 2^n).
        for(int count = 0; count <= n2; count++) {
            //sumsRight[count] this is my vector of subset sum having subset of size count
            Collections.sort(sumsRight.computeIfAbsent(count, key -> new ArrayList<>()));
        }
        int minValue = Integer.MAX_VALUE; //abs(2*s1 - S)
        for(int k = 0; k <= n1; k++) {
            int m = n-k; //left hand side me k elements hai to right hand side me n-k elements
            List<Integer> leftBucket = sumsLeft.getOrDefault(k, new ArrayList<>());
            for(int leftSubSum : leftBucket) {
                int need = (S - 2*leftSubSum)/2;
                List<Integer> rightBucket = sumsRight.getOrDefault(m, new ArrayList<>());
                int low = lowerBound(rightBucket, need);
                if(low < rightBucket.size()) {
                    int rightSubSum = rightBucket.get(low);
                    minValue = Math.min(minValue, Math.abs(2*(leftSubSum + rightSubSum) - S));
                }
                if(low-1 >= 0) {
                    int rightSubSum = rightBucket.get(low-1);
                    minValue = Math.min(minValue, Math.abs(2*(leftSubSum + rightSubSum) - S));
                }
            }
        }
        return minValue;
    }

    //returns index of first element >= need (insertion point), i.e. C++ lower_bound
    private int lowerBound(List<Integer> list, int need) {
        int lo = 0, hi = list.size();
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if(list.get(mid) < need) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
}
