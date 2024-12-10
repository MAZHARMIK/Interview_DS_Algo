/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i
                                : https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-ii
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Brute Force - Try all possible substrings)
//T.C : O(n^3)
//S.C : O(n^2), total substrings
class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();

        map<string, int> mp; //"substring, int"
        for(int i = 0; i < n; i++) {
            string curr;
            for(int j = i; j < n; j++) {
                if(curr.empty() || curr.back() == s[j]) {
                    curr.push_back(s[j]);
                    mp[curr]++;
                } else {
                    break;
                }
            }
        }

        int result = 0;
        for(auto &it : mp) {
            string str = it.first;
            int count = it.second;
            if(count >= 3 && str.length() > result) {
                result = str.length();
            }
        }

        return result == 0 ? -1 : result;
                
    }
};


//Approach-2 (Better Brute Force)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();

        map<pair<char, int>, int> mp;

        for(int i = 0; i < n; i++) {
            char ch = s[i];
            int l = 0;
            for(int j = i; j < n; j++) {
                if(s[j] == ch) {
                    l++;
                    mp[{ch, l}]++;
                } else {
                    break;
                }
            }
        }


        int result = 0;
        for(auto &it : mp) {
            //char ch = it.first.first;
            int length = it.first.second;
            int freq = it.second;

            if(freq >= 3 && length > result) {
                result = length;
            }
        }

        return result == 0 ? -1 : result;
    }
};


//Approach-3 (Optimal - using a 2-d substring store)
//T.C : O(n)
//S.C : O(26*n) ~ O(n)
class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();

        vector<vector<int>> matrix(26, vector<int>(n+1, 0));
        
        char prev_char = s[0];
        int length = 0;

        for(int i = 0; i < n; i++) {
            char curr_char = s[i];

            if(curr_char == prev_char) {
                length += 1;
                matrix[curr_char-'a'][length] += 1;
            } else {
                length = 1;
                matrix[curr_char-'a'][length] += 1;
                prev_char = curr_char;
            }
        }


        int result = 0;
        for(int i = 0; i < 26; i++) {
            int cumSum = 0;
            for(int j = n; j >= 1; j--) {
                cumSum += matrix[i][j];
                if(cumSum >= 3) {
                    result = max(result, j);
                    break;
                }
            }
        }
        return result == 0 ? -1 : result;
    }
};



/**************************************************************** JAVA ****************************************************************/
//Approach-1 (Brute Force - Try all possible substrings)
//T.C : O(n^3)
//S.C : O(n^2), total substrings
class Solution {
    public int maximumLength(String s) {
        int n = s.length();
        Map<String, Integer> mp = new HashMap<>(); // Map to store substring and its frequency
        
        for (int i = 0; i < n; i++) {
            StringBuilder curr = new StringBuilder();
            for (int j = i; j < n; j++) {
                if (curr.length() == 0 || curr.charAt(curr.length() - 1) == s.charAt(j)) {
                    curr.append(s.charAt(j));
                    mp.put(curr.toString(), mp.getOrDefault(curr.toString(), 0) + 1);
                } else {
                    break;
                }
            }
        }
        
        int result = 0;
        for (Map.Entry<String, Integer> entry : mp.entrySet()) {
            String str = entry.getKey();
            int count = entry.getValue();
            if (count >= 3 && str.length() > result) {
                result = str.length();
            }
        }
        
        return result == 0 ? -1 : result;
    }
}


//Approach-2 (Better Brute Force)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
    public int maximumLength(String s) {
        // Create a map to store the count of all substrings
        Map<Pair<Character, Integer>, Integer> count = new HashMap<>();
        int substringLength = 0;

        for (int start = 0; start < s.length(); start++) {
            char character = s.charAt(start);
            substringLength = 0;

            for (int end = start; end < s.length(); end++) {
                // If the current character matches the initial character, increment the count
                if (character == s.charAt(end)) {
                    substringLength++;
                    Pair<Character, Integer> key = new Pair<>(character, substringLength);
                    count.put(key, count.getOrDefault(key, 0) + 1);
                } else {
                    break;
                }
            }
        }

        // Variable to store the longest substring length with frequency at least 3
        int ans = 0;
        for (Map.Entry<Pair<Character, Integer>, Integer> entry : count.entrySet()) {
            int length = entry.getKey().getValue(); // Access length from Pair
            if (entry.getValue() >= 3 && length > ans) {
                ans = length;
            }
        }

        return ans == 0 ? -1 : ans;
    }
}

//Approach-3 (Optimal using a 2-d substring store)
//T.C : O(n)
//S.C : O(26*n) ~ O(n)
class Solution {
    public int maximumLength(String s) {
        int n = s.length();
        int[][] matrix = new int[26][n + 1]; // Matrix to store counts for each character and length
        char prevChar = s.charAt(0);
        int length = 0;

        // Populate the matrix
        for (int i = 0; i < n; i++) {
            char currChar = s.charAt(i);

            if (currChar == prevChar) {
                length += 1;
                matrix[currChar - 'a'][length] += 1;
            } else {
                length = 1;
                matrix[currChar - 'a'][length] += 1;
                prevChar = currChar;
            }
        }

        int result = 0;

        // Calculate the result by checking cumulative sums in reverse order
        for (int i = 0; i < 26; i++) {
            int cumSum = 0;
            for (int j = n; j >= 1; j--) {
                cumSum += matrix[i][j];
                if (cumSum >= 3) {
                    result = Math.max(result, j);
                    break;
                }
            }
        }

        return result == 0 ? -1 : result;
    }
}
