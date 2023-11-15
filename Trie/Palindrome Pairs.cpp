/*
    Company Tags  : Airbnb
    Leetcode Link : https://leetcode.com/problems/palindrome-pairs/
*/

//Another approach using map is present in map section. Link : https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/HashMap/Palindrome%20Pairs.cpp

//This approach is using trie
//Time complexity : O(n * k^2), where we traverse n words and then search k length (average length of word in trie) and verify if they are palindrome as well which takes k time.
class Solution {
public:
    vector<vector<int>> result;
    struct trieNode{
        int wordIndex;
        vector<int> restIsPalList;
        trieNode* children[26];
    };
    
    trieNode* getNode() {
        trieNode* temp  = new trieNode();
        temp->wordIndex = -1;
        for(int i = 0; i<26; i++) {
            temp->children[i] = NULL;
        }
        return temp;
    }
    
    void addNode(trieNode* root, string& key, int index) {
        trieNode* pCrawl = root;
        for(int i = key.length()-1; i>=0;  i--) {
            int idx = key[i] - 'a';
            
            if(isPalindrome(key, 0, i)) {
                pCrawl->restIsPalList.push_back(index);
            }
            
            if(pCrawl->children[idx] == NULL) {
                pCrawl->children[idx] = getNode();
            }
            
            pCrawl = pCrawl->children[idx];
        }
        
        pCrawl->wordIndex = index;
    }
    
    bool isPalindrome(string & key, int i, int j) {
        while(i < j) {
            if(key[i] != key[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    void search(trieNode* root, string &key, int index) {
        trieNode* pCrawl = root;
        
        for(int i = 0; i < key.length(); i++) {
            int idx = key[i]-'a';
            
            //example : xyzll zyx
            if(pCrawl->wordIndex != -1 && isPalindrome(key, i, key.length()-1)) {
                result.push_back({index, pCrawl->wordIndex});
            }
            
            if(pCrawl->children[idx] == NULL)
                return;
            
            pCrawl = pCrawl->children[idx];
            
        }
        
        //example : abcd dcba
        if(pCrawl->wordIndex != -1 && pCrawl->wordIndex != index) {
            result.push_back({index, pCrawl->wordIndex});
        }
        
        //example : zyx llxyz
        
        for(int j : pCrawl->restIsPalList) {
            result.push_back({index, j});
        }
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        result.clear();
        trieNode* root = getNode();
        int n = words.size();
        
        for(int i = 0; i<n; i++) {
            addNode(root, words[i], i);
        }
        
        for(int i = 0; i<n; i++) {
            search(root, words[i], i);
        }
        
        return result;
    }
};
