/*     Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k
*/


/*************************************************************** C++ ***************************************************************/
//Approach (Using observation - counting unique)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> st;

        for(int &x : nums) {
            if(x < k) {
                return -1;
            } else if(x > k) {
                st.insert(x);  
            }
        }
        return st.size();
    }
};


/*************************************************************** JAVA ***************************************************************/
//Approach (Using observation - counting unique)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int minOperations(int[] nums, int k) {
        Set<Integer> set = new HashSet<>();

        for (int x : nums) {
            if (x < k) {
                return -1;
            } else if (x > k) {
                set.add(x);
            }
        }

        return set.size();
    }
}
