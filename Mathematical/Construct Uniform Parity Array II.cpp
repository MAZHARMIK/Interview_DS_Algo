/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link Part I        : https://leetcode.com/problems/construct-uniform-parity-array-i
    Leetcode Link Part II       : https://leetcode.com/problems/construct-uniform-parity-array-ii
*/


/*********************************************************** C++ **************************************************/
//Approach (Mathematical observation)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minEl = *min_element(begin(nums1), end(nums1));

        if(minEl % 2 == 1) { //odd - then we can convert all even to odd
            return true; //all nums2 will be odd
        }

        //check if we can make all even in nums2
        for(int &num : nums1) {
            if(num % 2 == 1) {
                return false;
            }
        }

        return true; //all nums2 will be even
    }
};


/*********************************************************** JAVA **************************************************/
//Approach (Mathematical observation)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public boolean uniformArray(int[] nums1) {
        int minEl = Integer.MAX_VALUE;
        for (int num : nums1) {
            minEl = Math.min(minEl, num);
        }

        if (minEl % 2 == 1) {   // odd - then we can convert all even to odd
            return true;        // all nums2 will be odd
        }

        // check if we can make all even in nums2
        for (int num : nums1) {
            if (num % 2 == 1) {
                return false;
            }
        }
        return true;            // all nums2 will be even
    }
}
