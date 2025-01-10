/*        Scroll below to see JAVA code as well     */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Amazon, Google
    Leetcode Link               : https://leetcode.com/problems/word-subsets/
*/

/********************************************************************** C++ **********************************************************************/
//Approach - (Simple storing character frequency in map and checking)
//T.C : O(n*l1 + m*l2) , n = # of words in words1, l1 = average length of word in words1, similarly m and l2 for words2
//S.C : O(26) ~= O(1)
class Solution {
public:
    bool isSubset(vector<int>& freq2, vector<int>& temp) {
        for(int i = 0; i < 26; i++) { //O(1)
            if(temp[i] < freq2[i]) {
                return false; //not a subset
            }
        }
        return true;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result;

        vector<int> freq2(26);
        //Total characters par iterate = O(n * l1)
        for(string &word : words2) { //O(n)
            int temp[26] = {0}; //vector<int> temp(26, 0)

            for(char &ch : word) { //O(l1)
                temp[ch-'a']++;

                freq2[ch-'a'] = max(freq2[ch-'a'], temp[ch-'a']);
            }
        }
        //O(m*l2)
        for(string &word : words1) { //O(m)
            vector<int> temp(26, 0);

            for(char &ch : word) { //O(l2)
                temp[ch-'a']++;
            }

            if(isSubset(freq2, temp) == true) { //O(1)
                result.push_back(word);
            }
        }

        //T.C : O(n*l1 m*l2) = overall saare characters of words1 and words2
        //S,C : O(26) ~= O(1)

        return result;
    }
};


/********************************************************************** JAVA **********************************************************************/
//Approach - (Simple storing character frequency in map and checking)
//T.C : O(n*l1 + m*l2) , n = # of words in words1, l1 = average length of word in words1, similarly m and l2 for words2
//S.C : O(26) ~= O(1)
import java.util.*;

class Solution {
    public List<String> wordSubsets(String[] words1, String[] words2) {
        List<String> result = new ArrayList<>();
        
        // Step 1: Calculate the maximum frequency requirement for words2
        int[] freq2 = new int[26]; // Frequency array for all characters
        for (String word : words2) {
            int[] temp = new int[26]; // Temporary frequency array for the current word
            for (char ch : word.toCharArray()) {
                temp[ch - 'a']++;
                freq2[ch - 'a'] = Math.max(freq2[ch - 'a'], temp[ch - 'a']);
            }
        }
        
        // Step 2: Check each word in words1
        for (String word : words1) {
            int[] temp = new int[26]; // Frequency array for the current word
            for (char ch : word.toCharArray()) {
                temp[ch - 'a']++;
            }
            
            // Check if the word satisfies the universal condition
            if (isSubset(freq2, temp)) {
                result.add(word);
            }
        }
        
        return result;
    }
    
    // Helper method to check if freq2 is a subset of temp
    private boolean isSubset(int[] freq2, int[] temp) {
        for (int i = 0; i < 26; i++) {
            if (temp[i] < freq2[i]) {
                return false; // Not a subset
            }
        }
        return true;
    }
}
