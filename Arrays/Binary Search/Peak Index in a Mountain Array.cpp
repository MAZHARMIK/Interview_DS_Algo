/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Op07kT-LoH8
      Company Tags                : GOOGLE
      Leetcode Link               : https://leetcode.com/problems/peak-index-in-a-mountain-array/
*/

//A very good Followup Qn on this - Leetcode - 1059 : Find in Mountain Array


//Approach-1 (Using Linear Search) - T.C : O(n)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        
        int i = 0;
       //You can remove i < n-1 check because array is gauranteed to be Mountain (given in qn)
        while(i < n-1 && arr[i] < arr[i+1])
            i++;
        
        return i;
    }
};


//Approach-2 (Using Binary Search) - T.C : O(log(n))
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        
        int l = 0;
        int r = n-1;
        
        while(l < r) {
            
            int mid = l + (r-l)/2;
            
            if(arr[mid] < arr[mid+1])
                l = mid+1;
            else
                r = mid;
            
        }
        
        return l;
    }
};
