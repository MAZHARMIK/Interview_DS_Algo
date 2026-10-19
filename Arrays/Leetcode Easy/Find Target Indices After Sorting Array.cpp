/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/find-target-indices-after-sorting-array
*/

/*********************************************************** C++ **************************************************/
//Approach-1 (Sort and find)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();

        sort(begin(nums), end(nums));
        
        vector<int> result;
        for(int i = 0; i < n; i++) {
            if(nums[i] == target) {
                result.push_back(i);
            }
        }

        return result;
    }
};


//Approach-2 (Using one Count variable)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count = 0;  // Number of elements less than target
        for (int &num : nums) {
            if (num < target) 
                count++;
        }

        vector<int> result;
        for (int& num : nums) {
            if (num == target) {
                result.push_back(count);
                count++;
            }
        }
        return result;
    }
};


//Approach-2 (Using two Count variables)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        
        int count1 = 0;  // Number of elements less than target
        int count2 = 0;  // Number of elements equal to target
        for (int &num : nums) {
            if (num < target) 
                count1++;
            else if(num == target)
                count2++;
        }

        vector<int> result;
        for(int i = count1; i < count1+count2; i++) {
            result.push_back(i);
        }
        return result;
    }
};




/*********************************************************** JAVA **************************************************/
//Approach-1 (Sort and find)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
    public List<Integer> targetIndices(int[] nums, int target) {
        int n = nums.length;

        Arrays.sort(nums);

        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                result.add(i);
            }
        }

        return result;
    }
}


//Approach-2 (Using one Count variable)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public List<Integer> targetIndices(int[] nums, int target) {
        int count = 0;  // Number of elements less than target
        for (int num : nums) {
            if (num < target)
                count++;
        }

        List<Integer> result = new ArrayList<>();
        for (int num : nums) {
            if (num == target) {
                result.add(count);
                count++;
            }
        }
        return result;
    }
}


//Approach-3 (Using two Count variables)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public List<Integer> targetIndices(int[] nums, int target) {
        int count1 = 0;  // Number of elements less than target
        int count2 = 0;  // Number of elements equal to target
        for (int num : nums) {
            if (num < target)
                count1++;
            else if (num == target)
                count2++;
        }

        List<Integer> result = new ArrayList<>();
        for (int i = count1; i < count1 + count2; i++) {
            result.add(i);
        }
        return result;
    }
}
