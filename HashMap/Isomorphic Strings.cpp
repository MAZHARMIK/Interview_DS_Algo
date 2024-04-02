/*     Scroll down to see JAVA code also    */
/*
      MY YOUTUBE VIDEO ON THIS Qn : 
      Company Tags                : LinkedIn
      Leetcode Link               : https://leetcode.com/problems/isomorphic-strings/
*/


/****************************************** C++ ******************************************/
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
