/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/check-if-n-and-its-double-exist
*/


/************************************************************ C++ ************************************************/
//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && arr[i] == 2*arr[j]) {
                    return true;
                }
            }
        }

        return false;
    }
};


//Approach-2 (Using extra space)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> st;

        for(int i = 0; i < n; i++) {
            if(st.find(arr[i]*2) != st.end()) {
                return true;
            } else if(arr[i]%2 == 0 && st.find(arr[i]/2) != st.end()) {
                return true;
            }
            st.insert(arr[i]);
        }

        return false;
    }
};


//Approach-3 (Using Binary Search)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int bSearch(vector<int>& arr, int target) {
        int l = 0;
        int r = arr.size()-1;

        int mid;
        while(l <= r) {
            mid = l + (r-l)/2;
            if(arr[mid] == target) {
                return mid;
            } else if(arr[mid] > target) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return -1;
    }

    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        sort(begin(arr), end(arr));

        for(int i = 0; i < n; i++) {
            int j = bSearch(arr, 2*arr[i]);

            if(j != -1 && j != i) {
                return true;
            }
        }

        return false;

    }
};



/************************************************************ C++ ************************************************/
//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
    public boolean checkIfExist(int[] arr) {
        int n = arr.length;

        // Iterate over each pair (i, j)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // If i != j and arr[i] is 2 times arr[j]
                if (i != j && arr[i] == 2 * arr[j]) {
                    return true;
                }
            }
        }

        return false;
    }
}


//Approach-2 (Using extra space)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public boolean checkIfExist(int[] arr) {
        int n = arr.length;
        HashSet<Integer> set = new HashSet<>();

        // Traverse the array
        for (int i = 0; i < n; i++) {
            // If 2 * arr[i] is already in the set, return true
            if (set.contains(arr[i] * 2)) {
                return true;
            } 
            // If arr[i] is even and arr[i] / 2 is in the set, return true
            else if (arr[i] % 2 == 0 && set.contains(arr[i] / 2)) {
                return true;
            }
            // Add the current element to the set
            set.add(arr[i]);
        }

        return false;
    }
}


//Approach-3 (Using Binary Search)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
    // Binary search helper function
    public int bSearch(int[] arr, int target) {
        int l = 0;
        int r = arr.length - 1;
        int mid;

        // Binary search logic
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return -1;
    }

    public boolean checkIfExist(int[] arr) {
        int n = arr.length;
        // Sorting the array before applying binary search
        Arrays.sort(arr);

        // Iterate over each element in the array
        for (int i = 0; i < n; i++) {
            // Perform binary search for 2 * arr[i]
            int j = bSearch(arr, 2 * arr[i]);

            // If the element is found and it's not the same index, return true
            if (j != -1 && j != i) {
                return true;
            }
        }

        return false;
    }
}
