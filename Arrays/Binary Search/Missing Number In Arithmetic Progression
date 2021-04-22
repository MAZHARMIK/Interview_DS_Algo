/*
    Company Tags  : Paytm, FactSet, Ola Cabs
    Leetcode Link : https://leetcode.com/problems/missing-number-in-arithmetic-progression/
    
    Premimum Question:
     Given an array that represents elements of arithmetic progression in order. One element is missing in the progression, find the missing number.
    Examples:


    Input: arr[]  = {2, 4, 8, 10, 12, 14}
    Output: 6

    Input: arr[]  = {1, 6, 11, 16, 21, 31};
    Output: 26
*/

//Approach-1 O(n)

class Solution {
public:
    int findMissing(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)
            return -1;

        int a       = nums[0];
        int d       = nums[1]-nums[0];
        int missing = -1;
        for(int i = 1; i<n; i++) {
            int next_term = a+d;

            if(next_term != nums[i]) {
                missing = next_term;
                break;
            }

            a = nums[i];
        }
        return missing;
    }
};


//Approach-2 O(log(n)) Binary Search
class Solution {
public:
    int findMissing(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)
            return -1;

        int missing = -1;

        int low = 0, high = n-1;
        int mid = low+(high-low)/2;
        int d   = (nums[n-1] - nums[0])/n; //This is a good way to find d

        while(low <= high) {
            mid = low+(high-low)/2;

            if(nums[mid+1] - nums[mid] != d) {
                missing = nums[mid] + d;
                break;
            } else if(mid > 0 && nums[mid]-nums[mid-1] != d) {
                missing = nums[mid]-d;
                break;
            }

            if(nums[0]+mid*d == nums[mid])
                low = mid+1;
            else
                high = mid-1;
        }

        return missing;
    }
};
