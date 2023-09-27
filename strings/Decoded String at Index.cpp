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
    public static String decodeAtIndex(String s, int k) {
        int n = s.length();
        long size = 0;
        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                size *= (c - '0');
            } else {
                size += 1;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            char c = s.charAt(i);
            k %= size;

            if (k == 0 && Character.isLetter(c)) {
                return String.valueOf(c);
            }

            if (Character.isDigit(c)) {
                size /= (c - '0');
            } else {
                size -= 1;
            }
        }
        
        return "";
    }
}
