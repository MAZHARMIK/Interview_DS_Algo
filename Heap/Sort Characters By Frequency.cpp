/*
    MY YOUTUBE VIDEO ON THIS Qn (Approach-1) : https://www.youtube.com/watch?v=pnxShVARLLw
    MY YOUTUBE VIDEO ON THIS Qn (Approach-2) : https://www.youtube.com/watch?v=HwCYa1_2vkU
    Company Tags                             : Amazon, Google, Oracle, Zoho, Zycus
    Leetcode Link                            : https://leetcode.com/problems/sort-characters-by-frequency/
*/

//Approach-1 (Using Simple vector of pair and sorting it -  O(nlogn)
class Solution {
public:
    typedef pair<char, int> P;
    
    string frequencySort(string s) {
        vector<P> vec(123);
        
        for(char &ch : s) {
            int freq = vec[ch].second;
            vec[ch] = {ch, freq+1};
        }
        
        auto comp = [&](P &p1, P &p2) {
            return p1.second > p2.second;
        };
        
        sort(begin(vec), end(vec), comp);
        
        string result = "";
        
        for(int i = 0; i <= 122; i++) {
            result += string(vec[i].second, vec[i].first);
        }
        return result;
    }
};



//Approach-2 (Using Priority Queue) - O(nlong)
class Solution {
public:
    typedef pair<char, int> P;
    struct comp {
        bool operator()(P &p1, P &p2) {
            return p1.second<p2.second; //max-heap
        }
    };
    
    string frequencySort(string s) {
        priority_queue<P, vector<P>, comp> pq;
        
        unordered_map<char, int> mp;
        for(char &ch : s) {
            mp[ch]++;
        }
        
        for(auto &it : mp) {
            pq.push({it.first, it.second});
        }
        
        string result = "";
        
        while(!pq.empty()) {
            P temp = pq.top();
            pq.pop();
            
            result += string(temp.second, temp.first);
        }
        return result;
    }
};
