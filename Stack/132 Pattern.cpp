/*
    MY YOUTUBE VIDEO ON THIS Qn : 
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
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
            return false;
        stack<int> st;
        vector<int> min_i_for_j(n);
        min_i_for_j[0] = nums[0];
        
        for(int i = 1; i<n; i++)
            min_i_for_j[i] = min(min_i_for_j[i-1], nums[i]);
        
        for(int j = n-1; j > 0; j--) {
            while(!st.empty() && nums[st.top()] < nums[j]) {
                if(nums[st.top()] > min_i_for_j[j-1])
                    return true;
                st.pop();
            }
            st.push(j);
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
class Solution {
    public boolean find132pattern(int[] nums) {
        int n = nums.length;
        if (n < 3) {
            return false;
        }

        Stack<Integer> st = new Stack<>();
        int[] min_i_for_j = new int[n];
        min_i_for_j[0] = nums[0];

        for (int i = 1; i < n; i++) {
            min_i_for_j[i] = Math.min(min_i_for_j[i - 1], nums[i]);
        }

        for (int j = n - 1; j > 0; j--) {
            while (!st.isEmpty() && nums[st.peek()] < nums[j]) {
                if (nums[st.peek()] > min_i_for_j[j - 1]) {
                    return true;
                }
                st.pop();
            }
            st.push(j);
        }
        return false;
    }
}
