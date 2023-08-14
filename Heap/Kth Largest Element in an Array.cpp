/*
    MY YOUTUBE VIDEO ON THIS Qn :  Approach-1 and Approach-2 : https://www.youtube.com/watch?v=cI0shWNnB4o
                                   Approach-3 : <soon>
    Company Tags                :  Flipkart, VMWare, Accolite, Amazon, Microsoft, Snapdeal, ABCO, SAP Labs, Cisco, Rockstand
    Leetcode Qn Link            :  https://leetcode.com/problems/kth-largest-element-in-an-array/
*/

************************************************************ C++ ************************************************************
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





************************************************************ JAVA ************************************************************
//Approach-1 Using Min-heap (T.C : n*logn)
class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> minh = new PriorityQueue<>();
        for (int num: nums) {
            minh.add(num);
            if (minh.size() > k) {
                minh.remove();
            }
        }
        
        return minh.peek();
    }
}
    
//Approach-2 Using sorting (T.C : n*logn)
class Solution {
    public int findKthLargest(int[] nums, int k) {
        Arrays.sort(nums); //Ascending order
        return nums[nums.length - k];
    }
}


//Approach-3 (Using QuickSelect Algorithm
//Time complexity: O(n) on average, O(n2) in the worst case (See video above for explanation)
