/*
    Company Tags  : Microsoft, Amazon
    Leetcode Link : https://leetcode.com/problems/word-ladder/
*/
class Solution {
public:
    void pushAdjacentWords(unordered_map<string, bool>& mp, queue<string>& que, string curr) {
        int n = curr.length();
        for(int i = 0; i<n; i++) {
            char temp = curr[i];
            //check for all letters at index i
            for(char ch = 'a'; ch<='z'; ch++) {
                curr[i] = ch;
                if(mp.find(curr) != mp.end() && mp[curr] ==  false) {//not visited
                    mp[curr] = true; //mark visited   
                    que.push(curr);
                }
            }
            curr[i] = temp;
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(wordList.size() == 0)
            return 0;
        //First add words in a map for easy access
        unordered_map<string, bool> mp;
        
        for(string& word : wordList) {
            mp[word] = false; //means this word is not visited yet
        }
        
        //The endWord should be in the list
        if(mp.find(endWord) == mp.end())
            return 0;
        
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
                    return level;
                pushAdjacentWords(mp, que, curr);
            }
            level++;
        }
        
        //we never found the end word
        return 0;
    }
};
