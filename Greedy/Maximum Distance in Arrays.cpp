/*    Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=OO6i7g3it4Q
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/maximum-distance-in-arrays
*/


/**************************************************** C++ ****************************************************/
//Approach - Simple Greedy
//T.C : O(m)
//S.C : O(1)
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int MIN = arrays[0].front();
        int MAX = arrays[0].back();

        int result = 0;

        for(int i = 1; i < arrays.size(); i++) {
            int currMin = arrays[i].front();
            int currMax = arrays[i].back();

            result = max({result, abs(currMin - MAX), abs(currMax - MIN)});

            MAX = max(MAX, currMax);
            MIN = min(MIN, currMin);
        }
        return result;
    }
};


/**************************************************** JAVA ****************************************************/
//Approach - Simple Greedy
//T.C : O(m)
//S.C : O(1)
class Solution {
    public int maxDistance(List<List<Integer>> arrays) {
        int MIN = arrays.get(0).get(0);
        int MAX = arrays.get(0).get(arrays.get(0).size() - 1);

        int result = 0;

        for (int i = 1; i < arrays.size(); i++) {
            int currMin = arrays.get(i).get(0);
            int currMax = arrays.get(i).get(arrays.get(i).size() - 1);

            result = Math.max(result, Math.max(Math.abs(currMin - MAX), Math.abs(currMax - MIN)));

            MAX = Math.max(MAX, currMax);
            MIN = Math.min(MIN, currMin);
        }
        return result;
    }
}
