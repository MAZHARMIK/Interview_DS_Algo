/*
    Company Tags  : Amazon
    Leetcode Link : https://leetcode.com/problems/verifying-an-alien-dictionary/
*/

//Approach-1 (O(n*l)
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> vec(26, 0);
        int idx = 0;
        for(char ch:order) {
            vec[ch-'a'] = idx++;
        }
        
        
        int n = words.size();
        for(int i = 0; i<n-1; i++) {
            string word1 = words[i];
            int    n1    = word1.length();
            string word2 = words[i+1];
            int    n2    = word2.length();
            
            for(int j = 0; j<n1; j++) {
                //for case like "apple", "app"
                if(j >= n2)
                    return false;
                
                if(word1[j] != word2[j]) {
                    if(vec[word1[j]-'a'] > vec[word2[j]-'a'])
                        return false;
                    else
                        break;
                        //if two diff characters are sorted then no need to check further break
                }
            }
            
        }
        return true;        
    }
};

//Approach-2 (O(n*l) - smarter approach
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        int count[26] = {0};
        
        for(int i = 0; i<26; i++)
            count[order[i]-'a'] = i;
        
        for(string &word : words) {
            for(char &ch : word)
                ch = count[ch-'a'];
        }
        
        return is_sorted(begin(words), end(words));
    }
};

//Approach-3 (Using comparator : just for the sake of practice)
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> count(26, 0);
        int idx = 0;
        for(char &x : order)
            count[x-'a'] = idx++;
        
        auto lambda = [&](string &s1, string &s2) {
            int n = s1.length();
            for(int i = 0; i<n; i++) {
                if(i >= s2.length())
                    return false;
                
                if(s1[i] != s2[i]) {
                    if(count[s1[i]-'a'] > count[s2[i]-'a'])
                        return false;
                    else if(count[s1[i]-'a'] < count[s2[i]-'a'])
                        return true;
                }
                
            }

            return true;
        };

        vector<string> clone = words;
        sort(begin(clone), end(clone), lambda);

        return clone==words;
    }
};
