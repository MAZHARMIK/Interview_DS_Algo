/*         Scroll down to see JAVA code also             */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ku4oITayEmk
    Company Tags                : Apple, LinkedIn, Amazon, Facebook, Microsoft
    Leetcode Link               : https://leetcode.com/problems/product-of-array-except-self/
*/

/****************************************************************** C++ ******************************************************************/
//Approach-1 (Using Division)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 0;
        int product_without_zero = 1;
        for(int i: nums) {
            if(i == 0)
                product++;
            else
                product_without_zero *= i;
        }
        
        vector<int> result(nums.size());
        for(int i = 0; i<nums.size(); i++) {
            if(nums[i] != 0) {
                if(product > 0)
                    result[i] = 0;
                else
                    result[i] = product_without_zero/nums[i];
            }
            else {
                if(product > 1)
                    result[i] = 0;
                else
                    result[i] = product_without_zero;
            } 
        }
        return result;
    }
};


//Approach-2 (Using extra space)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0] = 1;
        right[n-1] = 1;
        
        for(int i = 1; i<nums.size(); i++) {
            left[i] = left[i-1]*nums[i-1];
        }
        
        for(int i = n-2; i>=0; i--) {
            right[i] = right[i+1]*nums[i+1];
        }
        
        vector<int> result(n);
        for(int i = 0; i<n; i++) {
            result[i] = left[i]*right[i];
        }
        
        return result;
    }
};

//Approach-3 (Using constant space)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        result[0] = 1;
        
        for(int i = 1; i<nums.size(); i++) {
            result[i] = result[i-1]*nums[i-1];
        }
        
        int right = 1;
        for(int i = n-1; i>=0; i--) {
            result[i] = result[i]*right;
            right *= nums[i];
        }
        
        return result;
    }
};



/****************************************************************** JAVA ******************************************************************/
// Approach-1 (Using Division)
// T.C: O(n)
// S.C: O(1)
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int product = 0;
        int productWithoutZero = 1;
        for (int i : nums) {
            if (i == 0)
                product++;
            else
                productWithoutZero *= i;
        }

        int[] result = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                if (product > 0)
                    result[i] = 0;
                else
                    result[i] = productWithoutZero / nums[i];
            } else {
                if (product > 1)
                    result[i] = 0;
                else
                    result[i] = productWithoutZero;
            }
        }
        return result;
    }
}


// Approach-2 (Using extra space)
// T.C: O(n)
// S.C: O(n)
class Solution {
    public int[] productExceptSelf2(int[] nums) {
        int n = nums.length;
        int[] left = new int[n];
        int[] right = new int[n];
        left[0] = 1;
        right[n - 1] = 1;

        for (int i = 1; i < nums.length; i++) {
            left[i] = left[i - 1] * nums[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] * nums[i + 1];
        }

        int[] result = new int[n];
        for (int i = 0; i < n; i++) {
            result[i] = left[i] * right[i];
        }

        return result;
    }
}


// Approach-3 (Using constant space)
// T.C: O(n)
// S.C: O(1)
class Solution {
    public int[] productExceptSelf3(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];
        result[0] = 1;

        for (int i = 1; i < nums.length; i++) {
            result[i] = result[i - 1] * nums[i - 1];
        }

        int right = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] = result[i] * right;
            right *= nums[i];
        }

        return result;
    }
}
