/*     Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=5qlXato2VkE
    Company Tags                : Will update later
    Leetcode Link               : https://leetcode.com/problems/find-triangular-sum-of-an-array
*/


/************************************************************ C++ *****************************************************/
//Approach-1 (Using O(n) space - Do as asked)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int triangularSum(vector<int>& nums) {

        while (nums.size() > 1) {
            vector<int> temp;
            for (int i = 0; i < nums.size() - 1; ++i) {
                temp.push_back((nums[i] + nums[i + 1]) % 10);
            }
            //std::move - avoids copying and is faster and more memory-efficient.
            nums = move(temp);
        }

        return nums[0];
    }
};


//Approach-2 (O(1) space using two pointers)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for (int size = n - 1; size >= 1; size--) {

            for (int i = 0; i < size; i++) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
            
        }
        return nums[0];
    }
};



/************************************************************ JAVA *****************************************************/
//Approach-1 (Using O(n) space - Do as asked)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
    public int triangularSum(int[] nums) {
        while (nums.length > 1) {
            int[] temp = new int[nums.length - 1];
            for (int i = 0; i < nums.length - 1; i++) {
                temp[i] = (nums[i] + nums[i + 1]) % 10;
            }
            nums = temp; // No std::move in Java; reassignment just points nums to new array
        }
        return nums[0];
    }
}


//Approach-2 (O(1) space using two pointers)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
    public int triangularSum(int[] nums) {
        for (int size = nums.length - 1; size >= 1; size--) {
            for (int i = 0; i < size; i++) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
        }
        return nums[0];
    }
}
