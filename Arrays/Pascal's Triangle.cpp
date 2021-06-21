/*
    Company Tags  : Adobe, Amazon
    Leetcode Link : https://leetcode.com/problems/pascals-triangle/
*/

//Approach-1 (Using simple math formula)
class Solution {
public:
    vector<int> getRow(int line) {
        int prev = 1;
        vector<int> temp{1};
        for(int i = 1; i<line+1; i++) {
            int curr = ((line-i+1) * prev)/i;
            temp.push_back(curr);
            prev = curr;
        }
        return temp;
    }
    
    vector<vector<int>> generate(int line) {
        vector<vector<int>> result;
        result.push_back({1});
        if(line == 1) {
            return result;
        }
        
        for(int lineNo = 1; lineNo < line; lineNo++) {
            result.push_back(getRow(lineNo));
        }
        
        return result;
    }
};

//Approach-2 (Using DP)
class Solution {
public:
    vector<vector<int>> generate(int line) {
        vector<vector<int>> result;
        
        result.push_back({1});
        
        for(int i = 2; i<=line; i++) {
            vector<int> curr(i);
            vector<int> prev = result[i-2];
            
            curr[0] = 1;
            for(int j = 0; j<prev.size()-1; j++) {
                curr[j+1] = prev[j] + prev[j+1];
            }
            curr[i-1] = 1;
            
            result.push_back(curr);
        }
        
        return result;
    }
};
