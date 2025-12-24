/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=_lC3Wb5di2s
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/shifting-letters-ii
*/


/************************************************************ C++ ************************************************/
//Approach (Using Difference Array Technique)
//T.C : O(m+n), m = length of queries, n = length of array
//S.C : O(n)
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n , 0); // Difference array with size n + 1
        
        // Step 1: Populate the difference array
        for (const auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];
            
            if (direction == 1) { // Forward shift
                diff[start] += 1;
                if(end+1 < n)
                    diff[end + 1] -= 1;
            } else { // Backward shift
                diff[start] -= 1;
                if(end+1 < n)
                    diff[end + 1] += 1;
            }
        }
        
        // Step 2: Compute the prefix sum to get the net shifts for each character
        for (int i = 1; i < n; ++i) {
            diff[i] += diff[i - 1]; // Add the value from the previous index
        }
        
        // Step 3: Apply the shifts to the string
        for (int i = 0; i < n; ++i) {
            int shift = (diff[i] % 26 + 26) % 26 ; // handles negative as well 
            
            // Apply the shift to character
            s[i] = ((s[i] - 'a' + shift) % 26) + 'a';
            /*
                Note : s[i]-'a' gives the corresponding number of character s[i]
                       +shift adds the shift
                       %26 is to wrap around (0-25)
                       'a' + in the end converts back the number to character
            */
        }
        
        return s;
    }
};



/************************************************************ JAVA ************************************************/
//Approach (Using Difference Array Technique)
//T.C : O(m+n), m = length of queries, n = length of array
//S.C : O(n)
class Solution {
    public String shiftingLetters(String s, int[][] shifts) {
        int n = s.length();
        int[] diff = new int[n]; // Difference array with size n

        // Step 1: Populate the difference array
        for (int[] shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];

            if (direction == 1) { // Forward shift
                diff[start] += 1;
                if (end + 1 < n) {
                    diff[end + 1] -= 1;
                }
            } else { // Backward shift
                diff[start] -= 1;
                if (end + 1 < n) {
                    diff[end + 1] += 1;
                }
            }
        }

        // Step 2: Compute the prefix sum to get the net shifts for each character
        for (int i = 1; i < n; i++) {
            diff[i] += diff[i - 1]; // Add the value from the previous index
        }

        // Step 3: Apply the shifts to the string
        StringBuilder result = new StringBuilder(s);
        for (int i = 0; i < n; i++) {
            int shift = diff[i] % 26; // Ensure shift is within the range [0, 25]
            if (shift < 0) {
                shift += 26; // Handle negative shifts (backward)
            }

            // Apply the shift to character
            char newChar = (char) (((result.charAt(i) - 'a' + shift) % 26) + 'a');
            result.setCharAt(i, newChar);
        }

        return result.toString();
    }
}
