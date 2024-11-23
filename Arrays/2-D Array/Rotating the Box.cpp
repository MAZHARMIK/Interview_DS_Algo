/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/rotating-the-box/description
*/


/******************************************** C++ ********************************************/
//Approach-1 (Brute Force)
//T.C : O(col * row * row)
//S.C : O(1) - Not considering the space of result
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        vector<vector<char>> result(n, vector<char>(m));

        //Transpose
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                result[i][j] = box[j][i];
            }
        }

        //90 degree k lie - Reverse kardo ahr row ko
        for(vector<char>& row : result) {
            reverse(begin(row), end(row));
        }

        //Apply the gravity
        for(int j = 0; j < m; j++) {
            for(int i = n-1; i >= 0; i--) {
                if(result[i][j] == '.') { //if it is a space
                    int stoneRow = -1;

                    for(int k = i-1; k >= 0; k--) {
                        if(result[k][j] == '*') {
                            break;
                        } else if(result[k][j] == '#') {
                            stoneRow = k;
                            break;
                        }
                    }

                    if(stoneRow != -1) {
                        result[i][j] = '#';
                        result[stoneRow][j] = '.';
                    }
                }
            }
        }

        return result;
    }
};


//Approach-2 (Optimized)
//T.C : O(col * row)
//S.C : O(1) - Not considering the space of result
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        vector<vector<char>> result(n, vector<char>(m));

        //Transpose
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                result[i][j] = box[j][i];
            }
        }

        //90 degree k lie - Reverse kardo ahr row ko
        for(vector<char>& row : result) {
            reverse(begin(row), end(row));
        }


        //Apply the gravity
        //O(col * row)
        for(int j = 0; j < m; j++) {
            int spaceBottomRow = n-1;
            for(int i = n-1; i >= 0; i--) {
                if(result[i][j] == '*') {
                    spaceBottomRow = i-1;
                    continue;
                }

                if(result[i][j] == '#') {
                    result[i][j] = '.';
                    result[spaceBottomRow][j] = '#';
                    spaceBottomRow--;
                }
            }
        }

        return result;
    }
};



/******************************************** C++ ********************************************/
//Approach-1 (Brute Force)
//T.C : O(col * row * row)
//S.C : O(1) - Not considering the space of result
class Solution {
    public char[][] rotateTheBox(char[][] box) {
        int m = box.length;
        int n = box[0].length;

        // Create a new result array with dimensions swapped
        char[][] result = new char[n][m];

        // Transpose the box
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[i][j] = box[j][i];
            }
        }

        // Reverse each row to achieve a 90-degree rotation
        for (int i = 0; i < n; i++) {
            reverseRow(result[i]);
        }

        // Apply gravity
        for (int j = 0; j < m; j++) {
            for (int i = n - 1; i >= 0; i--) {
                if (result[i][j] == '.') { // If it's a space
                    int stoneRow = -1;

                    // Look for the nearest stone above
                    for (int k = i - 1; k >= 0; k--) {
                        if (result[k][j] == '*') {
                            break; // Stop at an obstacle
                        } else if (result[k][j] == '#') {
                            stoneRow = k;
                            break;
                        }
                    }

                    if (stoneRow != -1) {
                        result[i][j] = '#';
                        result[stoneRow][j] = '.';
                    }
                }
            }
        }

        return result;
    }

    // Helper method to reverse a row
    private void reverseRow(char[] row) {
        int left = 0, right = row.length - 1;
        while (left < right) {
            char temp = row[left];
            row[left] = row[right];
            row[right] = temp;
            left++;
            right--;
        }
    }
}


//Approach-2 (Optimized)
//T.C : O(col * row)
//S.C : O(1) - Not considering the space of result
class Solution {
    public char[][] rotateTheBox(char[][] box) {
        int m = box.length;
        int n = box[0].length;

        // Create a new result array with dimensions swapped
        char[][] result = new char[n][m];

        // Transpose the box
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[i][j] = box[j][i];
            }
        }

        // Reverse each row to achieve a 90-degree rotation
        for (int i = 0; i < n; i++) {
            reverseRow(result[i]);
        }

        // Apply gravity
        // O(columns * rows)
        for (int j = 0; j < m; j++) {
            int spaceBottomRow = n - 1;
            for (int i = n - 1; i >= 0; i--) {
                if (result[i][j] == '*') {
                    spaceBottomRow = i - 1;
                    continue;
                }

                if (result[i][j] == '#') {
                    result[i][j] = '.';
                    result[spaceBottomRow][j] = '#';
                    spaceBottomRow--;
                }
            }
        }

        return result;
    }

    // Helper method to reverse a row
    private void reverseRow(char[] row) {
        int left = 0, right = row.length - 1;
        while (left < right) {
            char temp = row[left];
            row[left] = row[right];
            row[right] = temp;
            left++;
            right--;
        }
    }
}
