/*     Scroll below to see JAVA code also    */
/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=pYqncHGUqh4
      Company Tags                : AMAZON
      Leetcode Link               : https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x
*/


/*************************************************** C++ ***************************************************/
//Approach-1 (Using binary search)
//T.C : O(n*logn)
//S.C : O(1)
class Solution {
public:

    int specialArray(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();

        for(int x = 0; x <=n; x++) {
            
            int i = lower_bound(begin(nums), end(nums), x) - begin(nums);

            if(n-i == x) {
                return x;
            }
        }

        return -1;
    }
};


//Approach-2 (Binary search on answer)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:

    int specialArray(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        
        int l = 0, r = n;
        while(l <= r) {
            int mid_x = l + (r-l)/2;

            int i = lower_bound(begin(nums), end(nums), mid_x) - begin(nums);

            if(n-i == mid_x) {
                return mid_x;
            } else if(n-i > mid_x) {
                l = mid_x+1;
            } else {
                r = mid_x-1;
            }
        }

        return -1;
    }
};


//Approach-3 (Using counting Sort + Prefix Sum)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();

        /*
            Every number larger than N is useless for our purpose,
            and we can treat those numbers as N. 
        */
        vector<int> freq(n+1);

        for(int i = 0; i < n; i++) {
            freq[min(n, nums[i])]++;
        }

        int c_sum = 0;
        for(int i = n; i >= 0; i--) {
            c_sum += freq[i];
            if(i == c_sum) {
                return i;
            }
        }
        
        return -1;
    }
};



/*************************************************** JAVA ***************************************************/
//Approach-1 (Using binary search)
//T.C : O(n*logn)
//S.C : O(1)
class Solution {
    public int specialArray(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;

        for (int x = 0; x <= n; x++) {
            int i = lowerBound(nums, x);

            if (n - i == x) {
                return x;
            }
        }

        return -1;
    }

    // Custom implementation of lower bound
    private int lowerBound(int[] nums, int x) {
        int left = 0;
        int right = nums.length;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}


//Approach-2 (Binary search on answer)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
    public int specialArray(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        
        int l = 0, r = n;
        while (l <= r) {
            int mid_x = l + (r - l) / 2;
            int i = lowerBound(nums, mid_x);

            if (n - i == mid_x) {
                return mid_x;
            } else if (n - i > mid_x) {
                l = mid_x + 1;
            } else {
                r = mid_x - 1;
            }
        }

        return -1;
    }

    // Custom implementation of lower bound
    private int lowerBound(int[] nums, int x) {
        int left = 0;
        int right = nums.length;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
}


//Approach-3 (Using counting Sort + Prefix Sum)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int specialArray(int[] nums) {
        int n = nums.length;
        
        // Frequency array
        int[] freq = new int[n + 1];
        
        // Populate the frequency array
        for (int num : nums) {
            if (num >= n) {
                freq[n]++;
            } else {
                freq[num]++;
            }
        }
        
        // Calculate cumulative sum from the end
        int c_sum = 0;
        for (int i = n; i >= 0; i--) {
            c_sum += freq[i];
            if (i == c_sum) {
                return i;
            }
        }
        
        return -1;
    }
}
