/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=-2Z4ngPy4H0
      Company Tags                : Two Sigma
      Leetcode Link               : https://leetcode.com/problems/power-of-four/
*/

/******************************************************************* C++ ************************************************************************/
//Approach-1 (Simplest for loop)
//T.C : log(n) to base 4
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0){
            return false;
        }
        while(n%4 == 0){
            n /= 4;
        }
        return n==1;   
    }
};

//Approach-2 (Using Maths)
//T.C : O(log(a)) -> pow(4, a),the exponentiation operation still requires logarithmic time with respect to the value of a.
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        
        int a = (log(n)/log(4)); 
        /*
            4^a = n
            a = log(n) to base 4
            a = log(n) to base e / log(4) to base e
        */
        
        if(n == pow(4, a))
            return true;
        
        return false;
    }
};

//Approach-3 (Using Bit and Maths)
//T.C : O(1)
class Solution {
public:
    bool isPowerOfFour(int n) {

      /*
          num & (num - 1) == 0 : This checks if the number is a power of 2.
          (n - 1) % 3          : All numbers that are powers of 4 have this property. For example, 4^1 - 1 = 3, 4^2 - 1 = 15, 4^3 - 1 = 63, and so on.
          Maths proff of (n-1)%3 
          Consider three consecutive numbers: n, n+1, and n+2, where n is any integer. If n is a multiple of 3, then it is itself divisible by 3. 
          If n is one more than a multiple of 3, i.e., n=3k+1 for some integer k, 
          then n+2 = 3k+3 = 3(k+1) is a multiple of 3. 
          If n is two more than a multiple of 3, i.e., n=3k+2 for some integer kk, 
          then n+1 = 3k+3 = 3(k+1) is a multiple of 3.
      */
      
        return n > 0 && (n & (n - 1)) == 0 && (n - 1) % 3 == 0;
    }
};


/******************************************************************* JAVA ************************************************************************/
//Approach-1 (Simplest for loop)
//T.C : log(n) to base 4
class Solution {
    public boolean isPowerOfFour(int n) {
        if (n == 0) {
            return false;
        }
        while (n % 4 == 0) {
            n /= 4;
        }
        return n == 1;
    }
}


//Approach-2 (Using Maths)
//T.C : O(log(a)) -> pow(4, a),the exponentiation operation still requires logarithmic time with respect to the value of a.
class Solution {
    public boolean isPowerOfFour(int n) {
        if (n <= 0) {
            return false;
        }
        
        int a = (int) (Math.log(n) / Math.log(4));
        /*
            4^a = n
            a = log(n) to base 4
            a = log(n) to base e / log(4) to base e
        */
        
        return n == Math.pow(4, a);
    }
}


//Approach-3 (Using Bit and Maths)
//T.C : O(1)
class Solution {
    public boolean isPowerOfFour(int n) {
       /*
          num & (num - 1) == 0 : This checks if the number is a power of 2.
          (n - 1) % 3          : All numbers that are powers of 4 have this property. For example, 4^1 - 1 = 3, 4^2 - 1 = 15, 4^3 - 1 = 63, and so on.
          Maths proff of (n-1)%3 
          Consider three consecutive numbers: n, n+1, and n+2, where n is any integer. If n is a multiple of 3, then it is itself divisible by 3. 
          If n is one more than a multiple of 3, i.e., n=3k+1 for some integer k, 
          then n+2 = 3k+3 = 3(k+1) is a multiple of 3. 
          If n is two more than a multiple of 3, i.e., n=3k+2 for some integer kk, 
          then n+1 = 3k+3 = 3(k+1) is a multiple of 3.
      */
        return n > 0 && (n & (n - 1)) == 0 && (n - 1) % 3 == 0;
    }
}
