/*
      MY YOUTUBE VIDEO ON THIS Qn :  
      Company Tags                : GOOGLE
      Leetcode Link               : https://leetcode.com/problems/text-justification/
*/

//T.C : O(n*k)
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;
        
        while(i < n) {
            int lettersCount = words[i].length();
            int j            = i+1;
            int spaceSlots   = 0;
            
            while(j < n && spaceSlots + lettersCount + words[j].length() + 1 <= maxWidth) {
                lettersCount += words[j].length();
                spaceSlots   += 1;
                j++;
            }
            
            int remainingSlots = maxWidth - lettersCount;
            
            
            int eachWordSpace = spaceSlots == 0 ? 0 : remainingSlots / spaceSlots;
            int extraSpace    = spaceSlots == 0 ? 0 : remainingSlots % spaceSlots;
            
            if(j == n) { //Means we are on last line - Left justfied
                eachWordSpace = 1;
                extraSpace    = 0;
            }
            
            string s;
            
            for(int k = i; k < j; k++) {
                s += words[k];
                
                if(k == j-1)
                    continue;
                
                for(int space = 1; space <= eachWordSpace; space++)
                    s += " ";
                
                if(extraSpace > 0) {
                    s += " ";
                    extraSpace--;
                }
            }
            
            while(s.length() < maxWidth) {
                s += " ";
            }
            
            result.push_back(s);
            i = j;
        }
        
        return result;
    }
};
