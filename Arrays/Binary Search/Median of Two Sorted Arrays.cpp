/*
    Company Tags  : Google, Microsoft, Apple, Zenefits, Yahoo, Adobe, Dropbox
    Leetcode Link : https://leetcode.com/problems/median-of-two-sorted-arrays/
*/

//Approach-1 (O(nlong))
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        vector<int> temp(m+n);
        int i = 0, j = 0, k = 0;
        
        while(i < m && j < n) {
            if(nums1[i] < nums2[j])
                temp[k++] = nums1[i++];
            else
                temp[k++] = nums2[j++];
        }
        
        while(i < m) temp[k++] = nums1[i++];
        while(j < n) temp[k++] = nums2[j++];
        
        int size = m+n;
        
        if(size%2 != 0) return temp[size/2];
        
        return (temp[size/2]+temp[max(0, size/2-1)])/(double(2));
        
    }
};

//Approach-2 (O(log(min(m, n)))
//Source : Tushar Roy's Explanation : https://www.youtube.com/watch?v=LPFhl65R7ww
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int m = nums1.size();
        int n = nums2.size();
        
        int low = 0, high = m;
        while(low <= high) {
            
            int Px = low + (high-low)/2;
            int Py = (m+n+1)/2 - Px;
            
            int maxLeftX  = (Px == 0) ? INT_MIN : nums1[Px-1];
            int minRightX = (Px == m) ? INT_MAX : nums1[Px];
            
            int maxLeftY  = (Py == 0) ? INT_MIN : nums2[Py-1];
            int minRightY = (Py == n) ? INT_MAX : nums2[Py];
            
            if(maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if((m+n)%2 == 0)
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/(double)2;
                
                return max(maxLeftX, maxLeftY);
            } else if(maxLeftX > minRightY) {
                high = Px-1;
            } else {
                low = Px+1;
            }
        }
        
        return -1;
    }
};
