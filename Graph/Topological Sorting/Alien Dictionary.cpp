/*
    Company Tags  : Airbnb, Amazon, Apple, Bloomberg, Cohesity, Facebook, Flipkart, Google, Microsoft, Oracle, Pinterest,
                    Pocket, Gems, Snapchat, Square, Twitter, Uber, VMware, .Star
    Leetcode Link : https://leetcode.com/problems/alien-dictionary/
    
    It's a Premium Qn, so the Description has been added below:
     There is a new alien language which uses the latin alphabet.
     However, the order among letters are unknown to you.

     You receive a list of words from the dictionary, where words are sorted lexicographically
     by the rules of this new language.

     Derive the order of letters in this language.

     Example - 1
     Input  : [ "wrt", "wrf", "er", "ett", "rftt" ]

     Output : "wertf".
     
    Exmaple - 2
    Input : [ "z", "x", "z" ]

     Output: ""

     Explanation: The order is invalid, so return "".


     Note:
     You may assume all letters are in lowercase.
     If the order is invalid, return an empty string.
     There may be multiple valid order of letters, return any one of them is fine.

*/

/*
    This is a popular question which tests your knowledge on "Topological Sorting".
    Why "Topological Sorting" ?
    Whenever any question deals with ordering (which comes first) and there are nodes, then do think about Topological Sorting. It may be a hint.
*/

//Approach-1 (Topological Sorting : BFS(Kahn's Algorithm)
class Solution {
public:
    string result;
    void buildGraph(unordered_map<char, set<char>>& adj, vector<string>& words, vector<int>& indegree) {
        int n = words.size();

        //First insert all unique characters
        for(string &word : words) {
            for(char &ch : word) {
                adj[ch] = set<char>{};
            }
        }

        //Connect letters (find dependencies)
        for(int i = 1; i<n; i++) {
            string first  = words[i-1];
            string second = words[i];

            int l = min(first.length(), second.length());
            for(int j = 0; j<l; j++) {
                char u = first[j];
                char v = second[j];
                if(u != v) {
                    indegree[v-'a']++;
                    adj[u].insert(v);
                    break;
                }

                //if second is a prefix of first, we have wrong order
                if (j + 1 == l && first.length() > second.length()) {
                    adj.clear();
                    return;
                }
            }
            
        }
    }

    void  kahnsAlgo(unordered_map<char, set<char>>& adj, int V, vector<int>& indegree) {
        queue<char> que;
        for(int i = 0; i<26; i++) {
            char ch = i+'a';
            if(indegree[i] == 0 && adj.count(ch)) {
                que.push(ch);
            }
        }

        int count = que.size();
        while(!que.empty()) {
            char curr = que.front();
            que.pop();
            result.push_back(curr);
            for(const char &x : adj[curr]) {
                indegree[x-'a']--;
                if(indegree[x-'a'] == 0) {
                    count++;
                    que.push(x);
                }
            }
        }

        if(count != V)
            result = "";
    }

    string alienOrder(vector<string>& words) {
        unordered_map<char, set<char>> adj;
        vector<int> indegree(26, 0);

        buildGraph(adj, words, indegree);
        int V = adj.size();
        kahnsAlgo(adj, V, indegree);

        return result;
    }
};

//Approach-2 (DFS - Coming Soon)
