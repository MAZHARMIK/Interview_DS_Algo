/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=jC0wWjBrKss
    Company Tags                : Adobe, Amazon
    Leetcode Link               : https://leetcode.com/problems/pascals-triangle/
*/

/*************************************************** C++ ********************************************************/
//Approach-1 (Doing simply just like Pascal triangle is formed)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        
        for(int i = 0; i<numRows; i++) {
            
            result[i] = vector<int>(i+1, 1);
            
            for(int j = 1; j < i; j++) {
                
                result[i][j] = result[i-1][j] + result[i-1][j-1];
                
            }
            
        }
        
        return result;
    }
};

//Approach-2 (Using simple math formula)
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


/*************************************************** JAVA ********************************************************/
//Approach-1 (Doing simply just like Pascal triangle is formed)
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<>();
        
        for(int i = 0; i<numRows; i++) {
            List<Integer> row = new ArrayList<>(i+1);
            for(int j = 0; j <= i; j++) {
                if(j == 0 || j == i) {
                    row.add(1);
                } else {
                    int num = result.get(i-1).get(j) + result.get(i-1).get(j-1);
                    row.add(num);
                }
            }
            result.add(row);
        }
        return result;
    }
}
