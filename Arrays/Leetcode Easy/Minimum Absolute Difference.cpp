/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=9flIHrF2tuA
    Company Tags                : JIO (for a Flutter developer role)
    Leetcode Link               : https://leetcode.com/problems/minimum-absolute-difference
*/



/*********************************************************** C++ **************************************************/
//Approach (Sort and find and collect)
//T.C : O(nlogn) 
//S.C : O(1)
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(begin(arr), end(arr));
        vector<vector<int>> result;
        int n = arr.size();
        
        int minDiff = INT_MAX;
        for(int i = 1; i < n; i++) {
            int diff = arr[i] - arr[i-1];
            minDiff = min(diff, minDiff);
        }
        
        for(int i = 1; i<n; i++) {
            int diff = arr[i]-arr[i-1];
            
            if(diff == minDiff) {
                result.push_back({arr[i-1], arr[i]});
            }
        }
        
        
        return result;
        
    }
};



/*********************************************************** JAVA **************************************************/
//Approach (Sort and find and collect)
//T.C : O(nlogn) 
//S.C : O(1)
class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        Arrays.sort(arr);

        List<List<Integer>> result = new ArrayList<>();
        int n = arr.length;

        int minDiff = Integer.MAX_VALUE;

        // First pass: find minimum difference
        for (int i = 1; i < n; i++) {
            int diff = arr[i] - arr[i - 1];
            minDiff = Math.min(minDiff, diff);
        }

        // Second pass: collect pairs with min difference
        for (int i = 1; i < n; i++) {
            int diff = arr[i] - arr[i - 1];
            if (diff == minDiff) {
                result.add(Arrays.asList(arr[i - 1], arr[i]));
            }
        }

        return result;
    }
}
