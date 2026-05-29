/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=dRwEixchYqc
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/binary-prefix-divisible-by-5
*/

/****************************************************************************** C++ ******************************************************************************/
//Approach (Using bit concept and modular arithmetic)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> result(n);

        int remain = 0;
        
        for(int i = 0; i < n; i++) {
            remain = (remain*2 + nums[i]) % 5;

            result[i] = (remain == 0);
        }

        return result;
    }
};




/****************************************************************************** JAVA ******************************************************************************/
//Approach (Using bit concept and modular arithmetic)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public List<Boolean> prefixesDivBy5(int[] nums) {
        int n = nums.length;
        List<Boolean> result = new ArrayList<>(n);

        int remain = 0;

        for (int i = 0; i < n; i++) {
            remain = (remain * 2 + nums[i]) % 5;
            result.add(remain == 0);
        }

        return result;
    }
}
