/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ocGDVKYJKVo
      Company Tags                : AMAZON
      Leetcode Link               : https://leetcode.com/problems/pascals-triangle-ii/
*/

/*
  Watch my Pascal's Triangle - I video - https://www.youtube.com/watch?v=jC0wWjBrKss
*/

/********************************************* C++ *********************************************/

//Approach-1 (Using the same code of Pascal's Triangle-I
//T.C : O(rowIndex * rowIndex)
//S.C : O(rowIndex * rowIndex)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> result(rowIndex+1);
        
        for(int i = 0; i<rowIndex+1; i++) {
            
            result[i] = vector<int>(i+1, 1);
            
            for(int j = 1; j < i; j++) {
                
                result[i][j] = result[i-1][j] + result[i-1][j-1];
                
            }
            
            if(i == rowIndex) //Just return when you find rowIndex
                return result[i];
            
        }
        
        return {};
    }
};


//Approach-2 (Using less space from Approach-1 above)
//We only need prev array to find current result
//T.C : O(rowIndex * rowIndex)
//S.C : less than O(rowIndex * rowIndex)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev;
        
        for(int i = 0; i<rowIndex+1; i++) {
            
            vector<int> curr = vector<int>(i+1, 1);
            
            for(int j = 1; j < i; j++) {
                
                curr[j] = prev[j] + prev[j-1];
                
            }
            prev = curr;
        }
        
        return prev;
    }
};


/********************************************* JAVA *********************************************/
//Approach-1 (Using the same code of Pascal's Triangle-I
//T.C : O(rowIndex * rowIndex)
//S.C : O(rowIndex * rowIndex)
class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<List<Integer>> result = new ArrayList<>();
        
        for (int i = 0; i < rowIndex + 1; i++) {
            List<Integer> row = new ArrayList<>();
            
            for (int j = 0; j < i + 1; j++) {
                if (j == 0 || j == i) {
                    row.add(1);
                } else {
                    row.add(result.get(i - 1).get(j - 1) + result.get(i - 1).get(j));
                }
            }
            
            result.add(row);
        }
        
        return result.get(rowIndex);
    }
}


//Approach-2 (Using less space from Approach-1 above)
//We only need prev array to find current result
//T.C : O(rowIndex * rowIndex)
//S.C : less than O(rowIndex * rowIndex)
class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> prev = new ArrayList<>();
        
        for (int i = 0; i < rowIndex + 1; i++) {
            List<Integer> curr = new ArrayList<>();
            for (int j = 0; j < i + 1; j++) {
                if (j == 0 || j == i) {
                    curr.add(1);
                } else {
                    curr.add(prev.get(j) + prev.get(j - 1));
                }
            }
            prev = curr;
        }
        
        return prev;
    }
}
