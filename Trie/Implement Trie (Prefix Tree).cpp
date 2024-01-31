/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=YXefcFMpemo
    Company Tags                : Microsoft
    Leetcode Link               : https://leetcode.com/problems/implement-trie-prefix-tree/
*/


/**************************************************** C++ ****************************************************/
/*
the time complexity for insertion, search, and prefix search is O(L), and the space complexity is O(N), 
where L is the length of words or prefixes and N is the total number of characters in all words.
*/
class Trie {
public:
    
    struct trieNode { 
        trieNode *children[26]; 
        bool isEndOfWord; 
    };
    
    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->isEndOfWord = false;
        
        for (int i = 0; i < 26; i++) {
			newNode->children[i] = NULL;
		}
        
        return newNode;
    }
    
    /** Initialize your data structure here. */
    trieNode* root;
    
    Trie() {
        root = getNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        trieNode *crawler = root; 
        
        for (int i = 0; i < word.length(); i++) { 
            int index = word[i] - 'a'; 
            if (!crawler->children[index]) 
                crawler->children[index] = getNode();
            
            crawler = crawler->children[index]; 
        }
        
        crawler->isEndOfWord = true; 
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        trieNode *crawler = root; 
        
        for (int i = 0; i < word.length(); i++) { 
            int index = word[i] - 'a'; 
            if (!crawler->children[index]) 
                return false; 
            crawler = crawler->children[index]; 
        }
        return (crawler != NULL && crawler->isEndOfWord); 
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        trieNode *crawler = root;
        int i = 0;
        for (i = 0; i < prefix.length(); i++) { 
            int index = prefix[i] - 'a'; 
            
            if (!crawler->children[index]) 
                return false; 
            
            crawler = crawler->children[index]; 
        }
        if(i==prefix.length())
            return true;
        return false;
    }
};


/**************************************************** JAVA ****************************************************/
/*
the time complexity for insertion, search, and prefix search is O(L), and the space complexity is O(N), 
where L is the length of words or prefixes and N is the total number of characters in all words.
*/
class Trie {
    static class TrieNode {
        TrieNode[] children;
        boolean isEndOfWord;

        TrieNode() {
            children = new TrieNode[26];
            isEndOfWord = false;
        }
    }

    private TrieNode root;

    Trie() {
        root = new TrieNode();
    }

    private TrieNode getNode() {
        return new TrieNode();
    }

    public void insert(String word) {
        TrieNode crawler = root;

        for (int i = 0; i < word.length(); i++) {
            int index = word.charAt(i) - 'a';
            if (crawler.children[index] == null)
                crawler.children[index] = getNode();

            crawler = crawler.children[index];
        }

        crawler.isEndOfWord = true;
    }

    public boolean search(String word) {
        TrieNode crawler = root;

        for (int i = 0; i < word.length(); i++) {
            int index = word.charAt(i) - 'a';
            if (crawler.children[index] == null)
                return false;
            crawler = crawler.children[index];
        }
        return crawler != null && crawler.isEndOfWord;
    }

    public boolean startsWith(String prefix) {
        TrieNode crawler = root;
        int i = 0;
        for (i = 0; i < prefix.length(); i++) {
            int index = prefix.charAt(i) - 'a';

            if (crawler.children[index] == null)
                return false;

            crawler = crawler.children[index];
        }
        return i == prefix.length();
    }
}
