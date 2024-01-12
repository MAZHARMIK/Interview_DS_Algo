/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=oSSMo0PCQts
    Company Tags                : Google, Amazon, Microsoft, Meta
    Leetcode Link               : https://leetcode.com/problems/determine-if-string-halves-are-alike/
*/

/******************************************************** C++ ********************************************************/
//Approach-1 (without Using Set)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool isVowel(char &ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || 
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }
    bool halvesAreAlike(string s) {
        int n = s.length();
        
        int mid = n/2;
        
        int i = 0, j = mid;
        
        int countL = 0;
        int countR = 0;
        
        while(i < n/2 && j < n) {
            if(isVowel(s[i])) countL++;
            
            if(isVowel(s[j])) countR++;
            
            i++;
            j++;
        }
        
        
        return countL == countR;
    }
};


//Approach-1 (without Using Set)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        
        int mid = n/2;
        
        int i = 0, j = mid;
        
        int countL = 0;
        int countR = 0;
        
        string vowels = "aeiouAEIOU";
        unordered_set<char> st(begin(vowels), end(vowels));
        
        while(i < n/2 && j < n) {
            if(st.find(s[i]) != st.end()) countL++;
            
            if(st.find(s[j]) != st.end()) countR++;
            
            i++;
            j++;
        }
        
        
        return countL == countR;
    }
};


/******************************************************** JAVA ********************************************************/
//Approach-1 (without Using Set)
//T.C : O(n)
//S.C : O(1)
public class Solution {
    public boolean isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || 
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }

    public boolean halvesAreAlike(String s) {
        int n = s.length();

        int mid = n / 2;

        int i = 0, j = mid;

        int countL = 0;
        int countR = 0;

        while (i < n / 2 && j < n) {
            if (isVowel(s.charAt(i))) countL++;

            if (isVowel(s.charAt(j))) countR++;

            i++;
            j++;
        }

        return countL == countR;
    }
}


//Approach-1 (without Using Set)
//T.C : O(n)
//S.C : O(n)
public class Solution {
    public boolean halvesAreAlike(String s) {
        int n = s.length();

        int mid = n / 2;

        int i = 0, j = mid;

        int countL = 0;
        int countR = 0;

        Set<Character> vowels = new HashSet<>();
        String vowelString = "aeiouAEIOU";
        for (char c : vowelString.toCharArray()) {
            vowels.add(c);
        }

        while (i < n / 2 && j < n) {
            if (vowels.contains(s.charAt(i))) countL++;

            if (vowels.contains(s.charAt(j))) countR++;

            i++;
            j++;
        }

        return countL == countR;
    }
}
