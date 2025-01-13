/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-length-of-string-after-operations/
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 - (Simple simulation)
//T.C : O(n)
//S.C : O(26) ~ O(1)
class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        vector<int> freq(26, 0);
        int deleted = 0;

        for(int i = 0; i < n; i++) {
            
            freq[s[i] - 'a'] += 1;

            if(freq[s[i]-'a'] == 3) {
                freq[s[i] - 'a'] -= 2; //we delete two characters
                deleted += 2; //we have deleted 2 characters here
            }
        }

        return n - deleted;

    }
};


//Approach-2 - (Simple Observation)
//T.C : O(n)
//S.C : O(26) ~ O(1)
class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);

        for(char& ch : s) {
            freq[ch-'a']++;
        }


        int result = 0;
        for(int i = 0; i < 26; i++) {
            if(freq[i] == 0)
                continue;

            if(freq[i] % 2 == 0) {
                result += 2;
            } else {
                result += 1;
            }
        }

        return result;
    }
};



/**************************************************************** JAVA ****************************************************************/
//Approach-1 - (Simple simulation)
//T.C : O(n)
//S.C : O(26) ~ O(1)
class Solution {
    public int minimumLength(String s) {
        int n = s.length();

        int[] freq = new int[26];
        int deleted = 0;

        for(int i = 0; i < n; i++) {
            freq[s.charAt(i) - 'a'] += 1;

            if(freq[s.charAt(i) -'a'] == 3) {
                freq[s.charAt(i) - 'a'] -= 2;
                deleted += 2;
            }
        }

        return n - deleted;
    }
}


//Approach-2 - (Simple Observation)
//T.C : O(n)
//S.C : O(26) ~ O(1)
class Solution {
    public int minimumLength(String s) {
        int n = s.length();

        int[] freq = new int[26];

        for(char ch : s.toCharArray()) {
            freq[ch-'a'] += 1;
        }

        int result = 0;

        for(int i = 0; i < 26; i++) {
            if(freq[i] == 0) {
                continue;
            }

            if(freq[i]%2 == 0) {
                result += 2;
            } else {
                result += 1;
            }
        }

        return result;
        
    }
}
