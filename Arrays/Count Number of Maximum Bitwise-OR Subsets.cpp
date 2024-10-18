/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets
*/


/************************************************************ C++ ************************************************/
//Approach-1 (Using simple recursion to find subsets)
//T.C : O(2^n)
//S.C : O(1)
class Solution {
public:
    //O(2^n)
    int countSubsets(int idx, int currOr, vector<int>& nums, int maxOr) {
        if(idx == nums.size()) {
            if(currOr == maxOr)
                return 1; //Found one subset
            return 0;
        }

        //Take nums[idx]
        int takeCount = countSubsets(idx+1, currOr | nums[idx], nums, maxOr);

        //Not taken nums[idx]
        int notTakeCount = countSubsets(idx+1, currOr, nums, maxOr);


        return takeCount + notTakeCount;

    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(int &num : nums) {
            maxOr |= num;
        }

        int currOr = 0;
        return countSubsets(0, currOr, nums, maxOr);
    }
};



//Approach-2 (Memoizing to store subproblems result)
//T.C : O(n*maxOr)
//S.C : O(1)
class Solution {
public:
    //O(2^n)
    int countSubsets(int idx, int currOr, vector<int>& nums, int maxOr, vector<vector<int>>& t) {
        if(idx == nums.size()) {
            if(currOr == maxOr)
                return t[idx][currOr] = 1; //Found one subset
            return t[idx][currOr] = 0;
        }

        if(t[idx][currOr] != -1) {
            return t[idx][currOr];
        }

        //Take nums[idx]
        int takeCount = countSubsets(idx+1, currOr | nums[idx], nums, maxOr, t);

        //Not taken nums[idx]
        int notTakeCount = countSubsets(idx+1, currOr, nums, maxOr, t);


        return t[idx][currOr] = takeCount + notTakeCount;

    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(int &num : nums) {
            maxOr |= num;
        }
        int n = nums.size();

        vector<vector<int>> t(n+1, vector<int>(maxOr+1, -1));
        int currOr = 0;
        return countSubsets(0, currOr, nums, maxOr, t);
    }
};



/************************************************************ JAVA ************************************************/
//Approach-1 (Using simple recursion to find subsets)
//T.C : O(2^n)
//S.C : O(1)
class Solution {
    // O(2^n)
    private int countSubsets(int idx, int currOr, int[] nums, int maxOr) {
        if (idx == nums.length) {
            if (currOr == maxOr)
                return 1; // Found one subset
            return 0;
        }

        // Take nums[idx]
        int takeCount = countSubsets(idx + 1, currOr | nums[idx], nums, maxOr);

        // Not taken nums[idx]
        int notTakeCount = countSubsets(idx + 1, currOr, nums, maxOr);

        return takeCount + notTakeCount;
    }

    public int countMaxOrSubsets(int[] nums) {
        int maxOr = 0;
        for (int num : nums) {
            maxOr |= num;
        }

        int currOr = 0;
        return countSubsets(0, currOr, nums, maxOr);
    }
}

//Approach-2 (Memoizing to store subproblems result)
//T.C : O(n*maxOr)
//S.C : O(1)
class Solution {
    // O(2^n)
    private int countSubsets(int idx, int currOr, int[] nums, int maxOr, int[][] t) {
        if (idx == nums.length) {
            if (currOr == maxOr)
                return t[idx][currOr] = 1; // Found one subset
            return t[idx][currOr] = 0;
        }

        if (t[idx][currOr] != -1) {
            return t[idx][currOr];
        }

        // Take nums[idx]
        int takeCount = countSubsets(idx + 1, currOr | nums[idx], nums, maxOr, t);

        // Not taken nums[idx]
        int notTakeCount = countSubsets(idx + 1, currOr, nums, maxOr, t);

        return t[idx][currOr] = takeCount + notTakeCount;
    }

    public int countMaxOrSubsets(int[] nums) {
        int maxOr = 0;
        for (int num : nums) {
            maxOr |= num;
        }
        int n = nums.length;

        int[][] t = new int[n + 1][maxOr + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= maxOr; j++) {
                t[i][j] = -1;
            }
        }

        int currOr = 0;
        return countSubsets(0, currOr, nums, maxOr, t);
    }
}
