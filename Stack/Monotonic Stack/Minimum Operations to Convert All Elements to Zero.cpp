/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn   : 
    Company Tags                  : Will update later
    Leetcode Link                 : https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero
*/


/********************************************************************** C++ **********************************************************************/
//Approach (Brute Force)
//T.C : O(n*u), u = unique elements, in worst case  u = n
//S.C : O(u), in worst case u = n
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_set<int> st(begin(nums), end(nums)); //O(n) space

        int n = nums.size();

        int ops = 0;

        for(int target : st) { //O(U*n)
            if(target == 0)
                continue;
            
            bool flow = false;
            for(int i = 0; i < n; i++) {
                if(nums[i] == target) {
                    if(!flow) {
                        flow = true;
                        ops++;
                    }
                } else if(nums[i] < target) {
                    flow = false;
                }
            }
        }

        return ops;

        
    }
};



//Approach (Optimal using Monotonic Increasing Stack)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;

        int ops = 0;

        for(int i = 0; i < nums.size(); i++) {
            while(!st.empty() && st.top() > nums[i]) {
                st.pop();
            }

            if(nums[i] == 0)
                continue;
            
            if(st.empty() || st.top() < nums[i]) {
                st.push(nums[i]);
                ops++;
            }
        }

        return ops;
    }
};




/********************************************************************** JAVA **********************************************************************/
//Approach (Brute Force)
//T.C : O(n*u), u = unique elements, in worst case  u = n
//S.C : O(u), in worst case u = n
class Solution {
    public int minOperations(int[] nums) {
        Set<Integer> unique = new HashSet<>();
        for (int num : nums) {
            unique.add(num);
        }

        int n = nums.length;
        int ops = 0;

        for (int target : unique) {
            if (target == 0) continue;

            boolean flow = false;
            for (int i = 0; i < n; i++) {
                if (nums[i] == target) {
                    if (!flow) {
                        flow = true;
                        ops++;
                    }
                } else if (nums[i] < target) {
                    flow = false;
                }
            }
        }

        return ops;
    }
}


//Approach (Optimal using Monotonic Increasing Stack)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int minOperations(int[] nums) {
        Stack<Integer> st = new Stack<>();
        int ops = 0;

        for (int num : nums) {
            while (!st.isEmpty() && st.peek() > num) {
                st.pop();
            }

            if (num == 0) continue;

            if (st.isEmpty() || st.peek() < num) {
                st.push(num);
                ops++;
            }
        }

        return ops;
    }
}
