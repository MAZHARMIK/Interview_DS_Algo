/*			Scroll below to see JAVA code also			*/
/*
	MY YOUTUBE VIDEO ON THIS Qn : 
    	Company Tags  		    : Amazon (many times), Meta
    	Leetcode Link 		    : https://leetcode.com/problems/partition-labels/
*/


/*************************************************************** C++ *************************************************/
//Approach-1 (basic approach that we should come up with in first call)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();

        vector<int> result;

        //last occurance of each character
        //unordered_map<char, int> mp;
        vector<int> mp(26, -1);
        for(int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            mp[idx] = i;
        }

        int i = 0;
        while(i < n) {
            int end = mp[s[i]-'a'];

            int j = i;
            while(j < end) {
                end = max(end, mp[s[j]-'a']);
                j++;
            }
            result.push_back(j-i+1);
            i = j+1;
        }

        return result;
    }
};


//Approach-2 (Clean code)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();

        vector<int> result;

        //last occurance of each character
        //unordered_map<char, int> mp;
        vector<int> mp(26, -1);
        for(int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            mp[idx] = i;
        }

        int i = 0;
        int start = 0;
        int end = 0;
        while(i < n) {
            end = max(end, mp[s[i]-'a']);
            if(i == end) {
                result.push_back(end-start+1);
                start = end+1;
            }
            i++;
        }

        return result;
    }
};



/*************************************************************** JAVA *************************************************/
//Approach-1 (basic approach that we should come up with in first call)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public List<Integer> partitionLabels(String s) {
        int n = s.length();
        List<Integer> result = new ArrayList<>();
        
        // Last occurrence of each character
        int[] lastIndex = new int[26];
        for (int i = 0; i < n; i++) {
            lastIndex[s.charAt(i) - 'a'] = i;
        }
        
        int i = 0;
        while (i < n) {
            int end = lastIndex[s.charAt(i) - 'a'];
            int j = i;
            while (j < end) {
                end = Math.max(end, lastIndex[s.charAt(j) - 'a']);
                j++;
            }
            result.add(j - i + 1);
            i = j + 1;
        }
        
        return result;
    }
}

// Approach-2 (Clean Code)
// T.C : O(n)
// S.C : O(1)
class Solution2 {
    public List<Integer> partitionLabels(String s) {
        int n = s.length();
        List<Integer> result = new ArrayList<>();
        
        // Last occurrence of each character
        int[] lastIndex = new int[26];
        for (int i = 0; i < n; i++) {
            lastIndex[s.charAt(i) - 'a'] = i;
        }
        
        int i = 0;
        int start = 0;
        int end = 0;
        while (i < n) {
            end = Math.max(end, lastIndex[s.charAt(i) - 'a']);
            if (i == end) {
                result.add(end - start + 1);
                start = end + 1;
            }
            i++;
        }
        
        return result;
    }
}
