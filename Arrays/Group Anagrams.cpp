/*                            Scroll below to see JAVA code also                                  */
/*
  MY YOUTUBE VIDEO ON THIS Qn : Using Sortng     - https://www.youtube.com/watch?v=--k5-3EOObs&t=2s
                                Without Sorting  - https://www.youtube.com/watch?v=TNe3gF4r128&t=1s
  Company Tags                : Amazon(mutiple times), Google, Uber, Facebook, Bloomberg, Yahoo, Goldman Sachs, Microsoft, Apple, Walmart Labs, 
                                Twilio, Affirm
  Leetcode Link               : https://leetcode.com/problems/group-anagrams/
  GfG Link                    : https://practice.geeksforgeeks.org/problems/print-anagrams-together/1
*/

/************************************************************** C++ **************************************************************/
//Approach-1 (Using Sorting)
//T.C : O(n*klog(k))  (n = size of input, k = maximum length of a string in the input vector)
//S.C : O(n*k)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(auto str:strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(str);
        }
        
        vector<vector<string>> result;
        for(auto it : mp) {
            result.push_back(it.second);
        }
        
        return result;
    }
};


//Approach-2
//T.C : O(n*k)  (n = size of input, k = maximum length of a string in the input vector)
//S.C : O(n*k)
class Solution {
public:
    
    string generate(string &s) {
        int count[26] = {0};
        
        for(char &ch : s) {
            count[ch-'a']++;
        }
        
        string new_s;
        
        for(int i = 0; i<26; i++) {
            
            if(count[i] > 0) {
                new_s += string(count[i], i+'a');
            }
        }
        
        return new_s;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(string &s : strs) {
            string new_s = generate(s);
            
            mp[new_s].push_back(s);
        }
        
        vector<vector<string>> result;
        for(auto &it : mp) {
            result.push_back(std::move(it.second));
        }
        
        return result;
        
    }
};


/************************************************************** JAVA **************************************************************/
//Approach-1 (Using Sorting)
//T.C : O(n*klog(k))  (n = size of input, k = maximum length of a string in the input vector)
//S.C : O(n*k)
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();

        for (String str : strs) {
            char[] charArray = str.toCharArray();
            Arrays.sort(charArray);
            String sortedStr = new String(charArray);

            if (!map.containsKey(sortedStr)) {
                map.put(sortedStr, new ArrayList<>());
            }

            map.get(sortedStr).add(str);
        }

        return new ArrayList<>(map.values());
    }
}


//Approach-2
//T.C : O(n*k)  (n = size of input, k = maximum length of a string in the input vector)
//S.C : O(n*k)
class Solution {
    private String generate(String s) {
        int[] count = new int[26];

        for (char ch : s.toCharArray()) {
            count[ch - 'a']++;
        }

        StringBuilder newS = new StringBuilder();

        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                newS.append(String.valueOf((char) (i + 'a')).repeat(count[i]));
            }
        }

        return newS.toString();
    }

    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();

        for (String s : strs) {
            String newS = generate(s);

            if (!map.containsKey(newS)) {
                map.put(newS, new ArrayList<>());
            }

            map.get(newS).add(s);
        }

        return new ArrayList<>(map.values());
    }
}
