/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Google, Microsoft, Apple, Zenefits, Yahoo, Adobe, Dropbox
    Leetcode Link               : https://leetcode.com/problems/median-of-two-sorted-arrays/
*/

//Approach-1 - Brute Force
//T.C : O(m+n)
//S.C : O(m+n)
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
        
        if(size%2 != 0)
            return temp[size/2];
        
        return (temp[size/2]+temp[(size/2)-1])/2.0;
        
    }
};


//Approach-2 - Optimising Space from Approach-1
//T.C : O(m+n)
//S.C : O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int size = m+n;
        
        int idx1 = (size/2)-1;
        int element1 = -1;
        int idx2 = size/2;
        int element2 = -1;
        
        int i = 0, j = 0, k = 0;
        
        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                if(k == idx1) {
                    element1 = nums1[i];
                }
                if(k == idx2) {
                    element2 = nums1[i];
                }
                i++;
            } else {
                if(k == idx1) {
                    element1 = nums2[j];
                }
                if(k == idx2) {
                    element2 = nums2[j];
                }
                j++;
            }
            k++;
        }
        
        while(i < m) {
            if(k == idx1) {
                element1 = nums1[i];
            }
            if(k == idx2) {
                element2 = nums1[i];
            }
            i++;
            k++;
        }
        
        while(j < n) {
            if(k == idx1) {
                element1 = nums2[j];
            }
            if(k == idx2) {
                element2 = nums2[j];
            }
            j++;
            k++;
        }

        if(size%2 == 1)
            return element2;
        
        return (element1 + element2)/2.0;
        
    }
};
