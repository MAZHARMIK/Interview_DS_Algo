/*
    Company Tags  : Google
    Leetcode Link : https://leetcode.com/problems/maximum-product-of-word-lengths/
*/

//Approach-1 (Simple as per the question) Time : O(n^2)
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int maxP = 0;
        
        bool nocommon = true;
        for(int i = 0; i<n-1; i++) {
            for(int j = i+1; j<n; j++) {
                string s1 = words[i];
                string s2 = words[j];
                
                int n1    = s1.length();
                int n2    = s2.length();
                
                nocommon = true;
                
                if(n1*n2 > maxP) {
                    vector<int> count(26, 0);
                    for(const char &ch:s2) {
                        count[ch-'a']++;
                    }
                    for(const char& ch : s1) {
                        if(count[ch-'a'] != 0) {
                            nocommon = false;
                            break;
                        }
                    }
                    if(nocommon)
                        maxP = n1*n2;
                }
            }
        }
        
        return maxP;
    }
};

//Approach-2
