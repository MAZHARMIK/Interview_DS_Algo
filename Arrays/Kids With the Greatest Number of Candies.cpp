/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ZUEKt3TAYLc
    Company Tags                : NA
    Leetcode Link               : https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
*/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        
        int maxC = *max_element(begin(candies), end(candies));
        
        vector<bool> result(n, false);
        
        for(int i = 0; i<n; i++) {
            
            if(candies[i] + extraCandies >= maxC) {
                result[i] = true;
            }
            
        }
        return result;
    }
};
