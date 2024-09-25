/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/sum-of-prefix-scores-of-strings
*/


/************************************************************ C++ ************************************************/
//Approach - Using TRIE 
//T.C : O(n*l), n = number of words, l = average length of each word
//S.C : O(n*l), need to store all characters of words
struct trieNode {
    int countP = 0;
    trieNode* children[26];
};

class Solution {
public:

    trieNode* getTrieNode() {
        trieNode* newNode = new trieNode();
        for(int i = 0; i < 26; i++) {
            newNode->children[i] = nullptr;
        }
        newNode->countP = 0;
        return newNode;
    }

    void insert(string& word, trieNode* root) {
        trieNode* crawl = root;

        for(char &ch : word) {
            int idx = ch - 'a';

            if(!crawl->children[idx]) {
                crawl->children[idx] = getTrieNode();
            }

            crawl->children[idx]->countP += 1;
            crawl = crawl->children[idx];
        }
    }

    int getScore(string& word, trieNode* root) {
        trieNode* crawl = root; //"abc"
        int score = 0;

        for(char &ch : word) {
            int idx = ch - 'a';
            score += crawl->children[idx]->countP;

            crawl = crawl->children[idx]; // now i am at "b" wala node
        }

        return score;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();

        trieNode* root = getTrieNode();
        for(string &word : words) {
            insert(word, root);
        }

        vector<int> result(n);
        //result[i] = sum of scores of prefixes of words[i]
        for(int i = 0; i < n; i++) {
            result[i] = getScore(words[i], root);
        }

        return result;
    }
};



/************************************************************ JAVA *****************************************************/
//Approach - Using TRIE 
//T.C : O(n*l), n = number of words, l = average length of each word
//S.C : O(n*l), need to store all characters of words
class Solution {
    
    // TrieNode class equivalent to struct trieNode in C++
    class TrieNode {
        int countP = 0; // stores the number of prefixes ending here
        TrieNode[] children = new TrieNode[26]; // array to store children

        // Constructor to initialize a new TrieNode
        public TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = null;
            }
            countP = 0;
        }
    }

    // Function to create a new TrieNode (Not needed separately in Java)
    private TrieNode getTrieNode() {
        return new TrieNode(); 
    }

    // Function to insert a word into the Trie
    private void insert(String word, TrieNode root) {
        TrieNode crawl = root;
        
        for (char ch : word.toCharArray()) {
            int idx = ch - 'a';
            
            if (crawl.children[idx] == null) {
                crawl.children[idx] = getTrieNode();
            }
            
            crawl.children[idx].countP += 1;
            crawl = crawl.children[idx];
        }
    }

    // Function to get the score for the word (sum of scores for all prefixes)
    private int getScore(String word, TrieNode root) {
        TrieNode crawl = root;
        int score = 0;

        for (char ch : word.toCharArray()) {
            int idx = ch - 'a';
            score += crawl.children[idx].countP;
            crawl = crawl.children[idx];
        }

        return score;
    }

    // Main function to return the sum of prefix scores for each word
    public int[] sumPrefixScores(String[] words) {
        int n = words.length;
        TrieNode root = getTrieNode();

        // Insert all words into the Trie
        for (String word : words) {
            insert(word, root);
        }

        // Array to store the result (sum of prefix scores for each word)
        int[] result = new int[n];

        // Calculate the sum of prefix scores for each word
        for (int i = 0; i < n; i++) {
            result[i] = getScore(words[i], root);
        }

        return result;
    }
}
