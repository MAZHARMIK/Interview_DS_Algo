/*   Scroll below to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will udpate later
    Leetcode Link               : https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville
*/


/******************************************************* C++ *******************************************************/
//Approach-1 (Simple using map)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> result;
        unordered_map<int, int> mp;
        for (int &num : nums) {
            mp[num]++;
            if (mp[num] == 2) {
                result.push_back(num);
            }
        }
        return result;
    }
};


//Approach-2 (Using bit mask and XOR)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        //0....n-1
        int n = nums.size() - 2;

        int XOR = 0; //a^b

        for(int &num : nums) {
            XOR ^= num;
        }

        for(int num = 0; num <= n-1; num++) { //original list
            XOR ^= num;
        }

        int trailZeroCount = __builtin_ctz(XOR);
        int mask = 1 << trailZeroCount;

        int G1 = 0;
        int G2 = 0;


        for(int &num : nums) {
            if(num & mask) {
                G1 ^= num;
            } else {
                G2 ^= num;
            }
        }

        for(int num = 0; num <= n-1; num++) {
            if(num & mask) {
                G1 ^= num;
            } else {
                G2 ^= num;
            }
        }

        return {G1, G2};
    }
};




/******************************************************* JAVA *******************************************************/
//Approach-1 (Simple using map)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int[] getSneakyNumbers(int[] nums) {
        List<Integer> result = new ArrayList<>();
        Map<Integer, Integer> map = new HashMap<>();

        for (int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
            if (map.get(num) == 2) {
                result.add(num);
            }
        }

        // Convert List<Integer> to int[]
        int[] res = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            res[i] = result.get(i);
        }

        return res;
    }
}


//Approach-2 (Using bit mask and XOR)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int[] getSneakyNumbers(int[] nums) {
        int n = nums.length - 2;
        int XOR = 0; // a ^ b

        // XOR of all numbers in nums
        for (int num : nums) {
            XOR ^= num;
        }

        // XOR of all numbers from 0 to n-1 (the original list)
        for (int num = 0; num <= n - 1; num++) {
            XOR ^= num;
        }

        // Find rightmost set bit (similar to __builtin_ctz in C++)
        int trailZeroCount = Integer.numberOfTrailingZeros(XOR);
        int mask = 1 << trailZeroCount;

        int G1 = 0;
        int G2 = 0;

        // Separate into two groups based on mask bit
        for (int num : nums) {
            if ((num & mask) != 0) {
                G1 ^= num;
            } else {
                G2 ^= num;
            }
        }

        for (int num = 0; num <= n - 1; num++) {
            if ((num & mask) != 0) {
                G1 ^= num;
            } else {
                G2 ^= num;
            }
        }

        return new int[]{G1, G2};
    }
}
