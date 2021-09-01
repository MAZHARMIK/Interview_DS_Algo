/*
    Company Tags  : Apple
    Frequency     : 28%
    Leetcode Link : https://leetcode.com/problems/array-nesting/
*/

class Solution {
public:
    int depth = 0;
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 0;
      
        for(int i = 0; i<n; i++) {
            int start  = nums[i];
            nums[i] = -1;
            int length = 0;
            
            //Go to depth as much as you can until you hit -1 (i.e. a number which was already visited)
            while(start != -1) {
                length++;
                int temp = start;
                start = nums[start];
                nums[temp] = -1;
            }
          
            maxLength = max(maxLength, length);
        }
        return maxLength;
    }
};
