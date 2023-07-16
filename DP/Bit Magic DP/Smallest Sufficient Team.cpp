/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=CAoBD84G2gI
      Company Tags                : AMAZON
      Leetcode Link               : https://leetcode.com/problems/smallest-sufficient-team/
*/

//Approach-1 (Storing mask in map for memoizing) - Recursion + Memoization
class Solution {
public:
    
    int m, n;
    int target_mask;
    vector<int> result;
    unordered_map<string , int > dp;
    
    void solve(vector<int> &people_skill , int idx , vector<int> &temp, int mask ) {
        
       if(idx == people_skill.size()) {
           if(mask == target_mask) {
               if(result.size() == 0 || result.size() >= temp.size()) {
                   result = temp;
               }
           }
           return;
       }
        
        string s = to_string(idx) + to_string(mask);
        
         if(dp.find(s) != dp.end()) {
           if(dp[s] <= temp.size())
               return ; 
        }
        
        if(result.size() != 0 && temp.size() >= result.size()) 
            return; 
        
        solve(people_skill , idx + 1 , temp , mask ); // no

         if( (mask | people_skill[idx]) != mask) { //Because a person's skill set can be empty. So we won't take them
            temp.push_back(idx);
            solve(people_skill, idx + 1, temp , mask | people_skill[idx]);

            temp.pop_back();
            dp[s] = (temp.size() != 0 ) ? temp.size() : -1;
        }
    }
    
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        n = req_skills.size();                                                                                          
        m = people.size();
        
        unordered_map<string, int> skills; //skill -> unique number
        for (int i = 0; i < n; ++i)
            skills[req_skills[i]] = i;
        
        // represent each person by a single bitmasked number (k'th bit represents if a person has the k'th skill or not)
        vector<int> people_skill;
        for (auto &v: people) {
            int skill_bit = 0;
            for (string &skill: v)
                skill_bit |= 1 << skills[skill];
            
            people_skill.push_back(skill_bit);
        }
        
        // required set of skills mask (All set to 1s)
        target_mask = pow(2, n) - 1;
        vector<int> temp;
        solve(people_skill, 0, temp, 0);
        return result;
    }
};

//Approach-2 (Using vector<vector<int>> instead of unordered_map to memoize)

class Solution {
public:
    
    int m, n;
    int target_mask;
    vector<int> result;
    vector<vector<int>> t;
    
    void solve(vector<int> &people , int idx , vector<int> &temp, int mask ) {
        
       if(idx == people.size()) {
           if(mask == target_mask) {
               if(result.size() == 0 || result.size() >= temp.size()) {
                   //vector<int> copy = temp;
                   result = temp;
               }
           }
           return;
       }
        
        if(t[idx][mask] != -1) {
            if(t[idx][mask] <= temp.size())
               return ; 
        }
        
        if(result.size() != 0 && temp.size() >= result.size()) 
            return; 
        
        solve(people , idx + 1 , temp , mask ); // no

        if( (mask | people[idx]) != mask) {
            temp.push_back(idx);
            solve(people, idx + 1, temp , mask | people[idx]);

            temp.pop_back();
            t[idx][mask] = (temp.size() != 0 ) ? temp.size() : -1;
        }

    }
    
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        n = req_skills.size();                                                                                          
        m = people.size();
        
        unordered_map<string, int> skills; //skill -> unique number
        for (int i = 0; i < n; ++i)
            skills[req_skills[i]] = i;
        
        // represent each person by a single bitmasked number (k'th bit represents if a person has the k'th skill or not)
        vector<int> people_skill;
        for (auto &v: people) {
            int skill_bit = 0;
            for (string &skill: v)
                skill_bit |= 1 << skills[skill];
            
            people_skill.push_back(skill_bit);
        }
        
        // required set of skills mask (All set to 1s)
        target_mask = pow(2, n) - 1;

        t.resize(62, vector<int>(target_mask+1, -1));
        vector<int> temp;
        solve(people_skill, 0, temp, 0);
        return result;
    }
};
