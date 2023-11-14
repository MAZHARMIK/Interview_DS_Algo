/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=EdEvy2_o5OE
      Company Tags                : META, AMAZON, GOOGLE
      Leetcode Link               : https://leetcode.com/problems/unique-length-3-palindromic-subsequences
*/

/************************************************************ C++ ************************************************************/
//Approach-1
//T.C : O(n)
//S.C : O(1) - Only 26 sized always
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        unordered_set<char> unique_letters;
        
        for(char &ch : s) {
            unique_letters.insert(ch);
        }
        
        int result = 0;
        
        for(char letter : unique_letters) {
            
            int first_idx = -1;
            int last_idx  = -1;
            
            for(int i = 0; i<n; i++) {
                if(s[i] == letter) {
                    
                    if(first_idx == -1) {
                        first_idx = i;
                    }
                    
                    last_idx = i;
                    
                }
            }
            
                            
            unordered_set<char> st;
            for(int middle = first_idx+1; middle <= last_idx-1; middle++) {
                st.insert(s[middle]);
            }

            result += st.size();
            
        }
        
        return result;
    }
};


//Approach-2 (Storing first and last indices before hand
//T.C : O(n)
//S.C : O(1) - Only 26 sized always
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<pair<int, int>> indices(26, {-1, -1});
        
        for(int i = 0; i<n; i++) {
            char ch = s[i];
            int idx = ch-'a';
            
            if(indices[idx].first == -1) {
                indices[idx].first = i;
            }
            
            indices[idx].second = i;
        }
        
        
        int result = 0;
        for(int i = 0; i<26; i++) {
            if(indices[i] == make_pair(-1, -1)) {
                continue;
            }
            
            unordered_set<char> st;
            for(int middle = indices[i].first+1; middle <= indices[i].second-1; middle++) {
                
                st.insert(s[middle]);
                
            }
            
            result += st.size();
        }
        
        return result;
    }
};



/************************************************************ JAVA ************************************************************/
//Approach-1
//T.C : O(n)
//S.C : O(1) - ONly 26 sized always
class Solution {
    public int countPalindromicSubsequence(String s) {
        int n = s.length();
        Set<Character> uniqueLetters = new HashSet<>();

        for (char ch : s.toCharArray()) {
            uniqueLetters.add(ch);
        }

        int result = 0;

        for (char letter : uniqueLetters) {

            int firstIdx = -1;
            int lastIdx = -1;

            for (int i = 0; i < n; i++) {
                if (s.charAt(i) == letter) {

                    if (firstIdx == -1) {
                        firstIdx = i;
                    }

                    lastIdx = i;

                }
            }

            Set<Character> set = new HashSet<>();
            for (int middle = firstIdx + 1; middle <= lastIdx - 1; middle++) {
                set.add(s.charAt(middle));
            }

            result += set.size();

        }

        return result;
    }
}


//Approach-2 (Storing first and last indices before hand
//T.C : O(n)
//S.C : O(1) - Only 26 sized always
class Solution {
    public int countPalindromicSubsequence(String s) {
        int[] first = new int[26];
        int[] last = new int[26];
        Arrays.fill(first, -1);
        Arrays.fill(last, -1);
        
        for (int i = 0; i < s.length(); i++) {
            int curr = s.charAt(i) - 'a';
            if (first[curr] == - 1) {
                first[curr] = i;
            }
            
            last[curr] = i;
        }
        
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (first[i] == -1) {
                continue;
            }
            
            Set<Character> st = new HashSet();
            for (int middle = first[i] + 1; middle < last[i]; middle++) {
                st.add(s.charAt(middle));
            }
            
            ans += st.size();
        }
        
        return ans;
    }
}
