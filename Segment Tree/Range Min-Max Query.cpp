/*
    Company Tags  : Facebook (Variation)
    Qn Link       : https://practice.geeksforgeeks.org/problems/range-minimum-query/1#
    Below code for "Min" Query. Simply replace min() with max() and it will be "Max" Query
*/

#include<bits/stdc++.h>
using namespace std;

int buildTree(vector<int>& nums, vector<int>& st, int ss, int se, int si) {
    if(ss > se)
        return INT_MAX;
    
    if(ss == se) {
        return st[si] = nums[se];
	}
	
    int mid = ss + (se-ss)/2;

    return st[si] = min(buildTree(nums, st, ss, mid, 2*si+1), buildTree(nums, st, mid+1, se, 2*si+2));
    
}

int getMin(vector<int>& st, int ss, int se, int &qs, int &qe, int si) {
    //if range is out of query range
    if(ss > qe || se < qs) {
        return INT_MAX;
    }
    
    //if range is totally inside query range
    if(ss >= qs && se <= qe) {
        return st[si];
    }
    
    //else we need to split and find the required query range
    int mid = ss + (se-ss)/2;
    
    return min(getMin(st, ss, mid, qs, qe, 2*si+1), getMin(st, mid+1, se, qs, qe, 2*si+2));
}

void updateTree(vector<int>& st, int ss, int se, int& idx, int& diff,  int si) {
	if(ss > se)
		return;
    //if idx is out of current range, then it has no impact 
    if(idx < ss || idx > se)
        return;
    st[si] += diff;
	if(ss != se) {
		int mid = ss + (se - ss)/2;
		updateTree(st, ss, mid, idx, diff, 2*si+1);
		updateTree(st, mid+1, se, idx, diff, 2*si+2);    
	}
}

int main() {
    vector<int> vec{1, 3, 2, 7, 9, 11};
    int n = vec.size();
    vector<int> st(4*n);
    buildTree(vec, st, 0, n-1, 0);
    int qs = 1, qe = 5;
    cout << getMin(st, 0, n-1, qs, qe, 0) << endl;

    
return 0;
}
