/*
    Company Tags      : Amazon, ABCO, Flipkart
    Video Explanation : You can request for a video explanation by letting me know on LinkedIn. It's free
    Question Link     : https://practice.geeksforgeeks.org/problems/rotation4723/1
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
