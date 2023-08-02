/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=T8hqjK94Fig
    Compnay Tags                : Accolite, Amazon, OYO Rooms, Samsung, Snapdeal, Citrix, Walmart, MAQ Software, Cisco, Apple
    Leetcode Qn Link            : https://leetcode.com/problems/permutations/
*/


//Approach-1 (Swapping elements in nums)
class Solution {
public:
    vector<vector<int>> result;
    int n;
    
    void solve(int idx, vector<int>& nums) {

        if(idx == n) {
            result.push_back(nums);
            return;
        }
        
        for(int i = idx; i < n; i++) {
            swap(nums[i], nums[idx]);
            
            solve(idx+1, nums);
            
            swap(nums[i], nums[idx]);
        }
        
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        
        solve(0, nums);
        
        return result;
    }
};


//Approach-2 (A very general Backtracking pattern which can help solve subsets, Subsets II, Permutations, Permutations II,  Combination Sum, Combination Sum II as well.
class Solution {
public:
    vector<vector<int>> result;
    unordered_set<int> st;
    int n;
    
    void solve(vector<int>& temp, vector<int>& nums) {

        if(temp.size() == n) {
            result.push_back(temp);
            return;
        }
        
        for(int i = 0; i<n; i++) {
            if(st.find(nums[i]) == st.end()) {
                temp.push_back(nums[i]);
                st.insert(nums[i]);

                solve(temp, nums);

                st.erase(nums[i]);
                temp.pop_back();
            }
        }
        
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        
        vector<int> temp;
        
        solve(temp, nums);
        
        return result;
    }
};
