/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=r51_ZifUdvU
    Company Tags                : AMAZON
    Leetcode Link               : https://leetcode.com/problems/is-subsequence/
    
    I have added this question because there is another concept through which this can be solved as well (see approach-1 below). That concept may not be optimal
    for this question but it helps to solve related questions optimally. Example : Leetcode-792 (Number of Matching Subsequences) asked by GOOGLE
    My Code for Leetcode-792 using this approach - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Binary%20Search/Number%20of%20Matching%20Subsequences.cpp
*/

/*************************************************** C++ *************************************************/
//Follow Up Approach
//Approach-1 (Using Binary Search) -> This is an important concept for qns like Leetcode-792
class Solution {
public:
    bool isSubsequence(string s, string t) {
        map<char, vector<int>> mp;
        
        //saving incides of each character in t
        for(int i = 0; i<t.length(); i++) {
            char ch = t[i];
            mp[ch].push_back(i);
        }
        
        int prev = -1;
        //Now, look if we can find characters of s with increasing indices
        //Example : s = "abc", t = "ahbgdc" -> {a -> {0}, h -> {1}, b ->{2}, g -> {3}, d -> {4}, c -> {5}
        //Characters of "abc"
        //a -> {0}
        //b -> {2}
        //c -> {5}
        //indices are in increasing order -> {0, 2, 5}, so this is a subsequence of t
        for(char &ch : s) {
            if(mp.find(ch) == mp.end())
                return false;
            
            vector<int> indices = mp[ch];
            
            auto it = upper_bound(begin(indices), end(indices), prev);
            
            if(it == indices.end())
                return false;
            
            prev = *it;
        }
        
        return true;
    }
};

//Approach-2 (Simplest O(n) approach)
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m  = t.length();
        int n  = s.length();
        int i = 0, j = 0;

        while(i < m) {
            if(t[i] == s[j])
                j++;
            i++;
        }

        return j == n;
    }
};


/*************************************************** JAVA *************************************************/
//Follow Up Approach
//Approach-1 (Using Binary Search) -> This is an important concept for qns like Leetcode-792
public class Solution {
    public boolean isSubsequence(String s, String t) {
        Map<Character, List<Integer>> mp = new HashMap<>();
        
        for (int i = 0; i < t.length(); i++) {
            char ch = t.charAt(i);
            mp.computeIfAbsent(ch, k -> new ArrayList<>()).add(i);
        }
        
        int prev = -1;
        for (char ch : s.toCharArray()) {
            if (!mp.containsKey(ch))
                return false;
            
            List<Integer> indices = mp.get(ch);
            
            int index = Collections.binarySearch(indices, prev + 1);
            
            if (index < 0)
                index = -index - 1;
            
            if (index == indices.size())
                return false;
            
            prev = indices.get(index);
        }
        
        return true;
    }
}

//Approach-2 (Simplest O(n) approach)
public class Solution {
    public boolean isSubsequence(String s, String t) {
        int m = t.length();
        int n = s.length();
        int i = 0, j = 0;

        while (i < m && j < n) {
            if (t.charAt(i) == s.charAt(j)) {
                j++;
            }
            i++;
        }

        return j == n;
    }
}
