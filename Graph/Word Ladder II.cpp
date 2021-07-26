/*
    Company Tags  : Amazon, Yelp
    Leetcode Link : https://leetcode.com/problems/word-ladder-ii/
    
    I will be back with more and simpler approaches soon
*/

//Approach-1 (Using BFS and DFS) i.e. Using Concept of Word Ladder I
class Solution {
public:
    unordered_map<string, unordered_set<string>> adj;
    vector<vector<string>> result;
    
    void pushAdjacentWords(unordered_map<string, bool>& mp, unordered_map<string, int>& visited, queue<string>& que, string curr) {
        
        string temp  = curr;
        for(int i = 0; i<curr.length(); i++) {
            
            for(char ch = 'a'; ch <= 'z'; ch++) {
                if(temp[i] == ch) continue;
                
                temp[i] = ch;
                
                if(mp.find(temp) != end(mp) && temp != curr) {
                    if(visited.find(temp) == end(visited)) {
                        visited[temp] = visited[curr]+1;
                        que.push(temp);
                        adj[curr].insert(temp);
                    } else if (visited[temp] == visited[curr]+1) {
                        adj[curr].insert(temp);
                    }
                }
            }
            
            temp[i] = curr[i];
        }
        
    }
    
    void DFS(string currWord, string& endWord, vector<string>& path) {
        path.push_back(currWord);  //Push current word
        
        if(currWord == endWord) {
            result.push_back(path);
            path.pop_back();
            return;
        }
        
        for(auto &x : adj[currWord])
            DFS(x, endWord, path);
        
        path.pop_back();    //Pop current word to Backtrack
        
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        adj.clear();
        //First add words in a map for easy access
        unordered_map<string, bool> mp;
        unordered_map<string, int> visited;
        for(string& word : wordList) {
            mp[word] = 0; //means this word is not visited yet
        }
        
        //The endWord should be in the list
        if(mp.find(endWord) == mp.end()) return {};
        
        int level = 1; //beginWord is at level 1
        
        queue<string> que;
        que.push(beginWord);
        
        //Just do a BFS traversal
        while(!que.empty()) {
            int n = que.size();
            while(n--) {
                string curr = que.front();
                que.pop();
                if(curr == endWord)
                    break;
                pushAdjacentWords(mp, visited, que, curr);
            }
            level++;
        }
                
        //So here we have sortest path till endWord = level
        //We now do a DFS on our special adjacency list 
        //What's special ? the edge is always from a node to a node to next level
        vector<string> path;
        DFS(beginWord, endWord, path);
        return result;
    }
};
