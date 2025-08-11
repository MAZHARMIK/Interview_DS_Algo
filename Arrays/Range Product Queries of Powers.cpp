/*     Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Scr9qJ5ioq4
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/range-product-queries-of-powers
*/


/************************************************************ C++ *****************************************************/
//Approach (Building powers array using bits information)
//T.C : O(Q), where Q = size of queries
//S.C : O(1)
class Solution {
public:
    int M = 1e9+7;

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        vector<int> result;

        //Build powers array
        for(int i = 0; i < 32; i++) {
            if((n & (1 << i)) != 0) { //ith bit is set
                powers.push_back(1 << i);
            }
        }

        for(auto &query : queries) {
            int start = query[0];
            int end = query[1];

            long product = 1;
            for(int i = start; i <= end; i++) {
                product = (product * powers[i]) % M;
            }

            result.push_back(product);
        }

        return result;

    }
};


/************************************************************ JAVA *****************************************************/
//Approach (Building powers array using bits information)
//T.C : O(Q), where Q = size of queries
//S.C : O(1)
class Solution {
    int MOD = (int)(1e9 + 7);

    public int[] productQueries(int n, int[][] queries) {
        List<Long> powers = new ArrayList<>();
        List<Integer> result = new ArrayList<>();

        // Build powers array
        for (int i = 0; i < 32; i++) {
            if ((n & (1 << i)) != 0) { // i-th bit is set
                powers.add((long)(1 << i));
            }
        }

        for (int[] query : queries) {
            int start = query[0];
            int end = query[1];

            long product = 1;
            for (int i = start; i <= end; i++) {
                product = (product * powers.get(i)) % MOD;
            }

            result.add((int)product);
        }

        // Convert result to int array
        return result.stream().mapToInt(i -> i).toArray();
    }
}
