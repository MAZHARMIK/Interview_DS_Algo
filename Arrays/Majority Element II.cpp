/*                                    Scroll below to see JAVA code also                                */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Q6L5SoS-fTo
    Company Tags                : Amazon, Google
    Leetcode Qn Link            : https://leetcode.com/problems/majority-element-ii/
*/

/**************************************************** C++ ****************************************************/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        int maj1    = NULL;
        int count1 = 0;

        int maj2    = NULL;
        int count2 = 0;
        int freq = floor(n/3);
        
        for(int i = 0; i<n; i++) {
            if(nums[i] == maj1)
                count1++;
            else if(nums[i] == maj2)
                count2++;
            else if(count1 == 0) {
                maj1 = nums[i];
                count1 = 1;
            } else if(count2 == 0) {
                maj2 = nums[i];
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        
        vector<int> result; //because atmost two elements can occur more than ⌊ n/3 ⌋ in an array of length n
        count1 = 0;
        count2 = 0;
        for(int num:nums) {
            if(num == maj1)
                count1++;
            else if(num == maj2)
                count2++;
        }
        if(count1 > floor(n/3))
            result.push_back(maj1);
        if(count2 > floor(n/3))
            result.push_back(maj2);
        return result;


    }
};



/**************************************************** JAVA ****************************************************/
public class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int n = nums.length;
        
        Integer maj1 = null;
        int count1 = 0;

        Integer maj2 = null;
        int count2 = 0;
        
        for (int num : nums) {
            if (maj1 != null && num == maj1) {
                count1++;
            } else if (maj2 != null && num == maj2) {
                count2++;
            } else if (count1 == 0) {
                maj1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                maj2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        
        count1 = 0;
        count2 = 0;
        for (int num : nums) {
            if (maj1 != null && num == maj1) {
                count1++;
            } else if (maj2 != null && num == maj2) {
                count2++;
            }
        }
        
        List<Integer> result = new ArrayList<>();
        if (count1 > Math.floor(n / 3)) {
            result.add(maj1);
        }
        if (count2 > Math.floor(n / 3)) {
            result.add(maj2);
        }
        
        return result;
    }
}
