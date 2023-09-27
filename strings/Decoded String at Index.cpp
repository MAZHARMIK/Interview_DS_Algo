/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=xK95Wlng_RA
    Company Tags                : National Instruments, Oracle, Google, TCS
    Leetcode Link               : https://leetcode.com/problems/decoded-string-at-index/
*/

/************************************************ C++ ************************************************/
class Solution {
public:
    string decodeAtIndex(string S, int K) {
        int n = S.length();
        long long size = 0;
        
        for(char ch:S) {
            if(isdigit(ch)) {
                size = size*(ch-'0');
            } else {
                size++;
            }
        }
        
        for(int i = n-1; i>=0; i--) {
            K = K%size;
            
            if(K == 0  && isalpha(S[i]))
                return string(1, S[i]);
            
            if(isalpha(S[i]))
                size--;
            else
                size = size/(S[i]-'0');
        }
        
        return "";
        
    }
};



/************************************************ JAVA ************************************************/
public class Solution {
    public String decodeAtIndex(String S, int K) {
        int n = S.length();
        long size = 0;

        for (char ch : S.toCharArray()) {
            if (Character.isDigit(ch)) {
                size *= (ch - '0');
            } else {
                size++;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            K = K % (int) size;

            if (K == 0 && Character.isLetter(S.charAt(i))) {
                return String.valueOf(S.charAt(i));
            }

            if (Character.isLetter(S.charAt(i))) {
                size--;
            } else {
                size /= (S.charAt(i) - '0');
            }
        }

        return "";
    }
}

