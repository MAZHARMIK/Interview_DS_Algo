/*
    Company Tags : Google, Amazon, SAP Labs
    Qn Link      : https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1#
    
    Alternative question (Asked in an interview) :
    John goes to mall with his mom. He sees that there many toys. He insists his mom to buy him toys.
    His mom told him ok fine, you can pick the toys but in two conditions :
    1) You can pick toys in line (you can't skip any toy in between) (Hint: She is asking for a subarray)
    2) You can have only two types of toys.
    
    Find maximum number of toys that can be picked up by John.
    
    So this question is nothing but : "Find the length of longest subarray/substring having k unique characters"
    
*/

//It's a Classical sliding window problem
//We traverse the string two times with i and j pointer in worst case. Time : o(n+n) = O(n)
class Solution{
    public:
    int longestKSubstr(string s, int k) {
        int n = s.length();
        int i = 0, j = 0;
        unordered_map<char, int> mp;
        int maxLen = -1;
        while(j < n) {
            mp[s[j]]++;
  
            if(mp.size() == k) {
                maxLen = max(maxLen, j-i+1);
            } else if(mp.size() > k) {
                while(mp.size() > k) {
                    mp[s[i]]--;
                    if(mp[s[i]] <= 0)
                        mp.erase(s[i]);
                    i++;
                }
            }
            j++;
        }
        return maxLen;
    }
};
