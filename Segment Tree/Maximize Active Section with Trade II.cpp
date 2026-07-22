/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=YW6kW65yRx8
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/maximize-active-section-with-trade-ii
*/


/**************************************************************** C++ ****************************************************************/
//Approach (Binary search and Segment Tree)
//T.C : O(n + qlog(n))
//S.C : O(n+q)
void buildSegmentTree(int i, int l, int r, int segmentTree[], int arr[]) {
    if (l == r) {
        segmentTree[i] = arr[l];
        return;
    }

    int mid = l + (r - l) / 2;
    buildSegmentTree(2 * i + 1, l, mid, segmentTree, arr);
    buildSegmentTree(2 * i + 2, mid + 1, r, segmentTree, arr);
    segmentTree[i] = max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
}

int* constructST(int arr[], int n) {
    int* segmentTree = new int[4 * n];
    buildSegmentTree(0, 0, n - 1, segmentTree, arr);
    return segmentTree;
}

int querySegmentTree(int start, int end, int i, int l, int r, int segmentTree[]) {
    if (l > end || r < start) {
        return INT_MIN;
    }

    if (l >= start && r <= end) {
        return segmentTree[i];
    }

    int mid = l + (r - l) / 2;
    return max(querySegmentTree(start, end, 2 * i + 1, l, mid, segmentTree),
               querySegmentTree(start, end, 2 * i + 2, mid + 1, r, segmentTree));
}

int RMQ(int st[], int n, int a, int b) {
    return querySegmentTree(a, b, 0, 0, n - 1, st);
}

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int activeCount = count(begin(s), end(s), '1');

        vector<int> blockStart;
        vector<int> blockEnd;


        int i = 0;
        while(i < n) {
            if(s[i] == '0') {
                int start = i;
                while(i < n && s[i] == '0') i++;
                blockStart.push_back(start);
                blockEnd.push_back(i-1);
            } else {
                i++;
            }
        }  

        int m = blockStart.size();

        //If there is only one block of zeros
        //example : s = "11000011" , answer = simply count of 1s "activeCount"
        if(m < 2) {
            return vector<int>(queries.size(), activeCount);
        }

        vector<int> blockSize(m);
        for(int i = 0; i < m; i++) {
            blockSize[i] = blockEnd[i] - blockStart[i] + 1;
        }

        //Pairsum : blockSize[i] = blockSize[i] + blockSize[i+1]
        int N = blockSize.size()-1; //this many pairs will be there in pairSum
        //{2, 3, 4, 5, 2}
        vector<int> pairSum(N);
        for(int i = 0; i < N; i++) {
            pairSum[i] = blockSize[i] + blockSize[i+1];
        }

        int *st = constructST(pairSum.data(), N);

        vector<int> result;
        for(auto &q : queries) { //O(q*log)
            int l = q[0];
            int r = q[1];

            //first block in this range
            int low  = lower_bound(begin(blockEnd), end(blockEnd), l) - begin(blockEnd); //log
            int high = upper_bound(begin(blockStart), end(blockStart), r) - begin(blockStart) - 1; //log

            int maxPairSum = 0;
            if(low < high) { //we need atleast two blocks
                int firstLen = blockEnd[low] - max(blockStart[low], l) + 1; 
                int lastLen  = min(blockEnd[high], r) - blockStart[high] + 1;

                if(high - low == 1) { //exactly two blocks are there only
                    maxPairSum = firstLen + lastLen;
                } else {
                    int pair1 = firstLen + blockSize[low+1];
                    int pair2 = blockSize[high-1] + lastLen;
                    int RMQMaxPairSum = RMQ(st, N, low+1, high-2); //log
                    maxPairSum = max({pair1, pair2, RMQMaxPairSum});
                }
            }
            result.push_back(maxPairSum + activeCount);
        }

        return result;
    }
};



/**************************************************************** JAVA ****************************************************************/
//Approach (Binary search and Segment Tree)
//T.C : O(n + qlog(n))
//S.C : O(n+q)
class Solution {
    static void buildSegmentTree(int i, int l, int r, int[] segmentTree, int[] arr) {
        if (l == r) {
            segmentTree[i] = arr[l];
            return;
        }

        int mid = l + (r - l) / 2;
        buildSegmentTree(2 * i + 1, l, mid, segmentTree, arr);
        buildSegmentTree(2 * i + 2, mid + 1, r, segmentTree, arr);
        segmentTree[i] = Math.max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
    }

