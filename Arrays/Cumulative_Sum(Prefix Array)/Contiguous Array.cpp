/*    Scroll down to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS QN : 
    Company Tags                : Meta, Google
    Leetcode Link               : https://leetcode.com/problems/contiguous-array/
    
    NOTES - This falls under the same pattern as Leetcode - 560, 930, 1074
    Leetcode-560, 1074 - https://youtu.be/-SWrz90jCUM?si=9dnkn65t_pgeHgyA
    Leetcode 930 - https://youtu.be/5Quv9nnZs34?si=aMNPNqLGPaoluWrR
*/


/********************************************************************** C++ **********************************************************************/
//Using the same pattern code
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        
        unordered_map<int, int> mp;
        int currSum = 0;
        int maxL = 0;
        mp[0] = -1;
        for(int i = 0; i<n; i++) {
           
            currSum += (nums[i] == 1) ? 1 : -1;
            
            if(mp.find(currSum) != mp.end()) {
                maxL = max(maxL, i-mp[currSum]);
            } else
                mp[currSum] = i;
        }
        
        return maxL;
    }
};


/********************************************************************** JAVA **********************************************************************/
//Using the same pattern code
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int findMaxLength(int[] nums) {
        int n = nums.length;
        if (n == 1)
            return 0;
        
        HashMap<Integer, Integer> mp = new HashMap<>();
        int currSum = 0;
        int maxL = 0;
        
        mp.put(0, -1);
        
        for (int i = 0; i < n; i++) {
            currSum += (nums[i] == 1) ? 1 : -1;
            if (mp.containsKey(currSum)) {
                maxL = Math.max(maxL, i - mp.get(currSum));
            } else
                mp.put(currSum, i);
        }
        return maxL;
    }
}
