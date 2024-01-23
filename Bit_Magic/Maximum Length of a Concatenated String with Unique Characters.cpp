/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=eVIQUNvFR4E
    Company Tags                : Amazon
    Leetcode Link               : https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters
*/

/********************************************************* C++ ****************************************************************************/
//T.C : O(2^n)
//S.C : O(n)
class Solution {
public:
      void dfs(int idx, int temp, int &result, vector<int>& uniqueCharStrings) {
          
            result = max(result, __builtin_popcount(temp));
          
            for (int i = idx; i < uniqueCharStrings.size(); i++) {
                
                if ((temp & uniqueCharStrings[i]) == 0) { //means no unique characters in temp and uniqueCharStrings[i]
                    //So concatenate them : temp | uniqueCharStrings[i]
                    
                    dfs(i + 1, temp | uniqueCharStrings[i], result, uniqueCharStrings);
                    
                }
            }
      }
    
      int maxLength(vector<string>& arr) {
        vector<int> uniqueCharStrings;

        for (string &s : arr) {
            unordered_set<char> st(begin(s), end(s));
            
            if (st.size() != s.length())  //means they have duplicates
                continue;
            
            int val = 0; //Store the string in form of a number (binary)
            for (char &ch : s) 
                val |= 1 << (ch - 'a');
            
            uniqueCharStrings.push_back(val);
        }

        int result = 0; //This will store the longest 
        dfs(0, 0, result, uniqueCharStrings);
        return result;
    }
};




/********************************************************* JAVA ****************************************************************************/
//T.C : O(2^n)
//S.C : O(n)
class Solution {
    public int maxLength(List<String> arr) {
        List<Integer> uniqueCharStrings = new ArrayList<>();

        for (String s : arr) {
            Set<Character> set = new HashSet<>();
            
            for (char ch : s.toCharArray()) {
                set.add(ch);
            }

            if (set.size() != s.length()) { // means they have duplicates
                continue;
            }

            int val = 0; // Store the string in the form of a number (binary)
            for (char ch : s.toCharArray()) {
                val |= 1 << (ch - 'a');
            }

            uniqueCharStrings.add(val);
        }

        int[] result = { 0 }; // This will store the longest
        dfs(0, 0, result, uniqueCharStrings);
        return result[0];
    }

    private void dfs(int idx, int temp, int[] result, List<Integer> uniqueCharStrings) {
        result[0] = Math.max(result[0], Integer.bitCount(temp));

        for (int i = idx; i < uniqueCharStrings.size(); i++) {
            if ((temp & uniqueCharStrings.get(i)) == 0) {
                // means no unique characters in temp and uniqueCharStrings[i]
                // So concatenate them: temp | uniqueCharStrings[i]
                dfs(i + 1, temp | uniqueCharStrings.get(i), result, uniqueCharStrings);
            }
        }
    }
}
