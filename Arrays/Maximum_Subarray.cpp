/*
    Company Tags  : MWare, Zoho, Flipkart, Morgan Stanley, Accolite, Amazon, Microsoft, OYO Rooms, Samsung, Snapdeal, 24*7 Innovation Labs
                    D-E-Shaw, FactSet, Hike, Housing.com, MakeMyTrip, MetLife, Ola Cabs, Oracle, Payu, Teradata, Visa, Walmart
    Leetcode Link : https://leetcode.com/problems/maximum-subarray/
*/

//Approach-1 (Time : O(n^2))
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n   = nums.size();
        for(int i = 1; i<n; i++) {
            nums[i] += nums[i-1];
        }
        int maxS = INT_MIN;
        
        for(int i = 0; i<n; i++) {
            for(int j = i; j<n; j++) {
                int end   =  nums[j];
                int start =  i > 0 ? nums[i-1] : 0;
                maxS = max(maxS, end-start);
            }
        }
        
        return maxS;
    }
};

//Approach-2 (Time : O(nlogn))
class Solution {
public:
    int divideConquer(vector<int>& nums, int l, int r) {
        if(l > r) {
            return INT_MIN;
        }
        
        int mid   = l + (r-l)/2;
        int Lsum  = divideConquer(nums, l, mid-1);
        int Rsum  = divideConquer(nums, mid+1, r);
        
        int leftSum  = 0;
        int rightSum = 0;
        int tempSum  =  0 ;
        for(int i = mid-1; i >= l; i--) {
            tempSum += nums[i];
            leftSum = max(leftSum, tempSum);
        }
        
        tempSum = 0;
        for(int i = mid+1; i <= r; i++) {
            tempSum += nums[i];
            rightSum = max(rightSum, tempSum);
        }
        
        return max({Lsum, Rsum, leftSum + rightSum + nums[mid]});
    }
    int maxSubArray(vector<int>& nums) {
        int n   = nums.size();
        
        return divideConquer(nums, 0, n-1);
    }
};

//Approach-3 (Time : O(n)) Kadane's Algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n       = nums.size();
        int sum     = nums[0];
        int maxSum  = nums[0];
        
        for(int i = 1; i<n; i++) {
            sum     = max(sum + nums[i], nums[i]);
            maxSum  = max(maxSum, sum);
        }
        
        return maxSum;
    }
};
