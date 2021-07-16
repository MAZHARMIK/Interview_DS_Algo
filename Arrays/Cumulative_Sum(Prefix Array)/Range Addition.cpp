/*
    Company Tags  : Google
    Leetcode Link : https://leetcode.com/problems/range-addition/
    
    Since, it's a premium Qn, I have provided the Description as well
    
    Description
    Assume you have an array of length n initialized with all 0's and are given k update operations.
    Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element
    of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.
    Return the modified array after all k operations were executed.
    
    Example : 
        Given:
        length = 5,
        updates = 
        [
          [1,  3,  2],
          [2,  4,  3],
          [0,  2, -2]
        ]
        return [-2, 0, 3, 5, 3]

        Explanation:
        Initial state:
        [ 0, 0, 0, 0, 0 ]

        After applying operation [1, 3, 2]:
        [ 0, 2, 2, 2, 0 ]

        After applying operation [2, 4, 3]:
        [ 0, 2, 5, 5, 3 ]

        After applying operation [0, 2, -2]:
        [-2, 0, 3, 5, 3 ]
    
*/


//Approach - 1 : (Brute Force) Time - O(Q*n)
//Q = number of queries
//n = max distance between start and end
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
        vector<int> nums(length);

        for(vector<int> &vec : updates) {
            int start  = vec[0];
            int end    = vec[1];
            int update = vec[2];

            for(int i = start; i<= end; i++) {
                nums[i] += update;
            }
        }

        return nums;
    }
};

//Approach-2 (Using concept of Cumulative Sum (Prefix Sum)) : Time : O(Q+n)
/*
  Logic : Only update the "start" index because the further updates ( > start) will be taken
  care while doing cumulative sum.
  But we don't want elements after "end" index to be updated, so we substract the update_value
  from ("end"+1) index because cuulative sum will even things out for me.
*/
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
        vector<int> nums(length);

        for(vector<int> &vec : updates) {
            int start    = vec[0];
            int end_next = vec[1]+1;
            int update   = vec[2];
            
            nums[start] += update;
            if(end_next < length)
                nums[end_next] -= update;

        }

        for(int i = 1; i<length; i++)
            nums[i] += nums[i-1];

        return nums;
    }
};
