/*
    MY YOUTUBE VIDEO ON THIS Qn : <soon>
    Company Tags                : Yogiyo (Food delivering app)
    Frequency                   : Not known yet
    Leetcode Link               : https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
*/

//Approach-1 (Using Sliding Window) 52/53 test cases passed (O(n^2)) Approach
class Solution {
public:
    bool isVowel(const char& ch) {
        return ch=='a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    int findTheLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n     = s.length();
        int maxL  = 0;
        int start = 0;
        int end   = 0;
        
        while(end < n) {
            char curr = s[end];
            end++;
            if(isVowel(curr)) mp[curr]++;
            
            unordered_map<char, int> temp(mp); //create a temporary map
            
            //you need to decrease the window size until you get all vowels in even count
            while(temp['a']%2 || temp['e']%2 || temp['i']%2 || temp['o']%2 || temp['u']%2) {
                if(isVowel(s[start]))
                    temp[s[start]]--;
                
                start++; //reduce the window size
                
                if(end-start <= maxL) break; //aage barhne se fayda nahi hai bhai
            }
            
            maxL = max(maxL, end-start);
            start = 0;
        }
        
        return maxL;
    }
};

//Approach-2 (using Mask and Xor property) Accepted solution (O(n)) approach
//This belongs to Bit_Magic repository as well (You will find the link to this question in Bit_magic repository as well)
class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int mask = 0;
        int maxL = 0;
        for(int i = 0; i<s.length(); i++) {
            int val = 0;
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                val = s[i]; //agar vowel hai to uski value lelo else consonant me 0 rahegi val
            
            mask = mask^val; //xor nikala
            
            if(!mp.count(mask)) //agar past me nahi dekha to map me daaldo
                mp[mask] = i;
            
            maxL = max(maxL, i - mp[mask]); //maxL nikaal lo
        }
        return maxL;
    }
};
