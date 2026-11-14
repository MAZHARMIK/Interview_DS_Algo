/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn   : https://www.youtube.com/watch?v=QNR7kzSFbXU
    Company Tags                  : Will update soon
    Leetcode Link                 : https://leetcode.com/problems/minimum-positive-sum-subarray
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Super Brute Force)
//T.C : O(n*r)
//S.C : O(1)
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int result = INT_MAX;
    
        for (int i = 0; i < n; ++i) {
            int currSum = 0;

            for (int j = i; j < n && (j - i + 1) <= r; ++j) {
                currSum += nums[j];

                if ((j - i + 1) >= l && currSum > 0) {
                    result = min(result, currSum);
                }
            }
        }

        return result == INT_MAX ? -1 : result;    
    }
};


//Approach-2 (Improved Brute Force)
//T.C : O(n*(r-l+1))
//S.C : O(n)
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();

        vector<int> prefixSum(n, 0);

        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        int result = INT_MAX;
        for (int i = 0; i < n; i++) {

            for (int len = l; len <= r && i + len <= n; len++) {
                int j = i + len - 1;

                int sum = prefixSum[j] - (i > 0 ? prefixSum[i - 1] : 0);

                if (sum > 0) 
                    result = min(result, sum);
            }
        }

        return result == INT_MAX ? -1 : result;
    }
};



//Approach-3 (Using Sliding Window and Multiset)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();

        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        multiset<int> st;
        st.insert(0);

        int result = INT_MAX;

        for(int j = l-1; j < n; j++) {
            if(j - l >= 0) {
                st.insert(prefixSum[j-l]);
            }

            int outOld = j-r-1;
            if(outOld >= 0) {
                st.erase(st.find(prefixSum[outOld]));
            } else if(outOld == -1) {
                st.erase(st.find(0));
            }

            auto it = st.lower_bound(prefixSum[j]);
            if(it != begin(st)) {
                it--;
                result = min(result, prefixSum[j] - *it);
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};



/**************************************************************** JAVA ****************************************************************/
//Approach-1 (Super Brute Force)
//T.C : O(n*r)
//S.C : O(1)
class Solution {
    public int minimumSumSubarray(List<Integer> nums, int l, int r) {
        int n = nums.size();
        int result = Integer.MAX_VALUE;

        for (int i = 0; i < n; ++i) {
            int currSum = 0;

            for (int j = i; j < n && (j - i + 1) <= r; ++j) {
                currSum += nums.get(j);

                if ((j - i + 1) >= l && currSum > 0) {
                    result = Math.min(result, currSum);
                }
            }
        }

        return result == Integer.MAX_VALUE ? -1 : result;
    }
}


//Approach-2 (Improved Brute Force)
//T.C : O(n*(r-l+1))
//S.C : O(n)
class Solution {
    public int minimumSumSubarray(List<Integer> nums, int l, int r) {
        int n = nums.size();

        int[] prefixSum = new int[n];

        prefixSum[0] = nums.get(0);
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums.get(i);
        }

        int result = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {

            for (int len = l; len <= r && i + len <= n; len++) {
                int j = i + len - 1;

                int sum = prefixSum[j] - (i > 0 ? prefixSum[i - 1] : 0);

                if (sum > 0)
                    result = Math.min(result, sum);
            }
        }

        return result == Integer.MAX_VALUE ? -1 : result;
    }
}


//Approach-3 (Using Sliding Window and Multiset)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {

    // helper: insert one copy (multiset.insert)
    private void add(TreeMap<Integer, Integer> st, int val) {
        st.merge(val, 1, Integer::sum);
    }

    // helper: erase one copy (multiset.erase(multiset.find(val)))
    private void removeOne(TreeMap<Integer, Integer> st, int val) {
        int cnt = st.get(val);
        if (cnt == 1) st.remove(val);
        else st.put(val, cnt - 1);
    }

    public int minimumSumSubarray(List<Integer> nums, int l, int r) {
        int n = nums.size();

        int[] prefixSum = new int[n];
        prefixSum[0] = nums.get(0);
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums.get(i);
        }

        TreeMap<Integer, Integer> st = new TreeMap<>();
        add(st, 0);

        int result = Integer.MAX_VALUE;

        for (int j = l - 1; j < n; j++) {
            if (j - l >= 0) {
                add(st, prefixSum[j - l]);
            }

            int outOld = j - r - 1;
            if (outOld >= 0) {
                removeOne(st, prefixSum[outOld]);
            } else if (outOld == -1) {
                removeOne(st, 0);
            }

            // largest value strictly less than prefixSum[j]
            Integer lower = st.lowerKey(prefixSum[j]);
            if (lower != null) {
                result = Math.min(result, prefixSum[j] - lower);
            }
        }
        return result == Integer.MAX_VALUE ? -1 : result;
    }
}
