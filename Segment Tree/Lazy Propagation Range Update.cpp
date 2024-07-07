/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=FB_LjtTQwlw
    Company Tags                : Google and many other companies ask problems based on this
    GfG Link                    : https://www.geeksforgeeks.org/lazy-propagation-in-segment-tree/
*/

//NOTE - Below is just the function for updateRange
//i.e. For each query, we are asked to update values of nodes in range [start....end]

/*************************************************************** C++ ******************************************/
//T.C : O(logn)
//S.C : O(n)
//Assuming we have defined segmentTree[4*n] and lazyTree[4*n]
void updateRange(int start, int end, int i, int l, int r, int val) {
    if (lazyTree[i] != 0) {
        segTree[i] += (r - l + 1) * lazyTree[i];
      
        if (l != r) { //Not a leaf node
            lazyTree[i * 2 + 1] += lazyTree[i]; //Left Child in Lazy Tree
            lazyTree[i * 2 + 2] += lazyTree[i]; //Right Child in Lazy tree
        }
        lazyTree[i] = 0;
    }

    //Invalid or out of range
    if (l > end || r < start || l > r)
        return;

    //[start...end[ is Exactly withing range of current nod [l..r]
    if (l >= start && r <= end) {
        segTree[i] += (r - l + 1) * val;
        if (l != r) {
            lazyTree[i * 2 + 1] += val;
            lazyTree[i * 2 + 2] += val;
        }
        return;
    }

    //Call for left and right subtree
    int mid = (l + r) / 2;
    updateRange(start, end, 2*i+1, l, mid, val);
    updateRange(start, end, 2*i+2, mid+1, r, val);
    segTree[i] = segTree[i * 2 + 1] + segTree[i * 2 + 2];
}
