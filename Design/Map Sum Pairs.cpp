/*
    Company Tags  : Akuna Capital
    Leetcode Link : https://leetcode.com/problems/map-sum-pairs/
*/

//Approach-1 (Just do what's mentioned in the Qn) Time : n*m
//where, n = number of queries, m = maximum length of a query string
class MapSum {
public:
    unordered_map<string, int> mp;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        mp[key] = val;
    }
    
    int sum(string prefix) {
        int sum = 0;
        for(auto &it : mp) {
            if(it.first.find(prefix) == 0)
                sum += it.second;
        }
        return sum;
    }
};

//Approach-2 (Questions like these are always meant to be solved by "Tried" DS
/*
Time : Insertion in trie : O(n)
		  Sum                   : O(total length of all insertions) I traverse whole trie
*/
class MapSum {
public:
	/*****************************************START : Trie related functions*********************************************/
    struct trieNode{
        char ch;
        int val = 0;
        trieNode* children[26];
    };
    
    trieNode* getTrieNode(char ch) {
        trieNode* temp = new trieNode;
        temp->ch = ch;
        for(int i = 0; i<26; i++) temp->children[i] = NULL;
        return temp;
    }
    
    void insertNode(string key, int val) {
        trieNode* pCrawl = root;
        
        for(char &ch : key) {
            if(pCrawl->children[ch-'a'] == NULL)
                pCrawl->children[ch-'a'] = getTrieNode(ch);
            
            pCrawl = pCrawl->children[ch-'a'];
        }
        
        pCrawl->val = val;
    }
    
    int findSum(trieNode* pCrawl) {
        if(!pCrawl)
            return 0;
        
        int sum = pCrawl->val;
        for(int i = 0; i<26; i++) {
            sum += findSum(pCrawl->children[i]);
        }
        return sum;
    }
    /*****************************************END : Trie related functions******************************************/
	
    trieNode* root = NULL;
    MapSum() {
        root = getTrieNode('.');
    }
    
    void insert(string key, int val) {
        insertNode(key, val);
    }
    
    int sum(string prefix) {
        trieNode* pCrawl = root;
        for(char &ch : prefix) {
            if(pCrawl->children[ch-'a'] == NULL)
                return 0;
            pCrawl = pCrawl->children[ch-'a'];
        }
        
        return pCrawl == NULL ? 0 : findSum(pCrawl);
    }
};
