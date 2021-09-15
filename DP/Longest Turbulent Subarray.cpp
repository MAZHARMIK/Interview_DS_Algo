/*
    Company Tags  : Google (With Variations)
    Frequency     : Yet to be known :-(
    Leetcode Link : https://leetcode.com/problems/longest-turbulent-subarray/
*/

//More approaches and explanations to be added soon (Please stay tuned :-) )

//Approach-1 (Using Bottom UP DP)
//Link to a very good explanation to this approach : https://www.youtube.com/watch?v=lcXYW7UEguI
class Solution {
public:
    
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 1;
        
        int maxL = 1;
        vector<vector<int>> t(2, vector<int>(n, 0));
        t[0][0] = 1; //up trend
        t[1][0] = 1; //down trend
        
        for(int i = 1; i<n; i++) {
            if(arr[i] == arr[i-1]) {
                t[0][i] = 1;
                t[1][i] = 1;
            } else if(arr[i] > arr[i-1]) {
                t[0][i] = t[1][i-1]+1;
                t[1][i] = 1;
            } else {
                t[0][i] = 1;
                t[1][i] = t[0][i-1]+1;
            }
            
            maxL = max({maxL, t[0][i], t[1][i]});
        }
        
        return maxL;
    }
};

//Approach-2 (Using two pointers) (I will add the explanation soon)
class Solution {
public:
    bool isValid(vector<int>& arr, int& end) {
        return ((arr[end] > arr[end-1] && arr[end] > arr[end+1]) ||
           (arr[end] < arr[end-1] && arr[end] < arr[end+1]));
    }
    
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 1;
        
        int maxL = 1;
        
        int start = 0;
        while(start < n-1) {
            if(arr[start] == arr[start+1]) {
                start++;
                continue;
            }
            
            int end = start + 1;
            while(end < n-1 && isValid(arr, end)) end++;
            
            maxL = max(maxL, end-start+1);
            start = end;
        }
        
        return maxL;
    }
};
