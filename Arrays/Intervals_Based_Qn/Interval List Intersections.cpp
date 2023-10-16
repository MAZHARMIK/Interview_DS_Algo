/*
    MY YOUTUBE VIDEO ON THIS Qn : Sooooooon
    Company Tags                : Amazon, Meta, Microsoft
    Leetcode Link               : https://leetcode.com/problems/interval-list-intersections/
*/

class Solution {
public:
    typedef vector<int> V;
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int m = firstList.size();
        int n = secondList.size();
        vector<V> result;
        int i = 0, j = 0;
        
        while(i < m && j < n) {
            
            int x = max(firstList[i][0], secondList[j][0]);
            int y = min(firstList[i][1], secondList[j][1]);
            if(x <= y)
                result.push_back({x, y}); //Add only when the interval is valid (increasing)
            
            if(firstList[i][1] > secondList[j][1])
                j++;
            else
                i++;
        }
        
        return result;
    }
};
