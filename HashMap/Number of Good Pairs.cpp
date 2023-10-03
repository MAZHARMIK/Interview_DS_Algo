/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=RSu9uQ-OGb0
    Company Tags                : META
    Leetcode Link               : https://leetcode.com/problems/number-of-good-pairs/
*/

/********************************************************* C++ *********************************************************/
//Approach-1 (Using simple double for loop and counting good pairs)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        for(int i = 0; i<n-1; i++) {
            int num = nums[i];
            
            for(int j = i+1; j<n; j++) {
                if(nums[j] == nums[i]) {
                    count++;
                }
            }
        }
        
        return count;
    }
};

//Approach-2 (Using hashmap)
//T.C : O(n) - Two Times Traversing
//S.C : O(1)
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int result = 0;
        unordered_map<int, int> mp;
        
        for(int &num : nums) {
            mp[num]++;
        }
        
        for(auto &it : mp) {
            
            int count = it.second;
            result += (count * (count-1))/2;
            
        }
        
        return result;
    }
};

//Approach-3 (Using hashmap)
//T.C : O(n) - One Time Traversing
//S.C : O(1)
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int result = 0;
        unordered_map<int, int> mp;
        
        for(int &num : nums) {
            result += mp[num]++;
        }
      
        return result;
    }
};

/********************************************************* JAVA *********************************************************/
//Approach-1 (Using simple double for loop and counting good pairs)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
    public int numIdenticalPairs(int[] nums) {
        int n = nums.length;
        int count = 0;
        
        for (int i = 0; i < n - 1; i++) {
            int num = nums[i];
            
            for (int j = i + 1; j < n; j++) {
                if (nums[j] == num) {
                    count++;
                }
            }
        }
        
        return count;
    }
}

//Approach-2 (Using hashmap)
//T.C : O(n) - Two Times Traversing
//S.C : O(1)
class Solution {
    public int numIdenticalPairs(int[] nums) {
        int result = 0;
        Map<Integer, Integer> map = new HashMap<>();
        
        for (int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        
        for (int count : map.values()) {
            result += (count * (count - 1)) / 2;
        }
        
        return result;
    }
}


//Approach-3 (Using hashmap)
//T.C : O(n) - One Time Traversing
//S.C : O(1)
class Solution {
    public int numIdenticalPairs(int[] nums) {
        int result = 0;
        Map<Integer, Integer> map = new HashMap<>();
        
        for (int num : nums) {
            result += map.getOrDefault(num, 0);
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        
        return result;
    }
}
