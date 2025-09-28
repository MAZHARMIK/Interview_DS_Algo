/*     Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=wukuOrHM3eg
    Company Tags                : C3.ai
    Leetcode Link               : https://leetcode.com/problems/largest-perimeter-triangle/
    
*/


/************************************************************ C++ *****************************************************/
//Approach (Simply sort and check linearly)
//T.C : O(nlogn))
//S.C : O(1)
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        
        sort(begin(nums), end(nums));
        
        for(int i = n-3; i>=0; i--) {
            //nums[i] < nums[i+1] < nums[i+2]
            
            if(nums[i] + nums[i+1] > nums[i+2]) //a + b > c
                return nums[i] + nums[i+1] + nums[i+2];
        }
        
        return 0;
        
    }
};



/************************************************************ JAVA *****************************************************/
//Approach (Simply sort and check linearly)
//T.C : O(nlogn))
//S.C : O(1)
class Solution {
    public int largestPerimeter(int[] nums) {
        int n = nums.length;
        
        Arrays.sort(nums); // Sort the array
        
        for (int i = n - 3; i >= 0; i--) {
            // nums[i] < nums[i+1] < nums[i+2]
            if (nums[i] + nums[i + 1] > nums[i + 2]) { // a + b > c
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }
        
        return 0;
    }
}
