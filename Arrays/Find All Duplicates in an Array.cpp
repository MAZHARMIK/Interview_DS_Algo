/*    Scroll below to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=NqadCpaZnkk
    Company Tags                : Pocket Gems, Amazon, Meta
    Leetcode Link               : https://leetcode.com/problems/find-all-duplicates-in-an-array
*/


/********************************************************************* C++ *****************************************************/
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> result; 
        for(int i = 0; i < n; i++) {
            int num = abs(nums[i]);
            
            if(nums[num-1] < 0) {
                result.push_back(num);
            } else {
                nums[num-1] *= -1;
            }
        }
        
        return result;
        
    }
};



/********************************************************************* JAVA *****************************************************/
//T.C : O(n)
//S.C : O(1)
public class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        int n = nums.length;

        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int num = Math.abs(nums[i]);

            if (nums[num - 1] < 0) {
                result.add(num);
            } else {
                nums[num - 1] *= -1;
            }
        }

        return result;
    }
}
