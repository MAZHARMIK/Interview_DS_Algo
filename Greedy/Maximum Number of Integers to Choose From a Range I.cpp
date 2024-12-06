/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=urduKO4oFlo
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i
*/


/************************************************************ C++ ************************************************/
//Approach - Simple Greedily select smallest numbers
//T.C : O(n)
//S.C : O(m)
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st(begin(banned), end(banned));
        int count = 0;
        int sum = 0;

        for(int num = 1; num <= n; num++) {
            if(st.count(num)) {
                continue;
            }

            if(sum + num <= maxSum) {
                count++;
                sum += num;
            } else {
                break;
            }
        }

        return count;
    }
};



/************************************************************ JAVA *********************************************************/
//Approach - Simple Greedily select smallest numbers
//T.C : O(n)
//S.C : O(m)
class Solution {
    public int maxCount(int[] banned, int n, int maxSum) {
        HashSet<Integer> set = new HashSet<>();
        for (int num : banned) {
            set.add(num);
        }

        int count = 0;
        int sum = 0;

        for (int num = 1; num <= n; num++) {
            if (set.contains(num)) {
                continue;
            }

            if (sum + num <= maxSum) {
                count++;
                sum += num;
            } else {
                break;
            }
        }

        return count;
    }
}
