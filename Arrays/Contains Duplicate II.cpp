/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=B5v3KZpRreQ
    Company Tags                : Airbnb, Palantir Technologies
    Leetcode Link               : https://leetcode.com/problems/contains-duplicate-ii/
    Using sliding window        : https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Sliding%20Window/Contains%20Duplicate%20II.cpp
*/
/**************************************** C++ ****************************************/
//T.C. :O(n)
//S.C. :O(n)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
        for(int i = 0; i<nums.size(); i++) {
            
            if(mp.find(nums[i]) != mp.end() &&  //check if present in map and abs(i-j) <= k
               abs(mp[nums[i]] - i) <= k)
                return true;
            else
                mp[nums[i]] = i; //{number, index}
            
        }
        
        return false;
    }
};

/**************************************** JAVA ****************************************/
//T.C. :O(n)
//S.C. :O(n)
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer, Integer> mp = new HashMap<>();
        
        for (int i = 0; i < nums.length; i++) {
            if (mp.containsKey(nums[i]) && Math.abs(mp.get(nums[i]) - i) <= k) {
                return true;
            } else {
                mp.put(nums[i], i); // {number, index}
            }
        }
        
        return false;
    }
}
