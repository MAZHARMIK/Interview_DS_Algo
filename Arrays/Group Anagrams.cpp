/*
  MY YOUTUBE VIDEO ON THIS Qn : Using Sortng     - https://www.youtube.com/watch?v=--k5-3EOObs&t=2s
                                Without Sorting  - https://www.youtube.com/watch?v=TNe3gF4r128&t=1s
  Company Tags                : Amazon(mutiple times), Google, Uber, Facebook, Bloomberg, Yahoo, Goldman Sachs, Microsoft, Apple, Walmart Labs, 
                                Twilio, Affirm
  Leetcode Link               : https://leetcode.com/problems/group-anagrams/
  GfG Link                    : https://practice.geeksforgeeks.org/problems/print-anagrams-together/1
*/


/*
Approach-1
Time : O(n*klog(k))  (n = size of input, k = maximum length of a string in the input vector)
*/
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


/*
Approach-2
Time : O(n*k)  (n = size of input, k = maximum length of a string in the input vector)
*/
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
