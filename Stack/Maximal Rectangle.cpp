/*        Scroll below to see JAVA code also        */
/*
    Company Tags  : Amazon, Directi, Intuit, MakeMyTrip, Microsoft, Samsung
    Leetcode Link : https://leetcode.com/problems/maximal-rectangle/
*/

/***************************************************** C++ ****************************************************/
//Approach-1 (using NSL and NSR to find MAH (Maximum Area in Histogram)
//T.C : O(row*(col+col)) ~= O(row*col)
//S.C : O(col)
class Solution {
public:
    vector<int> NSR(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int pseudo_index = n;
        vector<int> right(n);
        for(int i = n-1; i>=0; i--) {
            if(st.empty()) {
                right[i] = pseudo_index;
            } else {
                while(!st.empty() && heights[st.top()] >= heights[i])
                    st.pop();
                if(st.empty())
                    right[i] = pseudo_index;
                else
                    right[i] = st.top();
            }
            st.push(i);
        }
        return right;
    }
    vector<int> NSL(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int pseudo_index = -1;
        vector<int> left(n);
        for(int i = 0; i<n; i++) {
            if(st.empty()) {
                left[i] = pseudo_index;
            } else {
                while(!st.empty() && heights[st.top()] >= heights[i])
                    st.pop();
                if(st.empty())
                    left[i] = pseudo_index;
                else
                    left[i] = st.top();
            }
            st.push(i);
        }
        return left;
    }
    
    int MAH(vector<int>& heights) {
        int n = heights.size();
        vector<int> right = NSR(heights);
        vector<int> left  = NSL(heights);
        vector<int> width(n);
        for(int i = 0; i<n; i++)
            width[i] = right[i]-left[i]-1;
        int max_area = 0;
        
        for(int i = 0; i<n; i++) {
            int a =  width[i]*heights[i];
            if(max_area < a)
                max_area = a; 
        }
        return max_area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> height(m);
        for(int i = 0; i<m; i++) {
            height[i] = (matrix[0][i]=='1')?1:0;
        }
        int maxA = MAH(height);
        for(int i = 1; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(matrix[i][j] == '0')
                    height[j] = 0;
                else
                    height[j] += 1;
            }
            maxA = max(maxA, MAH(height));
        }
        return maxA;
    }
};

//Approach-2 (Simplified MAH)
class Solution {
public:
    //SImplified
    int MAH(vector<int>& heights, int& n) {
        stack<int> st;
        int i = 0;
        int maxArea = 0;
        int area = 0;
        while(i < n) {
            if(st.empty() || heights[i] >= heights[st.top()]) {
                st.push(i++);
            } else {
                int index = st.top();
                st.pop();
                
                if(st.empty()) {
                    area = heights[index] * i;
                } else {
                    area = heights[index] * (i - st.top() - 1);
                }
                
                maxArea = max(maxArea, area);
            }
        }
        
        while(!st.empty()) {
            int index = st.top();
            st.pop();

            if(st.empty()) {
                area = heights[index] * i;
            } else {
                area = heights[index] * (i - st.top() - 1);
            }

            maxArea = max(maxArea, area);
        }
        
        return maxArea;
        
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        
        int maxArea = 0;
        int m       = matrix.size();
        int n       = matrix[0].size();
        
        /*
        [1, 0, 1, 0, 0]
        [1, 0, 1, 1, 1] =>  [2, 0, 2, 1, 1]
        [1, 1, 1, 1, 1] =>  [3, 1, 3, 2, 2]
        [1, 0, 0, 1, 0] ->  [3, 0, 0, 3, 0]
        */
        
        vector<int> heights(n, 0);
        for(int col = 0; col < n; col++) {
            heights[col] = matrix[0][col] == '0' ? 0 : 1;
        }
        
        maxArea = MAH(heights, n);
        
        for(int row = 1; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(matrix[row][col] == '0') {
                    heights[col] = 0;
                } else {
                    heights[col] += 1;
                }
            }
            
            maxArea = max(maxArea, MAH(heights, n));
        }
        
        return maxArea;
    }
};


/***************************************************** JAVA ****************************************************/
//Approach-1 (using NSL and NSR to find MAH (Maximum Area in Histogram)
//T.C : O(row*(col+col)) ~= O(row*col)
//S.C : O(col)
class Solution {
    public int[] NSR(int[] heights) {
        Stack<Integer> st = new Stack<>();
        int n = heights.length;
        int pseudo_index = n;
        int[] right = new int[n];
        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                right[i] = pseudo_index;
            } else {
                while (!st.empty() && heights[st.peek()] >= heights[i])
                    st.pop();
                if (st.empty())
                    right[i] = pseudo_index;
                else
                    right[i] = st.peek();
            }
            st.push(i);
        }
        return right;
    }

    public int[] NSL(int[] heights) {
        Stack<Integer> st = new Stack<>();
        int n = heights.length;
        int pseudo_index = -1;
        int[] left = new int[n];
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                left[i] = pseudo_index;
            } else {
                while (!st.empty() && heights[st.peek()] >= heights[i])
                    st.pop();
                if (st.empty())
                    left[i] = pseudo_index;
                else
                    left[i] = st.peek();
            }
            st.push(i);
        }
        return left;
    }

    public int MAH(int[] heights) {
        int n = heights.length;
        int[] right = NSR(heights);
        int[] left = NSL(heights);
        int[] width = new int[n];
        for (int i = 0; i < n; i++)
            width[i] = right[i] - left[i] - 1;
        int max_area = 0;

        for (int i = 0; i < n; i++) {
            int a = width[i] * heights[i];
            if (max_area < a)
                max_area = a;
        }
        return max_area;
    }

    public int maximalRectangle(char[][] matrix) {
        if (matrix.length == 0)
            return 0;
        int n = matrix.length;
        int m = matrix[0].length;
        int[] height = new int[m];
        for (int i = 0; i < m; i++) {
            height[i] = (matrix[0][i] == '1') ? 1 : 0;
        }
        int maxA = MAH(height);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0')
                    height[j] = 0;
                else
                    height[j] += 1;
            }
            maxA = Math.max(maxA, MAH(height));
        }
        return maxA;
    }
}



//Approach-2 (Simplified MAH)
class Solution {
    public int MAH(int[] heights, int n) {
        Stack<Integer> st = new Stack<>();
        int i = 0;
        int maxArea = 0;
        int area = 0;
        while (i < n) {
            if (st.isEmpty() || heights[i] >= heights[st.peek()]) {
                st.push(i++);
            } else {
                int index = st.pop();

                if (st.isEmpty()) {
                    area = heights[index] * i;
                } else {
                    area = heights[index] * (i - st.peek() - 1);
                }

                maxArea = Math.max(maxArea, area);
            }
        }

        while (!st.isEmpty()) {
            int index = st.pop();

            if (st.isEmpty()) {
                area = heights[index] * i;
            } else {
                area = heights[index] * (i - st.peek() - 1);
            }

            maxArea = Math.max(maxArea, area);
        }

        return maxArea;

    }

    public int maximalRectangle(char[][] matrix) {
        if (matrix.length == 0)
            return 0;

        int maxArea = 0;
        int m = matrix.length;
        int n = matrix[0].length;

        int[] heights = new int[n];
        for (int col = 0; col < n; col++) {
            heights[col] = matrix[0][col] == '0' ? 0 : 1;
        }

        maxArea = MAH(heights, n);

        for (int row = 1; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (matrix[row][col] == '0') {
                    heights[col] = 0;
                } else {
                    heights[col] += 1;
                }
            }

            maxArea = Math.max(maxArea, MAH(heights, n));
        }

        return maxArea;
    }
}
