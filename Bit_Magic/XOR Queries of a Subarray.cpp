/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=rZYdNpHXz0o
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/xor-queries-of-a-subarray
*/

/******************************************************** C++ ********************************************************/
//Approach (Simple XOR Property & Cumulative Xor)
//T.C : O(n+q)
//S.C : O(n)
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();

        vector<int> cumXor(n, 0); //space : O(n)

        cumXor[0] = arr[0];
        for(int i = 1; i < n; i++) { //O(n)
            cumXor[i] = cumXor[i-1] ^ arr[i];
        }

        vector<int> result;
        for(vector<int>& query : queries) { //O(q)
            int L = query[0];
            int R = query[1];

            int xor_val = cumXor[R] ^ (L == 0 ? 0 : cumXor[L-1]);

            result.push_back(xor_val);
        }

        return result;
    }
};



/******************************************************** JAVA ********************************************************/
//Approach (Simple XOR Property & Cumulative Xor)
//T.C : O(n+q)
//S.C : O(n)
class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int n = arr.length;

        // Create an array to store the cumulative XOR values.
        int[] cumXor = new int[n];
        cumXor[0] = arr[0];

        // Calculate the cumulative XOR values for the array.
        for (int i = 1; i < n; i++) {
            cumXor[i] = cumXor[i - 1] ^ arr[i];
        }

        // Create a result array to store the XOR values for each query.
        int[] result = new int[queries.length];

        // Process each query.
        for (int i = 0; i < queries.length; i++) {
            int L = queries[i][0];
            int R = queries[i][1];

            // Calculate the XOR for the subarray from L to R.
            result[i] = cumXor[R] ^ (L == 0 ? 0 : cumXor[L - 1]);
        }

        // Return the result array.
        return result;
    }
}
