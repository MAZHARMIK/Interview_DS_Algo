/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=aC7q-YCFV2o
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
        return (totalNumberOfTuples / 2) * 8;  // Divide by 2 to correct double-counting
        /*
            For example : for nums = {2, 3, 4, 6}, one tuple will be {2, 6, 3, 4} -> we count 8 possible permutations for this.
            (2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
            (3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)

            Now, our for loop later will also pick tuple {3, 4, 2, 6} which will again give same 8 permutations.
        */
    }
};


//Approach-2 (Improving a little more after sorting)
//T.C : O(n^4 + nlogn)
//S.C : O(1)
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int totalNumberOfTuples = 0;
        int n = nums.size();
        sort(begin(nums), end(nums));

        // Four nested loops to select a, b, c, d
        for (int i = 0; i < n; i++) {           // Choose a
            for (int j = n-1; j > i; j--) {   // Choose b (distinct from a)

                for(int k = i+1; k < j; k++) {
                    for(int l = j-1; l > k; l--) {

                        int p1 = nums[i] * nums[j];
                        int p2 = nums[k] * nums[l];

                        if(p1 == p2) {
                            totalNumberOfTuples++;
                        }

                    }
                }

            }
        }

        // Each unique combination corresponds to 8 possible tuples
        return totalNumberOfTuples * 8;
    }
};


//Approach-3 (Better Brute Force)
//T.C : O(n^3)
//S.C : O(n)
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
        return totalNumberOfTuples * 8;
    }
};



//Approach-4 (Using maths and combination)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int tuples = 0;

        unordered_map<int, int> mp; //product -> frequency

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int p = nums[i] * nums[j];
                mp[p]++;
            }
        }

        for(auto &it : mp) {
            int prod = it.first;
            int freq = it.second;

            tuples += (freq * (freq-1))/2;
        }

        return tuples * 8;
    }
};


/************************************************************ JAVA *****************************************************/
// Approach-1 (Brute Force)
// T.C : O(n^4)
// S.C : O(1)
class Solution {
    public int tupleSameProduct(int[] nums) {
        int totalNumberOfTuples = 0;
        int n = nums.length;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    for (int l = k + 1; l < n; l++) {
                        if (i != k && i != l && j != k && j != l) {
                            int product1 = nums[i] * nums[j];
                            int product2 = nums[k] * nums[l];
                            
                            if (product1 == product2) {
                                totalNumberOfTuples++;
                            }
                        }
                    }
                }
            }
        }
        return (totalNumberOfTuples / 2) * 8;
    }
}

// Approach-2 (Sorting to improve efficiency)
// T.C : O(n^4 + nlogn)
// S.C : O(1)
class Solution {
    public int tupleSameProduct(int[] nums) {
        int totalNumberOfTuples = 0;
        int n = nums.length;
        Arrays.sort(nums);
        
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j > i; j--) {
                for (int k = i + 1; k < j; k++) {
                    for (int l = j - 1; l > k; l--) {
                        int p1 = nums[i] * nums[j];
                        int p2 = nums[k] * nums[l];
                        
                        if (p1 == p2) {
                            totalNumberOfTuples++;
                        }
                    }
                }
            }
        }
        return totalNumberOfTuples * 8;
    }
}

// Approach-3 (Better Brute Force)
// T.C : O(n^3)
// S.C : O(n)
class Solution {
    public int tupleSameProduct(int[] nums) {
        int totalNumberOfTuples = 0;
        int n = nums.length;
        Arrays.sort(nums);
        
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j > i; j--) {
                int product = nums[i] * nums[j];
                Set<Integer> st = new HashSet<>();
                
                for (int k = i + 1; k < j; k++) {
                    if (product % nums[k] == 0) {
                        int lValue = product / nums[k];
                        
                        if (st.contains(lValue)) {
                            totalNumberOfTuples++;
                        }
                        
                        st.add(nums[k]);
                    }
                }
            }
        }
        return totalNumberOfTuples * 8;
    }
}

// Approach-4 (Using HashMap for counting pairs)
// T.C : O(n^2)
// S.C : O(n)
class Solution {
    public int tupleSameProduct(int[] nums) {
        int n = nums.length;
        int tuples = 0;
        Map<Integer, Integer> mp = new HashMap<>();
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int p = nums[i] * nums[j];
                mp.put(p, mp.getOrDefault(p, 0) + 1);
            }
        }
        
        for (int freq : mp.values()) {
            tuples += (freq * (freq - 1)) / 2;
        }
        
        return tuples * 8;
    }
}
