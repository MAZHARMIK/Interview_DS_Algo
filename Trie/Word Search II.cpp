/*
    MY YOUTUBE VIDE ON THIS Qn  : https://www.youtube.com/watch?v=DMP2bqW6URA
    Company Tags                : Google, Amazon, Facebook (Meta), Microsoft, Salesforce, Directi, MakeMyTrip, Nvidia, Yahoo
    Leetcode Qn Link            : https://leetcode.com/problems/word-search-ii/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/72cf44eabd18006810efad06fbb623a0682acee2/1
*/

//Approach-1 (Using string in struct)
class Solution {
public:
    vector<string> result;
    int r, c;
    vector<pair<int, int>> directions{{-1, 0},{1, 0},{0, 1},{0, -1}};
    struct trieNode {
        bool endOfWord;
        trieNode* children[26];
        string word;
    };

    trieNode* getNode() {
        trieNode* temp = new trieNode();
        temp->endOfWord = false;
        for(int i = 0; i<26; i++) {
            temp->children[i] = NULL;
        }
        temp->word = "";
        return temp;
    }

    void insert(trieNode* root, string str) {
        trieNode* pCrawl = root;
        for(char ch:str) {
            if(pCrawl->children[ch-'a'] == NULL) {
                pCrawl->children[ch-'a'] = getNode();
            }
            pCrawl = pCrawl->children[ch-'a'];
        }
        pCrawl->endOfWord = true;
        pCrawl->word = str;
    }

    void DFS(vector<vector<char>>& board, int i, int j, trieNode* root) {
        if(i<0 || i >= r || j<0 || j >= c || board[i][j] == '$' || root->children[board[i][j]- 'a'] == NULL) {
            return;
        }
        root = root->children[board[i][j]- 'a'];
        if(root->endOfWord == true) {
            result.push_back(root->word);
            root->endOfWord = false;
        }
        char temp     = board[i][j];
        
        board[i][j] = '$';
        for(pair<int, int> p:directions) {
            int new_i = i+p.first;
            int new_j = j+p.second;
            DFS(board, new_i, new_j, root);
        }
        board[i][j] = temp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        r = board.size();
        c = board[0].size();

        trieNode* root = getNode();
        for(string str:words) {
            insert(root, str);
        }

        for(int i = 0; i<r; i++) {
            for(int j = 0; j<c; j++) {
                char ch = board[i][j];
                if(root->children[ch-'a'] != NULL) {
                    DFS(board, i, j, root);
                }
            }
        }
        return result;
    }
};


//Approach-2 (Using char in struct)
class Solution {
public:
    vector<string> result;
    int m, n;
    
    struct trieNode {
        bool endOfWord;
        char ch;
        trieNode* children[26];
    };
    
    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->endOfWord = false;
        for(int i = 0; i<26; i++) {
            newNode->children[i] = NULL;
        }
        
        newNode->ch = ' ';
        return newNode;
    }
    
    void insert(trieNode* root, string &word) {
        trieNode* pCrawl = root;
        
        for(int i = 0; i<word.length(); i++) {
            char ch = word[i];
            int idx = ch-'a';
            
            if(pCrawl->children[idx] == NULL) {
                pCrawl->children[idx] = getNode();
                pCrawl->children[idx]->ch = ch;
            }
            
            pCrawl = pCrawl->children[idx];
        }
        
        pCrawl->endOfWord = true;
    }
    
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void findWords(vector<vector<char>>& board, int i, int j, trieNode* root, string s) {
        if(i < 0 || i >= m || j < 0 || j >= n)
            return;
        
        char ch = board[i][j];
        int idx = ch-'a';
        if(board[i][j] == '$' || root->children[idx] == NULL)
            return;
        
        root = root->children[idx];
        s.push_back(ch);
        if(root->endOfWord == true) {
            result.push_back(s);
            root->endOfWord = false;
        }
        
        char temp = board[i][j];
        board[i][j] = '$';
        for(vector<int>& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            
            findWords(board, new_i, new_j, root, s);
        }
        board[i][j] = temp;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        
        trieNode* root = getNode();
        
        for(string &word : words) {
            insert(root, word);
        }
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                char ch = board[i][j];
                int idx = ch-'a';
                string s = "";
                if(root->children[idx] != NULL)
                    findWords(board, i, j, root,s);
            }
        }
        
        return result;
    }
};
