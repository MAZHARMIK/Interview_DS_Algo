/*
    Company Tags  : Adobe
    Leetcode Link : https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
*/

//Approach-1 (Naive, find all subarrays and get your result)

//Approach-2 (Time : O(n))
/*
	Let's take an Example shown below : 
    L = 2
    R = 3
    prevCount = 0;
    Count     = 0;
    {2,    1,    1,    4,    3}
     i
     j
     
     L <= nums[j] <= R
     So, we find total number of subarrays ending at j
     i.e.
     {2}
     Count += j-i+1
     prevCOunt = j-i+1 = 1  //(You will get to know later why I am saving this prevCount)
     i.e. Count = 1
     
     
    {2,    1,     1,    4,    3}
     i
           j
    
    nums[j] < L
    Let's look at subarrays ending at this j
    {1}     -> We can't take it because maximum is less then L
    {2, 1}  -> We can take it because maximum is in range [L, R]
    
    Total number of subarrays ending at this j will be equal to total subarrays which we could make previously
    So, we keep track of how many subarrays we could make previsously to this j (prevCount)
    Count += prevCount;
    i.e. Count = 2
    
    
    {2,    1,     1,    4,    3}
     i
                  j
    nums[j] < L
    Let's look at subarrays ending at this j
    {1}       -> We can't take it because maximum is less then L
    {1, 1}    -> We can't take it because maximum is less than L
    {2, 1, 1} -> We can take it because maximum (2) is in range [L, R]
    
    Total number of subarrays ending at this j will be equal to total subarrays which we could make previously
    So, we keep track of how many subarrays we could make previsously to this j (prevCount)
    Count += prevCount;
    i.e. Count = 3
    
    {2,    1,     1,    4,    3}
     i
                        j
    
    nums[j] > R
    Let's look at subarrays ending at this j
    {4}          -> We can't take it because maximum is greater then R
    {1, 4}       -> We can't take it because maximum is greater then R
    {1, 1, 4}    -> We can't take it because maximum is greater then R
    {2, 1, 1, 4} -> We can't take it because maximum is greater then R
    
    Total number of subarrays ending at this j will be 0, so for further iteration my prevCount = 0;
    prevCount = 0;
    And, this j can't be a part of any subarray now, so we move i to (j+1)
    
    
    {2,    1,     1,    4,    3}
                              i
                              j
    
    This is same as case-1
    Count += j-i+1 = 4-4+1;
    i.e. Count = 4
    prevCount = j-i+1 = 1;
    
*/

//Code
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int L, int R) {
        int i = 0, j = 0;
        int count = 0;
        int prevC = 0;
        int n = nums.size();
        while(j < n) {
            if(nums[j] >= L && nums[j] <= R) {
                prevC   = j-i+1;
                count += prevC;
            } else if(nums[j] < L) {
                count += prevC;
            } else {
                i     = j+1;
                prevC = 0;
            }
            j++;
        }

        return count;
    }
};
