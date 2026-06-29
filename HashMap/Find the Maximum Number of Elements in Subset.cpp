/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=_71KQ4Voj3c
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/find-the-maximum-number-of-elements-in-subset
*/

/*************************************************************** C++ ***************************************************************/
//T.C : O(n * log log M), M = maximum number in the nums
//S.C : O(n)
class Solution {
public:
    typedef long long ll;

    int maximumLength(vector<int>& nums) {
        unordered_map<ll, int> mp;

        for(int &num : nums) {
            mp[num]++;
        }

        int result = 0;

        if(mp[1]%2) { //Odd
            result = mp[1];
        } else { //even
            result = mp[1]-1;
        }

        for(auto &[num, _] : mp) {
            if(num == 1) continue;

            ll curr = num;
            int len = 0;

            while(mp.count(curr) && mp[curr] > 1) {
                len += 2;
                curr = curr*curr;
            }

            if(mp.count(curr) == 1) {
                len += 1;
            } else {
                len -= 1;
            }

            result = max(result, len);
        }

        return result;
    }
};

/*************************************************************** JAVA ***************************************************************/
//T.C : O(n * log log M), M = maximum number in the nums
//S.C : O(n)
class Solution {
    public int maximumLength(int[] nums) {
        Map<Long, Integer> cnt = new HashMap<>();
        for (int num : nums) {
            cnt.merge((long) num, 1, Integer::sum);
        }

        int result = 0;
       
        int ones = cnt.getOrDefault(1L, 0);
        result = (ones % 2 == 1) ? ones : ones - 1;

        for (long num : cnt.keySet()) {
            if (num == 1) continue;

            long curr = num;
            int len = 0;
            while (cnt.getOrDefault(curr, 0) > 1) {
                len += 2;
                curr = curr * curr;
            }
            len += cnt.containsKey(curr) ? 1 : -1;

            result = Math.max(result, len);
        }

        return result;
    }
}
