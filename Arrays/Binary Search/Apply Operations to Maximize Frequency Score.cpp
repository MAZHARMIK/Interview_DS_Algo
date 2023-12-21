/*
    My YouTube Video Link : https://www.youtube.com/watch?v=Iaz-8ZQYUvs
    Company Tags          : will update soon
    Leetcode Link         : https://leetcode.com/problems/apply-operations-to-maximize-frequency-score/
*/

/************************************ C++ ****************************************/
//T.C : O(n * log(n))
//S.C : O(n)
class Solution {
    typedef long long int ll;
    bool IsPossible (int len, const vector<int>& nums, const vector<ll>& prefix, const ll K, int n) {
        if(len == 0)
            return false;
        
        int i = 0;
        int j = len-1;
        
        while(j < n) {
            ll target_idx = (i+j) / 2;
            ll target     = nums[target_idx];
            
            
            ll operations_left  = 0;
            ll operations_right = 0;
            
            if(target_idx == 0) {
                operations_left = 0;
            } else {
                operations_left = abs(((target_idx - i) * target) - (prefix[target_idx-1] - (i > 0 ? prefix[i-1] : 0)));
            }
            
            operations_right    = abs(((j - target_idx) * target) - (prefix[j] - prefix[target_idx]));
          
            if(operations_right + operations_left <= K) {
                return true;
            }
            
            i++;
            j++;
            
        }
        
        return false;
    }
    
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        int n = nums.size();
        sort (nums.begin(), nums.end());
        
        vector<ll> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) 
            prefix[i] = prefix[i-1] + nums[i];
        
        int min_score     = 1;
        int max_score     = n;
        int result_score  = 1;
        
        while (min_score <= max_score) {
            int mid = (min_score + max_score) / 2;
            
            if (IsPossible(mid, nums, prefix, k, n)) {
                result_score = mid;
                min_score = mid + 1;
            } else {
                max_score = mid - 1;
            }
        }
        
        return result_score;
    }
};


/************************************ JAVA ****************************************/
//T.C : O(n * log(n))
//S.C : O(n)
class Solution {
    private boolean isPossible(int len, int[] nums, long[] prefix, long k, int n) {
        if (len == 0)
            return false;

        int i = 0;
        int j = len - 1;

        while (j < n) {
            long targetIdx = (i + j) / 2;
            long target = nums[(int) targetIdx];

            long operationsLeft;
            long operationsRight;

            if (targetIdx == 0) {
                operationsLeft = 0;
            } else {
                operationsLeft = Math.abs(((targetIdx - i) * target)
                        - (prefix[(int) targetIdx - 1] - (i > 0 ? prefix[i - 1] : 0)));
            }

            operationsRight = Math.abs(((j - targetIdx) * target) - (prefix[j] - prefix[(int) targetIdx]));

            if (operationsRight + operationsLeft <= k) {
                return true;
            }

            i++;
            j++;
        }

        return false;
    }

    public int maxFrequencyScore(int[] nums, long k) {
        int n = nums.length;
        Arrays.sort(nums);

        long[] prefix = new long[n];
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + nums[i];

        int minScore = 1;
        int maxScore = n;
        int resultScore = 1;

        while (minScore <= maxScore) {
            int mid = (minScore + maxScore) / 2;

            if (isPossible(mid, nums, prefix, k, n)) {
                resultScore = mid;
                minScore = mid + 1;
            } else {
                maxScore = mid - 1;
            }
        }

        return resultScore;
    }
}
