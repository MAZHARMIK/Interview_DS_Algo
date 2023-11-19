/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=XzjcPpSph0s
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal
*/

/****************************************************************** C++ ******************************************************************/
//Approach - Using sorting
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        
        sort(begin(nums), end(nums));
        
        int count = 0;
        
        for(int i = n-1; i > 0; i--) {
            if(nums[i] == nums[i-1]) {
                continue;
            }
            
            count += n-i;
        }
        
        
        return count;
        
        
    }
};


/****************************************************************** JAVA ******************************************************************/
//Approach - Using sorting
//T.C : O(nlogn)
//S.C : O(1)
public class Solution {
    public int reductionOperations(int[] nums) {
        int n = nums.length;

        Arrays.sort(nums);

        int count = 0;

        for (int i = n - 1; i > 0; i--) {
            if (nums[i] == nums[i - 1]) {
                continue;
            }

            count += n - i;
        }

        return count;
    }
}

