/*
    Company Tags  : Airbnb
    Leetcode Link : https://leetcode.com/problems/palindrome-pairs/
*/

//NOTE: This approach will TLE now due to new test cases. So, trie is the accepted approach.

//Another approach using trie is present in trie section : Link : https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Trie/Palindrome%20Pairs.cpp

//This approach is using hashmap
//Time : O(n * k^2), where is k = average length of each word
class Solution {
public:
    vector<vector<int>> result;
    bool isPalindrome(string &key) {
        int i = 0, j = key.length()-1;
        
        while(i < j) {
            if(key[i] != key[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        result.clear();
        
        unordered_map<string, int> mp;
        int n = words.size();
        
        for(int i = 0; i<n; i++) {
            mp[words[i]] = i;
        }
        
        //case-1 Check for empty string 0 <= words[i].length <= 300
        if(mp.find("") != mp.end()) {
            int emptyIndex = mp[""];
            
            for(int i = 0; i<n; i++) {
                if(i != emptyIndex && isPalindrome(words[i])) {
                    result.push_back({emptyIndex, i});
                    result.push_back({i, emptyIndex});
                }
            }
        }
        
        //case-2 Look for mirror words . example : ["abcd", "dcba"];
        for(int i = 0; i<n; i++) {
            string word      = words[i];
            reverse(begin(word), end(word));
            
            if(mp.find(word) != mp.end() && mp[word] != i) { //be careful for cases like "aa" whose reverse is "aa" itself
                result.push_back({i, mp[word]});
                
            }
        }
        
        /*
            case-3
            3.1 : When left half is a pallindrome and reverse of right half is present in map.
                  Example : ["abaxy", "yx"] -> "yx" + "abaxy" = "yxabaxy" is a palindrome
        
            3.2 : When right half is a pallindrome and reverse of left half is present in map.
                  Example : ["xyaba", "yx"] -> "xyaba" + "yx" = "xyabayx" is a palindrome
        */
        
        for(int i = 0; i<n; i++) {
            string word = words[i];
            
            //cut into left hald and right half
            for(int cut = 1; cut<word.length(); cut++) {
                string leftHalf         = word.substr(0, cut);
                string rightHalf        = word.substr(cut);
                
                string reverseLeftHalf  = leftHalf;
                reverse(begin(reverseLeftHalf), end(reverseLeftHalf));
                
                string reverseRightHalf  = rightHalf;
                reverse(begin(reverseRightHalf), end(reverseRightHalf));
                
                if(isPalindrome(leftHalf) && mp.find(reverseRightHalf) != mp.end()) {
                    result.push_back({mp[reverseRightHalf], i});
                }
                
                if(isPalindrome(rightHalf) && mp.find(reverseLeftHalf) != mp.end()) {
                    result.push_back({i, mp[reverseLeftHalf]});
                }
            }
        }
        
        return result;
    }
};
