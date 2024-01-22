/*
    MY YOUTUE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=j89Yzq3IwVY
    Company tags               : Amazon
    Leetcode Link              : https://leetcode.com/problems/set-mismatch/
*/

/****************************************************************** C++ ******************************************************************/
//Approach-1 (Smart Approach)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        
        int dup     = -1;
        int missing = -1;
        
        for(int i = 0; i<n; i++) {
            int num = abs(nums[i]);
            
            if(nums[num-1] < 0)
                dup = num;
            else
                nums[num-1] *= (-1);
        }
        
        for(int i = 0; i<n; i++) {
            if(nums[i] > 0) {
                missing = i+1;
                break;
            }
        }
        
        return {dup, missing};
    }
};


//Approach-2 (Basic Approach)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int miss = 0, dup = 0;
        
        map<int, int> mp;
        for(int x:nums) {
            mp[x]++;
        }
        
        for(int i = 1; i<=n; i++) {
            if(mp.count(i)) {
                if(mp[i] == 2)
                    dup = i;
            } else
                miss = i;
        }
        
        return {dup, miss};
    }
};


/****************************************************************** C++ ******************************************************************/
//Approach-1 (Smart Approach)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int[] findErrorNums(int[] nums) {
        int n = nums.length;
        
        int dup = -1;
        int missing = -1;
        
        for (int i = 0; i < n; i++) {
            int num = Math.abs(nums[i]);
            
            if (nums[num - 1] < 0)
                dup = num;
            else
                nums[num - 1] *= (-1);
        }
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                missing = i + 1;
                break;
            }
        }
        
        return new int[]{dup, missing};
    }
}



//Approach-2 (Basic Approach)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int[] findErrorNums(int[] nums) {
        int n = nums.length;
        int miss = 0, dup = 0;
        
        Map<Integer, Integer> map = new HashMap<>();
        for (int x : nums) {
            map.put(x, map.getOrDefault(x, 0) + 1);
        }
        
        for (int i = 1; i <= n; i++) {
            if (map.containsKey(i)) {
                if (map.get(i) == 2) {
                    dup = i;
                }
            } else {
                miss = i;
            }
        }
        
        return new int[]{dup, miss};
    }
}
