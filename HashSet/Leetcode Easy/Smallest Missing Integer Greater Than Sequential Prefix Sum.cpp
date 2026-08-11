/*   SCROLL BELOW TO SEE THE JAVA CODE AS WELL  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=K8vdd4IeD-o
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/description/
*/


/*************************************************************** C++ ***************************************************************/
//Approach-1 (using set)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> st(begin(nums), end(nums));

        int sequential = nums[0];
        for(int j = 1; j < n; j++) {
            if(nums[j] == nums[j-1] + 1) {
                sequential += nums[j];
            } else {
                break;
            }
        }

        while(st.count(sequential)) { //O(n)
            sequential++;
        }

        return sequential;

    }
};



//Approach-2 (using sorting)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        int sequential = nums[0];
        for(int j = 1; j < n; j++) {
            if(nums[j] == nums[j-1] + 1) {
                sequential += nums[j];
            } else {
                break;
            }
        }

        sort(begin(nums), end(nums));
        for(int i = 0; i < n; i++) {
            if(nums[i] == sequential)
                sequential++;
        }

        return sequential;

    }
};



/*************************************************************** JAVA ***************************************************************/
//Approach-1 (using set)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int missingInteger(int[] nums) {
        int n = nums.length;
        Set<Integer> st = new HashSet<>();
        for (int num : nums) {
            st.add(num);
        }
        
        int sequential = nums[0];
        for (int j = 1; j < n; j++) {
            if (nums[j] == nums[j - 1] + 1) {
                sequential += nums[j];
            } else {
                break;
            }
        }
        
        while (st.contains(sequential)) { //O(n)
            sequential++;
        }
        
        return sequential;
    }
}




//Approach-2 (using sorting)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
    public int missingInteger(int[] nums) {
        int n = nums.length;
        
        int sequential = nums[0];
        for (int j = 1; j < n; j++) {
            if (nums[j] == nums[j - 1] + 1) {
                sequential += nums[j];
            } else {
                break;
            }
        }
        
        Arrays.sort(nums);
        for (int i = 0; i < n; i++) {
            if (nums[i] == sequential) {
                sequential++;
            }
        }
        
        return sequential;
    }
}
