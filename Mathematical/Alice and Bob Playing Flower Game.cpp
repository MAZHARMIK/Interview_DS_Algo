/*     Scroll below to see JAVA code    */
/*
    MY YOUTUBE VIDEO ON THIS Qn                : https://www.youtube.com/watch?v=8PuV3IvUgk8
    Company Tags                               : will soon update
    Leetcode Link                              : https://leetcode.com/problems/alice-and-bob-playing-flower-game
    
*/

/****************************************************** C++ **************************************************************/
//Approach - Using simple maths
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    long long flowerGame(int n, int m) {
        return 1LL * ((n+1)/2) * (m/2) + 1LL * (n/2) * ((m+1)/2);
    }
};



/****************************************************** JAVA **************************************************************/
//Approach - Using simple maths
//T.C : O(1)
//S.C : O(1)
class Solution {
    public long flowerGame(int n, int m) {
        long oddN = (n + 1) / 2;   // ceil(n/2)
        long evenN = n / 2;        // floor(n/2)
        long oddM = (m + 1) / 2;   // ceil(m/2)
        long evenM = m / 2;        // floor(m/2)

        return oddN * evenM + evenN * oddM;
    }
}
