/*
    Company Tags    : Amazon
    Question Link   : https://practice.geeksforgeeks.org/problems/row-with-minimum-number-of-1s/0/
    Time complexity : O(m*long(n))
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int binary_search(vector<int>& t) {
    int l = 0, r = t.size()-1;

    while(l < r) {
        int mid = l + (r-l)/2;
        
        if(t[mid] == 1) {
            r = mid;
        } else {
            l = mid+1;
        }
    }
    if(t[r] == 1)
        return r;
    return -1;
}

int main()
 {
	int T, m, n;
	cin >> T;
	while(T--) {
	    cin >> m >> n;
	    vector<vector<int>> t(m, vector<int>(n));
	    for(int i = 0; i<m; i++) {
	        for(int j = 0; j<n; j++) {
	            cin >> t[i][j];
	        }
	    }
	    
	    
	bool no_one = true;
        int minCount_ones = INT_MAX;
        int row = -1;
        for(int i = 0; i<m; i++) {
            if(t[i][n-1] == 0)
                continue;
            no_one = false;
            int first_one_index = binary_search(t[i]);
            if(first_one_index != -1) {
                int count_ones = n-first_one_index;
                if(count_ones < minCount_ones) {
                    row = i;
                    minCount_ones = count_ones;
                }
            }
        }
        cout << row << endl;
	}
}
