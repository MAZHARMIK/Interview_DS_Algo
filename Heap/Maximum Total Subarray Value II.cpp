/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=7L-0oxtqEGw
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/maximum-total-subarray-value-ii/
*/

/*********************************************************** C++ **************************************************/
//Approach (Segment Tree + Max Heap)
//T.C : O(n*logn + k*logn)
//S.C : O(n)
class SegmentTree {
public:
    vector<int> segmentTree;
    bool isMinTree;

    SegmentTree(vector<int>& nums, bool flag) {
        int n = nums.size();
        this->isMinTree = flag;

        segmentTree.resize(4 * n);

        buildSegmentTree(0, 0, n - 1, nums);
    }

    void buildSegmentTree(int i, int l, int r, vector<int>& nums) {
        if (l == r) {
            segmentTree[i] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;

        buildSegmentTree(2 * i + 1, l, mid, nums);
        buildSegmentTree(2 * i + 2, mid + 1, r, nums);

        if (isMinTree) {
            segmentTree[i] = min(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
        } else {
            segmentTree[i] = max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
        }
    }

    int querySegmentTree(int start, int end, int i, int l, int r) {
        //No overlap
        if (l > end || r < start) {
            return isMinTree ? INT_MAX : INT_MIN;
        }

        //Complete Overlap
        if (l >= start && r <= end) {
            return segmentTree[i];
        }

        int mid = l + (r - l) / 2;

        int a = querySegmentTree(start, end, 2 * i + 1, l, mid);
        int b = querySegmentTree(start, end, 2 * i + 2, mid + 1, r);

        if (isMinTree) {
            return min(a, b);
        }

        return max(a, b);
    }

    int query(int l, int r, int n) {
        return querySegmentTree(l, r, 0, 0, n - 1);
    }
};

class Solution {
public:
    typedef long long ll;

    ll getValue(int l, int r, SegmentTree& minST, SegmentTree& maxST, int n) {
        int minEl = minST.query(l, r, n);
        int maxEl = maxST.query(l, r, n);

        return (ll)maxEl - minEl;
    }

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        SegmentTree minST(nums, true);   //true is for minimum
        SegmentTree maxST(nums, false);  //false is for maximum

        //{val, l, r} max. heap
        priority_queue<tuple<ll, int, int>> pq;

        //Step-1 (Initialize the heap with best value)
        //O(n*logn)
        for (int l = 0; l < n; l++) {  //l to n-1
            ll value = getValue(l, n - 1, minST, maxST, n);  //log(n)
            pq.push({value, l, n - 1});
        }

        //Step-2 Find top k
        ll result = 0;
        //O(k * log(n))
        while (k--) {
            auto [value, l, r] = pq.top();
            pq.pop();

            result += value;

            ll nextBestValue = getValue(l, r - 1, minST, maxST, n);  //log(n)

            pq.push({nextBestValue, l, r - 1});  //log(n)
        }

        return result;
    }
};


/*********************************************************** JAVA **************************************************/
//Approach (Segment Tree + Max Heap)
//T.C : O(n*logn + k*logn)
//S.C : O(n)
class SegmentTree {
    int[] segmentTree;
    boolean isMinTree;

    SegmentTree(int[] nums, boolean flag) {
        int n = nums.length;
        this.isMinTree = flag;
        segmentTree = new int[4 * n];
        buildSegmentTree(0, 0, n - 1, nums);
    }

    void buildSegmentTree(int i, int l, int r, int[] nums) {
        if (l == r) {
            segmentTree[i] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;

        buildSegmentTree(2 * i + 1, l, mid, nums);
        buildSegmentTree(2 * i + 2, mid + 1, r, nums);

        if (isMinTree) {
            segmentTree[i] = Math.min(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
        } else {
            segmentTree[i] = Math.max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
        }
    }

    int querySegmentTree(int start, int end, int i, int l, int r) {
        //No overlap
        if (l > end || r < start) {
            return isMinTree ? Integer.MAX_VALUE : Integer.MIN_VALUE;
        }

        //Complete Overlap
        if (l >= start && r <= end) {
            return segmentTree[i];
        }

        int mid = l + (r - l) / 2;

        int a = querySegmentTree(start, end, 2 * i + 1, l, mid);
        int b = querySegmentTree(start, end, 2 * i + 2, mid + 1, r);

        if (isMinTree) {
            return Math.min(a, b);
        }

        return Math.max(a, b);
    }

    int query(int l, int r, int n) {
        return querySegmentTree(l, r, 0, 0, n - 1);
    }
}

class Solution {
    long getValue(int l, int r, SegmentTree minST, SegmentTree maxST, int n) {
        int minEl = minST.query(l, r, n);
        int maxEl = maxST.query(l, r, n);
        return (long) maxEl - minEl;
    }

    public long maxTotalValue(int[] nums, int k) {
        int n = nums.length;

        SegmentTree minST = new SegmentTree(nums, true);   //true is for minimum
        SegmentTree maxST = new SegmentTree(nums, false);  //false is for maximum

        //{val, l, r} max. heap
        PriorityQueue<long[]> pq = new PriorityQueue<>((a, b) -> Long.compare(b[0], a[0]));

        //Step-1 (Initialize the heap with best value)
        //O(n*logn)
        for (int l = 0; l < n; l++) {
            long value = getValue(l, n - 1, minST, maxST, n);  //log(n)
            pq.offer(new long[]{value, l, n - 1});
        }

        //Step-2 Find top k
        long result = 0;
        //O(k * log(n))
        while (k-- > 0) {
            long[] top = pq.poll();
            long value = top[0];
            int l = (int) top[1];
            int r = (int) top[2];

            result += value;

            long nextBestValue = getValue(l, r - 1, minST, maxST, n);  //log(n)

            pq.offer(new long[]{nextBestValue, l, r - 1});  //log(n)
        }

        return result;
    }
}
