/*
    Company Tags  : Not known yet. It's an amazing question and one must know about such concepts and approaches
    Leetcode Link : https://leetcode.com/problems/three-equal-parts/
*/

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n = arr.size();
        int sum = accumulate(begin(arr), end(arr), 0);
        
        if(sum == 0)
            return {0, n-1};
        else if(sum%3 != 0)
            return {-1, -1};
        
        int k = sum/3;
        //So every partition must have k 1's
        //So let's find three partitions having k 1's and compare them bit by bit
        
        int start = -1, mid = -1, end = -1;
        int count = 0;

        //[1,  1,  1,  0,  0,  1,  1,  0,  1,  0,  1,  1,  1,  1,  1,  1]
        for(int i = 0; i<n; i++) {
            if(arr[i] == 0) continue;
            
            count += arr[i];
            if(count > k) {
                count = 1;
            }
            
            if(count == 1) {
                if(start == -1) start = i;
                else if(mid == -1) mid = i;
                else if(end == -1) end = i;
                else break;
            }
        }
        
        /*
            we have found three sections and we have pointers to starting '1' of
            each section.
            we now compare them bit by bit
        */
        
        while(end < n && arr[start] == arr[mid] && arr[mid] == arr[end]) {
            start++;  mid++;   end++;
        }
        
        //It means we couldn't match all sections
        if(end != n)  return {-1, -1};
        
        return {start-1, mid};
    }
};
