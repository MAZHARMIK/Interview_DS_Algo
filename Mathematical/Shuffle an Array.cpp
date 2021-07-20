/*
    Company Tags  : NIL (Let me know when you find it) :-)
    Leetcode Link : 
*/

class Solution {
public:
    vector<int> nums;
    int n;
    Solution(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        srand(time(0));
    }
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        vector<int> result(nums);
        for(int i = 0; i<n; i++) {
            int idx = rand()%(n-i);
                
            swap(result[i], result[i+idx]);
        }
        return result;
    }
  
    /*ALTERNATIVE "Fisher–Yates shuffle Algorithm"
     vector<int> shuffle() {
        vector<int> result(nums);
        for(int i = n-1; i > 0; i--) {
            int idx = rand()%(i+1); //generates index from 0 to i
                
            swap(result[i], result[idx]);
        }
        return result;
    }
    */
};
