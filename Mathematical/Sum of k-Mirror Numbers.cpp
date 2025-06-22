/*     Scroll below to see JAVA code    */
/*
    MY YOUTUBE VIDEO ON THIS Qn                : https://www.youtube.com/watch?v=j_cFgoSJqDQ
    Company Tags                               : will soon update
    Leetcode Link                              : https://leetcode.com/problems/sum-of-k-mirror-numbers/
    
*/

/****************************************************** C++ **************************************************************/
//Approach - Using palindrome generation logic
//T.C : ~O((10 ^ D) * D), where D = number of digits in k-mirror number
//S.C : O(D), where D = number of digits in k-mirror number
class Solution {
public:
    
    bool isPalindrome(string baseK) {
        int i = 0;
        int j = baseK.length()-1;

        while(i <= j) {
            if(baseK[i] != baseK[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    string convertToBaseK(long long num, int k) {
        if(num == 0) {
            return "0";
        }

        string res = "";
        while(num > 0) {
            res += to_string(num%k);
            num /= k;
        }

        return res;
    }

    long long kMirror(int k, int n) {
        long long sum = 0;
        int L = 1; //create L length palindromes

        while(n > 0) {
            int half_length = (L+1)/2;
            
            long long min_num = pow(10, half_length-1);
            long long max_num = pow(10, half_length) - 1;

            for(int num = min_num; num <= max_num; num++) {
                string first_half = to_string(num);
                string second_half = first_half;
                reverse(begin(second_half), end(second_half));

                string pal = "";
                if(L % 2 == 0) { //even length palindrome
                    pal = first_half + second_half;
                } else { //off length palindrome
                    pal = first_half + second_half.substr(1);
                }

                long long pal_num = stoll(pal);

                string baseK = convertToBaseK(pal_num, k);

                if(isPalindrome(baseK)) {
                    sum += pal_num; //found one k-mirror number
                    n--;
                    if(n == 0) {
                        break;
                    }
                }
            }

            L++;
        }

        return sum;
    }
};


/****************************************************** JAVA **************************************************************/
//Approach - Using palindrome generation logic
//T.C : ~O((10 ^ D) * D), where D = number of digits in k-mirror number
//S.C : O(D), where D = number of digits in k-mirror number
class Solution {
    
    // Check if a string is a palindrome
    private boolean isPalindrome(String s) {
        int left = 0, right = s.length() - 1;
        
        while (left <= right) {
            if (s.charAt(left++) != s.charAt(right--)) {
                return false;
            }
        }
        return true;
    }

    // Convert a number to base-k string representation
    private String convertToBaseK(long num, int k) {
        if (num == 0) return "0";
        
        StringBuilder res = new StringBuilder();
        while (num > 0) {
            res.append(num % k);
            num /= k;
        }
        return res.toString();
    }

    public long kMirror(int k, int n) {
        long sum = 0;
        int length = 1;

        while (n > 0) {
            int halfLength = (length + 1) / 2;
            long minNum = (long)Math.pow(10, halfLength - 1);
            long maxNum = (long)Math.pow(10, halfLength) - 1;

            for (long num = minNum; num <= maxNum; num++) {
                String firstHalf = Long.toString(num);
                String secondHalf = new StringBuilder(firstHalf).reverse().toString();
                
                String fullPalindrome;
                if (length % 2 == 0) {
                    fullPalindrome = firstHalf + secondHalf;
                } else {
                    fullPalindrome = firstHalf + secondHalf.substring(1);
                }

                long palNum = Long.parseLong(fullPalindrome);
                String baseK = convertToBaseK(palNum, k);

                if (isPalindrome(baseK)) {
                    sum += palNum;
                    n--;
                    if (n == 0) {
                        return sum;
                    }
                }
            }
            length++;
        }
        return sum;
    }
}
