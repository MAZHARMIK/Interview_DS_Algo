/*
    Company Tags  : Variation of this question has been asked in "Google and some other companies"
    Leetcode Link : https://leetcode.com/problems/partition-array-into-disjoint-intervals/
    If you notice Approach-2 below , it's Similar to Qn (Leetcode 768 - Max Chunks To Make Sorted II)
    Link : https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Max%20Chunks%20To%20Make%20Sorted%20II.cpp
*/

//Approach-1 (Brute Force : O(n^2) time)
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        
        int maxE = nums[0];
        
        for(int i = 0; i<n; i++) {
            maxE = max(maxE, nums[i]);
            int j = i+1;
            for(; j<n; j++) {
                if(nums[j] < maxE)
                    break;
            }
            if(j == n)
                return i+1;
        }
        
        return -1;
    }
};


//Approach-2 (Using a very popular concept min-max track from left and right)
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        
        /*
            When the maximum of left-partition is less than minimum of right-partition,
            that's the point where we draw the line of partition
            Similar to Leetcode-768 (Max Chunks To Make Sorted II)
        */
        
        //So calculate minimum from right;
        vector<int> minRight(n);
        minRight[n-1] = nums[n-1];
        for(int i = n-2; i>=0; i--) {
            minRight[i] = min(minRight[i+1], nums[i]);
        }
        
        int maxLeft = nums[0];
        for(int i = 0; i<n-1; i++) {
            maxLeft = max(maxLeft, nums[i]);
            
            if(maxLeft <= minRight[i+1])
                return i+1;
        }
        return -1;
    }
};

//Approach-3 (One loop solution with explained comments)
/*
	I noticed many people posting this solution with no elaborated comments.
	So I have tried to put comments on lines which are really confusing.
*/
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        
        int leftMax  = nums[0];
        int currMax  = nums[0];
        int len      = 1; //Qn says it is gauranteed that a partitioning exists
        
        for(int i = 1; i<n; i++) {
            if(nums[i] < leftMax) {
                /*
                    If nums[i] is less than maximum to left, it must go to left partition
                    so, increase the length of partition
                */
                len = i+1;
                
                leftMax = currMax;
                /*
                    why this ?
                    Exampel : {5, 0, 3, 8, 6, 0, 10}
                    Until i = 2, leftMax is 5
                    Now, when we reach i = 3, we see that it's not less than leftMax (i.e. 8 > 5)
                    So, we don't need to partition BUT we update our currMax = 8
                    Now, we go to i = 4, our leftMax is still 5 and currMax = 8
                    Now, we reach to i = 5, leftMax is still 5 and nums[i] is less than leftMax i.e. (0 < 5)
                    so, we need to update our the partition length to (i+1)
                    BUT, here's the catch, After i  = 5, we need to have the leftMax as 8 and not 5 anymore.
                    That's why we update leftMax to currMax
                    i.e. leftMax = currMax;
                */
            } else {
                currMax = max(currMax, nums[i]); //Explained in above comment
            }
        }
        
        return len;
    }
};
