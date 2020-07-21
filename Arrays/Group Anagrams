/*
  Company Tags  : Amazon(mutiple times), Google, Uber, Facebook, Bloomberg, Yahoo, Goldman Sachs, Microsoft, Apple, Walmart Labs, Twilio, Affirm
  Leetcode Link : https://leetcode.com/problems/group-anagrams/
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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;
        
        vector<int> vec(26);
        for(string str:strs) {
            for(int i = 0; i<26; i++)
                vec[i] = 0;
            for(char c: str)
                vec[c-'a']++;
            
            mp[vec].push_back(str);
        }
        
        vector<vector<string>> result;
        for(auto it : mp) {
            result.push_back(it.second);
        }
        
        return result;
    }
};
