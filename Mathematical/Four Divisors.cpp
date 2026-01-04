/*     Scroll below to see JAVA code    */
/*
    MY YOUTUBE VIDEO ON THIS Qn                : https://www.youtube.com/watch?v=MOYYok4_e0I
    Company Tags                               : Capital One, Amazon, Microsoft, Google, Meta
    Leetcode Link                              : https://leetcode.com/problems/four-divisors/description/
    
*/

/****************************************************** C++ **************************************************************/
//Approach - Simple maths - Iterate and find factors
//T.C : O(n * sqrt(maxNumber))
//S.C : O(1)
class Solution {
public:
    int sumIfFourDivisors(int num) {
        int divisors = 0;
        int sum = 0;

        for (int div = 1; div * div <= num; div++) {
            if (num % div == 0) {
                int other = num / div;

                if (div == other) {
                    divisors++;
                    sum += div;
                } else {
                    divisors += 2;
                    sum += (div + other);
                }
            }

            if (divisors > 4) {
                return 0;
            }
        }

        return divisors == 4 ? sum : 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int result = 0;

        for (int &num : nums) {
            result += sumIfFourDivisors(num);
        }

        return result;
    }
};


/****************************************************** JAVA **************************************************************/
//Approach - Simple maths - Iterate and find factors
//T.C : O(n * sqrt(maxNumber))
//S.C : O(1)
class Solution {

    private int sumIfFourDivisors(int num) {
        int divisors = 0;
        int sum = 0;

        for (int div = 1; div * div <= num; div++) {
            if (num % div == 0) {
                int other = num / div;

                if (div == other) {
                    divisors++;
                    sum += div;
                } else {
                    divisors += 2;
                    sum += div + other;
                }
            }

            if (divisors > 4) {
                return 0;
            }
        }

        return divisors == 4 ? sum : 0;
    }

    public int sumFourDivisors(int[] nums) {
        int result = 0;

        for (int num : nums) {
            result += sumIfFourDivisors(num);
        }

        return result;
    }
}
