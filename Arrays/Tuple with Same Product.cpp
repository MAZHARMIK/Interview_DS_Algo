/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/tuple-with-same-product/description/
*/


/************************************************************ C++ *****************************************************/
//Approach-1 (Brute Force)
//T.C : O(n^4)
//S.C : O(1)
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int totalNumberOfTuples = 0;
        int n = nums.size();

        // Four nested loops to select a, b, c, d
        for (int i = 0; i < n; i++) {           // Choose a
            for (int j = i + 1; j < n; j++) {   // Choose b (distinct from a)
                for (int k = 0; k < n; k++) {   // Choose c
                    for (int l = k + 1; l < n; l++) { // Choose d (distinct from c)
                        // Ensure all four indices are distinct
                        if (i != k && i != l && j != k && j != l) {
                            int product1 = nums[i] * nums[j];
                            int product2 = nums[k] * nums[l];

                            // Check if products are equal
                            if (product1 == product2) {
                                totalNumberOfTuples++;
                            }
                        }
                    }
                }
            }
        }

        // Each unique combination corresponds to 8 possible tuples
        return totalNumberOfTuples / 2 * 8;  // Divide by 2 to correct double-counting
    }
};


//Approach-2 (Better Brute Force)
//T.C : O(n^3)
//S.C : O(1)
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int totalNumberOfTuples = 0;
        int n = nums.size();

        int result = 0;
        sort(begin(nums), end(nums));

        // Four nested loops to select a, b, c, d
        for (int i = 0; i < n; i++) {           // Choose a
            for (int j = n - 1; j > i; j--) {   // Choose b (distinct from a)

                int product = nums[i] * nums[j];
                unordered_set<int> st;

                for (int k = i+1; k < j; k++) {   // Choose c
                    
                    if(product % nums[k] == 0) {
                        int lValue = product/nums[k];

                        if(st.count(lValue)) {
                            totalNumberOfTuples++;
                        }

                        st.insert(nums[k]);
                    }
                }
            }
        }

        // Each unique combination corresponds to 8 possible tuples
        return totalNumberOfTuples * 8;  // Divide by 2 to correct double-counting
    }
};
