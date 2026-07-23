/*   Scroll below to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will udpate later
    Leetcode Link               : https://leetcode.com/problems/number-of-unique-xor-triplets-i
*/


/******************************************************* C++ *******************************************************/
//Approach (Bit observation)
//T.C : O(log2(n))
//S.C : O(1)
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if(n == 1 || n == 2)
            return n;
        
        int ans = 1; //2^0;
        while(ans <= n) {
            ans = (ans << 1);
        }

        return ans;
    }
};



/******************************************************* JAVA *******************************************************/
//Approach (Bit observation)
//T.C : O(log2(n))
//S.C : O(1)
class Solution {
    public int uniqueXorTriplets(int[] nums) {
        int n = nums.length;

        if (n == 1 || n == 2)
            return n;

        int ans = 1; // 2^0
        while (ans <= n) {
            ans = (ans << 1);
        }

        return ans;
    }
}
