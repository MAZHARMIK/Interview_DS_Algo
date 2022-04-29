/*
    Company Tags  : HyperVerge
    Leetcode Link : https://leetcode.com/problems/constrained-subsequence-sum/
    
    Please also see "Leetcode - 239 Sliding Window Maximum"  Both are similar to a great extent and this is the hard version.
*/

/*
  It can be solved using DP as well. See my 2 approaches here in DP section 
  Link : https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/DP/Constrained%20Subsequence%20Sum.cpp
*/


//Approach-3 (Using Priority_queue) Accepted
/*
	You want the maximum value in the range of [i, i-k]
	Why not store them in max heap and access them in one go
*/

class Solution {
public:
    typedef pair<int, int> P;
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> t(n, 0);
        t = nums;
        priority_queue<P, vector<P>> pq;
        pq.push({t[0], 0});
        
        int maxR = t[0];
        
        for(int i = 1; i<n; i++) {
            
            while(!pq.empty() && pq.top().second < i - k)
                pq.pop();
            
            t[i] = max(t[i], nums[i] + pq.top().first);
            pq.push({t[i], i});
            
            maxR = max(maxR, t[i]);
        }
        
        
        return maxR;
    }
};
