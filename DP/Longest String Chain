/*
    Company Tags  : Google
    Leetcode Link : https://leetcode.com/problems/longest-string-chain/
*/
/*
Before you see the solution below, you need to understand how one can come up with the idea that this question can be solved
with the concept of LIS(Longest increasing subsequence) ? Look for the keywords in the question. (comparison below)

		(This qn)                                         (LIS)
-You have to find the longest chain            -Longest length of subsequence
-nums[prev] < nums[curr]                       -words[prev] is predecessor of words[curr]

I think these two points are enough to give LIS a chance. That's how it clicked me atleast.
If you have any other explanation, please feel free to share. I am looking for multiple solutions/explanations to a question.

But, why I have sorted the input (in solutions below)?
Because in LIS, we needed the longest subsequence.
But here in this question, we need the longest chain no matter which word you put where (i.e. order doens't matter).
So, the best solution will come (longest) when you sort the input in ascending order of length. This will ensure you get the longest chain.
*


//Approach-1 (Recusrion + Memoized)
class Solution {
public:
    int t[1001][1001];
	//This function is simple just follow how question defines a predecessor
    bool predecessor(string& prev, string& curr) {
        int m = prev.length();
        int n = curr.length();
        
        if(n-m != 1 || m >= n)
            return false;
        
        int i = 0, j = 0;
		//prev should be a subsequence of curr
        while(i < m && j < n) {
            if(prev[i] == curr[j]) {
                i++;
            }
            j++;
        }
        return i==m;
    }
	//This is nothing but "Longest Increasing Subsequence"
    int modifiedLIS(vector<string>& words, int prev, int curr) {
        if(curr ==  words.size())
            return 0;
        if(t[prev+1][curr] != -1)
            return t[prev+1][curr];
        int taken = 0;
		/*
			Remember, in LIS, we used to check only
			nums[prev] < nums[curr]. But here just condition is
			changed as per the question
		*/
		
        if(prev < 0 || predecessor(words[prev], words[curr])) {
            taken = 1 + modifiedLIS(words, curr, curr+1);
        }
        
        int not_taken = modifiedLIS(words, prev, curr+1);
        
        return t[prev+1][curr] = max(taken, not_taken);
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), myFunction); //Why ? Reason at the top
        int n = words.size();
        int prev = -1;
        int curr = 0;
        memset(t, -1, sizeof(t));
        return modifiedLIS(words, prev, curr);
    }
};

//Approach-2 - (DP version of above)
class Solution {
public:
	//This function is simple just follow how question defines a predecessor
    bool predecessor(string& prev, string& curr) {
        int m = prev.length();
        int n = curr.length();
        
        if(n-m != 1 || m >= n)
            return false;
        
        int i = 0, j = 0;
		//prev should be a subsequence of curr
        while(i < m && j < n) {
            if(prev[i] == curr[j]) {
                i++;
            }
            j++;
        }
        return i==m;
    }
    int modifiedLIS(vector<string>& words) {
        int n = words.size();
        vector<int> t(n, 1);
        //t[i] = LIS ending at index i
        int result = 1;
        for(int i = 1; i<n; i++) {
            for(int j = 0; j<i; j++) {
				/*
					Remember, in LIS, we used to check only
					nums[j] < nums[i]. But here just condition is
					changed as per the question
				*/
                if(predecessor(words[j], words[i])) {
                    t[i] = max(t[i], 1 + t[j]);
                    result = max(result, t[i]);
                }
            }
        }
        
        return result;
    }
    
    static bool myFunction(string& s1, string& s2) {
        return s1.length() < s2.length();
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), myFunction); //Why ? Reason at the top
        
        return modifiedLIS(words);
    }
};


//Approach-3 Using HashMap [Time : O(NlogN+(N*L^2)) ]
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> mp;
        
		//lambda function for sorting
        auto myFunction = [&](string& s1, string& s2) {
            return s1.length() < s2.length();
        };
        
        sort(begin(words), end(words), myFunction);  //O(N*logN)
        
        int maxChain = 0;
        for(string &word:words) { O(N)
            int chain_word = 1;
            
            for(int i = 0; i < (int) word.length(); i++) {  // O(L)
                /*
			Find all possible predecessors of word by removing one character
			I you see that we have that predecessor, then we add +1 to the 
			predecessor chain to reach to current word.
			Similarly, for all possible predecessors, find the maximum chain to reach
			current word.
		*/
                string s = word.substr(0, i) + word.substr(i+1);  // O(L)
                auto it = mp.find(s);
            
                if(it != mp.end()) {
                    //find best predecessor
                    chain_word = max(chain_word, mp[s]+1);
                }
            }
            
            mp[word] = chain_word; //select the maximum chain for word
			//And at last find the maximum for all the words
            maxChain = max(maxChain, chain_word); //update the maximum chain obtained
        }
        
        return maxChain;
    }
};
