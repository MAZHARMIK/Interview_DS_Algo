/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=HodpFY9Y6Vs
    Company Tags                : Amazon, ABCO, Flipkart
    Question Link               : https://practice.geeksforgeeks.org/problems/rotation4723/1
*/

class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    int l = 0, r = n-1;
	    while(l < r) {
	        int mid = l + (r-l)/2;
	        if(arr[mid] < arr[r]) {
	            r = mid;
	        } else {
	            l = mid+1;
	        }
	    }
	    return r;
	}

};
