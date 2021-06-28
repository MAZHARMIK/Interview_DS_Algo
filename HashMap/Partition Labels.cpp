/*
    Company Tags  : Amazon (many times)
    Leetcode Link : https://leetcode.com/problems/partition-labels/
    NOTE : This question also falls under "Two Pointer" section
*/
/*
All approches are O(n+n) = O(n) time since we traverse the 
string once within a loop
*/

//Approach-1 (basic approach that we should come up with in first call)
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        int n = s.length();
		//store the last indices of every character in the map for quick access
        for(int i = n-1; i>=0; i--) {
            if(mp.find(s[i]) == mp.end()) {
                mp[s[i]] = i;
            }
        }

        vector<int> result;
        for(int i = 0; i<n;) {
            char ch       = s[i];
            int last_pos = mp[ch];
			//update last position to the maximum you can go
            for(int j = i+1; j<last_pos; j++) {
                char next_ch = s[j];
                if(mp[next_ch] > last_pos) {
                    last_pos = mp[next_ch];
                }
            }
            result.push_back(last_pos-i + 1);
            i = last_pos+1;
        }

        return result;
    }

};

//Approach-2 (Slight improvement on above solution)
class Solution {
public:
    vector<int> partitionLabels(string s) {
		//Me to interviewer : If the string only contains lower case letter, I should use array of size 26 (constant space)
        vector<int> mp(26, -1);
            
        int n = s.length();
        for(int i = n-1; i>=0; i--) {
            if(mp[s[i]-'a'] == -1)
                mp[s[i]-'a'] = i;
        }

        vector<int> result;
        for(int i = 0; i<n;) {
            char ch       = s[i];
            int last_pos = mp[ch-'a'];
            for(int j = i+1; j<last_pos; j++) {
                char next_ch = s[j];
                if(mp[next_ch-'a'] > last_pos) {
                    last_pos = mp[next_ch-'a'];
                }
            }
            result.push_back(last_pos-i + 1);
            i = last_pos+1;
        }

        return result;
    }
};

//Approach-3 (Cleaning the above approaches with a little tweak) (This approach is more like two pointer approach)
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> mp(26, -1);
            
        int n = s.length();
        for(int i = n-1; i>=0; i--) {
            if(mp[s[i]-'a'] == -1)
                mp[s[i]-'a'] = i;
        }

        vector<int> result;
        int start = 0, end = 0;
        for(int i = 0; i<n; i++) {
            end = max(end, mp[s[i]-'a']);
            if(i == end) { //you only find a label when you reach the farthest "end"
                result.push_back(end-start+1);
                start = end+1;
            }
        }

        return result;
    }

};
