/*
    Company Tags         : Amazon
    Leetcode Premimum qn : https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/ 
*/

class Solution {
public:
    int maxSubArrayLen(vector<int> &arr, int k) {
        int n = arr.size();
        int cumSum = 0;
	    int maxLen = 0;
	    unordered_map<int, int> mp;
	    mp[0] = -1;
	    for(int i = 0; i<n; i++) {
	        cumSum += arr[i];

	        if(mp.count(cumSum-k) && i-mp[cumSum-k] > maxLen)
	            maxLen = i-mp[cumSum-k];
	        
	        if(!mp.count(cumSum))
	            mp[cumSum] = i;
	    }
	    
	    return maxLen;
    }
};
