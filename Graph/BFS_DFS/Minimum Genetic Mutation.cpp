/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=H3kSFSv-t30
    Company Tags                : Twitter
    Leetcode Link               : https://leetcode.com/problems/minimum-genetic-mutation/
*/

//Just like Word Ladder
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bankset(bank.begin(), bank.end());
        
        unordered_set<string> visited;
        queue<string> que;
        que.push(start);
        visited.insert(start);
        
        int level = 0;
        
        while(!que.empty()) {
            int n = que.size();
            
            while(n--) {
                string curr = que.front();
                que.pop();
                
                if(curr ==  end)
                    return level;
                
                for(char ch : "ACGT") {
                    for(int i = 0; i<curr.length(); i++) {
                        string neighbour = curr;
                        neighbour[i] = ch;
                        
                        if(visited.find(neighbour) == visited.end() && 
                           bankset.find(neighbour) != bankset.end()) {
                            visited.insert(neighbour);
                            que.push(neighbour);
                        }
                    }
                }
            }
            level++;
        }
        
        return -1;
    }
};
