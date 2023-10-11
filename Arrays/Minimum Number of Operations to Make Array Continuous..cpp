/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=LqtcUyPBWrY
      Company Tags                : GOOGLE
      Leetcode Link               : https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/
*/

//NOTE : The problem is the same as "get the length of the longest subarray whose difference between min and max elements is N - 1". (Make sure to remove duplicate elements)
/*
Similar Leetcode Problems : 
Leetcode - 658 - Find K Closest Elements - 
Leetcode - 2779 - Maximum Beauty of an Array After Applying Operation - 
Leetcode - 220 - Contains Duplicate III
Leetcode - 1984 - Minimum Difference Between Highest and Lowest of K Scores
*/

/************************************************ C++ ************************************************/
//Approach-1 (Brute Force) - TLE
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        int result = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            
            int left_range  = nums[i]; //L
            int right_range = left_range + n - 1;
            
            int mehnat = 0;
            
            unordered_set<int> used;
            
            for(int j = 0; j < n; j++) {
                
                if(nums[j] >= left_range && nums[j] <= right_range && used.find(nums[j]) == used.end()) {
                    used.insert(nums[j]);
                    continue;
                } else {
                    mehnat++;
                }
                
            }
            
            result = min(result, mehnat);
            
        }
        
        return result;
    }
};

//Approach-2 (Optimal)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        set<int> st(begin(nums), end(nums));
        
        vector<int> temp(begin(st), end(st));
        
        int result = INT_MAX;
        
        for(int i = 0; i<temp.size(); i++) {
            
            int left_range  = temp[i];
            int right_range = left_range + n - 1;
            
            int j = upper_bound(begin(temp), end(temp), right_range) - begin(temp);
            
            int in_range  = j - i;
            int out_range = n - in_range;
            
            result = min(result, out_range);
            
        }
        
        return result;
    }
};



/************************************************ JAVA ************************************************/
//Approach-1 (Brute Force) - TLE
//T.C : O(n^2)
//S.C : O(n)
class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length;
        
        int result = Integer.MAX_VALUE;
        
        for (int i = 0; i < n; i++) {
            int leftRange = nums[i];
            int rightRange = leftRange + n - 1;
            
            int mehnat = 0;
            
            Set<Integer> used = new HashSet<>();
            
            for (int j = 0; j < n; j++) {
                if (nums[j] >= leftRange && nums[j] <= rightRange && !used.contains(nums[j])) {
                    used.add(nums[j]);
                } else {
                    mehnat++;
                }
            }
            
            result = Math.min(result, mehnat);
        }
        
        return result;
    }
}


//Approach-2 (Optimal)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length;
        int ans = n;
        
        HashSet<Integer> unique = new HashSet<>();
        for (int num : nums) {
            unique.add(num);
        }
        
        int[] newNums = new int[unique.size()];
        int index = 0;
        
        for (int num : unique) {
            newNums[index++] = num;
        }
            
        Arrays.sort(newNums);
        
        int j = 0;
        for (int i = 0; i < newNums.length; i++) {
            while (j < newNums.length && newNums[j] < newNums[i] + n) {
                j++;
            }

            int count = j - i;
            ans = Math.min(ans, n - count);
        }
        
        return ans;
    }
}
