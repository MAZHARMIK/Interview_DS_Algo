/*     Scroll below to see JAVA code    */
/*
    MY YOUTUBE VIDEO ON THIS Qn                : https://www.youtube.com/watch?v=FDsgahPLENw
    Company Tags                               : will soon update
    Leetcode Link                              : https://leetcode.com/problems/fraction-to-recurring-decimal
    
*/

/****************************************************** C++ **************************************************************/
//Approach - School wala Maths - Long Division
//T.C : O(denominator) approximately
//S.C : O(1)
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0)
            return "0";

        string result;

        if((long long)numerator * (long long)denominator < 0) {
            result += "-";
        }

        long long absNumerator = labs(numerator);
        long long absDenominator = labs(denominator);

        long long integerDiv = absNumerator / absDenominator;

        result += to_string(integerDiv); //log10(integerDiv)

        long long remain = absNumerator % absDenominator;
        if(remain == 0) {
            return result;
        }

        result += '.';

        unordered_map<int, int> mp;
        // 0 <= remain < denominator
        //O(denominator + length)
        while(remain != 0) {
            if(mp.count(remain)) {
                result.insert(mp[remain], "("); //O(length)
                result += ")";
                break;
            }

            mp[remain] = result.length();

            remain *= 10;
            int digit = remain / absDenominator;
            result += to_string(digit); //O(1)

            remain = remain % absDenominator;
        }

        return result;
    }
};



/****************************************************** JAVA **************************************************************/
//Approach - School wala Maths - Long Division
//T.C : O(denominator) approximately
//S.C : O(1)
class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        StringBuilder result = new StringBuilder();

        // Handle sign
        if ((long) numerator * (long) denominator < 0) {
            result.append("-");
        }

        long absNumerator = Math.abs((long) numerator);
        long absDenominator = Math.abs((long) denominator);

        // Integer part
        long integerPart = absNumerator / absDenominator;
        result.append(integerPart);

        long remain = absNumerator % absDenominator;
        if (remain == 0) return result.toString();

        result.append(".");

        Map<Long, Integer> map = new HashMap<>();
        while (remain != 0) {
            if (map.containsKey(remain)) {
                // Insert "(" at the position where this remainder first appeared
                int insertPos = map.get(remain);
                result.insert(insertPos, "(");
                result.append(")");
                break;
            }

            map.put(remain, result.length());
            remain *= 10;
            long digit = remain / absDenominator;
            result.append(digit);
            remain %= absDenominator;
        }

        return result.toString();
    }
}
