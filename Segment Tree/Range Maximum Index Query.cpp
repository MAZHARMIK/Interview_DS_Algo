/*	 Scroll below to see JAVA code also	*/
/*
    MY YOUTUBE VIDEO ON THIS Qn   : https://www.youtube.com/watch?v=5n2zzL8EqNY
    Company Tags  		          : will update later
    Leetcode Link 		          : NIL
*/

/******************************************************** C++ ***************************************************************/
//T.C : O(n + q*(logn)^2)
//S.C : O(n)
class Solution {
public:
    // Builds the segment tree using the max function and stores indices
    void buildSegmentTree(int i, int l, int r, int segmentTree[], vector<int>& arr) {
        if (l == r) {
            segmentTree[i] = l; // Store the index
            return;
        }
        
        int mid = l + (r - l) / 2;
        buildSegmentTree(2 * i + 1, l, mid, segmentTree, arr);
        buildSegmentTree(2 * i + 2, mid + 1, r, segmentTree, arr);
        
        // Store the index of the maximum element
        segmentTree[i] = (arr[segmentTree[2 * i + 1]] >= arr[segmentTree[2 * i + 2]]) ?
                        segmentTree[2 * i + 1] : segmentTree[2 * i + 2];
    }

    // Function to construct the segment tree
    int* constructST(vector<int>& arr, int n) {
        int* segmentTree = new int[4 * n];
        buildSegmentTree(0, 0, n - 1, segmentTree, arr);
        return segmentTree;
    }

    // Function to query the segment tree for the index of the maximum value in range [start, end]
    int querySegmentTree(int start, int end, int i, int l, int r, int segmentTree[], vector<int>& arr) {
        if (l > end || r < start) {
            return -1; // Return -1 for out-of-bound queries
        }
        
        if (l >= start && r <= end) {
            return segmentTree[i]; // Return the index of the maximum element
        }
        
        int mid = l + (r - l) / 2;
        int leftIndex = querySegmentTree(start, end, 2 * i + 1, l, mid, segmentTree, arr);
        int rightIndex = querySegmentTree(start, end, 2 * i + 2, mid + 1, r, segmentTree, arr);

        // Handle cases where one side is out of bounds
        if (leftIndex == -1)
            return rightIndex;
        if (rightIndex == -1)
            return leftIndex;

        // Return the index of the maximum element
        return (arr[leftIndex] >= arr[rightIndex]) ? leftIndex : rightIndex;
    }

    // Function to return the index of the maximum element in the range from a to b
    int RMIQ(int st[], vector<int>& arr, int n, int a, int b) {
        return querySegmentTree(a, b, 0, 0, n - 1, st, arr);
    }

    vector<int> rangeMaximumIndexQuery(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int* segmentTree = constructST(arr, n);

        vector<int> result;
        for(auto& query: queries){
            int a = query[0];
            int b = query[1];

            int idx = RMIQ(segmentTree, arr, n, a, b);
            result.push_back(idx);
        }
        return result;
    }
};



/******************************************************** JAVA ***************************************************************/
//T.C : O(n + q*(logn))
//S.C : O(n)
class Solution {
    // Builds the segment tree using the max function and stores indices
    void buildSegmentTree(int i, int l, int r, int[] segmentTree, int[] arr) {
        if (l == r) {
            segmentTree[i] = l; // Store the index
            return;
        }

        int mid = l + (r - l) / 2;
        buildSegmentTree(2 * i + 1, l, mid, segmentTree, arr);
        buildSegmentTree(2 * i + 2, mid + 1, r, segmentTree, arr);

        // Store the index of the maximum element
        segmentTree[i] = (arr[segmentTree[2 * i + 1]] >= arr[segmentTree[2 * i + 2]]) ?
                        segmentTree[2 * i + 1] : segmentTree[2 * i + 2];
    }

    // Function to construct the segment tree
    int[] constructST(int[] arr, int n) {
        int[] segmentTree = new int[4 * n];
        buildSegmentTree(0, 0, n - 1, segmentTree, arr);
        return segmentTree;
    }

    // Function to query the segment tree for the index of the maximum value in range [start, end]
    int querySegmentTree(int start, int end, int i, int l, int r, int[] segmentTree, int[] arr) {
        if (l > end || r < start) {
            return -1; // Return -1 for out-of-bound queries
        }

        if (l >= start && r <= end) {
            return segmentTree[i]; // Return the index of the maximum element
        }

        int mid = l + (r - l) / 2;
        int leftIndex = querySegmentTree(start, end, 2 * i + 1, l, mid, segmentTree, arr);
        int rightIndex = querySegmentTree(start, end, 2 * i + 2, mid + 1, r, segmentTree, arr);

        // Handle cases where one side is out of bounds
        if (leftIndex == -1)
            return rightIndex;
        if (rightIndex == -1)
            return leftIndex;

        // Return the index of the maximum element
        return (arr[leftIndex] >= arr[rightIndex]) ? leftIndex : rightIndex;
    }

    // Function to return the index of the maximum element in the range from a to b
    int RMIQ(int[] st, int[] arr, int n, int a, int b) {
        return querySegmentTree(a, b, 0, 0, n - 1, st, arr);
    }

    public int[] rangeMaximumIndexQuery(int[] arr, int[][] queries) {
        int n = arr.length;
        int[] segmentTree = constructST(arr, n);

        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int a = queries[i][0];
            int b = queries[i][1];

            int idx = RMIQ(segmentTree, arr, n, a, b);
            result[i] = idx;
        }
        return result;
    }
}
