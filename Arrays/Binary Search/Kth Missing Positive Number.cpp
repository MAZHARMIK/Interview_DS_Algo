/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=BltzCxN1vRc
    Company Tags                : Google, Apple, Amazon, Meta
    Leetcode Link               : https://leetcode.com/problems/kth-missing-positive-number/
*/


//Naive Approach - Linear Time Complexity
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int num = 1;
        
        int n = arr.size();
        int i = 0;
        while (i < n && k > 0) {
            
            if(arr[i] == num) {
                i++;
            } else {
                k--;
            }
            
            num++;
        }
        
        while(k--) {
            num++;
        }
        
        return num-1;
    }
};


//Approach-2 (Binary Search) - O(log(n))
/*
  Explanation : 
  Since all the number in the array are in increasing order , so If NONE of the elemts is missing then 
  for each index i we should have the value (i+1). Here we are considering 0 based indexing.
  But if some the elements upto any index is missing , then we can find the number of missing elements using above logic.

  No of missing numbers at index i = (Current Value at index i ) - ( Correct Value as per contiguous sequence )
  = A[i]-(i+1) // At any index i
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        
        int l = 0, r = n-1;
        
        while(l <= r) {
            int mid = l + (r-l)/2;
            
            if(arr[mid] - (mid+1) < k) { //A[mid]-(mid+1)   --> This gives umber of missing number before m'th index
                l = mid+1;
            } else {
                r = mid-1;
            }
            
        }
        
        
        return l + k; //see my youtube video above for the explanation of this line
    }
};
