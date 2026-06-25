/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update later
    Leetcode-3737 Link          : https://leetcode.com/problems/count-subarrays-with-majority-element-i
    Leetcode-3739 Link          : https://leetcode.com/problems/count-subarrays-with-majority-element-ii
*/


/************************************************************ C++ *****************************************************/
//Approach-1 (Brute Force) - PART I Accepted, PART II TLE
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int result = 0;

        for (int i = 0; i < n; ++i) {
            int count = 0;

            for (int j = i; j < n; ++j) {
                count += (nums[j] == target ? 1 : -1);

                if (count > 0) {
                    result++;
                }

            }
        }

        return result;
    }
};



//Approach-2 (Brute Force Prefix Sum) - PART I Accepted, PART II TLE
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(nums[i] == target)
                nums[i] = 1;
            else
                nums[i] = -1;
        }

        for(int i = 1; i < n; i++) {
            nums[i] += nums[i-1];
        }

        long long ans = 0;

        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                int sum = nums[r] - ((l > 0) ? nums[l-1] : 0);

                if(sum > 0)
                    ans++;
            }
        }

        return ans;

    }
};



//Approach-3 (Optimal Using Map) PART I Accepted, PART II TLE (Instead of map you can use an array of size 2*n+1 as well because we can have cumulaive sum from -n to +n)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        //Instead of map you can use an array of size 2*n+1 as well because we can have cumulaive sum from -n to +n)
        unordered_map<int,int> mp;   // mp[cumSum] = frequency of how many times cumSum has occurred
        
        int currSum = 0;
        
        mp[0] = 1; //we have seen cumSum = 0 in the beginning once

        long long validLeftPoints = 0;

        int result = 0;

        for (int x : nums) {
            if (x == target) {
                validLeftPoints += mp[currSum];
                currSum++;
            } else {
                currSum--;
                validLeftPoints -= mp[currSum];
            }

            mp[currSum]++;

            result += validLeftPoints;
        }

        return result;
    }
};




/************************************************************ JAVA *****************************************************/
//Approach-1 (Brute Force) - PART I Accepted, PART II TLE
//T.C : O(n^2)
//S.C : O(1)
class Solution {
    public int countMajoritySubarrays(int[] nums, int target) {
        int n = nums.length;
        int result = 0;
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = i; j < n; ++j) {
                count += (nums[j] == target ? 1 : -1);
                if (count > 0) {
                    result++;
                }
            }
        }
        return result;
    }
}


//Approach-2 (Brute Force Prefix Sum) - PART I Accepted, PART II TLE
//T.C : O(n^2)
//S.C : O(1)
class Solution {
    public int countMajoritySubarrays(int[] nums, int target) {
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            if (nums[i] == target)
                nums[i] = 1;
            else
                nums[i] = -1;
        }
        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }
        long ans = 0;
        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                int sum = nums[r] - ((l > 0) ? nums[l - 1] : 0);
                if (sum > 0)
                    ans++;
            }
        }
        return (int) ans;
    }
}


//Approach-3 (Optimal Using Map) PART I Accepted, PART II TLE (Instead of map you can use an array of size 2*n+1 as well because we can have cumulative sum from -n to +n)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public long countMajoritySubarrays(int[] nums, int target) {
        //Instead of map you can use an array of size 2*n+1 as well because we can have cumulative sum from -n to +n
        Map<Integer, Integer> mp = new HashMap<>();   // mp[cumSum] = frequency of how many times cumSum has occurred

        int currSum = 0;

        mp.put(0, 1); //we have seen cumSum = 0 in the beginning once
        long validLeftPoints = 0;
        long result = 0;
        for (int x : nums) {
            if (x == target) {
                validLeftPoints += mp.getOrDefault(currSum, 0);
                currSum++;
            } else {
                currSum--;
                validLeftPoints -= mp.getOrDefault(currSum, 0);
            }
            mp.merge(currSum, 1, Integer::sum);
            result += validLeftPoints;
        }
        return result;
    }
}
