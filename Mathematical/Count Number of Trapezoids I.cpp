/*     Scroll below to see JAVA code    */
/*
    MY YOUTUBE VIDEO ON THIS Qn                : https://www.youtube.com/watch?v=YI5ALyXyv_Q
    Company Tags                               : will soon update
    Leetcode Link                              : https://leetcode.com/problems/count-number-of-trapezoids-i
    
*/

/****************************************************** C++ **************************************************************/
//Approach - Simple Maths counting
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int M = 1e9+7;

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> mp; //y -> count

        for(auto &point : points) {
            int y = point[1];
            mp[y]++;
        }

        long long result = 0; //countof trapezoids

        long long prevHorizontalLines = 0;

        for(auto &it : mp) {
            int count = it.second;

            long long horizontalLines = (long long)count * (count-1)/2; //countC2

            result += horizontalLines * prevHorizontalLines;

            prevHorizontalLines += horizontalLines;
        }

        return result % M;


    }
};



/****************************************************** JAVA **************************************************************/
//Approach - Simple Maths counting
//T.C : O(n)
//S.C : O(n)
class Solution {
    static final int M = (int)1e9 + 7;

    public int countTrapezoids(int[][] points) {
        // Map y -> count of points having that y-coordinate
        Map<Integer, Integer> mp = new HashMap<>();
        for (int[] point : points) {
            int y = point[1];
            mp.put(y, mp.getOrDefault(y, 0) + 1);
        }

        long result = 0;
        long prevHorizontalLines = 0;

        // Iterate over the hashmap
        for (int count : mp.values()) {

            long horizontalLines = (long) count * (count - 1) / 2;  // C(n, 2)

            result = (result + horizontalLines * prevHorizontalLines) % M;

            prevHorizontalLines += horizontalLines;
        }

        return (int)(result % M);
    }
}
