/*
    MY YOUTUBE VIDEO ON THIS Qn : <soon>
    Company Tags                : Airbnb, Palantir Technologies
    Leetcode Link               : https://leetcode.com/problems/contains-duplicate-ii/
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_set<int> st;
        
        int i = 0, j = 0;
        
        while(j < n) {
            
            //step-1
            if(abs(i-j) > k) { //abs(i-j) <= k
                st.erase(nums[i]);
                i++; //shrink
            }
            
            //past me dekha hai nums[j] ?
            if(st.find(nums[j]) != st.end()) {
                return true;
            }
            
            st.insert(nums[j]);
            j++;
            
        }
        
        return false;
        
    }
};
