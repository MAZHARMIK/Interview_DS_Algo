/*
    Company Tags  : NIL
    Leetcode Link : https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
*/

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int sum = 0;
        
        int l = 1;
        int r = 1000000;
        while(l <= r) {
            
            int divisor = l + (r-l)/2;
            sum = 0;
            for(int x:nums) {
                sum += ceil((double)x/(double)divisor);
            }
            if(sum > threshold)
                l = divisor+1;
            else
                r = divisor-1;
        }
        return l;
    }
};
