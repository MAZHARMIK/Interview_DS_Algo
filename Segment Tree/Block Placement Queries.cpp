/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=s3_sqPldDTU
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/block-placement-queries/description/
*/


/*********************************************************** C++ **************************************************/
//Approach-1 (Brute Force using Ordered Set)
//T.C : O(Q * N) where Q = number of queries, N = number of obstacles inserted so far
//S.C : O(N) for the ordered set
class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        vector<bool> result;

        set<int> st;

        for(auto &query : queries) {
            if(query[0] == 1) { //Type-1 Query
                st.insert(query[1]); //insert x
            } else {
                int x = query[1];
                int sz = query[2];

                int prev = 0;
                bool found = false;

                for(int curr : st) {
                    if(curr > x) {
                        break;
                    }

                    if(curr - prev >= sz) {
                        found = true;
                        break;
                    }

                    prev = curr;
                }

                if(!found) {
                    found = (x - prev >= sz);
                }

                result.push_back(found);
            }
        }

        return result;
    }
};


//Approach-2 (Segment Tree + Ordered Set)
//T.C : O(Q * logN) where Q = number of queries, N = max coordinate (50000)
//S.C : O(N) for the segment tree and ordered set
class Solution {
public:
    vector<int> segmentTree;
    int n = 50000;

    void constructSegmentTree() {
        segmentTree.resize(4*n, 0);
    }

    void updateSegTree(int idx, int val, int i, int l, int r) {
        if(l == r) {
            segmentTree[i] = val;
            return;
        }

        int mid = l + (r-l)/2;

        if(idx <= mid) {
            updateSegTree(idx, val, 2*i+1, l, mid);
        } else {
            updateSegTree(idx, val, 2*i+2, mid+1, r);
        }

        segmentTree[i] = max(segmentTree[2*i+1], segmentTree[2*i+2]);
    }

    int querySegTree(int start, int end, int i, int l, int r) {
        if(l > end || r < start) { //out of range node hai ye, return kar jao
            return 0;
        }

        if(l >= start && r <= end) {
            return segmentTree[i];
        }

        int mid = l + (r-l)/2;

        return max(querySegTree(start, end, 2*i+1, l, mid), querySegTree(start, end, 2*i+2, mid+1, r));
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        constructSegmentTree();

        set<int> st; //obstacles
        st.insert(0);

        vector<bool> result;

        for(auto& query : queries) {
            if(query[0] == 1) {
                int x = query[1];

                auto it = st.upper_bound(x);
                int nxt = (it != st.end()) ? *it : -1;
                int pre = *prev(it);

                updateSegTree(x, x-pre, 0, 0, n-1);
                if(nxt != -1) updateSegTree(nxt, nxt-x, 0, 0, n-1);

                st.insert(x);
            } else {
                int x = query[1];
                int sz = query[2];

                auto it = st.upper_bound(x);
                int pre = *prev(it);

                int maxGap = querySegTree(0, pre, 0, 0, n-1);
                int best = max(maxGap, x-pre);

                result.push_back(best >= sz);
            }
        }

        return result;
    }
};


/*********************************************************** JAVA **************************************************/
//Approach-1 (Brute Force using Ordered Set)
//T.C : O(Q * N) where Q = number of queries, N = number of obstacles inserted so far
//S.C : O(N) for the ordered set
class Solution {
    public List<Boolean> getResults(int[][] queries) {
        List<Boolean> result = new ArrayList<>();

        TreeSet<Integer> st = new TreeSet<>();

        for(int[] query : queries) {
            if(query[0] == 1) { //Type-1 Query
                st.add(query[1]); //insert x
            } else {
                int x = query[1];
                int sz = query[2];

                int prev = 0;
                boolean found = false;

                for(int curr : st) {
                    if(curr > x) {
                        break;
                    }

                    if(curr - prev >= sz) {
                        found = true;
                        break;
                    }

                    prev = curr;
                }

                if(!found) {
                    found = (x - prev >= sz);
                }

                result.add(found);
            }
        }

        return result;
    }
}


//Approach-2 (Segment Tree + Ordered Set)
//T.C : O(Q * logN) where Q = number of queries, N = max coordinate (50000)
//S.C : O(N) for the segment tree and ordered set
class Solution {
    int[] segmentTree;
    int n = 50000;

    void constructSegmentTree() {
        segmentTree = new int[4 * n];
    }

    void updateSegTree(int idx, int val, int i, int l, int r) {
        if(l == r) {
            segmentTree[i] = val;
            return;
        }

        int mid = l + (r - l) / 2;

        if(idx <= mid) {
            updateSegTree(idx, val, 2*i+1, l, mid);
        } else {
            updateSegTree(idx, val, 2*i+2, mid+1, r);
        }

        segmentTree[i] = Math.max(segmentTree[2*i+1], segmentTree[2*i+2]);
    }

    int querySegTree(int start, int end, int i, int l, int r) {
        if(l > end || r < start) {
            return 0;
        }

        if(l >= start && r <= end) {
            return segmentTree[i];
        }

        int mid = l + (r - l) / 2;

        return Math.max(querySegTree(start, end, 2*i+1, l, mid),
                        querySegTree(start, end, 2*i+2, mid+1, r));
    }

    public List<Boolean> getResults(int[][] queries) {
        constructSegmentTree();

        TreeSet<Integer> st = new TreeSet<>();
        st.add(0);

        List<Boolean> result = new ArrayList<>();

        for(int[] query : queries) {
            if(query[0] == 1) {
                int x = query[1];

                Integer nxtVal = st.higher(x);
                int nxt = (nxtVal != null) ? nxtVal : -1;
                int pre = st.lower(x) != null ? st.lower(x) : st.floor(x);

                updateSegTree(x, x - pre, 0, 0, n - 1);
                if(nxt != -1) updateSegTree(nxt, nxt - x, 0, 0, n - 1);

                st.add(x);
            } else {
                int x = query[1];
                int sz = query[2];

                int pre = st.floor(x);

                int maxGap = querySegTree(0, pre, 0, 0, n - 1);
                int best = Math.max(maxGap, x - pre);

                result.add(best >= sz);
            }
        }

        return result;
    }
}
