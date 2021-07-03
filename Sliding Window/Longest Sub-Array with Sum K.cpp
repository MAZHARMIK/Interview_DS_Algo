/*
    Company Tags : Amazon
    Qn Link      : https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1#
*/

//This is actually a variable sized "sliding window technique"
class Solution{
    public:
    int lenOfLongSubarr(int nums[],  int n, int k) 
    { 
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int len = 0;
        for(int i = 0; i<n; i++) {
            sum += nums[i];
            int required = sum-k;
            if(mp.find(required) != mp.end()) {
                len = max(len, i-mp[required]);
            }
            
            if(mp.find(sum) == end(mp))
                mp[sum] = i;
        }
        
        return len;


    } 

};
