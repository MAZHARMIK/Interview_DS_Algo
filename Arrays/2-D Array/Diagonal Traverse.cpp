/*         Scroll below to see JAVA code as well        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://youtu.be/7HAKiGZSrWc
    Company Tags  : Google, Amazon
    Leetcode Link : https://leetcode.com/problems/diagonal-traverse/
*/

/*
    Note : If you want to travel diaginally from right side, you can use the key map as (i-j) instead of (i+j)
    Related Qn : https://leetcode.com/problems/sort-the-matrix-diagonally/
    Youtube Link : https://www.youtube.com/watch?v=mNWwJQ7_z4Q
*/


/****************************************************************** C++ ******************************************************************/
//T.C : O(m*n * log(m+n)), log because we are using ordered_map
//S.C : O(m*n)
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        map<int, vector<int>> mp;
        
        vector<int> result;
        
        //fill the map using [i+j]
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                mp[i+j].push_back(mat[i][j]);
            }
        }
        
        bool flip = true;
        for(auto &it : mp) {
            if(flip) {
                //it.second ko reverse kardo
                reverse(it.second.begin(), it.second.end());
            }
            
            for(int &num : it.second) {
                result.push_back(num);
            }
            
            flip = !flip;
        }
        
        return result;
    }
};


/****************************************************************** JAVA ******************************************************************/
//T.C : O(m*n * log(m+n)), log because we are using ordered_map
//S.C : O(m*n)
class Solution {
    public int[] findDiagonalOrder(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        
        // Use HashMap to store diagonals
        Map<Integer, List<Integer>> map = new HashMap<>();
        
        // Fill the map with diagonals
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int key = i + j;
                map.putIfAbsent(key, new ArrayList<>());
                map.get(key).add(mat[i][j]);
            }
        }
        
        List<Integer> resultList = new ArrayList<>();
        boolean flip = true;
        
        // Process diagonals in increasing order of keys
        for (int k = 0; k <= m + n - 2; k++) {
            List<Integer> diagonal = map.get(k);
            if (diagonal == null) continue;
            
            if (flip) {
                Collections.reverse(diagonal);
            }
            resultList.addAll(diagonal);
            
            flip = !flip;
        }
        
        // Convert result list to array
        int[] result = new int[resultList.size()];
        for (int i = 0; i < resultList.size(); i++) {
            result[i] = resultList.get(i);
        }
        
        return result;
    }
}
