/*
    Company Tags  : Google, Facebook, Amazon
    Frequency     : 60%
    Leetcode Link : https://leetcode.com/problems/expression-add-operators/
*/

class Solution {
public:
    vector<string> result;
    int target;
    string s;
    
    void solve(int i, const string& path, long prev, long prevNum) {
        if(i == s.length()) {
            if(prev == target) {
                result.push_back(path);
            }
            return;
        }
        
        string numStr;
        long num = 0;
        for(int j = i; j<s.length(); j++) {
            if(j > i && s[i] == '0') break;
            
            numStr += s[j];
            num     = num*10 + s[j]-'0';
            
            if(i == 0) {
                solve(j+1, path+numStr, num, num);
            } else {
                solve(j+1, path + "+" + numStr, prev+num, num);
                
                solve(j+1, path + "-" + numStr, prev-num, -num);

                solve(j+1, path + "*" + numStr, prev-prevNum + prevNum * num, prevNum*num);
            }
        }
    }
    
    vector<string> addOperators(string s, int target) {
        result = {};
        this->target = target;
        this->s    = s;
        
        solve(0, "", 0, 0);
        
        return result;
    }
};
