/*     Scroll below to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/fraction-addition-and-subtraction
*/

/**************************************************** C++ ****************************************************/
//Approach-1 (Simple simulation)
//T.C : O(n), n = length of expression
//S.C : O(1)
class Solution {
public:
    string fractionAddition(string expr) {
        int nume = 0;
        int deno = 1;

        int i = 0;
        int n = expr.length();
        while(i < n) {
            int currNume = 0;
            int currDeno = 0;

            bool isNeg = (expr[i] == '-');
            
            if(expr[i] == '+' || expr[i] == '-') {
                i++;
            }

            //Build the currNume
            while(i < n && isdigit(expr[i])) {
                int val = expr[i] - '0';
                currNume = (currNume*10) + val;
                i++;
            }

            i++; //numerator / denominator //skipiing the divisrio character '/'

            if(isNeg == true) {
                currNume *= -1;
            }

            //Build the currDeno
            while(i < n && isdigit(expr[i])) {
                int val = expr[i] - '0';
                currDeno = (currDeno * 10) + val;
                i++;
            }

            nume = nume * currDeno + currNume * deno;
            deno = deno * currDeno;
        }

        //num
        //deno
        //-3 / 6 //GCD : 3
        int GCD = abs(__gcd(nume, deno)); //3

        nume /= GCD; //-1
        deno /= GCD; //2

        return to_string(nume) + "/" + to_string(deno); //"-1/2"
    }
};



/**************************************************** JAVA ****************************************************/
//Approach-1 (Simple simulation)
//T.C : O(n), n = length of expression
//S.C : O(1)
class Solution {
    public String fractionAddition(String expr) {
        int nume = 0; // Numerator
        int deno = 1; // Denominator

        int i = 0;
        int n = expr.length();
        while (i < n) {
            int currNume = 0; // Current fraction numerator
            int currDeno = 0; // Current fraction denominator

            boolean isNeg = (expr.charAt(i) == '-');

            // Skip '+' or '-'
            if (expr.charAt(i) == '+' || expr.charAt(i) == '-') {
                i++;
            }

            // Build the current numerator
            while (i < n && Character.isDigit(expr.charAt(i))) {
                int val = expr.charAt(i) - '0';
                currNume = (currNume * 10) + val;
                i++;
            }

            i++; // Skip the division character '/'

            if (isNeg) {
                currNume *= -1; // Apply negative sign if needed
            }

            // Build the current denominator
            while (i < n && Character.isDigit(expr.charAt(i))) {
                int val = expr.charAt(i) - '0';
                currDeno = (currDeno * 10) + val;
                i++;
            }

            // Update the accumulated numerator and denominator
            nume = nume * currDeno + currNume * deno;
            deno = deno * currDeno;
        }

        // Simplify the fraction using the greatest common divisor (GCD)
        int gcd = gcd(Math.abs(nume), deno);

        nume /= gcd;
        deno /= gcd;

        // Return the result in the form "numerator/denominator"
        return nume + "/" + deno;
    }

    // Helper method to calculate the greatest common divisor (GCD) using Euclidean algorithm
    private int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}
