/*	 Scroll below to see JAVA code also	*/
/*
    MY YOUTUBE VIDEO ON THIS Qn   : https://www.youtube.com/watch?v=gRF7k0dNr7k
    Company Tags  		          : will update later
    Leetcode Link 		          : https://leetcode.com/problems/count-good-triplets-in-an-array
*/

/******************************************************** C++ ***************************************************************/
//Approach (Using Segment Tree)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    void updateSegmentTree(int i, int l, int r, int updateIndex, vector<long long>& segmentTree) {
        if (l == r) {
            segmentTree[i] = 1;
            return;
        }

        int mid = l + (r - l) / 2;
        if (updateIndex <= mid) {
            updateSegmentTree(2 * i + 1, l, mid, updateIndex, segmentTree);
        } else {
            updateSegmentTree(2 * i + 2, mid + 1, r, updateIndex, segmentTree);
        }

        segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
    }

    long long querySegmentTree(int queryStart, int queryEnd, int i, int l, int r, vector<long long>& segmentTree) {
        if (r < queryStart || l > queryEnd) {
            return 0;
        }

        if (l >= queryStart && r <= queryEnd) {
            return segmentTree[i];
        }

        int mid = l + (r - l) / 2;
        long long left = querySegmentTree(queryStart, queryEnd, 2 * i + 1, l, mid, segmentTree);
        long long right = querySegmentTree(queryStart, queryEnd, 2 * i + 2, mid + 1, r, segmentTree);
        return left + right;
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums2[i]] = i;
        }

        vector<long long> segmentTree(4 * n);  // 0-based indexing segment tree
        long long result = 0;

        // Update with first element's mapped index from nums2
        updateSegmentTree(0, 0, n - 1, mp[nums1[0]], segmentTree);

        for (int i = 1; i < n; i++) {
            int idx = mp[nums1[i]];
            long long leftCommonCount = querySegmentTree(0, idx, 0, 0, n - 1, segmentTree);
            long long leftNotCommonCount = i - leftCommonCount;
            long long elementsAfterIdxNums2 = (n - 1) - idx;
            long long rightCommonCount = elementsAfterIdxNums2 - leftNotCommonCount;
            result += leftCommonCount * rightCommonCount;

            updateSegmentTree(0, 0, n - 1, idx, segmentTree);
        }

        return result;
    }
};



/******************************************************** JAVA ***************************************************************/
//Approach (Using Segment Tree)
//T.C : O(nlogn)
//S.C : O(n)
import java.util.*;

class Solution {
    public void updateSegmentTree(int i, int l, int r, int updateIndex, long[] segmentTree) {
        if (l == r) {
            segmentTree[i] = 1;
            return;
        }

        int mid = l + (r - l) / 2;
        if (updateIndex <= mid) {
            updateSegmentTree(2 * i + 1, l, mid, updateIndex, segmentTree);
        } else {
            updateSegmentTree(2 * i + 2, mid + 1, r, updateIndex, segmentTree);
        }

        segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
    }

    public long querySegmentTree(int queryStart, int queryEnd, int i, int l, int r, long[] segmentTree) {
        if (r < queryStart || l > queryEnd) {
            return 0;
        }

        if (l >= queryStart && r <= queryEnd) {
            return segmentTree[i];
        }

        int mid = l + (r - l) / 2;
        long left = querySegmentTree(queryStart, queryEnd, 2 * i + 1, l, mid, segmentTree);
        long right = querySegmentTree(queryStart, queryEnd, 2 * i + 2, mid + 1, r, segmentTree);
        return left + right;
    }

    public long goodTriplets(int[] nums1, int[] nums2) {
        int n = nums1.length;
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            mp.put(nums2[i], i);
        }

        long[] segmentTree = new long[4 * n];
        long result = 0;

        updateSegmentTree(0, 0, n - 1, mp.get(nums1[0]), segmentTree);

        for (int i = 1; i < n; i++) {
            int idx = mp.get(nums1[i]);
            long leftCommonCount = querySegmentTree(0, idx, 0, 0, n - 1, segmentTree);
            long leftNotCommonCount = i - leftCommonCount;
            long elementsAfterIdxNums2 = (n - 1) - idx;
            long rightCommonCount = elementsAfterIdxNums2 - leftNotCommonCount;
            result += leftCommonCount * rightCommonCount;

            updateSegmentTree(0, 0, n - 1, idx, segmentTree);
        }

        return result;
    }
}
