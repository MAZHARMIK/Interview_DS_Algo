/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=MqMvkrkerIY
    Company Tags                : MICROSOFT'S 2020 MOST ASKED INTERVIEW QUESTION
    Leetcode Link               : https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
*/

/************************************************************ C++ ************************************************************/
//T.C : O(n*2^n)
//S.C : O(n)
//Approach-1 Using DP (Recur + Memo)
class Solution {
public:
    bool hasCommon(string &s1, string& s2) {
        int arr[26] = {0};
        
        for(char &ch : s1) {
            if(arr[ch-'a'] > 0)
                return true;
            arr[ch-'a']++;
        }
        
        for(char &ch : s2) {
            if(arr[ch-'a'] > 0)
                return true;
        }
        
        return false;
    }
    
    unordered_map<string, int> mp;
    
    int solve(int idx, vector<string>& arr, string temp, int n) {
        if(idx >= n)
            return temp.length();
        
        if(mp.find(temp) != mp.end())
            return mp[temp];
        
        int include = 0;
        int exclude = 0;
        if(hasCommon(arr[idx], temp)) {
            exclude = solve(idx+1, arr, temp, n);
        } else {
            exclude = solve(idx+1, arr, temp, n);
            temp += arr[idx];
            include = solve(idx+1, arr, temp, n);
        }
        
        return mp[temp] = max(include, exclude);
    }
    
    int maxLength(vector<string>& arr) {
        string temp = "";
        mp.clear();
        int n = arr.size();
        
        return solve(0, arr, temp, n);
        
    }
};

//Approach-2 (Checkout my Bit-Magic Repository. It has it's second approach using Bit Magic + DFS)




/************************************************************ JAVA ************************************************************/
//T.C : O(n*2^n)
//S.C : O(n)
//Approach-1 Using DP (Recur + Memo)
public class Solution {
    public int maxLength(List<String> arr) {
        return solve(0, arr, "", arr.size(), new HashMap<>());
    }

    private boolean hasCommon(String s1, String s2) {
        int[] arr = new int[26];

        for (char ch : s1.toCharArray()) {
            if (arr[ch - 'a'] > 0)
                return true;
            arr[ch - 'a']++;
        }

        for (char ch : s2.toCharArray()) {
            if (arr[ch - 'a'] > 0)
                return true;
        }

        return false;
    }

    private int solve(int idx, List<String> arr, String temp, int n, Map<String, Integer> memo) {
        if (idx >= n)
            return temp.length();

        String key = temp + idx;
        if (memo.containsKey(key))
            return memo.get(key);

        int include = 0;
        int exclude = 0;
        if (!hasCommon(arr.get(idx), temp)) {
            temp += arr.get(idx);
            include = solve(idx + 1, arr, temp, n, memo);
            temp = temp.substring(0, temp.length() - arr.get(idx).length());
        }
        exclude = solve(idx + 1, arr, temp, n, memo);

        int result = Math.max(include, exclude);
        memo.put(key, result);
        return result;
    }
}





//Approach-2 (Checkout my Bit-Magic Repository. It has it's second approach using Bit Magic + DFS)
