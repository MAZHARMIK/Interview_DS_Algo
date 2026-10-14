/*         Scroll down to see JAVA code also                    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/maximize-sum-of-squares-of-digits
*/


/********************************************************************* C++ ****************************************************************/
//Approach (Greedily Pick largest digit 9)
//T.C : O(num), we form a string of num digits
//S.C : O(1)
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > num * 9)
            return "";
        
        int nines  = sum/9;
        int remain = sum%9;

        string result(nines, '9');

        if(remain > 0) {
            result.push_back(remain + '0');
        }

        result.append(num - result.length(), '0');

        return result;
    }
};


/********************************************************************* C++ ****************************************************************/
//Approach (Greedily Pick largest digit 9)
//T.C : O(num), we form a string of num digits
//S.C : O(1)
class Solution {
    public String maxSumOfSquares(int num, int sum) {
        if (sum > num * 9)
            return "";

        int nines = sum / 9;
        int remain = sum % 9;

        StringBuilder result = new StringBuilder();

        for (int i = 0; i < nines; i++) {
            result.append('9');
        }

        if (remain > 0) {
            result.append((char) (remain + '0'));
        }

        while (result.length() < num) {
            result.append('0');
        }

        return result.toString();
    }
}
