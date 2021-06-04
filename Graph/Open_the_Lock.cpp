/*
    Also popular as  : Minimum rotations to unlock a circular lock
    Similar Question : Word Ladder ( Microsoft, Amazon ) : https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Word_Ladder.cpp
    Company Tags     : Let me know when you find it
    Leetcode Link    : https://leetcode.com/problems/open-the-lock/
*/

class Solution {
public:
    void fillNeighbors(queue<string>& que, string& curr, set<string>& dead) {
        for(int i = 0; i<4; i++) {
            char ch  = curr[i];

            char dec = ch=='0' ? '9' : ch-1;
            char inc = ch=='9' ? '0' : ch+1;

            curr[i]  = dec;
            if(!dead.count(curr) && !dead.count(curr)) {
                dead.insert(curr);
                que.push(curr);
            }

            curr[i] = inc;
            if(!dead.count(curr) && !dead.count(curr)) {
                dead.insert(curr);
                que.push(curr);
            }

            curr[i] = ch;
        }
    }
    int openLock(vector<string>& deadends, string target) {
        set<string> dead(begin(deadends), end(deadends));
        
        string start = "0000";        
        if(dead.count(start))
            return -1;
        
        queue<string> que;
        que.push(start);
        
        int level = 0;
        while(!que.empty()) {
            int n = que.size();
            
            while(n--) {
                string curr = que.front();
                que.pop();
                if(curr == target)
                    return level;
                
                fillNeighbors(que, curr, dead);
            }
            level++;
        }
        return -1;
    }
};
