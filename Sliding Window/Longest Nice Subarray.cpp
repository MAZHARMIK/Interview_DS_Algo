/*         Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/longest-nice-subarray/description/
*/


/********************************************************************** C++ **********************************************************************/
//Approach-1 (Brute Force)
//T.C : O(n^3)
//S.C : O(1)
class Solution {
public:
    bool isNice(vector<int>& nums, int start, int end) {
        int mask = 0;
        for (int i = start; i <= end; i++) {
            if ((mask & nums[i]) != 0) 
                return false;
            mask |= nums[i];
        }
        return true;
    }

    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isNice(nums, i, j)) {
                    result = max(result, j - i + 1);
                } else {
                    break; // No need to check further, as adding more elements will keep failing
                }
            }
        }

        return result;
    }
};


//Approach-2 (Better)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();

        int result = 0;

        for(int i = 0; i < n; i++) {
            int mask = 0;

            for(int j = i; j < n; j++) {
                if((mask & nums[j]) != 0) {
                    break;
                }

                result = max(result, j-i+1);
                mask = (mask | nums[j]);
            }
        }

        return result;
    }
};


//Approach-3 (Sliding Window Khandani Template)
//T.C : O(2*n) ~ O(n)
//S.C : O(1)
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        int j = 0;

        int result = 1;
        int mask = 0;

        while(j < n) {

            while((mask & nums[j]) != 0) { //keep shrinking
                mask = (mask ^ nums[i]);
                i++;
            }

            result = max(result, j-i+1);
            mask = (mask | nums[j]);
            j++;
        }

        return result;

    }
};


/********************************************************************** Java **********************************************************************/

//Approach-1 (Brute Force)
//T.C : O(n^3)
//S.C : O(1)
class Solution {
    public boolean isNice(int[] nums, int start, int end) {
        int mask = 0;
        for (int i = start; i <= end; i++) {
            if ((mask & nums[i]) != 0) 
                return false;
            mask |= nums[i];
        }
        return true;
    }

    public int longestNiceSubarray(int[] nums) {
        int n = nums.length;
        int result = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isNice(nums, i, j)) {
                    result = Math.max(result, j - i + 1);
                } else {
                    break; // No need to check further, as adding more elements will keep failing
                }
            }
        }

        return result;
    }
}


//Approach-2 (Better)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
    public int longestNiceSubarray(int[] nums) {
        int n = nums.length;
        int result = 0;

        for(int i = 0; i < n; i++) {
            int mask = 0;

            for(int j = i; j < n; j++) {
                if((mask & nums[j]) != 0) {
                    break;
                }

                result = Math.max(result, j - i + 1);
                mask = (mask | nums[j]);
            }
        }

        return result;
    }
}


//Approach-3 (Sliding Window Khandani Template)
//T.C : O(2*n) ~ O(n)
//S.C : O(1)
class Solution {
    public int longestNiceSubarray(int[] nums) {
        int n = nums.length;
        int i = 0;
        int j = 0;
        int result = 1;
        int mask = 0;

        while(j < n) {
            while((mask & nums[j]) != 0) { //keep shrinking
                mask = (mask ^ nums[i]);
                i++;
            }
            
            result = Math.max(result, j - i + 1);
            mask = (mask | nums[j]);
            j++;
        }

        return result;
    }
}
