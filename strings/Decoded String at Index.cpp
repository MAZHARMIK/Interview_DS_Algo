/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=xK95Wlng_RA
    Company Tags                : National Instruments, Oracle, Google, TCS
    Leetcode Link               : https://leetcode.com/problems/decoded-string-at-index/
*/
/*
* SEE THIS EXAMPLE WHICH WILL DEFINITELY HIT YOU ABOUT THE INTUITION *

Let's take an example : 
s = "leet2code3", k = 15 - (I have put the 15th char under ' ' for clear identifying)
decoded string = "leetleetcodele'e'tleetcodeleetleetcode" ------> (Note : 'e' is the 15th char)



No we're iterating from i = n-1;
input string s = "leet2code3", 

So since we're looking at char `3` now of the input string, we can visualize the decoded string to be split up like this:
decoded string = "leetleetcode    leetleetcode    leetleetcode"
Because it's "leetleetcode" duplicated 3 times.

So `K` is pointing here (shown as. K-->) 
decoded string = "leetleetcode    le  K-->etleetcode    leetleetcode"

Notice how we can also make `K` point to the following locations as well and it will still be the exact same letter:
decoded string = "le  K-->etleetcode    leetleetcode    leetleetcode"
OR
decoded string = "leetleetcode    leetleetcode    le  K-->etleetcode"

If we treat each duplicated string as it's own string, then K can point to any of the other duplicated strings at the 3rd character and it will still be the same letter.

So when we divide the decoded string length by the current digit, it gets rid of all the duplicates and only uses the first duplicate:
"leetleetcode"

And remember `K` was always the 3rd index of any of duplicated strings. So we say `K = K % size`. `size` being the length of a single duplicated string, so this will bring `K` to the correct index for just a single duplicated string.

So after getting rid of duplicate strings (size(decoded string) = size(decoded string) / digit) and we bring `K` to the same position of the smallest duplicated string (K = K % size(single duplicated decoded string = 3), we have this:
decoded string = "le  K-->etleetcode"

 Now, as we move forward, we reach to a position i which points to '2', 
input string = "leet  -->2"
decoded string = "le  K-->etleet"   -------> (K will point to)

We can split the decoded string like so:
decoded string = "leet    leet"

`K` points here:
decoded string = "le  K-->et    leet"
Which is the same as:
decoded string = "leet    le  K-->et"
                                 
So we can get rid of the duplicate string again so we have:
decoded string = "leet"
And we can mod `K` by the length of the duplicated string, but this time, `K` is already pointing to the character of the duplicate string with the smallest indexes anyways, so it doesn't do anything:
decoded string = "le  K-->et"
And then of course we return the 3rd character of this final reduced decoded string which is "e"
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
