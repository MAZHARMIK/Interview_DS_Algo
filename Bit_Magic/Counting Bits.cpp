/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=uwOz378g3ew
      Company Tags                : AMAZON
      Leetcode Link               : https://leetcode.com/problems/counting-bits/
*/

//Approach-1 (Using built-in function) - __builtin_popcount - O(nlog(n))
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1);
        
        for(int i = 0; i<n+1; i++) {
            result[i] = __builtin_popcount(i); //log(n)
        }
        
        return result;
    }
};

//Approach-2 - T.C : O(n)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1);
        
        if(n == 0)
            return result;
        
        result[1] = 1;
        
        for(int i = 2; i < n+1; i++) {
            
            if(i%2 == 0) {
                result[i] = result[i/2];
            } else {
                result[i] = result[i/2] + 1;
            }
            
        }
        
        return result;
        
    }
};
