/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/smallest-palindromic-rearrangement-ii/
*/


/*********************************************************** C++ **************************************************/
//Approach (Factorisation + Cumulative Sum + Binary Search)
//T.C : O(n × 26 × 26 × logk)
//S.C : O(n) for additional string
class Solution {
public:

    long long nCr(int n, int r, int k) {
        //nCr == nC(n-r)
        //5C3 == 5C2
        //5C2 == 5C(5-2) = 5C3
        r = min(r, n-r); //nCr == nC(n-r)

        long long result = 1;

        for(int i = 1; i <= r; i++) {//O(log2(k))
            result = result * (n - r + i)/i; //result is becoming twice

            if(result >= k) 
                return k;
        }

        return result;
    }

    string smallestPalindrome(string s, int k) {
        int n = s.length();

        char mid = ' ';
        if(n%2 == 1) { //odd length
            mid = s[n/2];
        }

        vector<int> count(26, 0);
        for(int i = 0; i < n; i++) {
            if(n%2 == 1 && i == n/2) continue; //mid character reserverd for middle one
            count[s[i] - 'a']++;
        }

        //half frequency will be used to build halfResult
        for(int i = 0; i < 26; i++) {
            count[i] /= 2;
        }

        string halfResult = "";
        int half = n/2;

        for(int i = 0; i < half; i++) { //O(n/2)
            //I am trying to fill ith position
            //What if I could never fill a character in ith position
            bool placedCharacter = false; //in ith position
            for(int j = 0; j < 26; j++) { //which character to put
                if(count[j] > 0) {
                    count[j] -= 1;

                    //count number of ways
                    long long ways = 1;
                    int letters = 0;
                    for(int c = 0; c < 26; c++) {
                        letters += count[c];
                    }

                    for(int c = 0; c < 26; c++) {
                        if(count[c] > 0) {
                            ways *= nCr(letters, count[c], k); //log2(k)
                            letters -= count[c];
                        }

                        if(ways >= k) {
                            break;
                        }
                    }

                    if(ways >= k) { //this block contains my kth one
                        halfResult.push_back(j + 'a'); //fixed this character at ith position
                        placedCharacter = true;
                        break;
                    }

                    k -= ways; //when k >= ways
                    count[j] += 1;
                }
            }

            if(placedCharacter == false)
                return "";
        }

        //halfResult + mid + (reverse of halfResult)
        string rev = halfResult;
        reverse(begin(rev), end(rev)); //O(n/2)

        if(mid != ' ') {
            halfResult.push_back(mid);
        }

        return halfResult + rev;
    }
};



/*********************************************************** JAVA **************************************************/
//Approach (Factorisation + Cumulative Sum + Binary Search)
//T.C : O(n × 26 × 26 × logk)
//S.C : O(n) for additional string
class Solution {

    long nCr(int n, int r, int k) {
        //nCr == nC(n-r)
        //5C3 == 5C2
        //5C2 == 5C(5-2) = 5C3
        r = Math.min(r, n - r); //nCr == nC(n-r)

        long result = 1;

        for (int i = 1; i <= r; i++) { //O(log2(k))
            result = result * (n - r + i) / i; //result is becoming twice

            if (result >= k)
                return k;
        }

        return result;
    }

    public String smallestPalindrome(String s, int k) {
        int n = s.length();

        char mid = ' ';
        if (n % 2 == 1) { //odd length
            mid = s.charAt(n / 2);
        }

        int[] count = new int[26];
        for (int i = 0; i < n; i++) {
            if (n % 2 == 1 && i == n / 2) continue; //mid character reserved for middle one
            count[s.charAt(i) - 'a']++;
        }

        //half frequency will be used to build halfResult
        for (int i = 0; i < 26; i++) {
            count[i] /= 2;
        }

        StringBuilder halfResult = new StringBuilder();
        int half = n / 2;

        for (int i = 0; i < half; i++) { //O(n/2)
            //I am trying to fill ith position
            //What if I could never fill a character in ith position
            boolean placedCharacter = false; //in ith position
            for (int j = 0; j < 26; j++) { //which character to put
                if (count[j] > 0) {
                    count[j] -= 1;

                    //count number of ways
                    long ways = 1;
                    int letters = 0;
                    for (int c = 0; c < 26; c++) {
                        letters += count[c];
                    }

                    for (int c = 0; c < 26; c++) {
                        if (count[c] > 0) {
                            ways *= nCr(letters, count[c], k); //log2(k)
                            letters -= count[c];
                        }

                        if (ways >= k) {
                            break;
                        }
                    }

                    if (ways >= k) { //this block contains my kth one
                        halfResult.append((char) (j + 'a')); //fixed this character at ith position
                        placedCharacter = true;
                        break;
                    }

                    k -= ways; //when k >= ways
                    count[j] += 1;
                }
            }

            if (placedCharacter == false)
                return "";
        }

        //halfResult + mid + (reverse of halfResult)
        StringBuilder rev = new StringBuilder(halfResult);
        rev.reverse(); //O(n/2)

        if (mid != ' ') {
            halfResult.append(mid);
        }

        return halfResult.toString() + rev.toString();
    }
}
