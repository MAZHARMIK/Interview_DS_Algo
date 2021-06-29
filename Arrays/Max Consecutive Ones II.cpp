/*
    Company Tags  : Google (This was an incremental question on Max Consecutive Ones I)
    Leetcode Link : https://leetcode.com/problems/max-consecutive-ones-ii/
    
    Since this is a premium question, I am providing the question details below
*/

/*
Description

Given a binary array, find the maximum number of consecutive 1s in this array if you can flip at most one 0.

    The input array will only contain 0 and 1.
    The length of input array is a positive integer and will not exceed 10,000.
    
  Example 1:
	Input:  nums = [1,0,1,1,0]
	Output:  4
	Explanation:
	Flip the first zero will get the the maximum number of consecutive 1s.
	After flipping, the maximum number of consecutive 1s is 4.

Example 2:
	Input: nums = [1,0,1,0,1]
	Output:  3
	Explanation:
	Flip each zero will get the the maximum number of consecutive 1s.
	After flipping, the maximum number of consecutive 1s is 3.  
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int n = nums.size();
        vector<int> ones(n, 0);

        int count = 0;
        //Count 1s to left of a 0
        for(int i = 0; i<n; i++) {
            if(nums[i] == 0) {
                ones[i] = count;
                count = 0;
            } else {
                count++;
            }
        }

        count = 0;
        int result = 0;
        //Count ones to right of a 0 and find the result at the same time
        for(int i = n-1; i>=0; i--) {
            if(nums[i] == 0) {
                ones[i] += count;
                result = max(result, ones[i]+1); //What is I convert this 0 to one
                count = 0;
            } else {
                count++;
            }
        }

        return result;
    }
};


//Approach-2 (Using 2 pointer technique : This approach falls under Two pointer section inside Array as well)
class Solution {
public:
    void moveUntilOneCount(vector<int>& nums, int& count, int& i, int& j) {
        if(count > 1) {
            while(j <= i && count > 1) {
                if(nums[j] == 0) {
                    count--;
                }
                j++;
            }
        }
    }
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int count = 0;
        int result = 0;
        while(i < n) {
            if(nums[i] == 0) {
                count++;
                moveUntilOneCount(nums, count, i, j);
            }
            result = max(result, i-j+1);
            i++;
        }
        return result;
    }
};


//Approach-3 (Using 2 pointer technique but slight improvement)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int count = 0;
        int result = 0;
        while(i < n) {
            if(nums[i] == 0) {
                count++;
			}
			if(count > 1) { //here, k = 1
				count -= nums[j] == 0 ? 1 : 0; //We can decrement 0 only if we reject 0 from left window boundary	
				j++; //This will anyway increase
			}
            result = max(result, i-j+1);
            i++;
        }
        return result;
    }
};
