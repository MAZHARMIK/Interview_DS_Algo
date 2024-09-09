/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=h-3aM0bEUZ8
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/spiral-matrix-iv/description
*/

/************************************************ C++ ************************************************/
//Simple SImulation
//T.C : O(m*n)
//S.C : O(1) (I am not considering the result matrix we have to return as result)
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));

        int id    = 0; //0, 1, 2, 3
        int top   = 0;
        int down  = m-1;
        int left  = 0;
        int right = n-1;

        while(top <= down && left <= right) {
            if(id == 0) { //left to right
                for(int i = left; head != NULL && i <= right; i++) {
                    matrix[top][i] = head->val;
                    head = head->next;
                }
                top++;
            }

            if(id == 1) { //top to down
                for(int i = top; head != NULL && i <= down; i++) {
                    matrix[i][right] = head->val;
                    head = head->next;
                }
                right--;
            }

            if(id == 2) { //right to left
                for(int i = right; head != NULL && i >= left; i--) {
                    matrix[down][i] = head->val;
                    head = head->next;
                }
                down--;
            }

            if(id == 3) { //down to top
                for(int i = down; head != NULL && i >= top; i--) {
                    matrix[i][left] = head->val;
                    head = head->next;
                }
                left++;
            }

            id = (id+1)%4; //0, 1, 2, 3
        }

        return matrix;
    }
};


/************************************************ JAVA ************************************************/
//Simple SImulation
//T.C : O(m*n)
//S.C : O(1) (I am not considering the result matrix we have to return as result)
class Solution {
    public int[][] spiralMatrix(int m, int n, ListNode head) {
        int[][] matrix = new int[m][n];
        
        // Initialize the matrix with -1
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = -1;
            }
        }

        int top = 0;
        int down = m - 1;
        int left = 0;
        int right = n - 1;
        int id = 0; // Direction identifier (0: left->right, 1: top->down, 2: right->left, 3: down->top)

        while (top <= down && left <= right && head != null) {
            if (id == 0) { // left to right
                for (int i = left; i <= right && head != null; i++) {
                    matrix[top][i] = head.val;
                    head = head.next;
                }
                top++;
            } 
            else if (id == 1) { // top to down
                for (int i = top; i <= down && head != null; i++) {
                    matrix[i][right] = head.val;
                    head = head.next;
                }
                right--;
            } 
            else if (id == 2) { // right to left
                for (int i = right; i >= left && head != null; i--) {
                    matrix[down][i] = head.val;
                    head = head.next;
                }
                down--;
            } 
            else if (id == 3) { // down to top
                for (int i = down; i >= top && head != null; i--) {
                    matrix[i][left] = head.val;
                    head = head.next;
                }
                left++;
            }

            id = (id + 1) % 4; // Cycle through directions
        }

        return matrix;
    }
}
