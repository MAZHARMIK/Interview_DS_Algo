/*
    Company Tags  : Amazon, Google (Small variation)
    Leetcode Link : Search Suggestions System
*/

//Approach - 1 (First solution that comes in our mind : Using TRIE Data Structure)
class Solution {
public:
    struct trieNode {
        char ch;
        bool end;
        trieNode* children[26] = {NULL};
    };
    
    trieNode* getNode(char ch) {
        trieNode* temp = new trieNode();
        temp->end      = false;
        temp->ch       = ch;
        return temp;
    }
    
    void insert(trieNode* root, string key) {
        trieNode* pCrawl = root;
        
        for(char &ch : key) {
            int idx = ch-'a';
            
            if(pCrawl->children[idx] == NULL) {
                pCrawl->children[idx] = getNode(ch);
            }
            
            pCrawl = pCrawl->children[idx];
        }
        
        pCrawl->end = true;
    }
    
    void getWord(trieNode* pCrawl, string temp, vector<string>& result) {
        if(result.size() == 3)
            return;
        
        if(pCrawl->end) {
            result.push_back(temp);
        }
        
        for(char ch = 'a'; ch<='z'; ch++) {
            trieNode* nextNode = pCrawl->children[ch-'a'];
            if(nextNode) {
                temp.push_back(ch);
                getWord(nextNode, temp, result);
                temp.pop_back();
            }
        }
            
    }
    
    vector<string> search(trieNode* root, string key) {
        trieNode* pCrawl = root;
        vector<string> result;
        for(char &ch : key) {
            int idx = ch-'a';
            if(!pCrawl->children[idx]) {
                return result;
            }
            pCrawl = pCrawl->children[idx];
        }
        
        getWord(pCrawl, key, result);
        
        return result;
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        trieNode* root = getNode('.');
        for(string &product : products) {
            insert(root, product);
        }
        
        vector<vector<string>> result;
        int n = searchWord.length();
        
        string prefix = "";
        for(int i = 0; i<n; i++) {
            prefix.push_back(searchWord[i]);
            result.push_back(search(root, prefix));
        }
        
        return result;
    }
};

//Approach-2 (Since, contraints are low, you can apply Binary Search (Lower bound))
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> result;
        int n = products.size();
        sort(begin(products), end(products));
        
        string prefix = "";
        int index = 0;
        for(char &ch : searchWord) {
            prefix.push_back(ch);
            
            int start = lower_bound(products.begin() + index, end(products), prefix) - begin(products);
            /*
                NOTE : lower bound returns element which is equal to or greater than the
                       search key(prefix here)
            */
            
            result.push_back({});
            
            for(int i = start; i<min(start+3, n); i++) {
                if(products[i].find(prefix) < n) {
                    result.back().push_back(products[i]);
                }
            }
            
            index = start;
        }
        
        return result;
    }
};
