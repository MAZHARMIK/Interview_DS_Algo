/*    Scroll below to see JAVA code also     */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=S2u88Gzby0U
    Company Tags                : Microsoft
    Leetcode Link               : https://leetcode.com/problems/minimum-common-value/
*/


/********************************************************************* C++ *********************************************************************/
//Approach-1 (Using set)
//T.C : O(m+n)
//S.C : O(m)
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(begin(nums1), end(nums1));
        
        for(int &num : nums2) {
            if(st.find(num) != st.end()) {
                return num;
            }
        }
        
        return -1;
    }
};


//Approach-2 (Using Binary Search)
//T.C : O(mlogn)
//S.C : O(1)
class Solution {
public:
    bool binarySearch(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        
        while(l <= r) {
            int mid = l + (r-l)/2;
            
            if(nums[mid] == target) {
                return true;
            } else if(nums[mid] < target) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        
        return false;
    }
    
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        for(int &num : nums1) {
            if(binarySearch(nums2, num))
                return num;
        }
        
        return -1;
    }
};


//Approach-3 (Using 2 Pointer)
//T.C : O(m+n)
//S.C : O(1)
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        int i = 0; //for nums1
        int j = 0; //for nums2
        
        while(i < m && j < n) {
            if(nums1[i] == nums2[j]) {
                return nums1[i];
            } else if(nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        
        return -1;
    }
};


/********************************************************************* JAVA *********************************************************************/
// Approach-1 (Using set)
// T.C : O(m+n)
// S.C : O(m)
class Solution {
    public int getCommon(int[] nums1, int[] nums2) {
        Set<Integer> set = new HashSet<>();
        for (int num : nums1) {
            set.add(num);
        }

        for (int num : nums2) {
            if (set.contains(num)) {
                return num;
            }
        }

        return -1;
    }
}

// Approach-2 (Using Binary Search)
// T.C : O(mlogn)
// S.C : O(1)
class Solution {
    public boolean binarySearch(int[] nums, int target) {
        int l = 0, r = nums.length - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return false;
    }

    public int getCommon(int[] nums1, int[] nums2) {
        for (int num : nums1) {
            if (binarySearch(nums2, num)) {
                return num;
            }
        }

        return -1;
    }
}

// Approach-3 (Using 2 Pointer)
// T.C : O(m+n)
// S.C : O(1)
class Solution {
    public int getCommon(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;

        int i = 0; // for nums1
        int j = 0; // for nums2

        while (i < m && j < n) {
            if (nums1[i] == nums2[j]) {
                return nums1[i];
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }

        return -1;
    }
}
