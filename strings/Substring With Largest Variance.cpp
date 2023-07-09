/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=M428--94ny0
    Company Tags                : AMAZON, GOOGLE
    Leetcode Link               : https://leetcode.com/problems/substring-with-largest-variance/

*/

//Approach-1 (Brute Force)
/*
  Find all substrings
  Find max freq and min freq of chars
  result = max(result, max_freq - min_freq)
*/


//Approach-2 (26*26*n)
class Solution {
public:
    int largestVariance(string s) {
        vector<int> count(26, 0);
        
        for(char &ch : s) {
            count[ch-'a']++;
        }
        
        int result = 0;

        for (char first = 'a'; first <= 'z'; ++first) {

            for (char second = 'a'; second <= 'z'; ++second) {

                if (count[first-'a'] == 0 || count[second-'a'] == 0) 
                    continue;

                int firstCount = 0;
                int secondCount = 0;
                bool pastLowFreq = false;

                for (const char& ch : s) {
                    if (ch == first) ++firstCount;
                    if (ch == second) ++secondCount;

                    if (secondCount > 0) {
                        result = max(result, firstCount - secondCount);
                    } else {
                        if (pastLowFreq) {
                            result = max(result, firstCount - 1);
                        }
                    } 

                    if (secondCount > firstCount) {
                        secondCount = 0;
                        firstCount = 0;
                        pastLowFreq = true;
                    }
                }
            }
        }
        return result;
    }
};
