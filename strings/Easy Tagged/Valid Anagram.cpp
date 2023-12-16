/*
    MY YOUTUBE VIDEO ON THIS QN : https://www.youtube.com/watch?v=1tmEKyRAMuY
    Company Tags                : Uber
    Leetcode Link               : https://leetcode.com/problems/valid-anagram/
    
    Follow Up - What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
    Answer - Either use a hashmap to store or an interger array of size 128 will work (in Approach-2)
*/

/*************************************************************************** C++ ***************************************************************************/
//Approach-1 (Using sorting)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(begin(s), end(s));
        sort(begin(t), end(t));
        
        return s == t;
    }
};


//Approach-1 (Using map)
//T.C : O(n)
//S.C : O(26) ~ O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(26, 0);
        
        for(char &ch : s) {
            count[ch-'a']++;
        }
        
        for(char &ch : t) {
            count[ch-'a']--;
        }
        //NOTE : You can also do above in only one for loop.
        /*
            for(int i = 0; i<n; i++) {
                count[s[i]-'a']++;
                count[t[i]-'a']--;
            }
        */
        
        // Check if all elements in the array are 0 --> You can write a for loop as well
        //This is just for learning purpose
        bool allZeros = all_of(begin(count), end(count), [](int element) {
            return element == 0;
        });
        
        return allZeros;
    }
};



/*************************************************************************** JAVA ***************************************************************************/
//Approach-1 (Using sorting)
//T.C : O(nlogn)
//S.C : O(1)
public class Solution {
    public boolean isAnagram(String s, String t) {
        char[] sChars = s.toCharArray();
        char[] tChars = t.toCharArray();
        
        Arrays.sort(sChars);
        Arrays.sort(tChars);
        
        return Arrays.equals(sChars, tChars);
    }
}


//Approach-1 (Using map)
//T.C : O(n)
//S.C : O(26) ~ O(1)
public class Solution {
    public boolean isAnagram(String s, String t) {
        int[] count = new int[26];

        for (char ch : s.toCharArray()) {
            count[ch - 'a']++;
        }

        for (char ch : t.toCharArray()) {
            count[ch - 'a']--;
        }

        // Check if all elements in the array are 0
        boolean allZeros = Arrays.stream(count).allMatch(element -> element == 0);

        return allZeros;
    }
}
