/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                :  Flipkart, VMWare, Accolite, Amazon, Microsoft, Snapdeal, ABCO, SAP Labs, Cisco, Rockstand
    Leetcode Qn Link            :  https://leetcode.com/problems/kth-largest-element-in-an-array/
*/

//Approach-1 Using Min-heap (T.C : n*logn)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //min heap
        priority_queue<int, vector<int>, greater<int>> minh;
        
        for(int i:nums) {
            minh.push(i);
            if(minh.size() > k)
                minh.pop();
        }
        
        return minh.top();
    }
};


//Approach-2 Using sorting (T.C : n*logn)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(begin(nums), end(nums), greater<int>());
        return nums[k - 1];
    }
};


//Approach-3 (Using QuickSelect Algorithm
//Time complexity: O(n) on average, O(n2) in the worst case (See video above for explanation)
