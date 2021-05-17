/*
    First you need to see how segment tree is impplemented.
    Then only, go to solve qns based on segment tree
    (It's mainly used in questions based on range and update queries)
*/

#include<bits/stdc++.h>
using namespace std;

int constructSt(vector<int>& nums, int l, int r, vector<int>& st, int si) {
    if(l > r)
        return 0;
    if(l == r) {
        st[si] = nums[l];
        return st[si];
    }
    int mid = l + (r-l)/2;

    st[si] = constructSt(nums, l, mid, st, 2*si+1) + constructSt(nums, mid+1, r, st, 2*si+2);

    return st[si];
}

int getSum(vector<int>& st, int ss, int se, int qs, int qe, int si) {
    //completely inside
    if(ss >= qs && se <= qe)
        return st[si];

    //out of bound
    if(se < qs || ss > qe)
        return 0;

    //if above two conditions not met, it means it's an over lap
    int mid = ss+(se-ss)/2;

    return getSum(st, ss, mid, qs, qe, 2*si+1) + getSum(st, mid+1, se, qs, qe, 2*si+2);
}

void updateSt(vector<int>& st, int ss, int se, int idx, int diff, int si) {
    //updates should be done only in relevant subtrees
    //else we don't need to go further down
    if(idx < ss || idx > se)
        return;

    st[si] += diff;

    if(ss != se) { //because mid will be 0 and we will continuously get stuck in 1st call (left half)
        int mid = ss+(se-ss)/2;
        updateSt(st, ss, mid, idx, diff, 2*si+1);    //1st call (left half)
        updateSt(st, mid+1, se, idx, diff, 2*si+2);  //2nd call (right half)
    }

}

int main() {
    vector<int> nums{1, 3, 5};
    int n = nums.size();

    int seg_size = 4*n;

    vector<int> st(seg_size); //segment tree
    int si = 0;     //index of segment tree

    constructSt(nums, 0, n-1, st, si);

    //This is my segment tree
    for(int i = 0; i<seg_size; i++) {
        cout << st[i] << " ";
    }
    cout << endl;
    //Range queries (O(log(n))
    cout << getSum(st, 0, n-1, 0, 1, 0) << endl; //output : 4
    cout << getSum(st, 0, n-1, 1, 2, 0) << endl; //output : 8

    //update array
    int idx   = 1;
    int val   = 4;
    int diff  = val - nums[idx];
    nums[idx] = val;

    //update value
    updateSt(st, 0, n-1, idx, diff, 0);

    //Range queries (O(log(n))
    cout << getSum(st, 0, n-1, 0, 1, 0) << endl; //output : 4
    cout << getSum(st, 0, n-1, 1, 2, 0) << endl; //output : 8

return 0;
}
