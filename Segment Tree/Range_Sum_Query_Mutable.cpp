/*
    Company Tags  : Facebook
    Leetcode Link : https://leetcode.com/problems/range-sum-query-mutable/
*/

//Range Queries are generally asked to check if the person knows about segment tree or not

//Approach-1 (Brute Force : TLE)
class NumArray {
public:
    vector<int> num;
    vector<int> dp;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n);
        num.resize(n);
        dp[0] = nums[0];
        num[0] = nums[0];
        for(int i = 1; i < n; i++){
            num[i] = nums[i];
            dp[i]  = dp[i-1] + nums[i];
        }
    }
    
    void update(int i, int val) {
        int update_diff = val-num[i];
        num[i] = val;
        for (int j = i ; j < dp.size(); j++) {
            dp[j] += update_diff;
        }
    }
    
    int sumRange(int left, int right) {
        if(left > 0)
            return dp[right] - dp[left-1];
        return dp[right];
    }
};

//Approach-2 (Segment Tree)
class NumArray {
public:
    void updateValueUtil(int ss, int se, int index, int diff, int si) {
        if(index < ss || index > se)
            return;
        
        //if index is in the range of current node, then update it and its children as well
        st[si] += diff;
        if(ss != se) {
            int mid = ss+(se-ss)/2;
            updateValueUtil(ss, mid, index, diff, 2*si+1);
            updateValueUtil(mid+1, se, index, diff, 2*si+2);
        }
    }
    void updateValue(vector<int>& nums, int n, int index, int new_val) {
        if(index < 0 || index >= n)
            return;
        
        int diff = new_val - nums[index];
        nums[index] = new_val;
        //update segment tree nodes with diff
        updateValueUtil(0, n-1, index, diff, 0);
    }
    int getSumRangeUtil(int ss, int se, int qs, int qe, int si) {
        //case-1 current segment completely fall inside query range
        //return the node sum because it will be part of result (no need to go down further)
        if(ss >= qs && se <= qe)
            return st[si];
        
        //case-2 current segment is completely outside of my range
        //return 0
        if(se < qs || ss > qe)
            return 0;
        
        //case-3 : current segment overlaps in the range query
        //Break and recursively find the correct range
        int mid = ss+(se-ss)/2;
        return getSumRangeUtil(ss, mid, qs, qe, 2*si+1) + getSumRangeUtil(mid+1, se, qs, qe, 2*si+2);
    }
    int getSumRange(int n, int qs, int qe) {
        if(qs < 0 || qe >= n || qs > qe)
            return -1;
        
        return getSumRangeUtil(0, n-1, qs, qe, 0);
    }
    int constructSTUtil(vector<int>& nums, int ss, int se, int si) {
        if(ss == se) {
            st[si] = nums[ss];
            return st[si];
        }
        
        int mid = ss+(se-ss)/2;
        
        st[si] = constructSTUtil(nums, ss, mid, 2*si+1) + constructSTUtil(nums, mid+1, se, 2*si+2);
        
        return st[si];
    }

    vector<int> st;
    vector<int> nums;
    int n;
    NumArray(vector<int>& arr) {
        n = arr.size();
        nums.resize(n);
        nums = arr;
        // Build segment tree from given array 
	st.resize(4*n);
        constructSTUtil(nums, 0, n-1, 0);
    }
    
    void update(int index, int val) {
        updateValue(nums, n, index, val);
    }
    
    int sumRange(int left, int right) {
        return getSumRange(n, left, right);
    }
};
