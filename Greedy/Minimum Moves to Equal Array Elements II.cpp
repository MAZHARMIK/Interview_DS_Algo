/*         Scroll down to see JAVA code also                    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
*/


/********************************************************************* C++ ****************************************************************/
//Approach-1 (Greedily Pick mid element)
//T.C : O(nlogn) for sorting
//S.C : O(1)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        int mid = nums[n/2];

        int moves = 0;
        for(int i = 0; i < n; i++) {
            moves += abs(nums[i] - mid);
        }

        return moves;
    }
};


//Approach-2 (Iterate till n/2)
//T.C : O(nlogn) for sorting
//S.C : O(1)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        int mid = nums[n/2];

        int moves = 0;
        for(int i = 0; i < n/2; i++) {
            moves += abs(nums[i] - mid);
            moves += abs(nums[n-i-1] - mid);
        }

        return moves;
    }
};

//Approach-3 (Use nth_element for Average Sort)
//T.C : Average O(n) for nth_element
//S.C : O(1)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        nth_element(begin(nums), begin(nums)+n/2, end(nums)); //O(n) average

        int mid = nums[n/2];

        int moves = 0;
        for(int i = 0; i < n/2; i++) {
            moves += abs(nums[i] - mid);
            moves += abs(nums[n-i-1] - mid);
        }

        return moves;
    }
};




/********************************************************************* JAVA ****************************************************************/
//Approach-1 (Greedily Pick mid element)
//T.C : O(nlogn) for sorting
//S.C : O(1)
class Solution {
    public int minMoves2(int[] nums) {
        int n = nums.length;

        Arrays.sort(nums);

        int mid = nums[n / 2];

        int moves = 0;
        for (int i = 0; i < n; i++) {
            moves += Math.abs(nums[i] - mid);
        }

        return moves;
    }
}


//Approach-2 (Iterate till n/2)
//T.C : O(nlogn) for sorting
//S.C : O(1)
class Solution {
    public int minMoves2(int[] nums) {
        int n = nums.length;

        Arrays.sort(nums);

        int mid = nums[n / 2];

        int moves = 0;
        for (int i = 0; i < n / 2; i++) {
            moves += Math.abs(nums[i] - mid);
            moves += Math.abs(nums[n - i - 1] - mid);
        }

        return moves;
    }
}


//I will cover QuickSort and QuickSelect in a separate video
//Approach-3 (Use nth_element for Average Sort)
//T.C : Average O(n) for nth_element
//S.C : O(1)
class Solution {
    private final Random rand = new Random();

    private void swap(int[] nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }

    private void quickSelect(int[] nums, int k) {
        int left = 0, right = nums.length - 1;

        while (left < right) {
            int pivot = nums[left + rand.nextInt(right - left + 1)];

            int lt = left, i = left, gt = right;
            while (i <= gt) {
                if (nums[i] < pivot)      swap(nums, lt++, i++);
                else if (nums[i] > pivot) swap(nums, i, gt--);
                else                      i++;
            }

            if (k < lt)       right = lt - 1;
            else if (k > gt)  left = gt + 1;
            else              return;
        }
    }

    public int minMoves2(int[] nums) {
        int n = nums.length;

        quickSelect(nums, n / 2);   // O(n) average

        int mid = nums[n / 2];

        int moves = 0;
        for (int i = 0; i < n / 2; i++) {
            moves += Math.abs(nums[i] - mid);
            moves += Math.abs(nums[n - i - 1] - mid);
        }

        return moves;
    }
}
