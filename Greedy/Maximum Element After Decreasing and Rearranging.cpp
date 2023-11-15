/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=HGkK9n5CUaY
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/
*/

/******************************************************************** C++ ********************************************************************/
//Apprpach-1 (Simply doing like asked in the Qn)
//T.C : O(nlogn)
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(begin(arr), end(arr));

        int n = arr.size();
        int maxEl = 1;

        for(int i = 0; i < n; i++) {

            if(i == 0) {
                arr[i] = 1;
            } else if(arr[i] - arr[i-1] > 1) {
                arr[i] = arr[i-1] + 1;
            }

            maxEl = max(maxEl, arr[i]);
        }

        return maxEl;

    }
};


/******************************************************************** JAVA ********************************************************************/
//Apprpach-1 (Simply doing like asked in the Qn)
//T.C : O(nlogn)
public class Solution {
    public int maximumElementAfterDecrementingAndRearranging(int[] arr) {
        Arrays.sort(arr);

        int n = arr.length;
        int maxEl = 1;

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                arr[i] = 1;
            } else if (arr[i] - arr[i - 1] > 1) {
                arr[i] = arr[i - 1] + 1;
            }

            maxEl = Math.max(maxEl, arr[i]);
        }

        return maxEl;
    }
}
