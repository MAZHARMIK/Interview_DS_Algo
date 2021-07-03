/*
    Company Tags  : Morgan Stanley, Amazon, Microsoft, Housing.com
    Leetcode Link : https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

//Approach-1 (Using set data structure and two pointer technique)
//Time : O(2*n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int l = 0;
        
        int n = s.length();
        int i = 0;
        int j = 0;
        while(j < n) {
            if(!st.count(s[j])) {
                st.insert(s[j]);
                l = max(l, (int)st.size());
                j++;
            } else {
                st.erase(s[i]);
                i++;
                /*
                    Example : "a b c d e a a"
                    When you are at 5th index, you notice that you saw 'a' somewhere before, you delete it from set
                    Now, you add this 'a' (5th index) in the set and move ahead at 6th index.
                    Now, you see that 'a' (6th index) is somewhere behind because it's in the set.
                    But you keep deleting from set until you delete this 'a' (5th index) from the set.
                    So, effectively you are iterating array 2 times in worst case. So, time = O(2*n)
                */
            }
        }
        return l;
    }
};

//Approach-2 (Using map data strcture and two pointer technique)
//Time : O(n)
/*
    Instead of deleting character one by one, we can directly jump 'i' just after the last appearance of a character.
    We will use to store indices of character. So, in that way we don't have to move 'i' one by one.
    Now one thing to note, 
    Example : "a a b a a b z b b"
    When you reach at index 4 ('a'), you move i = mp['a'] + 1. i.e. 'i' is now 4
    Now, When you are at 5th index ('b'), you notice that you have '(b, 2)' in map. So, you make i = map['b'] + 1; 
    i.e. i becomes 3 but did you notice you had made i = 4 above. This is an issue.
    So, we do this : i = max(i, mp[ch]+1); //which ever is larger we make that jump for 'i'
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int res = 0;
       
            
        int i = 0, j = 0;
        unordered_map<char, int> mp;
        
        while(j < n) {
            char ch = s[j];
            if(!mp.count(ch)) {
                //If not in map, update map and calculate length
                mp[ch] = j;
                res = max(res, j-i+1);
            } else {
                //if already present in map, make proper i jump and then calculate length
                i = max(i, mp[ch] + 1);
                mp[ch] = j; //Don't forget to update new index of ch
                res = max(res, j-i+1);
            }
            j++;
        }
        
        return res;
    }
};

//Approach-3 (Just simplifying Approach-2. Notice some statements are common in if and else block. Take them outside
//Time : O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int res = 0;       
            
        int i = 0, j = 0;
        unordered_map<char, int> mp;
        
        while(j < n) {
            char ch = s[j];
            if(mp.count(ch)) {
                i = max(i, mp[ch] + 1);
            }
            mp[ch] = j;
            res = max(res, j-i+1);
            j++;
        }
        
        return res;
    }
};
