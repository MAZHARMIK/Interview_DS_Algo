/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/make-array-elements-equal-to-zero
*/

/*********************************************************** C++ **************************************************/
//Approach-1 - (Simple simulation)
//T.C : O(n^ * m) 
//S.C : O(n)
class Solution {
public:
    bool isValid(vector<int>& nums, int count, int i, int direction) {
        vector<int> temp = nums;
        int idx = i;

        while (count > 0 && idx >= 0 && idx < nums.size()) {
            if (temp[idx] > 0) {
                temp[idx]--;
                direction *= -1;
                if (temp[idx] == 0) {
                    count--;
                }
            }
            idx += direction;
        }

        return count == 0; //all must become 0
    }

    int countValidSelections(vector<int>& nums) {
        int result = 0;
        int count = 0; //count of nums[i] != 0
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                count++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (isValid(nums, count, i, -1)) {
                    result++;
                }
                if (isValid(nums, count, i, 1)) {
                    result++;
                }
            }
        }

        return result;
    }
};



//Approach-2 - (Using cumulative sum)
//T.C : O(n) 
//S.C : O(1)
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();

        int result =0;
        int curr = 0;
        int S = accumulate(begin(nums), end(nums), 0);//for loop bhi likh sakte ho


        for(int i = 0; i < n; i++) {
            curr += nums[i]; //left sum

            int left  = curr;
            int right = S - left;

            if(nums[i] != 0) {
                continue;
            }

            if(left == right)
                result += 2;
            
            if(abs(left - right) == 1)
                result += 1;
        }

        return result;
    }
};


/*********************************************************** JAVA **************************************************/
//Approach-1 - (Simple simulation)
//T.C : O(n^ * m) 
//S.C : O(n)
class Solution {
    private boolean isValid(int[] nums, int count, int i, int direction) {
        int[] temp = nums.clone();
        int idx = i;

        while (count > 0 && idx >= 0 && idx < temp.length) {
            if (temp[idx] > 0) {
                temp[idx]--;
                direction *= -1;
                if (temp[idx] == 0) {
                    count--;
                }
            }
            idx += direction;
        }

        return count == 0; // all elements become 0
    }

    public int countValidSelections(int[] nums) {
        int n = nums.length;
        int result = 0;
        int count = 0;

        for (int num : nums) {
            if (num != 0) count++;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (isValid(nums, count, i, -1)) result++;
                if (isValid(nums, count, i, 1)) result++;
            }
        }

        return result;
    }
}


//Approach-2 - (Using cumulative sum)
//T.C : O(n) 
//S.C : O(1)
class Solution {
    public int countValidSelections(int[] nums) {
        int n = nums.length;
        int result = 0;
        int currSum = 0;
        int S = 0;

        for (int num : nums) {
            S += num;
        }

        for (int i = 0; i < n; i++) {
            currSum += nums[i];

            int left  = currSum;
            int right = S - left;

            if (nums[i] != 0) 
                continue;

            if (left == right)
                result += 2;
            else if (Math.abs(left - right) == 1)
                result++;
        }

        return result;
    }
}
