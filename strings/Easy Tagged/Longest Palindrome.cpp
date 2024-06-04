/*     Scroll below to see JAVA code also    */
/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=DSEng0xILV4
      Company Tags                : GOOGLE, AMAZON
      Leetcode Link               : https://leetcode.com/problems/longest-palindrome/description
*/


/************************************************************* C++ ***********************************************************/
//Approach-1 (Using simple set)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        unordered_set<char> st;

        int result = 0;
        for(char &ch : s) {
            if(st.count(ch)) {
                st.erase(ch);
                result += 2;
            } else {
                st.insert(ch);
            }
        }

        if(!st.empty())
            result++;
        
        return result;
    }
};


//Approach-2 (Using hashmap and countintg frequency)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        unordered_map<char, int> mp;

        int result = 0;
        for(char &ch : s) {
            mp[ch]++;
        }

        bool takeCentralChar = false;
        for(auto &it : mp) {
            if(it.second % 2 == 0) {
                result += it.second;
            } else {
                result += it.second - 1;
                takeCentralChar = true;
            }
        }

        if(takeCentralChar)
            result++;

        return result;
    }
};


//Approach-3 (one uteration)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        unordered_map<char, int> mp;

        int result  = 0;
        int oddFrq  = 0;

        for(char &ch : s) {
            mp[ch]++;

            if(mp[ch] % 2 != 0) {
                oddFrq++;
            } else {
                oddFrq--;
            }
        }

        if(oddFrq > 0) {
            return n - oddFrq + 1;
        }

        return n;
    }
};


/************************************************************* JAVA ***********************************************************/
//Approach-1 (Using simple set)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int longestPalindrome(String s) {
        int n = s.length();
        HashSet<Character> set = new HashSet<>();
        
        int result = 0;
        for(char ch : s.toCharArray()) {
            if(set.contains(ch)) {
                set.remove(ch);
                result += 2;
            } else {
                set.add(ch);
            }
        }
        
        if(!set.isEmpty()) {
            result++;
        }
        
        return result;
    }
}


//Approach-2 (Using hashmap and countintg frequency)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int longestPalindrome(String s) {
        int n = s.length();
        HashMap<Character, Integer> map = new HashMap<>();
        
        int result = 0;
        for(char ch : s.toCharArray()) {
            map.put(ch, map.getOrDefault(ch, 0) + 1);
        }
        
        boolean takeCentralChar = false;
        for(int count : map.values()) {
            if(count % 2 == 0) {
                result += count;
            } else {
                result += count - 1;
                takeCentralChar = true;
            }
        }
        
        if(takeCentralChar) {
            result++;
        }
        
        return result;
    }
}



//Approach-3 (one uteration)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int longestPalindrome(String s) {
        int n = s.length();
        HashMap<Character, Integer> map = new HashMap<>();
        
        int result = 0;
        int oddFreq = 0;
        
        for(char ch : s.toCharArray()) {
            map.put(ch, map.getOrDefault(ch, 0) + 1);
            
            if(map.get(ch) % 2 != 0) {
                oddFreq++;
            } else {
                oddFreq--;
            }
        }
        
        if(oddFreq > 0) {
            return n - oddFreq + 1;
        }
        
        return n;
    }
}
