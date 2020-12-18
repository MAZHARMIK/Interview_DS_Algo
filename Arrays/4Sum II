/*
    Company Tags  : NIL (Let me know when you get it :-) )
    Leetcode Link : https://leetcode.com/problems/4sum-ii/
*/

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<int, int> mp;
        
        for(int i:A) {
            for(int j:B) {
                mp[i+j]++;
            }
        }
        
        int count = 0;
        for(int k:C) {
            for(int l:D) {
                int target = -(k+l);
                count += mp[target];
            }
        }
        return count;
    }
};
