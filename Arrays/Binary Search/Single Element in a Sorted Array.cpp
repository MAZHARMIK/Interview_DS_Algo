/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=cw5XhYeAU5o&list=PLpIkg8OmuX-LkgtrEF7eyyYWJM3m5tVQY&index=4
    ╔═╦╗╔╦╗╔═╦═╦╦╦╦╗╔═╗
    ║╚╣║║║╚╣╚╣╔╣╔╣║╚╣═╣
    ╠╗║╚╝║║╠╗║╚╣║║║║║═╣
    ╚═╩══╩═╩═╩═╩╝╚╩═╩═╝
    Company Tags                : Amazon, D-E-Shaw, Ola Cabs, Codenation, Qualcomm, Microsoft
    Leetcode Link               : https://leetcode.com/problems/single-element-in-a-sorted-array/
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
        
        return nums[l]; //or, nums[r]
    }
};


//Approach : 3 (Another similar to Approach-2)
/*
    Some example to do a dry run to understand better:
    {1, 1, 2, 2, 3, 4, 4}
    {1, 1, 2, 3, 3}
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        int l = 0;
        int h = n-1;
        
        while(l < h) {
            int mid = l + (h-l)/2;
            
            bool isEven = (h-mid)%2 == 0;
            
            if(nums[mid] == nums[mid+1]) {
                if(isEven) {
                    l = mid+2;
                } else {
                    h = mid-1;
                }
            } else {
                if(isEven) {
                    h = mid;
                } else {
                    l = mid+1;
                }
            }
        }
        
        return nums[h];
    }
};
