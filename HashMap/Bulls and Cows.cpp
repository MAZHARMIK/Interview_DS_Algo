/*
    Company Tags  : Google, Airbnb, Amazon
    Leetcode Link : https://leetcode.com/problems/bulls-and-cows/
*/

class Solution {
public:
    string getHint(string secret, string guess) {
        /*
            Best example to understand the approach
            secret = "1122"
            guess  = "1222"
        */
        
        int bulls = 0;
        int cows  = 0;
        unordered_map<char, int> count;
        
        //fill map
        for(char &x : secret)
            count[x]++;
        
        //Count BULLS (Which are in same position)
        for(int i = 0; i<guess.size(); i++) {
            if(guess[i] == secret[i]) {
                bulls++;
                count[secret[i]]--;
            }
        }
        
        //Count Cows : Which are "not in same position" but present in secret
        //Note : The check for "not in same position"  is required because
        //       it was already considered in calculating BULLS
        for(int i = 0; i<guess.size(); i++) {
            if(count[guess[i]] > 0 && guess[i] != secret[i]) {
                cows++;
                count[guess[i]]--;
            }
        }
        
        
        string result  = to_string(bulls) + "A" + to_string(cows) + "B" ;
        return result;
    }

};
