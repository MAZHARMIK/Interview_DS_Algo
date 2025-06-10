/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/description/
*/

/*********************************************************** C++ **************************************************/
//Approach (Straught forward maxOdd - minEven)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxDifference(string s) {
        int n = s.length();

        int maxOdd  = 0;
        int minEven = n+1;

        vector<int> vec(26, 0);
        for(char &ch : s) {
            vec[ch-'a']++;
        }

        for(int i = 0; i < 26; i++) {
            if(vec[i] == 0)
                continue;

            if(vec[i]%2 == 0) {
                minEven = min(minEven, vec[i]);
            } else {
                maxOdd = max(maxOdd, vec[i]);
            }
        }

        return maxOdd - minEven;
    }
};



/*********************************************************** JAVA **************************************************/
//Approach (Straught forward maxOdd - minEven)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int maxDifference(String s) {
        int n = s.length();

        int maxOdd = 0;
        int minEven = n + 1;

        int[] freq = new int[26]; // for 'a' to 'z'

        for (char ch : s.toCharArray()) {
            freq[ch - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;

            if (freq[i] % 2 == 0) {
                minEven = Math.min(minEven, freq[i]);
            } else {
                maxOdd = Math.max(maxOdd, freq[i]);
            }
        }

        return maxOdd - minEven;
    }
}
