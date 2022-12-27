/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=JpQaui_-a4c
    Company Tags                : <soon>
    Leetcode Link               : https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/
*/


//Filling the least one first : O(nlogn)
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        int count = 0;
        vector<int> vec(n);
        
        for(int i = 0; i<n; i++) {
            vec[i] = capacity[i] - rocks[i];
        }
        
        sort(begin(vec), end(vec));
        
        for(int i = 0; i<n; i++) {
            if(additionalRocks >= vec[i]) {
                additionalRocks -= vec[i];
                count++;
            } else
                break;
        }
        
        return count;
    }
};
