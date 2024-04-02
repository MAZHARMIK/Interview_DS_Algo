/*     Scroll down to see JAVA code also    */
/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=2ISNCDJEgqQ
      Company Tags                : LinkedIn
      Leetcode Link               : https://leetcode.com/problems/isomorphic-strings/
*/


/****************************************** C++ ******************************************/
//Using array of size 256
//T.C : O(n)
//S.C : O(1) -> Take array of size 256 to handle all ASCII characters instead of taking map
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> mp1(256, -1);
        vector<int> mp2(256, -1);
        int n = s.length();
        
        for(int i = 0; i<n; i++) {
            char ch1 = s[i];
            char ch2 = t[i];
            
            if((mp1[ch1] != -1 && mp1[ch1] != ch2) ||
               (mp2[ch2] != -1  && mp2[ch2] != ch1)
               )
                return false;
            
            mp1[ch1] = ch2;
            mp2[ch2] = ch1;
            
        }
        
        return true;
    }
};


//Using unordered_map
//T.C : O(n)
//S.C : O(1) -> size of map will not exceed 256
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;
        
        int m = s.length();
        
        for(int i = 0; i < m; i++) {
            
            char ch1 = s[i];
            char ch2 = t[i];
            
            if(mp1.find(ch1) != mp1.end() && mp1[ch1] != ch2 || 
               mp2.find(ch2) != mp2.end() && mp2[ch2] != ch1
              ) {
                return false;
            }
            
            mp1[ch1] = ch2;
            mp2[ch2] = ch1;
        }
        
        return true;
    }
};



/****************************************** JAVA ******************************************/
//T.C : O(n)
//S.C : O(1) -> Take array of size 256 to handle all ASCII characters instead of taking map
class Solution {
    public boolean isIsomorphic(String s, String t) {
        int[] mp1 = new int[256];
        int[] mp2 = new int[256];
        Arrays.fill(mp1, -1);
        Arrays.fill(mp2, -1);
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            char ch1 = s.charAt(i);
            char ch2 = t.charAt(i);
            
            if ((mp1[ch1] != -1 && mp1[ch1] != ch2) || (mp2[ch2] != -1 && mp2[ch2] != ch1))
                return false;
            
            mp1[ch1] = ch2;
            mp2[ch2] = ch1;
        }
        
        return true;
    }
}


//Using unordered_map
//T.C : O(n)
//S.C : O(1) -> size of map will not exceed 256
public class Solution {
    public boolean isIsomorphic(String s, String t) {
        Map<Character, Character> mp1 = new HashMap<>();
        Map<Character, Character> mp2 = new HashMap<>();
        
        int m = s.length();
        
        for(int i = 0; i < m; i++) {
            
            char ch1 = s.charAt(i);
            char ch2 = t.charAt(i);
            
            if((mp1.containsKey(ch1) && mp1.get(ch1) != ch2) || 
               (mp2.containsKey(ch2) && mp2.get(ch2) != ch1)) {
                return false;
            }
            
            mp1.put(ch1, ch2);
            mp2.put(ch2, ch1);
        }
        
        return true;
    }
}
