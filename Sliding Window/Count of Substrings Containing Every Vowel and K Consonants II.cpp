/*         Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=8FP1kkYf2U4
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii
*/


/********************************************************************** C++ **********************************************************************/
//Approach (Sliding Window Khandani Template)
//T.C : O(2*n) ~ O(n)
//S.C : O(n)
class Solution {
public:
    bool isVowel(char &ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    long long countOfSubstrings(string word, int k) {
        int n = word.length();

        unordered_map<char, int> mp; //to keep count of vowels in a current window
        //S.C : O(5) constant

        //Preprocessing to be able to find index of just next consonant
        vector<int> nextCons(n); //S.C : O(n)
        int lastConsIdx = n;
        //T.C : O(n)
        for(int i = n-1; i >=0; i--) {
            nextCons[i] = lastConsIdx;
            if(!isVowel(word[i])) { //consonant
                lastConsIdx = i;
            }
        }


        int i = 0;
        int j = 0;
        long long count = 0;
        int cons = 0;
        //T.C : O(2*n) ~ O(n) 
        while(j < n) {
            char ch = word[j];
            if(isVowel(ch)) {
                mp[ch]++;
            } else {
                cons++;
            }

            //cons must be always == k
            while(cons > k) {
                char ch = word[i];
                if(isVowel(ch)) {
                    mp[ch]--;
                    if(mp[ch] == 0) {
                        mp.erase(ch);
                    }
                } else {
                    cons--;
                }
                i++;
            }

            while(i < n && mp.size() == 5 && cons == k) { //valid window
                int idx = nextCons[j]; //it will tell me the next consonant after jth index
                count += idx - j; //most important part
                char ch = word[i];
                if(isVowel(ch)) {
                    mp[ch]--;
                    if(mp[ch] == 0) {
                        mp.erase(ch);
                    }
                } else {
                    cons--;
                }
                i++;
            }

            j++;
        }

        return count;
    }
};



/********************************************************************** JAVA **********************************************************************/
//Approach (Sliding Window Khandani Template)
//T.C : O(2*n) ~ O(n)
//S.C : O(n)
import java.util.*;

class Solution {
    private boolean isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    
    public long countOfSubstrings(String word, int k) {
        int n = word.length();
        Map<Character, Integer> mp = new HashMap<>(); // to keep count of vowels in current window
        
        // Preprocessing to find index of next consonant
        int[] nextCons = new int[n];
        int lastConsIdx = n;
        for (int i = n - 1; i >= 0; i--) {
            nextCons[i] = lastConsIdx;
            if (!isVowel(word.charAt(i))) {
                lastConsIdx = i;
            }
        }
        
        int i = 0, j = 0;
        long count = 0;
        int cons = 0;
        
        while (j < n) {
            char ch = word.charAt(j);
            if (isVowel(ch)) {
                mp.put(ch, mp.getOrDefault(ch, 0) + 1);
            } else {
                cons++;
            }
            
            while (cons > k) {
                char ci = word.charAt(i);
                if (isVowel(ci)) {
                    mp.put(ci, mp.get(ci) - 1);
                    if (mp.get(ci) == 0) {
                        mp.remove(ci);
                    }
                } else {
                    cons--;
                }
                i++;
            }
            
            while (i < n && mp.size() == 5 && cons == k) {
                int idx = nextCons[j];
                count += idx - j;
                
                char ci = word.charAt(i);
                if (isVowel(ci)) {
                    mp.put(ci, mp.get(ci) - 1);
                    if (mp.get(ci) == 0) {
                        mp.remove(ci);
                    }
                } else {
                    cons--;
                }
                i++;
            }
            
            j++;
        }
        
        return count;
    }
}
