/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=9Foc4T5cq00
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/rabbits-in-forest/description
*/


/************************************************************ C++ *****************************************************/
//Approach (Grouping using map)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        for (int& x : answers) {
            mp[x]++;
        }

        int total = 0;

        for (auto& it : mp) {
            int x     = it.first;  // The answer given by rabbit
            int count = it.second; // How many rabbits gave that answer

            int groupSize = x + 1;
            int groups    = ceil((double)count / groupSize);

            total += groups * groupSize;
        }

        return total;
    }
};


/************************************************************ JAVA *****************************************************/
//Approach (Grouping using map)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int numRabbits(int[] answers) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int x : answers) {
            map.put(x, map.getOrDefault(x, 0) + 1);
        }

        int total = 0;

        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            int x = entry.getKey();      // The answer given by rabbit
            int count = entry.getValue(); // How many rabbits gave that answer

            int groupSize = x + 1;
            int groups = (int) Math.ceil((double) count / groupSize);

            total += groups * groupSize;
        }

        return total;
    }
}
