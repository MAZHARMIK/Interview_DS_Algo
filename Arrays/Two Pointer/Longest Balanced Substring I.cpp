/*			Scroll below to see JAVA code also			*/
/*
	    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=tEUJZkSgxuA
    	Company Tags  		          : Will update later
    	Leetcode Link 		          : https://leetcode.com/problems/longest-balanced-substring-i
*/


/*************************************************************** C++ *************************************************/
//Approach (try all subarrays)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:

    bool checkBalanced(vector<int>& freq) {
        int common = 0;
        for(int i = 0; i < 26; i++) {
            if(freq[i] == 0) continue;
            if(common == 0)
                common = freq[i];
            else if(freq[i] != common) {
                return false;
            }
        }

        return true;
    }

    int longestBalanced(string s) {
        int n = s.length();

        int maxL = 0;

        for(int i = 0; i < n; i++) {
            vector<int> freq(26, 0);

            for(int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                //i..j
                if(checkBalanced(freq)) {
                    maxL = max(maxL, j-i+1);
                }
            }
        }

        return maxL;
    }
};




/*************************************************************** JAVA *************************************************/
//Approach (try all subarrays)
//T.C : O(n^2)
//S.C : O(1)
class Solution {

    private boolean checkBalanced(int[] freq) {
        int common = 0;

        for (int f : freq) {
            if (f == 0) continue;

            if (common == 0) {
                common = f;
            } else if (f != common) {
                return false;
            }
        }
        return true;
    }

    public int longestBalanced(String s) {
        int n = s.length();
        int maxL = 0;

        for (int i = 0; i < n; i++) {
            int[] freq = new int[26];   // reset for every start index

            for (int j = i; j < n; j++) {
                freq[s.charAt(j) - 'a']++;

                if (checkBalanced(freq)) {
                    maxL = Math.max(maxL, j - i + 1);
                }
            }
        }

        return maxL;
    }
}
