/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=jpuDyt-ruFc&list=PLpIkg8OmuX-LkgtrEF7eyyYWJM3m5tVQY&index=1
    Company Tags                : LinkedIn, Amazon, Microsoft
    Leetcode Link               : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
    GfG Practice                : https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x2041/1
*/

/********************************************** C++ **********************************************/
//Approach-1 (Using Two Custom Binary Search)
//T.C : O(nlogn)
class Solution {
public:
    int find_first_position(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        int result = -1;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(nums[mid] == target) {
                result = mid; //possibly my answer
                r = mid-1;     //but lets look at left more
            } else if(nums[mid] > target) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        return result;
    }
    
    int find_last_position(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        int result = -1;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(nums[mid] == target) {
                result = mid; //possibly my answer
                l = mid+1;   //but lets look at right more
            } else if(nums[mid] > target) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        return result;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int l = find_first_position(nums, target);
        int r = find_last_position(nums, target);
        
        return {l, r};
    }
};


//Approach-2 (Using C++ STL)
//T.C : O(nlogn)
class Solution {
public:
    
    //Approach-2
    vector<int> search_stl(vector<int>& nums, int target) {
        //first element equal to or greater than target
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        //first element greater than target
        int r = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        //Why do we need this (nums[l] != target) ? 
        //Because lower_bound returns first element which is equal or GREATER THAN target.
        //So, in case the target is not in the list, it will return first greater element than target which will be wrong
        if(l == nums.size() || nums[l] != target)
            return {-1, -1};
        
        return {l, r-1};
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        return search_stl(nums, target); //Approach - 2
    }
};



/********************************************** JAVA **********************************************/
//Approach-1 (Using Two Custom Binary Search)
//T.C : O(nlogn)
class Solution {
    public int findFirstPosition(int[] nums, int target) {
        int l = 0, r = nums.length - 1;
        int result = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                result = mid; // possibly my answer
                r = mid - 1; // but lets look at left more
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }

    public int findLastPosition(int[] nums, int target) {
        int l = 0, r = nums.length - 1;
        int result = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                result = mid; // possibly my answer
                l = mid + 1; // but lets look at right more
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }

    public int[] searchRange(int[] nums, int target) {
        int firstPosition = findFirstPosition(nums, target);
        int lastPosition = findLastPosition(nums, target);
        return new int[]{firstPosition, lastPosition};
    }
}


//Approach-2 (Using Own written lower and upper bound in java)
//T.C : O(nlogn)
import java.util.Arrays;
import java.util.List;

class Solution {
    public int[] searchRange(int[] nums, int target) {
        int l = lowerBound(nums, target);
        int r = upperBound(nums, target);
        
        if (l == nums.length || nums[l] != target) {
            return new int[]{-1, -1};
        }
        
        return new int[]{l, r - 1};
    }
    
    private int lowerBound(int[] nums, int target) {
        int left = 0;
        int right = nums.length;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
    
    private int upperBound(int[] nums, int target) {
        int left = 0;
        int right = nums.length;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
}
