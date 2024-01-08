/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=cau0JE1q_ZA
    Company Tags                : Google, Meta, Netflix, Amazon, Apple, Baidu
    Leetcode Link               : https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
*/

/********************************************************** C++ **********************************************************/
//T.C : O(n^2)
//S.C : O(n^2) - because of the 2D array mp, where each row mp[i] represents a different index in the input vector nums
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        unordered_map<long, int> mp[n];
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                auto diff = (long)nums[i]-nums[j];
                auto it = mp[j].find(diff);
                
                int count_at_j = it==end(mp[j]) ? 0 : it->second;
                
                mp[i][diff] += count_at_j+1;
                result      += count_at_j;
                
            }
        }
        return result;
    }
};


//Approach-2 (Recursion  + Memo)
class Solution {
private:
    int solve(vector<int>& nums, int start, int curr, int len, long diff, unordered_map<string, int>& dp) {
        if (curr == nums.size() - 1)
            return 0;

        string temp = to_string(curr) + "#" + to_string(len);
        if (dp.find(temp) != dp.end())
            return dp[temp];

        int res = 0;
        for (int i = curr + 1; i < nums.size(); i++) {
            long k = static_cast<long>(nums[i]) - static_cast<long>(nums[curr]);
            if (len == 1 || diff == k) {
                len += 1;
                if (len >= 3)
                    res++;
                res += solve(nums, start, i, len, k, dp);
                len -= 1;
            }
        }

        dp[temp] = res;
        return res;
    }

public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int res = 0;
        unordered_map<string, int> dp;

        for (int i = 0; i < nums.size(); i++) {
            dp.clear();
            res += solve(nums, i, i, 1, 0, dp);
        }

        return res;
    }
};


/********************************************************** JAVA **********************************************************/
//T.C : O(n^2)
//S.C : O(n^2) - because of the 2D array mp, where each row mp[i] represents a different index in the input vector nums
public class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        int n = nums.length;
        int result = 0;
        Map<Long, Integer>[] mp = new HashMap[n];

        for (int i = 0; i < n; i++) {
            mp[i] = new HashMap<>();
            for (int j = 0; j < i; j++) {
                long diff = (long) nums[i] - nums[j];
                int count_at_j = mp[j].getOrDefault(diff, 0);

                result += count_at_j;
                
                // Increment the count at index i
                mp[i].put(diff, mp[i].getOrDefault(diff, 0) + count_at_j + 1);
            }
        }
        return result;
    }

}
