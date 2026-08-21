/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ONzyN2tE4fU
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/distribute-elements-into-two-arrays-ii/
*/


/**************************************************************** C++ ****************************************************************/
//Approach (Segment Tree)
//T.C : O(nlogn + n log m), m = map.size(), 
//S.C : O(4*m) ~ O(m) for segment tree and O(m) for map as well, so overall ~ O(m)
class SegmentTree {
public : 
    int m;
    vector<int> segTree;

    SegmentTree(int size) {
        m = size;
        segTree.assign(4*m, 0); //initialization with frequency 0
    }

    void segTreeUpdate(int i, int l, int r, int cv) {
        if(l == r) { //==cv
            segTree[i]++; //update frequency
            return;
        }

        int mid = l + (r-l)/2;
        if(cv <= mid) {
            segTreeUpdate(2*i+1, l, mid, cv);
        } else {
            segTreeUpdate(2*i+2, mid+1, r, cv);
        }

        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }

    void update(int cv) {
        //0 = index of root
        //0 = start range
        //m-1 = end range
        //cv = compressed value
        segTreeUpdate(0, 0, m-1, cv);
    }

    int segTreeQueryRangeSum(int start, int end, int i, int l, int r) {
        if(l > end || r < start) { //out of range
            return 0; //no overlap
        }

        if(l >= start && r <= end) { //completely inside range
            return segTree[i]; //return frequency
        }

        int mid = l + (r-l)/2;

        return segTreeQueryRangeSum(start, end, 2*i+1, l, mid) + 
               segTreeQueryRangeSum(start, end, 2*i+2, mid+1, r);

    }

    int query(int start, int end) {
        return segTreeQueryRangeSum(start, end, 0, 0, m-1);
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> sortedNums(begin(nums), end(nums));
        sort(begin(sortedNums), end(sortedNums)); //Sort the array

        unordered_map<int, int> mp; //to store nums[i] --> compressed value
        int compressedValue = 0;

        for(int &num : sortedNums) { //compressed value given to nums
            if(!mp.count(num)) {
                mp[num] = compressedValue;
                compressedValue++;
            }
        }

        int m = mp.size(); //compressed values = 0, 1, ... m-1

        vector<int> arr1;
        vector<int> arr2;

        SegmentTree segTree1(m); //for arr1
        SegmentTree segTree2(m); //for arr2

        //1st operations
        arr1.push_back(nums[0]);
        segTree1.update(mp[nums[0]]);

        //2nd Operation
        arr2.push_back(nums[1]);
        segTree2.update(mp[nums[1]]);

        for(int i = 2; i < n; i++) {
            int cv = mp[nums[i]];
            int c1 = segTree1.query(cv+1, m-1); //number of elements > nums[i] in arr1
            int c2 = segTree2.query(cv+1, m-1); //number of elements > nums[i] in arr2

            bool addToArr1 = false;
            if(c1 > c2) {
                addToArr1 = true;
            } else if(c2 > c1) {
                addToArr1 = false;
            } else { //c1 == c2
                addToArr1 = (arr1.size() <= arr2.size());
            }

            if(addToArr1) {
                arr1.push_back(nums[i]);
                segTree1.update(cv);
            } else {
                arr2.push_back(nums[i]);
                segTree2.update(cv);
            }
        }

        arr1.insert(end(arr1), begin(arr2), end(arr2));

        return arr1;

    }
};



/**************************************************************** JAVA ****************************************************************/
//Approach (Segment Tree)
//T.C : O(nlogn + n log m), m = map.size(), 
//S.C : O(4*m) ~ O(m) for segment tree and O(m) for map as well, so overall ~ O(m)
class SegmentTree {
    int m;
    int[] segTree;

    SegmentTree(int size) {
        m = size;
        segTree = new int[4 * m]; //initialization with frequency 0 (Java zero-inits by default)
    }

    void segTreeUpdate(int i, int l, int r, int cv) {
        if (l == r) { //==cv
            segTree[i]++; //update frequency
            return;
        }
        int mid = l + (r - l) / 2;
        if (cv <= mid) {
            segTreeUpdate(2 * i + 1, l, mid, cv);
        } else {
            segTreeUpdate(2 * i + 2, mid + 1, r, cv);
        }
        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }

    void update(int cv) {
        //0 = index of root
        //0 = start range
        //m-1 = end range
        //cv = compressed value
        segTreeUpdate(0, 0, m - 1, cv);
    }

    int segTreeQueryRangeSum(int start, int end, int i, int l, int r) {
        if (l > end || r < start) { //out of range
            return 0; //no overlap
        }
        if (l >= start && r <= end) { //completely inside range
            return segTree[i]; //return frequency
        }
        int mid = l + (r - l) / 2;
        return segTreeQueryRangeSum(start, end, 2 * i + 1, l, mid) +
               segTreeQueryRangeSum(start, end, 2 * i + 2, mid + 1, r);
    }

    int query(int start, int end) {
        return segTreeQueryRangeSum(start, end, 0, 0, m - 1);
    }
}

class Solution {
    public int[] resultArray(int[] nums) {
        int n = nums.length;
        int[] sortedNums = nums.clone();
        Arrays.sort(sortedNums); //Sort the array
        HashMap<Integer, Integer> mp = new HashMap<>(); //to store nums[i] --> compressed value
        int compressedValue = 0;
        for (int num : sortedNums) { //compressed value given to nums
            if (!mp.containsKey(num)) {
                mp.put(num, compressedValue);
                compressedValue++;
            }
        }
        int m = mp.size(); //compressed values = 0, 1, ... m-1
        List<Integer> arr1 = new ArrayList<>();
        List<Integer> arr2 = new ArrayList<>();
        SegmentTree segTree1 = new SegmentTree(m); //for arr1
        SegmentTree segTree2 = new SegmentTree(m); //for arr2
        //1st operation
        arr1.add(nums[0]);
        segTree1.update(mp.get(nums[0]));
        //2nd Operation
        arr2.add(nums[1]);
        segTree2.update(mp.get(nums[1]));
        
        for (int i = 2; i < n; i++) {
            int cv = mp.get(nums[i]);
            int c1 = segTree1.query(cv + 1, m - 1); //number of elements > nums[i] in arr1
            int c2 = segTree2.query(cv + 1, m - 1); //number of elements > nums[i] in arr2
            boolean addToArr1 = false;
            if (c1 > c2) {
                addToArr1 = true;
            } else if (c2 > c1) {
                addToArr1 = false;
            } else { //c1 == c2
                addToArr1 = (arr1.size() <= arr2.size());
            }
            if (addToArr1) {
                arr1.add(nums[i]);
                segTree1.update(cv);
            } else {
                arr2.add(nums[i]);
                segTree2.update(cv);
            }
        }
        arr1.addAll(arr2);
        //convert List<Integer> to int[]
        int[] result = new int[n];
        for (int i = 0; i < n; i++) {
            result[i] = arr1.get(i);
        }
        return result;
    }
}
