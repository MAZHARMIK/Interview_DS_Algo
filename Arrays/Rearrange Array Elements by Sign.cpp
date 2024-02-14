/*                                       Scroll down to see JAVA code                          */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=cSG2bzAuLGU
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/rearrange-array-elements-by-sign/
*/

/************************************************** C++ **************************************************/
//T.C : O(n)
//S.C : O(n) for result
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int pi = 0; //positive index
        int ni = 1; //negative index
        
        
        vector<int> result(n);
        
        for(int &num : nums) {
            if(num > 0) {
                result[pi] = num;
                pi +=2;
            } else {
                result[ni] = num;
                ni += 2;
            }
        }
        
        return result;   
    }
};


/************************************************** JAVA **************************************************/
//T.C : O(n)
//S.C : O(n) for result
class Solution {
    public int[] rearrangeArray(int[] nums) {
        int n = nums.length;
        int pi = 0; // positive index
        int ni = 1; // negative index

        int[] result = new int[n];

        for (int num : nums) {
            if (num > 0) {
                result[pi] = num;
                pi += 2;
            } else {
                result[ni] = num;
                ni += 2;
            }
        }

        return result;
    }
}
