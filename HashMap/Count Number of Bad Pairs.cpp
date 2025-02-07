/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/count-number-of-bad-pairs
*/


/************************************************************ C++ *****************************************************/
//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();

        long long result = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(j-i != nums[j] - nums[i]) {
                    result++;
                }
            }
        }

        return result;
    }
};

//Approach-2 (Using hashmap)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();

        long long result = 0;
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++) {
            int diff = nums[i] - i;

            int totalPairsTillIndex = i;
            int goodPairs           = mp[diff];

            result += (totalPairsTillIndex - goodPairs);

            mp[diff]++; 
        }

        return result;
    }
};


/************************************************************ Java *****************************************************/
//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
    public long countBadPairs(int[] nums) {
        int n = nums.length;
        long result = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (j - i != nums[j] - nums[i]) {
                    result++;
                }
            }
        }
        
        return result;
    }
}

//Approach-2 (Using hashmap)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public long countBadPairs(int[] nums) {
        int n = nums.length;
        long result = 0;
        HashMap<Integer, Integer> mp = new HashMap<>();
        
        for (int i = 0; i < n; i++) {
            int diff = nums[i] - i;
            int totalPairsTillIndex = i;
            int goodPairs = mp.getOrDefault(diff, 0);
            
            result += (totalPairsTillIndex - goodPairs);
            
            mp.put(diff, goodPairs + 1);
        }
        
        return result;
    }
}
