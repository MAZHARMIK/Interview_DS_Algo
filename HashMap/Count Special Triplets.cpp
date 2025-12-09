/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=WQ05CRcTraY
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/count-special-triplets/
*/


/************************************************************ C++ *****************************************************/
//Approach-1 (Using map : 2 Pass Solution)
//T.C : O(2*n)
//S.C : O(n)
class Solution {
public:
    int M = 1e9+7;

    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> mp_left;
        unordered_map<int, int> mp_right;

        int result = 0;

        for(int &num : nums) {
            mp_right[num]++;
        }

        for(int &num : nums) {
            mp_right[num]--;

            int left  = mp_left[num*2];
            int right = mp_right[num*2];

            result = (result + (1LL * left * right)) % M;

            mp_left[num]++;
        }

        return result;
    }
};



//Approach-2 (Using map :  Pass Solution)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int M = 1e9+7;

    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> valid_i;
        unordered_map<int, int> valid_j;

        int result = 0;

        for(int &num : nums) {
            
            if(num%2 == 0) { //if it's valid k, we got our triplet
                result = (result + valid_j[num/2]) % M;
            }

            //If it's valid j or not
            valid_j[num] = (valid_j[num] + valid_i[num*2]) % M;

            valid_i[num]++;
        }

        return result;
    }
};




/************************************************************ JAVA *****************************************************/
//Approach-1 (Using map : 2 Pass Solution)
//T.C : O(2*n)
//S.C : O(n)
class Solution {
    static final int M = (int)1e9 + 7;

    public int specialTriplets(int[] nums) {
        Map<Integer, Integer> mpLeft = new HashMap<>();
        Map<Integer, Integer> mpRight = new HashMap<>();

        int result = 0;

        // Fill mpRight with frequencies
        for (int num : nums) {
            mpRight.put(num, mpRight.getOrDefault(num, 0) + 1);
        }

        // Traverse again
        for (int num : nums) {
            // Reduce count from right map
            mpRight.put(num, mpRight.get(num) - 1);

            int left  = mpLeft.getOrDefault(num * 2, 0);
            int right = mpRight.getOrDefault(num * 2, 0);

            long add = (1L * left * right) % M;
            result = (int)((result + add) % M);

            mpLeft.put(num, mpLeft.getOrDefault(num, 0) + 1);
        }

        return result;
    }
}




//Approach-2 (Using map :  Pass Solution)
//T.C : O(n)
//S.C : O(n)
class Solution {
    static final int M = (int)1e9 + 7;

    public int specialTriplets(int[] nums) {
        Map<Integer, Integer> validI = new HashMap<>();
        Map<Integer, Integer> validJ = new HashMap<>();

        int result = 0;

        for (int num : nums) {

            // If num is valid k (k must be even)
            if (num % 2 == 0) {
                result = (result + validJ.getOrDefault(num / 2, 0)) % M;
            }

            // Is current num a valid j?
            int updatedJ = (validJ.getOrDefault(num, 0) +
                            validI.getOrDefault(num * 2, 0)) % M;
            validJ.put(num, updatedJ);

            // Count num as a valid i
            validI.put(num, validI.getOrDefault(num, 0) + 1);
        }

        return result;
    }
}
