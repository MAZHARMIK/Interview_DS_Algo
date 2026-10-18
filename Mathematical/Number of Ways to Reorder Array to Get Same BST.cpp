/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=YMe9Q2yZvBo
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/
*/

/*********************************************************** C++ **************************************************/
//Approach (Combinatorics and Pascal's Triangle)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
    typedef long long ll;
    ll MOD = 1e9 + 7;
    
    vector<vector<ll>> PT;
    
    int solve(vector<int>& nums) {
        int m = nums.size();
        
        if(m < 3)
            return 1;
        
        vector<int> left, right;
        
        int root = nums[0];
        for(int i = 1; i < m; i++) {
            
            if(nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
            
        }
        
        ll leftways  = solve(left)  % MOD;
        ll rightways = solve(right) % MOD;
        
        return (((leftways * rightways)%MOD) * PT[m-1][left.size()]) % MOD;
        
    }
    
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        
        
        PT.resize(n+1);
        
        for(int i = 0; i <= n; i++) {
            
            PT[i] = vector<long long>(i+1, 1);
            
            for(int j = 1; j < i; j++) {
                PT[i][j] = (PT[i-1][j-1] + PT[i-1][j]) % MOD;
            }
        }
        
        
        return (solve(nums)-1) % MOD;
    }
};



/*********************************************************** JAVA **************************************************/
//Approach (Combinatorics and Pascal's Triangle)
//T.C : O(n^2)
//S.C : O(n^2)
import java.util.*;

class Solution {
    private static final long MOD = 1_000_000_007L;
    private long[][] PT;

    private long solve(List<Integer> nums) {
        int m = nums.size();

        if (m < 3) {
            return 1;
        }

        List<Integer> left = new ArrayList<>();
        List<Integer> right = new ArrayList<>();

        int root = nums.get(0);
        for (int i = 1; i < m; i++) {
            if (nums.get(i) < root) {
                left.add(nums.get(i));
            } else {
                right.add(nums.get(i));
            }
        }

        long leftWays = solve(left) % MOD;
        long rightWays = solve(right) % MOD;

        return (((leftWays * rightWays) % MOD) * PT[m - 1][left.size()]) % MOD;
    }

    public int numOfWays(int[] nums) {
        int n = nums.length;

        // Build Pascal's triangle for nCr under modulo
        PT = new long[n + 1][];
        for (int i = 0; i <= n; i++) {
            PT[i] = new long[i + 1];
            Arrays.fill(PT[i], 1);

            for (int j = 1; j < i; j++) {
                PT[i][j] = (PT[i - 1][j - 1] + PT[i - 1][j]) % MOD;
            }
        }

        List<Integer> list = new ArrayList<>();
        for (int x : nums) {
            list.add(x);
        }

        return (int) ((solve(list) - 1 + MOD) % MOD);
    }
}
