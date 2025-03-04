/*     Scroll below to see JAVA code    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three
*/


//****************************************************** C++ ************************************************************************//
//Approach-1 (Using School Maths)
//T.C : O(log3(n))
//S.C : O(1)
class Solution {
public:
    bool checkPowersOfThree(int n) {
        int p = 0;

        while(pow(3, p) <= n) {
            p++;
        }

        while(n > 0) {
            if(n >= pow(3, p)) {
                n = n - pow(3, p);
            }

            if(n >= pow(3, p)) {
                return false;
            }

            p--;
        }

        return true;
    }
};


//Approach-2 (Using Ternary Representation)
//T.C : O(log3(n))
//S.C : O(1)
class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n > 0) {
            if(n%3 == 2) {
                return false;
            }

            n = n/3;
        }

        return true;
    }
};


//Approach-3 (Using take and not take power)
//T.C : O(2^(log3(n)))
//S.C : O(log3(n)) system resuction stack space
class Solution {
public:
    int solve(int n, int p) {
        if(n == 0) {
            return true;
        }

        if(pow(3, p) > n) {
            return false;
        }

        bool p_ko_lelo = solve(n - pow(3, p), p+1);

        bool p_ko_nahi_lo = solve(n, p+1);

        return p_ko_lelo || p_ko_nahi_lo;
    }

    bool checkPowersOfThree(int n) {
        return solve(n, 0);
    }
};



//****************************************************** Java ************************************************************************//
// Approach-1 (Using School Maths)
// T.C : O(log3(n))
// S.C : O(1)
class Solution {
    public boolean checkPowersOfThree(int n) {
        int p = 0;

        while (Math.pow(3, p) <= n) {
            p++;
        }

        while (n > 0) {
            if (n >= Math.pow(3, p)) {
                n -= Math.pow(3, p);
            }

            if (n >= Math.pow(3, p)) {
                return false;
            }

            p--;
        }

        return true;
    }
}

// Approach-2 (Using Ternary Representation)
// T.C : O(log3(n))
// S.C : O(1)
class Solution {
    public boolean checkPowersOfThree(int n) {
        while (n > 0) {
            if (n % 3 == 2) {
                return false;
            }
            n /= 3;
        }
        return true;
    }
}

// Approach-3 (Using take and not take power)
// T.C : O(2^(log3(n)))
// S.C : O(log3(n)) system recursion stack space
class Solution {
    private boolean solve(int n, int p) {
        if (n == 0) {
            return true;
        }
        
        if (Math.pow(3, p) > n) {
            return false;
        }
        
        boolean p_ko_lelo = solve(n - (int)Math.pow(3, p), p + 1);
        boolean p_ko_nahi_lo = solve(n, p + 1);
        
        return p_ko_lelo || p_ko_nahi_lo;
    }
    
    public boolean checkPowersOfThree(int n) {
        return solve(n, 0);
    }
}
