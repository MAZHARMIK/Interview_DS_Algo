/*   Scroll below to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will udpate later
    Leetcode Link               : https://leetcode.com/problems/add-binary
*/


/******************************************************* C++ *******************************************************/
//Approach (Simple binary addition)
//T.C : O(m+n)
//S.C : O(1)
class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.length()-1;
        int n = b.length()-1;

        string result = "";

        int sum = 0;
        int carry = 0;

        while(m >= 0 || n >= 0) {
            sum = carry;

            if(m >= 0) {
                sum += a[m] - '0';
                m--;
            }

            if(n >= 0) {
                sum += b[n] - '0';
                n--;
            }

            result.push_back((sum%2 == 0) ? '0' : '1');

            carry = (sum > 1) ? 1 : 0; //sum/2
        }

        if(carry) {
            result.push_back('1');
        }

        reverse(begin(result), end(result));
        return result;
    }
};



/******************************************************* JAVA *******************************************************/
//Approach (Simple binary addition)
//T.C : O(m+n)
//S.C : O(1)
class Solution {
    public String addBinary(String a, String b) {
        int m = a.length() - 1;
        int n = b.length() - 1;
        int carry = 0;
        int sum = 0;

        StringBuilder result = new StringBuilder();

        while (m >= 0 || n >= 0) {
            sum = carry;

            if (m >= 0) {
                sum += a.charAt(m) - '0';
                m--;
            }

            if (n >= 0) {
                sum += b.charAt(n) - '0';
                n--;
            }

            result.append((sum % 2 == 0) ? '0' : '1');

            carry = sum / 2;
        }

        if (carry == 1) {
            result.append('1');
        }

        return result.reverse().toString();
    }
}
