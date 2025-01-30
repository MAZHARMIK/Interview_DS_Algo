/*	 Scroll below to see JAVA code also	*/
/*
    MY YOUTUBE VIDEO ON THIS Qn   : Concept Video      : https://www.youtube.com/watch?v=SpBjlU3ETL0
                                    This problem Video : https://www.youtube.com/watch?v=Eh2UHBHxqvc
    Company Tags  		          : will update later
    Leetcode Link 		          : https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet
*/

/******************************************************** C++ ***************************************************************/
//Approach (Using Segment Tree Range Maximum Query + Binary Search)
//T.C : O(n + q*(logn)^2)
//S.C : O(n)
class Solution {
public:
    // Builds the segment tree using the max function and stores indices
    void buildSegmentTree(int i, int l, int r, int segmentTree[], vector<int>& heights) {
        if (l == r) {
            segmentTree[i] = l; // Store the index
            return;
        }
        
        int mid = l + (r - l) / 2;
        buildSegmentTree(2 * i + 1, l, mid, segmentTree, heights);
        buildSegmentTree(2 * i + 2, mid + 1, r, segmentTree, heights);
        
        // Store the index of the maximum element
        segmentTree[i] = (heights[segmentTree[2 * i + 1]] >= heights[segmentTree[2 * i + 2]]) ?
                        segmentTree[2 * i + 1] : segmentTree[2 * i + 2];
    }

    // Function to construct the segment tree
    int* constructST(vector<int>& heights, int n) {
        int* segmentTree = new int[4 * n];
        buildSegmentTree(0, 0, n - 1, segmentTree, heights);
        return segmentTree;
    }

    // Function to query the segment tree for the index of the maximum value in range [start, end]
    int querySegmentTree(int start, int end, int i, int l, int r, int segmentTree[], vector<int>& heights) {
        if (l > end || r < start) {
            return -1; // Return -1 for out-of-bound queries
        }
        
        if (l >= start && r <= end) {
            return segmentTree[i]; // Return the index of the maximum element
        }
        
        int mid = l + (r - l) / 2;
        int leftIndex = querySegmentTree(start, end, 2 * i + 1, l, mid, segmentTree, heights);
        int rightIndex = querySegmentTree(start, end, 2 * i + 2, mid + 1, r, segmentTree, heights);

        // Handle cases where one side is out of bounds
        if (leftIndex == -1)
            return rightIndex;
        if (rightIndex == -1)
            return leftIndex;

        // Return the index of the maximum element
        return (heights[leftIndex] >= heights[rightIndex]) ? leftIndex : rightIndex;
    }

    // Function to return the index of the maximum element in the range from a to b
    int RMIQ(int st[], vector<int>& heights, int n, int a, int b) {
        return querySegmentTree(a, b, 0, 0, n - 1, st, heights);
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int* segmentTree = constructST(heights, n);

        vector<int> result;
        for(auto& query: queries){
            int alice = min(query[0],query[1]);
            int bob   = max(query[0],query[1]);

            if(alice == bob || heights[bob] > heights[alice]){
                result.push_back(bob);
                continue;
            }

            int l = bob+1;
            int r = n - 1;
            int result_idx = INT_MAX;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                int idx = RMIQ(segmentTree, heights, n, l, mid);

                if (heights[idx] > max(heights[alice], heights[bob])) {
                    r = mid - 1;
                    result_idx = min(result_idx, idx);
                } else {
                    l = mid + 1;
                }
            }

            if(result_idx == INT_MAX) {
                result.push_back(-1);
            } else {
                result.push_back(result_idx);
            }
        }
        return result;
    }
};



/******************************************************** JAVA ***************************************************************/
//Approach (Using Segment Tree Range Maximum Query + Binary Search)
//T.C : O(n + q*(logn)^2)
//S.C : O(n)
class Solution {
    // Builds the segment tree using the max function and stores indices
    private void buildSegmentTree(int i, int l, int r, int[] segmentTree, int[] heights) {
        if (l == r) {
            segmentTree[i] = l; // Store the index
            return;
        }

        int mid = l + (r - l) / 2;
        buildSegmentTree(2 * i + 1, l, mid, segmentTree, heights);
        buildSegmentTree(2 * i + 2, mid + 1, r, segmentTree, heights);

        // Store the index of the maximum element
        segmentTree[i] = (heights[segmentTree[2 * i + 1]] >= heights[segmentTree[2 * i + 2]]) ?
                segmentTree[2 * i + 1] : segmentTree[2 * i + 2];
    }

    // Function to construct the segment tree
    private int[] constructST(int[] heights) {
        int n = heights.length;
        int[] segmentTree = new int[4 * n];
        buildSegmentTree(0, 0, n - 1, segmentTree, heights);
        return segmentTree;
    }

    // Function to query the segment tree for the index of the maximum value in range [start, end]
    private int querySegmentTree(int start, int end, int i, int l, int r, int[] segmentTree, int[] heights) {
        if (l > end || r < start) {
            return -1; // Return -1 for out-of-bound queries
        }

        if (l >= start && r <= end) {
            return segmentTree[i]; // Return the index of the maximum element
        }

        int mid = l + (r - l) / 2;
        int leftIndex = querySegmentTree(start, end, 2 * i + 1, l, mid, segmentTree, heights);
        int rightIndex = querySegmentTree(start, end, 2 * i + 2, mid + 1, r, segmentTree, heights);

        // Handle cases where one side is out of bounds
        if (leftIndex == -1) return rightIndex;
        if (rightIndex == -1) return leftIndex;

        // Return the index of the maximum element
        return (heights[leftIndex] >= heights[rightIndex]) ? leftIndex : rightIndex;
    }

    // Function to return the index of the maximum element in the range from a to b
    private int RMIQ(int[] st, int[] heights, int a, int b) {
        return querySegmentTree(a, b, 0, 0, heights.length - 1, st, heights);
    }

    public int[] leftmostBuildingQueries(int[] heights, int[][] queries) {
        int n = heights.length;
        int[] segmentTree = constructST(heights);
        int[] result = new int[queries.length];

        for (int q = 0; q < queries.length; q++) {
            int alice = Math.min(queries[q][0], queries[q][1]);
            int bob = Math.max(queries[q][0], queries[q][1]);

            if (alice == bob || heights[bob] > heights[alice]) {
                result[q] = bob;
                continue;
            }

            int l = bob + 1, r = n - 1, resultIdx = Integer.MAX_VALUE;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                int idx = RMIQ(segmentTree, heights, l, mid);

                if (heights[idx] > Math.max(heights[alice], heights[bob])) {
                    r = mid - 1;
                    resultIdx = Math.min(resultIdx, idx);
                } else {
                    l = mid + 1;
                }
            }

            result[q] = (resultIdx == Integer.MAX_VALUE) ? -1 : resultIdx;
        }

        return result;
    }
}
