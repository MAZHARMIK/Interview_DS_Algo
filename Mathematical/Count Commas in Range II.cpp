/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/count-commas-in-range-ii/description/
*/


/*********************************************************** C++ **************************************************/
//Approach-1 (counting simulation)
//T.C : O(log1000(n))
//S.C : O(1)
#define ll long long
class Solution {
public:
    long long countCommas(long long n) {
        ll result = 0;

        ll lower  = 1000;
        ll commas = 1;

        while(lower <= n) {
            ll upper = lower*1000 - 1;
            if(upper > n) upper = n;

            ll countNumbers = upper - lower + 1;
            result += (countNumbers * commas);

            lower *= 1000;
            commas++;
        }

        return result;
    }
};


//Approach-2 (Simplified counting simulation)
//T.C : O(log1000(n))
//S.C : O(1)
#define ll long long
class Solution {
public:
    long long countCommas(long long n) {
        ll result = 0;

        ll start = 1000;

        while(start <= n) {
            result += (n - start + 1);
            start *= 1000;
        }

        return result;
    }
};



/*********************************************************** JAVA **************************************************/
//Approach-1 (counting simulation)
//T.C : O(log1000(n))
//S.C : O(1)
class Solution {
    public long countCommas(long n) {
        long result = 0;
        long lower  = 1000;
        long commas = 1;
        while (lower <= n) {
            long upper = lower * 1000 - 1;
            if (upper > n) upper = n;
            long countNumbers = upper - lower + 1;
            result += (countNumbers * commas);
            lower *= 1000;
            commas++;
        }
        return result;
    }
}


//Approach-2 (Simplified counting simulation)
//T.C : O(log1000(n))
//S.C : O(1)
class Solution {
    public long countCommas(long n) {
        long result = 0;
        long start = 1000;
        while (start <= n) {
            result += (n - start + 1);
            start *= 1000;
        }
        return result;
    }
}
