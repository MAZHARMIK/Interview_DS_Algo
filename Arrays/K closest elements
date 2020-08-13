/*
    Company Tags : Amazon, OYO Rooms
    Qn Link      : https://practice.geeksforgeeks.org/problems/k-closest-elements/0
*/

#include<bits/stdc++.h>
using namespace std;
int bin_search(vector<int>& arr, int x) {
    int l = 0, r = arr.size()-1;
    while(l<=r) {
        int mid = l + (r-l)/2;
        if(arr[mid] < x) {
            l = mid+1;
        } else if(arr[mid] > x) {
            r = mid-1;
        } else {
            return mid;
        }
    }
    return -1;
}

void printRange(vector<int>& vec, int l, int r) {
    for(int i = l; i<=r; i++)
        cout << vec[i] << " ";
}

int main()
 {
	int T,n, k, x;
	cin >> T;
	while(T--) {
	    cin >> n;
	    vector<int> vec(n);
	    for(int i = 0; i<n; i++)
	        cin >> vec[i];
	    cin >> k >> x;

	    int cp = bin_search(vec, x);
	    if(cp == n-1) {
	        //print left k elements excluding x
	        printRange(vec, n-k-1, n-2);
	    } else if(cp == 0) {
	        //print right k elements excluding x
	        printRange(vec, 1, k);
	    } else {
	        int l = cp-k/2;
	        int r = cp+k/2;
	        if(r >= n) {
	            l = l-(r-n+1);
	            r = n-1;
	        }
	        else if(l<0) {
	            r = r-l;
	            l = 0;
	        }
	        printRange(vec, l, cp-1);
	        printRange(vec, cp+1, r);
	    }

        cout << "\n";
	}
	return 0;
}
