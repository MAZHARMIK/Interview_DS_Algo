/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS QN : 
    Company Tags                : Microsoft, Amazon
    Leetcode Link               : https://leetcode.com/problems/permutation-in-string
*/

/*********************************************************************** C++ ************************************************************/
//Approach-1 (Brute Force) - TLE
//T.C : O(n! * m)
//S.C : O(n)
class Solution {
public:
    int n;
    bool result;
    void solve(int idx, string& s1, string& s2) {
        if (idx == n) {
            if (s2.find(s1) != string::npos) {
                result = true;
            }
            return;
        }

        for (int i = idx; i < n; i++) {
            swap(s1[i], s1[idx]);
            
            solve(idx + 1, s1, s2);

            swap(s1[i], s1[idx]);

            // Early exit if a permutation has been found in s2
            if (result == true) 
                return;
        }
    }

    bool checkInclusion(string s1, string s2) {
        n = s1.length();
        result = false;  // Reset result for each call

        solve(0, s1, s2);

        return result;  // Return whether a permutation of s1 is found in s2
    }
};



//Approach-2 (Using Sorting and Comparing) - ACCEPTED
//T.C : O((m-n) * nlogn)
//S.C : O(n)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        // If s1 is longer than s2, it cannot be a substring
        if (n > m) return false;

        // Sort the string s1
        string sorted_s1 = s1;
        sort(sorted_s1.begin(), sorted_s1.end());

        // Iterate over each substring of s2 of length equal to s1
        for (int i = 0; i <= m - n; i++) {
            // Extract a substring of length n from s2 starting at index i
            string temp = s2.substr(i, n);

            // Sort the substring
            sort(temp.begin(), temp.end());

            // If the sorted substring matches the sorted s1, return true
            if (temp == sorted_s1) return true;
        }

        // No permutation found in s2
        return false;
    }
};



//Approach-3 (Sliding Window) - ACCEPTED
//T.C : O(m+n)
//S.C : O(26)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        // If s1 is larger than s2, no permutation can exist
        if (n > m) 
            return false;

        // Frequency vectors for s1 and the current window in s2
        vector<int> s1Freq(26, 0);
        vector<int> s2Freq(26, 0);

        // Slide the window over s2
        int i = 0;
        int j = 0;
        while(j < m) {
            // Include a new character from the right end of the window
            s2Freq[s2[j] - 'a']++;
            
            if(j - i + 1 == n) {
                // Check if the frequency vectors match
                if (s1Freq == s2Freq) 
                    return true;
            }

                            
            // Exclude the character from the left end of the window
            s2Freq[s2[i] - 'a']--;
            i++;
            j++;
        }

        return false;
    }
};



/*********************************************************************** JAVA ************************************************************/
//Approach-1 (Brute Force) - TLE
//T.C : O(n! * m)
//S.C : O(n)
class Solution {
    private int n; // Length of s1
    private boolean result; // Result indicating if a permutation is found

    // Backtracking method to generate permutations of s1
    private void solve(int idx, String s1, String s2) {
        if (idx == n) {
            // Check if the current permutation of s1 exists in s2
            if (s2.contains(s1)) {
                result = true;
            }
            return;
        }

        // Generate permutations of s1
        char[] charArray = s1.toCharArray(); // Convert to char array for swapping
        for (int i = idx; i < n; i++) {
            // Swap characters at positions idx and i
            swap(charArray, idx, i);
            // Convert char array back to string
            String newS1 = new String(charArray);
            // Recursively generate permutations
            solve(idx + 1, newS1, s2);
            // Swap back to restore the original order
            swap(charArray, idx, i);
            // Early exit if a permutation has been found in s2
            if (result) {
                return;
            }
        }
    }

    // Utility method to swap two characters in a char array
    private void swap(char[] array, int i, int j) {
        char temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    // Main method to check if any permutation of s1 exists in s2
    public boolean checkInclusion(String s1, String s2) {
        n = s1.length();
        result = false; // Reset result for each call
        // Start the backtracking process
        solve(0, s1, s2);
        return result; // Return whether a permutation of s1 is found in s2
    }
}

//Approach-2 (Using Sorting and Comparing) - ACCEPTED
//T.C : O((m-n) * nlogn)
//S.C : O(n)
class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int n = s1.length();
        int m = s2.length();

        // If s1 is longer than s2, it cannot be a substring
        if (n > m) return false;

        // Sort the string s1
        char[] sortedS1 = s1.toCharArray();
        Arrays.sort(sortedS1);

        // Iterate over each substring of s2 of length equal to s1
        for (int i = 0; i <= m - n; i++) {
            // Extract a substring of length n from s2 starting at index i
            String temp = s2.substring(i, i + n);

            // Sort the substring
            char[] sortedTemp = temp.toCharArray();
            Arrays.sort(sortedTemp);

            // If the sorted substring matches the sorted s1, return true
            if (Arrays.equals(sortedTemp, sortedS1)) return true;
        }

        // No permutation found in s2
        return false;
    }
}


//Approach-3 (Sliding Window) - ACCEPTED
//T.C : O(m+n)
//S.C : O(26)
class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int n = s1.length();
        int m = s2.length();

        // If s1 is larger than s2, no permutation can exist
        if (n > m) 
            return false;

        // Frequency arrays for s1 and the current window in s2
        int[] s1Freq = new int[26];
        int[] s2Freq = new int[26];

        // Fill the frequency array for s1
        for (char c : s1.toCharArray()) {
            s1Freq[c - 'a']++;
        }

        // Slide the window over s2
        int i = 0; // Start of the window
        for (int j = 0; j < m; j++) {
            // Include a new character from the right end of the window
            s2Freq[s2.charAt(j) - 'a']++;
            
            // Check if the window size is equal to s1
            if (j - i + 1 == n) {
                // Check if the frequency arrays match
                if (compareArrays(s1Freq, s2Freq)) 
                    return true;
                
                // Exclude the character from the left end of the window
                s2Freq[s2.charAt(i) - 'a']--;
                i++; // Move the start of the window
            }
        }

        return false;
    }

    // Helper method to compare two frequency arrays
    private boolean compareArrays(int[] arr1, int[] arr2) {
        for (int i = 0; i < 26; i++) {
            if (arr1[i] != arr2[i]) {
                return false;
            }
        }
        return true;
    }
}
