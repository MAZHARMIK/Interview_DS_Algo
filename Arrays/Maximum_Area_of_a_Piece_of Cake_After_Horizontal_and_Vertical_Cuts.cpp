/*
    Company Tags  : Amazon
    Leetcode Link : https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
*/

typedef unsigned long long ull;
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int maxh = 0;
        int maxw = 0;
        
        sort(begin(horizontalCuts), end(horizontalCuts));
        int m = horizontalCuts.size();
        int n = verticalCuts.size();
        sort(begin(verticalCuts), end(verticalCuts));
        
        int prev = 0;
        for(int i = 0; i<m; i++) {
            maxh = max(maxh, (horizontalCuts[i] - prev));
            prev = horizontalCuts[i];
        }
        
        maxh = max(maxh, (h-horizontalCuts[m-1]));
        
        prev = 0;
        for(int i = 0; i<n; i++) {
            maxw = max(maxw, (verticalCuts[i] - prev));
            prev = verticalCuts[i];
        }
        
        maxw = max(maxw, (w-verticalCuts[n-1]));
        
        int M = 1e9+7;
        return ((ull)maxh%M*(ull)maxw%M)%M;
    }
};
