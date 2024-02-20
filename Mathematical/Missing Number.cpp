/*                         Scroll down to see JAVA code also         */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=lpyQGkbDvqI
    Company Tags                : Facebook, Bloomberg, Accolite, Adobe, Amazon, Cisco, D-E-Shaw, Intuit, Microsoft, Morgan Stanley,
                                  Ola Cabs, Payu, Qualcomm, Visa (Dayummmmmm bro)
    Leetcode Link               : https://leetcode.com/problems/missing-number/
*/


/*************************************************************************** C++ ***************************************************************************/
//Approach-1 (XOR)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = nums.size();
        for(int i = 0; i<nums.size(); i++) {
            sum ^= i;
            sum ^= nums[i];
        }
        return sum;
    }
};


//Approach-2 (Math)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n*(n+1)/2;
        for(int i = 0; i<n; i++) {
            sum -= nums[i];
        }
        return sum;
    }
};

//Approach-3 (Binary Search)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l   = 0;
        int r   = n-1;
        int result = n;
        
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(nums[mid] > mid) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        return result;
        
    }
};


/*************************************************************************** JAVA ***************************************************************************/
// Approach-1 (XOR)
// T.C: O(n)
// S.C: O(1)
class Solution {
    public int missingNumber(int[] nums) {
        int sum = nums.length;
        for (int i = 0; i < nums.length; i++) {
            sum ^= i;
            sum ^= nums[i];
        }
        return sum;
    }
}

// Approach-2 (Math)
// T.C: O(n)
// S.C: O(1)
class Solution2 {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        int sum = n * (n + 1) / 2;
        for (int i = 0; i < n; i++) {
            sum -= nums[i];
        }
        return sum;
    }
}

// Approach-3 (Binary Search)
// T.C: O(nlogn)
// S.C: O(1)
class Solution3 {
    public int missingNumber(int[] nums) {
        Arrays.sort(nums);
        int l = 0;
        int r = nums.length-1;
        int mid = nums.length;

        while(l <= r) {
            int mid = l + (r-l)/2;
            if(nums[mid] > mid) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return result;
    }
}
