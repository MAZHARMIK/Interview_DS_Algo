/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=tFQWBeljuaU
    Company Tags                : Microsoft
    Leetcode Link               : https://leetcode.com/problems/delete-columns-to-make-sorted/
*/

//Approach - (Just compare letter by letter) - O(n*k)
//n = number of words in input
//k = length of each word (same for each word)
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        
        int k = strs[0].length();
        
        int count = 0;
        
        for(int i = 0; i<k; i++) {

            for(int j = 1; j<n; j++) {
                if(strs[j][i] < strs[j-1][i]) {
                    count++;
                    break;
                }
            }
        }
        
        return count;
    }
};
