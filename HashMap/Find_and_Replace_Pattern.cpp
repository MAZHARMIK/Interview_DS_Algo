/*
	Company Tags  : Google, Amazon, Goldman Sachs, Microsoft, MakeMyTrip
	Leetcode Link : https://leetcode.com/problems/find-and-replace-pattern/
*/

//Approach-1 (Two maps)
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<char, char> wp; //word to pattern
        unordered_map<char, char> pw; //pattern to word
        vector<string> result;
        
        for(const string& word:words) {
            int i = 0;
            int n = word.length();
            wp.clear();
            pw.clear();
            //Example : word = "ccc", pattern = "abb"
            for(; i<n; i++) {
                char w = word[i];     //c
                char p = pattern[i];  //a
                
				/*
				If curren char has been mapped already in the past, then it 
				should have been mapped by the char same as current char
				for qualifying
				*/
                if(wp.find(w) != wp.end()) {
                    if((pw.count(p) && pw[p] != w)  ||
                       (wp[w] != p)
                       )
                        break;
                } else {
					/*
					If current char was not mapped before, 
					then, lets say it is going to be mapped with x,
					then make sure that x is either not in pattern
					map or if it is in pattern map, then it should
					have been mapped to	current char only
					*/
                    if(pw.count(p) && pw[p] != w)
                        break;
                    wp[w]  = p;  //c->a, 
                    pw[p]  = w;  //a->c,
                }
            }
            if(i == n)
                result.push_back(word);
        }
        return result;
    }
};
//Approach-2 (Smart approach :-)  )
class Solution {
public:
    string normalPattern(const string& word) {
        char curr_ch   = 'a';
        string pattern = "";
        unordered_map<char, char> mp;
        
        for(const char& ch : word) {
            if(mp.find(ch) != mp.end()) {
                pattern.push_back(mp[ch]);
            } else {
                mp[ch] = curr_ch;
                pattern.push_back(curr_ch);
                curr_ch++;
            }
        }
        return pattern;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {		
        vector<string> result;
		//Get a universal pattern for "pattern"
        string normal = normalPattern(pattern);
        for(const string& word:words) {
			//any word that matches with universal pattern of given pattern
			//is valid
            if(normalPattern(word) == normal)
                result.push_back(word);
        }
        return result;
		/*
			Universal Pattern is nothing but just creating a normal pattern
			for every word. See the API normalPattern() to understand what it's generating
		*/
    }
};
