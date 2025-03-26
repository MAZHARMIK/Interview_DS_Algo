/*     Scroll below to see JAVA code    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid
*/


/****************************************************** C++ **************************************************************/
//Approach (Using Median and Maths)
//T.C : O(m*nlog(m*n))
//S.C : O(m*n)
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> vec;
        //O(m*n)
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                vec.push_back(grid[i][j]);
            }
        }

        int L = vec.size(); //m*n

        //sort(begin(vec), end(vec)); //O(LlogL)
        nth_element(begin(vec), begin(vec) + L/2, end(vec)); //O(L)
        //{4, 2, 8, 6}
        //{4, 2, 6, 8} - nth_element
        //{2, 4, 6, 8} - complete sorting

        int target = vec[L/2];
        int result = 0;
        for(int &num : vec) { //O(m*n)
            if(num%x != target%x) {
                return -1;
            }

            result += abs(target-num)/x;
        }

        return result;
    }
};


/****************************************************** JAVA ****************************************************************/
//Approach (Using Median and Maths)
//T.C : O(m*nlog(m*n))
//S.C : O(m*n)
class Solution {
    public int minOperations(int[][] grid, int x) {
        int m = grid.length;
        int n = grid[0].length;
        
        List<Integer> vec = new ArrayList<>();
        
        // Flatten the grid into a list
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vec.add(grid[i][j]);
            }
        }
        
        int L = vec.size();
        
        // Find the median using sorting (alternative to nth_element in C++)
        Collections.sort(vec);
        int target = vec.get(L / 2);
        
        int result = 0;
        for (int num : vec) {
            if (num % x != target % x) {
                return -1;
            }
            result += Math.abs(target - num) / x;
        }
        
        return result;
    }
}
