/*     Scroll below to see JAVA code also    */
/*
      MY YOUTUBE VIDEO ON THIS Qn : 
      Company Tags                : will update soon
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
