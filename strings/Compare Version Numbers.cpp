/*
    Company Tags  : Apple, Microsoft (They check how easily you are able to manage strict corner cases)
    Leetcode Link : https://leetcode.com/problems/compare-version-numbers/
*/

class Solution {
public:
    void getTokenNumbers(vector<int>& num, string& version) {
        stringstream ss(version);
        string token;
        while(getline(ss, token, '.')) {
            num.push_back(stoi(token));
        }
    }
    int compareVersion(string version1, string version2) {
        vector<int> nums1;
        getTokenNumbers(nums1, version1);
        
        vector<int> nums2;
        getTokenNumbers(nums2, version2);
        
        
        int i = 0, j = 0;
        int m = nums1.size();
        int n = nums2.size();

        while( i < m || j < n) {
            int num1 = i>=m ? 0 : nums1[i];
            int num2 = j>=n ? 0 : nums2[j];
            if(num1 > num2)
                return 1;
            else if(num1 < num2)
                return -1;
            else {
                i++;
                j++;
            }
        }
        return 0;
    }
};
