/*     Scroll below to see JAVA code also    */
/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=nCutrlJaRBo
      Company Tags                : will update later
      Leetcode Link               : https://leetcode.com/problems/find-the-minimum-amount-of-time-to-brew-potions
*/


/********************************************************************** C++ ********************************************************/
//Approach - Smart Simulation with updates
//T.C : O(m*n)
//S.C : O(n)
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<long long> finishTime(n, 0); // finishTime[i] = when wizard i finishes current potion

        for (int j = 0; j < m; ++j) {
            finishTime[0] += 1LL * mana[j] * skill[0];

            for (int i = 1; i < n; ++i)
                finishTime[i] = max(finishTime[i], finishTime[i - 1]) + 1LL * mana[j] * skill[i];

            for (int i = n - 1; i > 0; --i)
                finishTime[i - 1] = finishTime[i] - 1LL * mana[j] * skill[i];
        }
        return finishTime[n-1];
    }
};



/********************************************************************** C++ ********************************************************/
//Approach - Smart Simulation with updates
//T.C : O(m*n)
//S.C : O(n)
class Solution {
    public long minTime(int[] skill, int[] mana) {
        int n = skill.length;
        int m = mana.length;
        long[] finishTime = new long[n]; // finishTime[i] = when wizard i finishes current potion

        for (int j = 0; j < m; ++j) {
            finishTime[0] += (long) mana[j] * skill[0];

            for (int i = 1; i < n; ++i) {
                finishTime[i] = Math.max(finishTime[i], finishTime[i - 1]) + (long) mana[j] * skill[i];
            }

            for (int i = n - 1; i > 0; --i) {
                finishTime[i - 1] = finishTime[i] - (long) mana[j] * skill[i];
            }
        }

        return finishTime[n - 1];
    }
}
