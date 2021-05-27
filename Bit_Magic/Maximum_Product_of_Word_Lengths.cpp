/*
    Company Tags  : Google
    Leetcode Link : https://leetcode.com/problems/maximum-product-of-word-lengths/
*/

//Approach-1 (Without Bit magic)
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

//Approach-2 (With Bit magic)
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int maxP = 0;
        int n = words.size();
        vector<int> numeric(n, 0);
        /*
            a = 100000....  
            b = 010000....
            c = 001000....
            We are shifting 1 to left by character times
            This way we will get value for every word.
            Example : "abc"
            int numericValue = 100000....  |  010000.... | 001000....
            will be assigned to "abc"
            Those having same numeric value will result in 000000 when we do & between them
        */
        
        int k = 0;
        for(const string& word : words) {
            int numericValue = 0;
            
            for(const char& ch : word) {
                int val = ch-'a';
                //now left shift and add
                
                numericValue |= (1<<val);
            }
            numeric[k++] = numericValue; //numeric value of words[i]
        }
        
        //Now, do & operation to find which words have no common letters
        for(int i = 0; i<n-1; i++) {
            for(int j = i+1; j<n; j++) {
                if((numeric[i] & numeric[j]) == 0) { //means nothing common
                    int l1 = words[i].length();
                    int l2 = words[j].length();
                    maxP = max(maxP, l1*l2);
                }
            }
        }
        
        return maxP;
    }
};
