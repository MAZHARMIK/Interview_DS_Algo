/*         Scroll down to see JAVA code also                    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/find-the-lexicographically-smallest-valid-sequence/
*/


/********************************************************************* C++ ****************************************************************/
//Approach - Greedy pick
//T.C : O(m+n)
//S.C : O(n)
class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int> rightHandSideMatchLength(n, 0);

        int rightMatched = 0;
        int i = n-1;
        int j = m-1;
        while(i >= 0) {
            if(j >= 0 && word1[i] == word2[j]) {
                rightMatched++;
                j--;
            }

            rightHandSideMatchLength[i] = rightMatched;
            i--;
        }

        vector<int> seq;
        bool changePower = true; //can change only one character

        i = 0;
        j = 0;
        while(i < n && j < m) {
            if(word1[i] == word2[j]) {
                seq.push_back(i);
                j++;
            } else if(changePower == true && i+1 < n && rightHandSideMatchLength[i+1] >= m-j-1) {
                seq.push_back(i);
                j++;
                changePower = false;
            }

            i++;
        }

        return j == m ? seq : vector<int>();
    }
};



/********************************************************************* JAVA ****************************************************************/
//Approach - Greedy pick
//T.C : O(m+n)
//S.C : O(n)
class Solution {
    public int[] validSequence(String word1, String word2) {
        int n = word1.length();
        int m = word2.length();
        int[] rightHandSideMatchLength = new int[n];
        int rightMatched = 0;
        int i = n-1;
        int j = m-1;
        while(i >= 0) {
            if(j >= 0 && word1.charAt(i) == word2.charAt(j)) {
                rightMatched++;
                j--;
            }
            rightHandSideMatchLength[i] = rightMatched;
            i--;
        }
        int[] seq = new int[m];
        int idx = 0;              //fill pointer for seq
        boolean changePower = true; //can change only one character
        i = 0;
        j = 0;
        while(i < n && j < m) {
            if(word1.charAt(i) == word2.charAt(j)) {
                seq[idx++] = i;
                j++;
            } else if(changePower == true && i+1 < n && rightHandSideMatchLength[i+1] >= m-j-1) {
                seq[idx++] = i;
                j++;
                changePower = false;
            }
            i++;
        }
        return j == m ? seq : new int[0];
    }
}
