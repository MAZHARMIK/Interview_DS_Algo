/*	 Scroll below to see JAVA code also	*/
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=82HaBghHuDU
    Company Tags  		        : META
    Leetcode Link 		        : https://leetcode.com/problems/range-sum-query-mutable/description/
*/
//Range Queries are generally asked to check if the person knows about segment tree or not


/******************************************************** C++ ***************************************************************/
//Approach-1 (Brute Force : TLE)
//T.C : Constructor: O(n), where n is length of nums array
//      Update : O(1), sumRange: O(n)
//S.C : O(n)
class NumArray {
public:
    vector<int> num;
    int n;
    NumArray(vector<int>& nums) {
        num = nums;
        n   = nums.size();
    }
    
    void update(int index, int val) {
        num[index] = val;
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        for(int i = left; i <= right; i++) {
            sum += num[i];
        }
        return sum;
    }
};


//NOTE : You can improve Approach-1 further by taking another array storing cumulativeSum


//Approach-2 (Segment Tree)
//T.C : Constructor: O(n), where n is length of nums array
//      Update, sumRange: O(logN)
//S.C : O(n)
class NumArray {
public:

    int n;
    vector<int> segmentTree;

    void buildSegmentTree(int i, int l, int r, vector<int>& nums) {
        if(l == r) {
            segmentTree[i] = nums[l];
            return;
        }
        
        int mid = l + (r-l)/2;
        buildSegmentTree(2*i+1, l, mid, nums);
        buildSegmentTree(2*i+2, mid+1, r, nums);
        segmentTree[i] = segmentTree[2*i + 1] + segmentTree[2*i + 2];
    }

    void updateSegTree(int index, int val, int i, int l, int r) {
        if(l == r) {
            segmentTree[i] = val;
            return;
        }

        int mid = l + (r-l)/2;
        if(index <= mid) {
            updateSegTree(index, val, 2*i+1, l, mid);
        } else {
            updateSegTree(index, val, 2*i+2, mid+1, r);
        }

        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
    }

    int querySegmentTree(int start, int end, int i, int l, int r) {
        if(l > end || r < start) {
            return 0;
        }
        
        if(l >= start && r <= end) {
            return segmentTree[i];
        }
        
        int mid = l + (r-l)/2;
        return querySegmentTree(start, end, 2*i+1, l,    mid) + 
               querySegmentTree(start, end, 2*i+2, mid+1, r);
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segmentTree.resize(4*n);
        buildSegmentTree(0, 0, n-1, nums);
    }
    
    void update(int index, int val) {
        updateSegTree(index, val, 0, 0, n-1);
    }
    
    int sumRange(int left, int right) {
        return querySegmentTree(left, right, 0, 0, n-1);
    }
};




/******************************************************** JAVA ***************************************************************/
//Approach-1 (Brute Force : TLE)
//T.C : Constructor: O(n), where n is length of nums array
//      Update : O(1), sumRange: O(n)
//S.C : O(n)
class NumArray {
    private int[] num;
    private int n;

    public NumArray(int[] nums) {
        num = nums;
        n = nums.length;
    }

    public void update(int index, int val) {
        num[index] = val;
    }

    public int sumRange(int left, int right) {
        int sum = 0;
        for (int i = left; i <= right; i++) {
            sum += num[i];
        }
        return sum;
    }
}



//Approach-2 (Segment Tree)
//T.C : Constructor: O(n), where n is length of nums array
//      Update, sumRange: O(logN)
//S.C : O(n)
class NumArray {
    private int n;
    private int[] segmentTree;

    public NumArray(int[] nums) {
        n = nums.length;
        segmentTree = new int[4 * n];
        buildSegmentTree(0, 0, n - 1, nums);
    }

    private void buildSegmentTree(int i, int l, int r, int[] nums) {
        if (l == r) {
            segmentTree[i] = nums[l];
            return;
        }
        
        int mid = l + (r - l) / 2;
        buildSegmentTree(2 * i + 1, l, mid, nums);
        buildSegmentTree(2 * i + 2, mid + 1, r, nums);
        segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
    }

    public void update(int index, int val) {
        updateSegTree(index, val, 0, 0, n - 1);
    }

    private void updateSegTree(int index, int val, int i, int l, int r) {
        if (l == r) {
            segmentTree[i] = val;
            return;
        }

        int mid = l + (r - l) / 2;
        if (index <= mid) {
            updateSegTree(index, val, 2 * i + 1, l, mid);
        } else {
            updateSegTree(index, val, 2 * i + 2, mid + 1, r);
        }

        segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
    }

    public int sumRange(int left, int right) {
        return querySegmentTree(left, right, 0, 0, n - 1);
    }

    private int querySegmentTree(int start, int end, int i, int l, int r) {
        if (l > end || r < start) {
            return 0;
        }

        if (l >= start && r <= end) {
            return segmentTree[i];
        }

        int mid = l + (r - l) / 2;
        return querySegmentTree(start, end, 2 * i + 1, l, mid) + 
               querySegmentTree(start, end, 2 * i + 2, mid + 1, r);
    }
}
