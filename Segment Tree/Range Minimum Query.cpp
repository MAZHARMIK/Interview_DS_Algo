/*   Scroll below to see JAVA code also	*/
/*
	MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=qU4DAnv3o7g
   	Company Tags   	  	    : Facebook (Variation)
    	GFG Link       		    : https://practice.geeksforgeeks.org/problems/range-minimum-query/1#

    	Below code is for "Min" Query. Simply replace min() with max() and it will become for "Max" Query
*/


/************************************************************ C++ ***************************************************************************/
//Using Segment Tree
//T.C : O(q*log(n))
//S.C : O(4*n)
// Function to build the segment tree
void buildSegmentTree(int i, int l, int r, int segmentTree[], int arr[]) {
    if (l == r) {
        segmentTree[i] = arr[l];
        return;
    }
    
    int mid = l + (r - l) / 2;
    buildSegmentTree(2 * i + 1, l, mid, segmentTree, arr);
    buildSegmentTree(2 * i + 2, mid + 1, r, segmentTree, arr);
    segmentTree[i] = min(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
}

// Function to construct the segment tree
int* constructST(int arr[], int n) {
    int* segmentTree = new int[4 * n];
    buildSegmentTree(0, 0, n - 1, segmentTree, arr);
    return segmentTree;
}

// Function to query the segment tree for minimum value in range [start, end]
int querySegmentTree(int start, int end, int i, int l, int r, int segmentTree[]) {
    if (l > end || r < start) {
        return INT_MAX;
    }
    
    if (l >= start && r <= end) {
        return segmentTree[i];
    }
    
    int mid = l + (r - l) / 2;
    return min(querySegmentTree(start, end, 2 * i + 1, l, mid, segmentTree),
               querySegmentTree(start, end, 2 * i + 2, mid + 1, r, segmentTree));
}

// Function to return the minimum element in the range from a to b
int RMQ(int st[], int n, int a, int b) {
    return querySegmentTree(a, b, 0, 0, n - 1, st);
}



/************************************************************ JAVA ***************************************************************************/
//Using Segment Tree
//T.C : O(q*log(n))
//S.C : O(4*n)
class GfG {
    static int st[];

    // Function to build the segment tree
    public static void buildSegmentTree(int i, int l, int r, int arr[]) {
        if (l == r) {
            st[i] = arr[l];
            return;
        }

        int mid = l + (r - l) / 2;
        buildSegmentTree(2 * i + 1, l, mid, arr);
        buildSegmentTree(2 * i + 2, mid + 1, r, arr);
        st[i] = Math.min(st[2 * i + 1], st[2 * i + 2]);
    }

    // Function to construct the segment tree
    public static int[] constructST(int arr[], int n) {
        // Allocate memory for segment tree
        int height = (int) Math.ceil(Math.log(n) / Math.log(2));
        int size = 2 * (int) Math.pow(2, height) - 1;
        st = new int[size];

        // Build the segment tree
        buildSegmentTree(0, 0, n - 1, arr);

        return st;
    }

    // Function to query the segment tree for minimum value in range [l, r]
    public static int querySegmentTree(int start, int end, int i, int l, int r) {
        // If the range is completely outside the current node range
        if (l > end || r < start) {
            return Integer.MAX_VALUE;
        }

        // If the range is completely inside the current node range
        if (l >= start && r <= end) {
            return st[i];
        }

        // If the range is partially inside and outside the current node range
        int mid = l + (r - l) / 2;
        return Math.min(querySegmentTree(start, end, 2 * i + 1, l, mid),
                        querySegmentTree(start, end, 2 * i + 2, mid + 1, r));
    }

    // Function to return the minimum element in the range from l to r
    public static int RMQ(int st[], int n, int l, int r) {
        return querySegmentTree(l, r, 0, 0, n - 1);
    }
}
