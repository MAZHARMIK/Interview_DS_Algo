/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=JlBSoswl87c
      Company Tags                : META
      Leetcode Link               : https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/
*/

/**************************************************************** C++ ****************************************************************/
class Solution {
public:
    int M = 1e9+7;
    
    int countOrders(int n) {
        if(n == 1)
            return 1;

        long long result = 1;
        for(int i = 2; i <= n; i++) {
            
            int spaces = (i-1)*2 + 1;
            
            int possibility_of_i = spaces * (spaces+1)/2;
            
            result *= possibility_of_i;
            
            result %= M;
            
        }
        return result;
    }
};


/**************************************************************** JAVA ****************************************************************/
class Solution {
    public int M = 1000000007;
    
    public int countOrders(int n) {
        if(n == 1)
            return 1;
        long result = 1; 
        for(int i = 2; i<=n; i++) {
            int spaces = (i-1)*2 + 1;
            
            int possibility = spaces * (spaces+1)/2;
            
            result *= possibility;
            
            result %= M;
        }
        return (int)result;
    }
}
