/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=nEDXPkGsjXo
      Company Tags                : Microsoft
      Leetcode Link               : https://leetcode.com/problems/sort-vowels-in-a-string
*/

/*********************************************************** C++ **********************************************************************/
//Approach-1 (Separate string create and sort)
//T.C : O(nlog)
class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    string sortVowels(string s) {
        string temp;
        for(char &ch : s) {
            if(isVowel(ch)) {
                temp.push_back(ch);
            }
        }
        
        sort(begin(temp), end(temp));
        int j = 0;
        for(int i = 0; i<s.length(); i++) {
            if(isVowel(s[i])) {
                s[i] = temp[j];
                j++;
            }
        }
        
        return s;
    }
};


//Approach-2 (Without sorting. Counting the vowels - counting sort)
//T.C : O(n)
class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    
    string sortVowels(string s) {
        unordered_map<char, int> mp;
        
        for(char &ch : s) {
            if(isVowel(ch)) {
                mp[ch]++;
            }
        }
        
        string temp   = "AEIOUaeiou";
        
        int j = 0; //pointing to temp (current vowel)
        
        for(int i = 0; i<s.length(); i++) {
            
            if(isVowel(s[i])) {
                while(mp[temp[j]] == 0) {
                    j++;
                }
                
                s[i] = temp[j];
                mp[temp[j]]--;
            }
            
        }
        
        return s;
        
    }
};



/*********************************************************** JAVA **********************************************************************/
//Approach-1 (Separate string create and sort)
//T.C : O(nlog)
public class Solution {
    private boolean isVowel(char ch) {
        ch = Character.toLowerCase(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    public String sortVowels(String s) {
        StringBuilder temp = new StringBuilder();
        for (char ch : s.toCharArray()) {
            if (isVowel(ch)) {
                temp.append(ch);
            }
        }

        char[] tempArray = temp.toString().toCharArray();
        Arrays.sort(tempArray);

        int j = 0;
        char[] resultArray = s.toCharArray();
        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s.charAt(i))) {
                resultArray[i] = tempArray[j];
                j++;
            }
        }

        return new String(resultArray);
    }
}



//Approach-2 (Without sorting. Counting the vowels - counting sort)
//T.C : O(n)
public class Solution {
    private boolean isVowel(char ch) {
        ch = Character.toLowerCase(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    public String sortVowels(String s) {
        Map<Character, Integer> map = new HashMap<>();

        for (char ch : s.toCharArray()) {
            if (isVowel(ch)) {
                map.put(ch, map.getOrDefault(ch, 0) + 1);
            }
        }

        String vowels = "AEIOUaeiou";
        int j = 0; // pointing to temp (current vowel)

        char[] resultArray = s.toCharArray();

        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s.charAt(i))) {
                while (map.getOrDefault(vowels.charAt(j), 0) == 0) {
                    j++;
                }

                resultArray[i] = vowels.charAt(j);
                map.put(vowels.charAt(j), map.get(vowels.charAt(j)) - 1);
            }
        }

        return new String(resultArray);
    }
}
