/*
    MY YOUTUBE VIDEO ON THIS Qn : Brute Force - https://www.youtube.com/watch?v=r3lOL6srx1E
                                  Optimal - <soon>
    Company Tags                : Meta
    Leetcode Link               : https://leetcode.com/problems/dota2-senate/
*/

//Approach-1 (Brute Force) - ACCEPTED
class Solution {
public:

    bool removeSenator(string &senate, char ch, int idx) {
        bool loopAround = false;
        
        while(true) {
            
            if(idx == 0) {
                loopAround = true;
            }
            
            if(senate[idx] == ch) {
                senate.erase(begin(senate) + idx);
                break;
            }
            
            idx = (idx+1)%(senate.length());
            
        }
        
        return loopAround;
    }
    
    string predictPartyVictory(string senate) {
        
        int R_Count = count(begin(senate), end(senate), 'R');
        int D_Count = senate.length() - R_Count;
        
        
        int idx = 0;
        
        while(R_Count > 0 && D_Count > 0) {
            
            if(senate[idx] == 'R') {
                bool checkRemoval = removeSenator(senate, 'D', (idx+1)%(senate.length()));
                D_Count--;
                if(checkRemoval) {
                    idx--;
                }
            } else {
                bool checkRemoval = removeSenator(senate, 'R', (idx+1)%(senate.length()));
                R_Count--;
                if(checkRemoval) {
                    idx--;
                }
            }
            
            idx = (idx+1)%(senate.length());
            
        }
        
        return R_Count == 0 ? "Dire" : "Radiant";
        
    }
};


//Approach-2 (Improved Brute Force)
class Solution {
public:
    int n;
    void removeSenator(string &senate, vector<bool>& removed, char ch, int idx) {
        
        while(true) {
            
            if(senate[idx] == ch && removed[idx] == false) {
                removed[idx] = true;
                break;
            }
            idx = (idx+1)%n;
        }

    }
    
    string predictPartyVictory(string senate) {
        
        n = senate.length();
        
        int R_Count = count(begin(senate), end(senate), 'R');
        int D_Count = n - R_Count;
        
        int idx = 0;
        
        //Initially no one removed
        vector<bool> removed(n, false);
        
        while(R_Count > 0 && D_Count > 0) {
            
            if(!removed[idx]) {
            
                if(senate[idx] == 'R') {
                    removeSenator(senate, removed, 'D', (idx+1)%n);
                    D_Count--;
                    
                } else {
                    removeSenator(senate, removed, 'R', (idx+1)%n);
                    R_Count--;

                }
            }
            idx = (idx+1)%n;
            
        }
        
        return R_Count == 0 ? "Dire" : "Radiant";
        
    }
};


//Approach-3 (Using 2 Queues)
class Solution {
public:
    string predictPartyVictory(string senate) {
        
        int n = senate.length();
        
        queue<int> queR;
        queue<int> queD;
        
        for(int i = 0; i<n; i++) {
            if(senate[i] == 'R')
                queR.push(i);
            else
                queD.push(i);
        }
        
        while(!queR.empty() && !queD.empty()) {
            
            int R_idx = queR.front(); queR.pop();
            int D_idx = queD.front(); queD.pop();
            
            if(R_idx < D_idx) {
                queR.push(R_idx+n);
                //Why +n ?
                //Do this dry run on "RDD"
            } else {
                queD.push(D_idx+n);
                //Why +n ?
                //Do this dry run on "RDD"
            }
            
        }
        
        return queR.empty() ? "Dire" : "Radiant";
        
    }
};

//Approach-4 (Using Single Queue)
//soon
