/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=RZXxX1EU364
    Company Tags                : Amazon, META
    Leetcode Link               : https://leetcode.com/problems/132-pattern/
*/

/*********************************************************** C++ *********************************************/
//Approach-1
//T.C : O(n^3) - T.L.E : [94 / 103 test cases passed.]
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            
            for(int j = i+1; j<n; j++) {
                
                if(nums[j] > nums[i]) {
                    
                    for(int k = j+1; k<n; k++) {
                        if(nums[i] < nums[k] && nums[k] < nums[j] )
                            return true;
                    }
                    
                }
            }
        }
        return false;
    }
};


//Approach-2
//T.C : O(n^2) - T.L.E : [101 / 103 test cases passed.]
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int min_i = INT_MAX;
        int n = nums.size();
        for(int j = 0; j<n-1; j++) {
            min_i = min(min_i, nums[j]);
            for(int k = j+1; k<n; k++) {
                if(min_i < nums[k] && nums[k] < nums[j])
                    return true;
            }
        }
        return false;
    }
};

//Approach-3 --> Using Monotonic stack
//T.C : O(n) - We don't visit any element more than once
/*
    We are only storing one item in the stack, which is our ideal candidate for num2 (number that needs to be the largest). 
    If we find a number that is bigger than what we thought was our ideal candidate for num2; we pop out our stack 
    and store the value in num3 (mid value number), then we store the new ideal candidate for num2 in the stack. 
    On the next ith iteration, if nums[i] is actually less than s3, then we are done!
*/
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        //num1, num2, num3
        //num1 < num3 < num2
        int n  = nums.size();
        int num3 = INT_MIN;
        stack<int> st;
        
        for(int i = n-1; i >= 0; i--) {
            if(nums[i] < num3)
                return true;
            
            while(!st.empty() && nums[i] > st.top()) {
                num3 = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }

        return false;
    }
};

/*********************************************************** JAVA *********************************************/
//Approach-1
//T.C : O(n^3) - T.L.E : [94 / 103 test cases passed.]
class Solution {
    public boolean find132pattern(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] > nums[i]) {
                    for (int k = j + 1; k < n; k++) {
                        if (nums[i] < nums[k] && nums[k] < nums[j]) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
}


//Approach-2
//T.C : O(n^2) - T.L.E : [101 / 103 test cases passed.]
class Solution {
    public boolean find132pattern(int[] nums) {
        int min_i = Integer.MAX_VALUE;
        int n = nums.length;
        for (int j = 0; j < n - 1; j++) {
            min_i = Math.min(min_i, nums[j]);
            for (int k = j + 1; k < n; k++) {
                if (min_i < nums[k] && nums[k] < nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }
}

//Approach-3 --> Using stack
//T.C : O(n) - We don't visit any element more than once
import java.util.Stack;

class Solution {
    public boolean find132pattern(int[] nums) {
        int n = nums.length;
        int num3 = Integer.MIN_VALUE;
        Stack<Integer> stack = new Stack<>();

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < num3) {
                return true;
            }

            while (!stack.isEmpty() && nums[i] > stack.peek()) {
                num3 = stack.pop();
            }
            stack.push(nums[i]);
        }

        return false;
    }
}
