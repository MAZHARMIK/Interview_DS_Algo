/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=hlQGUgvkYXQ
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/decode-the-slanted-ciphertext
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Simple simulation with extra space)
//T.C : O(l), l = encodedText.length()
//S.C : O(l), all characters of encodedText in matrix
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int l       = encodedText.size();
        int columns = l / rows;

        string originalText;
        for (int col = 0; col < columns; col++) {
            for (int j = col; j < l; j += (columns + 1)) {
                originalText += encodedText[j];
            }
        }

        //Remove spaces put at the end
        while (!originalText.empty() && originalText.back() == ' ') {
            originalText.pop_back();
        }
        
        return originalText;
    }
};



class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 1) 
            return encodedText;

        int l       = encodedText.size();
        int columns = l / rows;

        string originalText = "";

        //Create matrix
        vector<vector<char>> mat(rows, vector<char>(columns));

        int idx = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                mat[i][j] = encodedText[idx++];
            }
        }

        //Read diagonally
        for (int col = 0; col < columns; col++) {
            int i = 0;
            int j = col;

            while (i < rows && j < columns) {
                originalText += mat[i][j];
                i++;
                j++;
            }
        }

        // Step 3: Remove trailing spaces
        while (!originalText.empty() && originalText.back() == ' ') {
            originalText.pop_back();
        }

        return originalText;

    }
};



//Approach-2 (Without extra space)
//T.C : O(l), l = encodedText.length()
//S.C : O(1)
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int l = encodedText.length();

        int columns = l / rows;

        string originalText;
        for(int col = 0; col < columns; col++) {
            for(int j = col; j < l; j += (columns+1)) {
                originalText += encodedText[j];
            }
        }

        while(!originalText.empty() && originalText.back() == ' ') {
            originalText.pop_back();
        }

        return originalText;
    }
};



/**************************************************************** JAVA ****************************************************************/
//Approach-1 (Simple simulation with extra space)
//T.C : O(l), l = encodedText.length()
//S.C : O(l), all characters of encodedText in matrix
// T.C : O(l)
// S.C : O(l)
class Solution {
    public String decodeCiphertext(String encodedText, int rows) {
        if (rows == 1) return encodedText;

        int l = encodedText.length();
        int columns = l / rows;

        char[][] mat = new char[rows][columns];

        int idx = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                mat[i][j] = encodedText.charAt(idx++);
            }
        }

        StringBuilder originalText = new StringBuilder();

        // Read diagonally
        for (int col = 0; col < columns; col++) {
            int i = 0, j = col;

            while (i < rows && j < columns) {
                originalText.append(mat[i][j]);
                i++;
                j++;
            }
        }

        // Remove trailing spaces
        while (originalText.length() > 0 && 
               originalText.charAt(originalText.length() - 1) == ' ') {
            originalText.deleteCharAt(originalText.length() - 1);
        }

        return originalText.toString();
    }
}


//Approach-2 (Without extra space)
//T.C : O(l), l = encodedText.length()
//S.C : O(1)
// T.C : O(l)
// S.C : O(1)
class Solution {
    public String decodeCiphertext(String encodedText, int rows) {
        int l = encodedText.length();
        int columns = l / rows;

        StringBuilder originalText = new StringBuilder();

        for (int col = 0; col < columns; col++) {
            for (int j = col; j < l; j += (columns + 1)) {
                originalText.append(encodedText.charAt(j));
            }
        }

        // Remove trailing spaces
        while (originalText.length() > 0 && 
               originalText.charAt(originalText.length() - 1) == ' ') {
            originalText.deleteCharAt(originalText.length() - 1);
        }

        return originalText.toString();
    }
}
