/*
    Company Tags  :  Amazon, D-E-Shaw, Ola Cabs
    Leetcode Link : https://leetcode.com/problems/single-element-in-a-sorted-array/
*/

//Approach : 1 (Using XOR operator) : O(n)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xor_Value = 0;
        
        for(int &num : nums) {
            xor_Value ^= num;
        }
        
        return xor_Value;
    }
};


//Approach : 2 (Using Binary Search) : O(log(n))
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        int mid;
        
        while(l < r) {
            mid = l + (r-l)/2;
            bool isEven = (r-mid)%2==0;
            
            if(nums[mid] == nums[mid+1]) {
                if(isEven) {
                    l = mid+2;
                } else {
                    r = mid-1;
                }
            } else if(nums[mid] == nums[mid-1]) {
                if(isEven) {
                    r = mid-2;
                } else {
                    l = mid+1;
                }
            } else {
                return nums[mid];
            }
        }
        
        return nums[l];
    }
};
