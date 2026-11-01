/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=8Oe-ORyiAIY
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/minimum-moves-to-equal-array-elements
*/


/*********************************************************** C++ **************************************************/
//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    bool allEqual(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[0]) return false;
        }
        return true;
    }

    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int moves = 0;

        while (!allEqual(nums)) {
            // Find the max element's index
            int maxIdx = 0;
            for (int i = 1; i < n; i++) {
                if (nums[i] > nums[maxIdx]) maxIdx = i;
            }

            // Increment everything except the max
            for (int i = 0; i < n; i++) {
                if (i != maxIdx) nums[i]++;
            }
            moves++;
        }

        return moves;
    }
};


//Approach-2 (Two Pass)
//T.C : O(2*n) ~ O(n)
//S.C : O(1)
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
  
        int sum    = accumulate(begin(nums), end(nums), 0);
        int min_el = *min_element(begin(nums), end(nums));

        return sum - n*min_el;
    }
};

//Approach-3 (One Pass)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
  
        int sum    = 0;
        int min_el = INT_MAX;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            min_el = min(min_el, nums[i]);
        }

        return sum - n*min_el;
    }
};




/*********************************************************** JAVA **************************************************/
//Approach-1 (Brute Force)
//T.C : O(moves * n)  -> TLE
//S.C : O(1)
class Solution {
    private boolean allEqual(int[] nums) {
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[0]) return false;
        }
        return true;
    }

    public int minMoves(int[] nums) {
        int n = nums.length;
        int moves = 0;

        while (!allEqual(nums)) {
            // Find the max element's index
            int maxIdx = 0;
            for (int i = 1; i < n; i++) {
                if (nums[i] > nums[maxIdx]) maxIdx = i;
            }

            // Increment everything except the max
            for (int i = 0; i < n; i++) {
                if (i != maxIdx) nums[i]++;
            }
            moves++;
        }

        return moves;
    }
}


//Approach-2 (Two Pass)
//T.C : O(2*n) ~ O(n)
//S.C : O(1)
class Solution {
    public int minMoves(int[] nums) {
        int n = nums.length;

        long sum = 0;
        for (int x : nums) {
            sum += x;
        }

        int minEl = Integer.MAX_VALUE;
        for (int x : nums) {
            minEl = Math.min(minEl, x);
        }

        return (int) (sum - (long) n * minEl);
    }
}



//Approach-3 (One Pass)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int minMoves(int[] nums) {
        int n = nums.length;

        long sum = 0;
        int minEl = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            minEl = Math.min(minEl, nums[i]);
        }

        return (int) (sum - (long) n * minEl);
    }
}
