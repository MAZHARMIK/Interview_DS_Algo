/*
    MY YOUTUBE VIDEO ON THIS Qn : <soon>
    Company Tags  : Google
    Leetcode Link : https://leetcode.com/problems/split-array-into-consecutive-subsequences/
*/

/*
  Summary :
  For an element arr[i] of the given array, it can either form a new subsequence or can be added to a subsequence ending at (arr[i] – 1).

  It is always better not to form a new subsequence as forming a new subsequence may result in some subsequences of length less than three.
  If there is no subsequence ending at (arr[i] – 1), there is no option but to form a new subsequence.

  If there are more than one subsequences that can accommodate the current element, always add the current element to the subsequence with
  the least number of elements, this will ensure the minimization of subsequences of length less than 3.
*/


class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> mp;
        unordered_map<int, int> prev;
        
        for(int &num : nums)
            mp[num]++;
        
        for(int &num : nums) {
            if(mp[num] <= 0) continue;
            
            if(prev[num] > 0) {
                prev[num]--;
                prev[num+1]++;
                mp[num]--;
            } else if(mp[num] > 0 && mp[num+1] > 0 && mp[num+2] > 0) {
                mp[num]--;
                mp[num+1]--;
                mp[num+2]--;
                prev[num+3]++;
            } else {
                return false;
            }
        }
        
        return true;
    }
};
