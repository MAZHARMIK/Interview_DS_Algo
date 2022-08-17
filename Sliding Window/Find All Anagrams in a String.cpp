/*
    Company Tags  : Microsoft, Google, Amazon
    Leetcode Link : https://leetcode.com/problems/find-all-anagrams-in-a-string/
*/

//Similar to normal sliding window qns
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> arr(26, 0);
        
        int m = s.length();
        int n = p.length();
        
        for(char &ch : p)
            arr[ch-'a']++;
        
        int i = 0, j = 0;
        vector<int> result;
        
        while(j < m) {
            arr[s[j] - 'a']--;
            
            if(j-i+1 == n) {
                if(arr == vector<int>(26, 0)) {
                    result.push_back(i);
                }
                
                arr[s[i]-'a']++;
                i++;
            }
            j++;
        }
        
        return result;
    }
};
