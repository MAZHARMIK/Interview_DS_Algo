/*         Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/count-subarrays-with-score-less-than-k
*/


/********************************************************************** C++ **********************************************************************/
//Approach  (Sliding Window)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        

        long long result = 0;
        long long sum    = 0;

        int i = 0;
        int j = 0;

        while(j < n) {
            sum += nums[j];

            while(i <= j && sum * (j - i + 1) >= k) { //shrink the window
                sum -= nums[i];
                i++;
            }

            //i...j
            //i+1...j
            //i+2...j
            result += (j-i+1);
            j++;
        }

        return result;
    }
};



/********************************************************************** JAVA **********************************************************************/
//Approach  (Sliding Window)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public long countSubarrays(int[] nums, long k) {
        int n = nums.length;
        
        long result = 0;
        long sum = 0;
        
        int i = 0;
        int j = 0;
        
        while (j < n) {
            sum += nums[j];
            
            while (i <= j && sum * (j - i + 1) >= k) {
                sum -= nums[i];
                i++;
            }
            
            result += (j - i + 1);
            j++;
        }
        
        return result;
    }
}
