/*   Scroll below to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=9MLiRUIbzvs
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/
*/

/************************************************** C++ **************************************************/
//Approach-1
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int result = -1;
        
        for (int &i : nums) {
            for (int &j : nums) {
                // If there exists a number j such that i is the negative of j
                if (i == -j) {
                    // Update the answer to the maximum of current ans and absolute value of i
                    result = max(result, abs(i));
                }
            }
        }

        return result;
    }
};

//Approach-2 (Using Sorting + 2-Pointers)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int i = 0;
        int j = nums.size() - 1;
        
        while (i < j) {
            if (-nums[i] == nums[j]) {
                return nums[j];
            } 
            else if (-nums[i] < nums[j]) { 
                j--;
            }
            else { 
                i++;
            }
        }
        return -1;
    }
};


//Approach-3 (Using set)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> seen;

        int result = -1;

        for(int num : nums) {
            if (seen.count(-num)) {
                result = max(result, abs(num));
            }
            seen.insert(num);
        }
        
        return result;
    }
};


//Approach-4 (Using nums[i] as index)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int result = -1;
   
        int arr[2001] = {0};

        for (int num : nums) {

            if (arr[-num + 1000] == 1)
                result = max(result, abs(num));

            // Mark the current number as seen
            arr[num + 1000] = 1;
        }

        return result;
    }
};


/************************************************** JAVA **************************************************/
//Approach-1
//T.C : O(n^2)
//S.C : O(1)
class Solution {
    public int findMaxK(int[] nums) {
        int result = -1;

        for (int i : nums) {
            for (int j : nums) {
                // If there exists a number j such that i is the negative of j
                if (i == -j) {
                    // Update the answer to the maximum of current ans and absolute value of i
                    result = Math.max(result, Math.abs(i));
                }
            }
        }

        return result;
    }
}


//Approach-2 (Using Sorting + 2-Pointers)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int findMaxK(int[] nums) {
        Arrays.sort(nums);

        int i = 0;
        int j = nums.length - 1;
        
        while (i < j) {
            if (-nums[i] == nums[j]) {
                return nums[j];
            } 
            else if (-nums[i] < nums[j]) { 
                j--;
            }
            else { 
                i++;
            }
        }
        return -1;
    }
}


//Approach-3 (Using set)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int findMaxK(int[] nums) {
        HashSet<Integer> seen = new HashSet<>();
        int result = -1;

        for (int num : nums) {
            if (seen.contains(-num)) {
                result = Math.max(result, Math.abs(num));
            }
            seen.add(num);
        }
        
        return result;
    }
}


//Approach-4 (Using nums[i] as index)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int findMaxK(int[] nums) {
        int result = -1;
        int[] arr = new int[2001];

        for (int num : nums) {
            if (arr[-num + 1000] == 1) {
                result = Math.max(result, Math.abs(num));
            }
            // Mark the current number as seen
            arr[num + 1000] = 1;
        }

        return result;
    }
}
