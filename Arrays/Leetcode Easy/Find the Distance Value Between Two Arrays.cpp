/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=OPMqFO5uOrM
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/find-the-distance-value-between-two-arrays
*/

/*********************************************************** C++ **************************************************/
//Approach-1 (Brute Force)
//T.C : O(m*n)
//S.C : O(1)
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;

        for (int& num1 : arr1) {
            bool valid = true;

            for (int& num2 : arr2) {
                if(abs(num1 - num2) <= d) {
                    valid = false;
                    break;
                }
            }
            
            count += valid; //False = 0, True = 1
        }

        return count;
    }
};



//Approach-2 (Binary Search - lower_bound)
//T.C : O(mlogn)
//S.C : O(1)
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(begin(arr2), end(arr2));

        int count = 0;

        int n = arr2.size();

        for(int i = 0; i < arr1.size(); i++) {
            int j = lower_bound(begin(arr2), end(arr2), arr1[i]) - begin(arr2);

            if(j == 0) { //all elements are greater or equal to arr1[i]
                count += (arr2[0] - arr1[i]) > d;
            } else if(j >= n) { //all elements are smaller than arr1[i]
                count += (arr1[i] - arr2[n-1]) > d;
            } else {
                count += (arr2[j] - arr1[i] > d) && (arr1[i] - arr2[j-1] > d);
            }
        }

        return count;
    }
};



/*********************************************************** JAVA **************************************************/
//Approach-1 (Brute Force)
//T.C : O(m*n)
//S.C : O(1)
class Solution {
    public int findTheDistanceValue(int[] arr1, int[] arr2, int d) {
        int count = 0;

        for (int num1 : arr1) {
            boolean valid = true;

            for (int num2 : arr2) {
                if (Math.abs(num1 - num2) <= d) {
                    valid = false;
                    break;
                }
            }

            if (valid) count++;
        }

        return count;
    }
}


//Approach-2 (Binary Search - lower_bound)
//T.C : O(mlogn)
//S.C : O(1)
class Solution {
    public int findTheDistanceValue(int[] arr1, int[] arr2, int d) {
        Arrays.sort(arr2);

        int count = 0;
        int n = arr2.length;

        for (int i = 0; i < arr1.length; i++) {
            int j = lowerBound(arr2, arr1[i]);

            if (j == 0) { //all elements are greater or equal to arr1[i]
                if (arr2[0] - arr1[i] > d) count++;
            } else if (j >= n) { //all elements are smaller than arr1[i]
                if (arr1[i] - arr2[n - 1] > d) count++;
            } else {
                if (arr2[j] - arr1[i] > d && arr1[i] - arr2[j - 1] > d) count++;
            }
        }

        return count;
    }

    // first index with arr[idx] >= target (n if none)
    private int lowerBound(int[] arr, int target) {
        int low = 0, high = arr.length;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
}
