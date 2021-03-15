/*
    Company Tags  : Uber, Google, Facebook, Amazon
    Leetcode Link : https://leetcode.com/problems/encode-and-decode-tinyurl/
*/

class Solution {
public:

    // Encodes a URL to a shortened URL.
    unordered_map<string, string> mp;
    int i = 0;
    string encode(string longUrl) {
        mp[to_string(i)] = longUrl;
        return "http://tinyurl.com/"+to_string(i++);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int index = shortUrl.size() - 1;
        while(shortUrl[index] != '/')
            index--;
        
        string s = shortUrl.substr(index+1);
        return mp[s];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
