/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=eWoaue1y-Cc
    Company Tags                : AMAZON, Generally asked in short Phone Inteviews
    Leetcode Link               : https://leetcode.com/problems/find-the-difference/?envType=daily-question&envId=2023-09-25
*/

/************************************************** C++ **************************************************/
//Approach-1
//T.C : Linear
//S.C : Extra space map
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mp;
        
        for(char &ch : s) {
            mp[ch]++;
        }
        
        for(char &ch : t) {
            mp[ch]--;
            
            if(mp[ch] < 0)
                return ch;
        }
        
        return 'a'; //send any random. It will never reach here
    }
};

//Approach-2 (Using Sum Difference)
//T.C : Linear
//S.C : constant
class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum = 0;
        
        for (char &ch: t)
            sum += ch;
        
        for (char &ch: s)
            sum -=ch;
        
        return (char)sum;
    }
};


//Approach-3 (Using XOR property)
//T.C : Linear
//S.C : constant
class Solution {
public:
    char findTheDifference(string s, string t) {
        int XOR = 0;
        
        for (char &ch: t)
            XOR ^= ch;
        
        for (char &ch: s)
            XOR ^=ch;
        
        return (char)XOR;
    }
};




/************************************************** JAVA **************************************************/
//Approach-1
//T.C : Linear
//S.C : Extra space map
public class Solution {
    public char findTheDifference(String s, String t) {
        Map<Character, Integer> mp = new HashMap<>();
        
        for (char ch : s.toCharArray()) {
            mp.put(ch, mp.getOrDefault(ch, 0) + 1);
        }
        
        for (char ch : t.toCharArray()) {
            mp.put(ch, mp.getOrDefault(ch, 0) - 1);
            
            if (mp.get(ch) < 0)
                return ch;
        }
        
        return 'a'; // send any random character; it will never reach here
    }
}


//Approach-2 (Using Sum Difference)
//T.C : Lines
//S.C : constant
public class Solution {
    public char findTheDifference(String s, String t) {
        int sum = 0;
        
        for (char ch : t.toCharArray())
            sum += ch;
        
        for (char ch : s.toCharArray())
            sum -= ch;
        
        return (char) sum;
    }
}


//Approach-3 (Using XOR property)
//T.C : Linear
//S.C : constant
public class Solution {
    public char findTheDifference(String s, String t) {
        int xor = 0;
        
        for (char ch : t.toCharArray())
            xor ^= ch;
        
        for (char ch : s.toCharArray())
            xor ^= ch;
        
        return (char) xor;
    }
}
