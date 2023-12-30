/*
    MY YOUTUBE VIDEO ON THIS QN : https://www.youtube.com/watch?v=BWETRja2KHg
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/
*/

/************************************************************ C++ ************************************************************/
//Approach-1 (Using hashmap to store frequency)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        unordered_map<char, int> count;

        for (string& word : words) {
            for (char &ch : word) {
                count[ch]++;
            }
        }

        for (auto &it : count) {
            if (it.second % n != 0) {
                return false;
            }
        }

        return true;
    }
};

//Approach-2 (Using array as hashmap for storing frequency)
//T.C : O(n)
//S.C : O(26)
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        
        int count[26] = {0};
        
        for(string &word : words) {
            
            for(char &ch : word) {
                count[ch-'a']++;
            }
            
        }
        
        for(int i = 0; i < 26; i++) {
            if(count[i]%n != 0) {
                return false;
            }
        }
        
        return true;
        
    }
};


//Approach-3 (Using STL+lambda and array as hashmap)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        int count[26] = {0};
        
        for (string &word : words) {
            for (char &ch : word) {
                ++count[ch - 'a'];
            }
        }
        
        auto lambda = [&](int c) {
                   return c % n == 0;
        };
        
        return all_of(begin(count), end(count), lambda);
        
        
        /*  Or, you can also write like this
            return all_of(begin(count), end(count), [&](int c) {
                   return c % n == 0;
            });
            
        */
        
    }
};


/************************************************************ JAVA ************************************************************/
//Approach-1 (Using hashmap to store frequency)
//T.C : O(n)
//S.C : O(n)
public class Solution {
    public boolean makeEqual(String[] words) {
        int n = words.length;
        Map<Character, Integer> count = new HashMap<>();

        for (String word : words) {
            for (char ch : word.toCharArray()) {
                count.put(ch, count.getOrDefault(ch, 0) + 1);
            }
        }

        for (int value : count.values()) {
            if (value % n != 0) {
                return false;
            }
        }

        return true;
    }
}


//Approach-2 (Using hash map store frequency)
//T.C : O(n)
//S.C : O(26)
class Solution {
    public boolean makeEqual(String[] words) {
        int n = words.length;

        int[] count = new int[26];

        for (String word : words) {
            for (char ch : word.toCharArray()) {
                count[ch - 'a']++;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (count[i] % n != 0) {
                return false;
            }
        }

        return true;
    }
}


//Approach-3 (Using library and array as hashmap)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public boolean makeEqual(String[] words) {
        int n = words.length;

        int[] count = new int[26];

        for (String word : words) {
            for (char ch : word.toCharArray()) {
                count[ch - 'a']++;
            }
        }

        return Arrays.stream(count).allMatch(c -> c % n == 0);
    }
}
