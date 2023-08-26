/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=DlgGx8GRo9M
      Company Tags                : Amazon, PayU, Cisco, Zoho
      Leetcode Link               : https://leetcode.com/problems/maximum-length-of-pair-chain/
*/

/*
  NOTE - Since this problem is a variant of LIS (only difference is that the Qn says that we can pick the element in any order)
  So we sort the input in ascending order to get the longest chain of pairs.
  Also, since it's variant of LIS, it can be solved using all those methods by which LIS could be solved.
*/

****************************** C++ ******************************
//Approach-1 (Using Simple LIS recursion+memo) - Since Qn asks to take pairs in any order, we sort it in the beginning
class Solution {
public:
   
    int n;
    int t[1001][1001];
    
    int lis(vector<vector<int>>& nums, int prev_idx, int curr_idx) {
       if(curr_idx == n)
           return 0;
        
        if(prev_idx != -1 && t[prev_idx][curr_idx] != -1)
            return t[prev_idx][curr_idx];
        
        int taken = 0;
        if(prev_idx == -1 || nums[curr_idx][0] > nums[prev_idx][1])
            taken = 1 + lis(nums, curr_idx, curr_idx+1);
        
        int not_taken = lis(nums, prev_idx, curr_idx+1);
        
        if(prev_idx != -1)
            t[prev_idx][curr_idx] =  max(taken, not_taken);
        
        return max(taken, not_taken);
            
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        memset(t, -1, sizeof(t));
        n = pairs.size();
        sort(begin(pairs), end(pairs)); //You can select pairs in any order.
        return lis(pairs, -1, 0);
    }
};


//Approach-2 (Using Simple LIS Bottom Up) - Since Qn asks to take pairs in any order, we sort it in the beginning
class Solution {
public:
    
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(begin(pairs), end(pairs));
        
        vector<int> t(n, 1);
        int maxL = 1;
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                
                if(pairs[j][1] < pairs[i][0]) {
                    t[i] = max(t[i], t[j]+1);
                    maxL = max(maxL, t[i]);
                }
            }
        }
        
        return maxL;
    }
};


****************************** JAVA ******************************
//Will update soon
