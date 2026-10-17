/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=8Fjin_L8Qmw
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-ii/
*/


/**************************************************************** C++ ****************************************************************/
//Approach (Segment Tree + Lazy Propagation
//T.C : O(nlogn)
//S.C : O(4*n)
class Solution {
public:
    typedef long long ll;
    int MOD = 1e9+7;
    int n;

    vector<ll> sqSumSegTree;
    vector<ll> sumSegTree;
    vector<ll> lazyTree;

    void lazyAddition(int i, int l, int r, int val) {
        int len = (r-l+1);

        sqSumSegTree[i] += 2*val*sumSegTree[i] + len * val * val;
        sumSegTree[i] += (len * val);
    }

    void updateRange(int start, int end, int i, int l, int r, int val) {
        if(lazyTree[i] != 0) {
            lazyAddition(i, l, r, lazyTree[i]);

            if(l != r) {
                lazyTree[2*i+1] += lazyTree[i];
                lazyTree[2*i+2] += lazyTree[i];
            }
            lazyTree[i] = 0;
        }

        //out of range
        if(l > end || r < start || l > r) {
            return;
        }

        //Completelty within range
        if(l >= start && r <= end) {
            lazyAddition(i, l, r, val);

            if(l != r) {
                lazyTree[2*i+1] += val;
                lazyTree[2*i+2] += val;
            }
            return;
        }

        int mid = l + (r-l)/2;
        updateRange(start, end, 2*i+1, l, mid, val);
        updateRange(start, end, 2*i+2, mid+1, r, val);

        sumSegTree[i]   = sumSegTree[2*i+1] + sumSegTree[2*i+2];
        sqSumSegTree[i] = sqSumSegTree[2*i+1] + sqSumSegTree[2*i+2];
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();

        sqSumSegTree.assign(4*n, 0);
        sumSegTree.assign(4*n, 0);
        lazyTree.assign(4*n, 0);

        vector<int> lastSeenIdx(100001, -1);
        ll result = 0;

        for(int i = 0; i < n; i++) {
            int start = lastSeenIdx[nums[i]] + 1;
            int end   = i;

            updateRange(start, end, 0, 0, n-1, 1);

            result = (result + sqSumSegTree[0]) % MOD;

            lastSeenIdx[nums[i]] = i;
        }

        return result;
    }
};




/**************************************************************** JAVA ****************************************************************/
//Approach (Segment Tree + Lazy Propagation
//T.C : O(nlogn)
//S.C : O(4*n)
class Solution {
    static final long MOD = 1_000_000_007L;
    int n;

    long[] sqSumSegTree;
    long[] sumSegTree;
    long[] lazyTree;

    void lazyAddition(int i, int l, int r, long val) {
        long len = r - l + 1;

        sqSumSegTree[i] += 2 * val * sumSegTree[i] + len * val * val;
        sumSegTree[i] += len * val;
    }

    void updateRange(int start, int end, int i, int l, int r, long val) {
        if (lazyTree[i] != 0) {
            lazyAddition(i, l, r, lazyTree[i]);

            if (l != r) {
                lazyTree[2 * i + 1] += lazyTree[i];
                lazyTree[2 * i + 2] += lazyTree[i];
            }
            lazyTree[i] = 0;
        }

        // out of range
        if (l > end || r < start || l > r) {
            return;
        }

        // completely within range
        if (l >= start && r <= end) {
            lazyAddition(i, l, r, val);

            if (l != r) {
                lazyTree[2 * i + 1] += val;
                lazyTree[2 * i + 2] += val;
            }
            return;
        }

        int mid = l + (r - l) / 2;
        updateRange(start, end, 2 * i + 1, l, mid, val);
        updateRange(start, end, 2 * i + 2, mid + 1, r, val);

        sumSegTree[i] = sumSegTree[2 * i + 1] + sumSegTree[2 * i + 2];
        sqSumSegTree[i] = sqSumSegTree[2 * i + 1] + sqSumSegTree[2 * i + 2];
    }

    public int sumCounts(int[] nums) {
        n = nums.length;

        sqSumSegTree = new long[4 * n];
        sumSegTree = new long[4 * n];
        lazyTree = new long[4 * n];

        int[] lastSeenIdx = new int[100001];
        java.util.Arrays.fill(lastSeenIdx, -1);
        long result = 0;

        for (int i = 0; i < n; i++) {
            int start = lastSeenIdx[nums[i]] + 1;
            int end = i;

            updateRange(start, end, 0, 0, n - 1, 1);

            result = (result + sqSumSegTree[0]) % MOD;

            lastSeenIdx[nums[i]] = i;
        }

        return (int) result;
    }
}
