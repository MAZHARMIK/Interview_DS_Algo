/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=xl0QjGnOU7I
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/trionic-array-i
*/


/*********************************************************** C++ **************************************************/
//Approach (Simply simulation)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();

        int i = 0;

        //Increasing
        while(i+1 < n && nums[i] < nums[i+1])
            i++;

        if(i == 0 || i == n-1)
            return false;
        
        //Decreasing
        while(i+1 < n && nums[i] > nums[i+1])
            i++;
        
        if(i == n-1)
            return false;
        
        //Increasing
        while(i+1 < n && nums[i] < nums[i+1])
            i++;
        

        return i == n-1;
    }
};


/*********************************************************** JAVA **************************************************/
//Approach (Simply simulation)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public boolean isTrionic(int[] nums) {
        int n = nums.length;
        int i = 0;

        // Increasing
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }

        // Must have at least one increasing step and not reach end
        if (i == 0 || i == n - 1) return false;

        // Decreasing
        while (i + 1 < n && nums[i] > nums[i + 1]) {
            i++;
        }

        // Must have at least one decreasing step and not reach end
        if (i == n - 1) return false;

        // Increasing again
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }

        return i == n - 1;
    }
}
