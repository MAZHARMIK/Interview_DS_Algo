/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted
*/


/************************************************************ C++ ************************************************/
//Approach (simple two pointer approach)
//T.C : O(n) - We don't visit any element once inside the while loop
//S.C : O(1)
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();

        //step-1 - Find the jth pointer from right side
        int j = n-1;
        while(j > 0 && arr[j] >= arr[j-1]) {
            j--;
        }

        int i = 0;
        int result = j; //we are removing all elements left to index j  becasue index j to n-1 are sorted
        
        //step-2 start finding correct i and j and find deleted elements = j - i - 1
        while(i < j && (i == 0 || arr[i] >= arr[i-1])) { //increasing ordere of elements from i

            //arr[j] < arr[i]
            while(j < n && arr[i] > arr[j]) {
                j++;
            }

            //we have found correct jth element such that arr[i] <= arr[j]
            result = min(result, j - i - 1);
            i++;
        }

        return result;

    }
};


/************************************************************ JAVA ************************************************/
//Approach (simple two pointer approach)
//T.C : O(n) - We don't visit any element once inside the while loop
//S.C : O(1)
class Solution {
    public int findLengthOfShortestSubarray(int[] arr) {
        int n = arr.length;

        // Step 1 - Find the jth pointer from the right side
        int j = n - 1;
        while (j > 0 && arr[j] >= arr[j - 1]) {
            j--;
        }

        // If the array is already sorted, no need to remove any subarray
        if (j == 0) return 0;

        int i = 0;
        int result = j; // removing all elements to the left of index j, as elements from j to n-1 are sorted

        // Step 2 - Start finding the correct i and j, and calculate the number of elements to delete
        while (i < j && (i == 0 || arr[i] >= arr[i - 1])) { // elements in increasing order from i

            // Move j to find the correct position such that arr[i] <= arr[j]
            while (j < n && arr[i] > arr[j]) {
                j++;
            }

            // We have found the correct jth element such that arr[i] <= arr[j]
            result = Math.min(result, j - i - 1);
            i++;
        }

        return result;
    }
}
