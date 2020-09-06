/*
    Leetcode Contest : 205
    Contest Link     : https://leetcode.com/contest/weekly-contest-205/  
*/

class Solution {
public:

    int twoProduct(long long target, vector<int>& nums) {
        map<int, int> mp;
        int count = 0;
        for(int i:nums) {
            if(target%i == 0) {
                count += mp[target/i];
            }
            mp[i]++;
        }
        return count;
    }

    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int sum = 0;
        for(int i:nums1) {
            sum += twoProduct((long long)i*(long long)i, nums2);
        }
        
        for(int i:nums2) {
            sum += twoProduct((long long)i*(long long)i, nums1);
        }
        return sum;
    }
};