    static int[] constructST(int[] arr, int n) {
        int[] segmentTree = new int[4 * n];
        buildSegmentTree(0, 0, n - 1, segmentTree, arr);
        return segmentTree;
    }

    static int querySegmentTree(int start, int end, int i, int l, int r, int[] segmentTree) {
        if (l > end || r < start) {
            return Integer.MIN_VALUE;
        }

        if (l >= start && r <= end) {
            return segmentTree[i];
        }

        int mid = l + (r - l) / 2;
        return Math.max(querySegmentTree(start, end, 2 * i + 1, l, mid, segmentTree),
                        querySegmentTree(start, end, 2 * i + 2, mid + 1, r, segmentTree));
    }

    static int RMQ(int[] st, int n, int a, int b) {
        return querySegmentTree(a, b, 0, 0, n - 1, st);
    }

    // first index k with arr[k] >= key   (C++ lower_bound)
    static int lowerBound(int[] arr, int len, int key) {
        int lo = 0, hi = len;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] < key) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }

    // first index k with arr[k] > key    (C++ upper_bound)
    static int upperBound(int[] arr, int len, int key) {
        int lo = 0, hi = len;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] <= key) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }

    public List<Integer> maxActiveSectionsAfterTrade(String s, int[][] queries) {
        int n = s.length();

        int activeCount = 0;
        for (int idx = 0; idx < n; idx++) {
            if (s.charAt(idx) == '1') activeCount++;
        }

        // scan zero-blocks, recording where each one sits
        int[] blockStart = new int[n];
        int[] blockEnd = new int[n];
        int m = 0;
        int i = 0;
        while (i < n) {
            if (s.charAt(i) == '0') {
                int start = i;
                while (i < n && s.charAt(i) == '0') i++;
                blockStart[m] = start;
                blockEnd[m] = i - 1;
                m++;
            } else {
                i++;
            }
        }

        //If there is only one block of zeros
        //example : s = "11000011" , answer = simply count of 1s "activeCount"
        if (m < 2) {
            List<Integer> res = new ArrayList<>();
            for (int k = 0; k < queries.length; k++) res.add(activeCount);
            return res;
        }

        int[] blockSize = new int[m];
        for (int k = 0; k < m; k++) {
            blockSize[k] = blockEnd[k] - blockStart[k] + 1;
        }

        // pairSum[k] = blockSize[k] + blockSize[k+1], gain from activating adjacent blocks
        int N = m - 1; //This many pair sum will be there in pairSum
        int[] pairSum = new int[N];
        for (int k = 0; k < N; k++) {
            pairSum[k] = blockSize[k] + blockSize[k + 1];
        }

        int[] st = constructST(pairSum, N);

        List<Integer> result = new ArrayList<>();
        for (int[] q : queries) {              // O(q * log n)
            int l = q[0];
            int r = q[1];

            // first block reaching into the window from the left
            int low  = lowerBound(blockEnd, m, l);          // log
            // last block reaching into the window from the right
            int high = upperBound(blockStart, m, r) - 1;    // log

            int maxPairSum = 0;
            if (low < high) {                  // need at least two blocks in the window
                int firstLen = blockEnd[low] - Math.max(blockStart[low], l) + 1;
                int lastLen  = Math.min(blockEnd[high], r) - blockStart[high] + 1;

                if (high - low == 1) {         // exactly two blocks only
                    maxPairSum = firstLen + lastLen;
                } else {
                    int pair1 = firstLen + blockSize[low + 1];
                    int pair2 = blockSize[high - 1] + lastLen;
                    int rmqMaxPairSum = (low + 1 <= high - 2) ? RMQ(st, N, low + 1, high - 2) : 0; 
                    maxPairSum = Math.max(pair1, Math.max(pair2, rmqMaxPairSum));
                }
            }
            result.add(maxPairSum + activeCount);
        }

        return result;
    }
}
