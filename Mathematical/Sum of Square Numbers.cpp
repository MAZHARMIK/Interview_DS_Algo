/*     Scroll below to see JAVA code    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : The code is straight forward. But, Let me know if you want the video. I will then upload.
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/sum-of-square-numbers
*/


//****************************************************** C++ ************************************************************************//
//Approach-1 (Brute Force) - TLE
//T.C : O(c)
//S.C : O(1)
class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long a = 0; a*a <= c; a++) {
            for(long b = 0; b*b <= c; b++) {
                if(a*a + b*b == c)
                    return true;
            }
        }

        return false;
    }
};


//Approach-2 (Improvement on Approach-1 above) - ACCEPTED
//T.C : sqrt(c * log(c))
//S.C : O(1)
class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long a = 0; a*a <= c; a++) {
            double b = sqrt(c - a*a);

            if(b == (int)b) {
                return true;
            }

        }

        return false;
    }
};


//Approach-3 (Binary Search to find b)
//T.C : sqrt(c * log(c))
//S.C : O(1)
class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long a = 0; a*a <= c; a++) {
            
            int x = c - (int)(a*a);
            //b*b == x (we need to find the b which satisfies this)
            
            int b_start = 0, b_end = x;

            while(b_start <= b_end) {
                long mid = b_start + (b_end - b_start) / 2;

                if(mid*mid == x) {
                    return true;
                } else if(mid * mid < x) {
                    b_start = mid+1;
                } else {
                    b_end = mid-1;
                }
            }

        }

        return false;
    }
};


//Approach-4 (Using 2-Pointers)
//T.C : O(sqrt(c))
//S.C : O(1)
class Solution {
public:
    bool judgeSquareSum(int c) {
        long a = 0;
        long b = sqrt(c);

        while(a <= b) {
            long k = a*a + b*b;

            if(k < c) {
                a++;
            } else if (k > c) {
                b--;
            } else {
                return true;
            }
        }

        return false;
    }
};



//****************************************************** JAVA ************************************************************************//
//Approach-1 (Brute Force) - TLE
//T.C : O(c)
//S.C : O(1)
class Solution {
    public boolean judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; a++) {
            for (long b = 0; b * b <= c; b++) {
                if (a * a + b * b == c) {
                    return true;
                }
            }
        }
        return false;
    }
}



//Approach-2 (Improvement on Approach-1 above) - ACCEPTED
//T.C : sqrt(c * log(c))
//S.C : O(1)
class Solution {
    public boolean judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; a++) {
            double b = Math.sqrt(c - a * a);

            if (b == (int) b) {
                return true;
            }
        }
        return false;
    }
}


//Approach-3 (Binary Search to find b)
//T.C : sqrt(c * log(c))
//S.C : O(1)
class Solution {
    public boolean judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; a++) {
            int x = c - (int) (a * a);
            // b*b == x (we need to find the b which satisfies this)

            int b_start = 0, b_end = x;

            while (b_start <= b_end) {
                long mid = b_start + (b_end - b_start) / 2;

                if (mid * mid == x) {
                    return true;
                } else if (mid * mid < x) {
                    b_start = (int) mid + 1;
                } else {
                    b_end = (int) mid - 1;
                }
            }
        }
        return false;
    }
}


//Approach-4 (Using 2-Pointers)
//T.C : O(sqrt(c))
//S.C : O(1)
class Solution {
    public boolean judgeSquareSum(int c) {
        long a = 0;
        long b = (long) Math.sqrt(c);

        while (a <= b) {
            long k = a * a + b * b;

            if (k < c) {
                a++;
            } else if (k > c) {
                b--;
            } else {
                return true;
            }
        }

        return false;
    }
}
