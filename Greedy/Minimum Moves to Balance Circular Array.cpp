/*     Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update later
    Leetcode Link               : https://leetcode.com/problems/minimum-moves-to-balance-circular-array/
*/


/************************************************************ C++ *****************************************************/
//Approach (Using Greedy)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    typedef long long ll;

    ll minMoves(vector<int>& balance) {
        int n = balance.size();

        int culpritIndex = -1;
        ll  sum          = 0;

        for (int i = 0; i < n; i++) {
            sum += balance[i];

            if (balance[i] < 0) {
                culpritIndex = i;
            }
            
        }

        if (culpritIndex == -1) 
            return 0;

        if (sum < 0) 
            return -1;

        ll moves = 0;
        int dist = 1; //neighbour

        while (balance[culpritIndex] < 0) {
            int right = (culpritIndex + dist) % n;
            int left  = (culpritIndex - dist + n) % n;

            ll available = balance[left] + balance[right];
            if(left == right)
                available -= balance[right];
            ll needed    = -balance[culpritIndex];
            ll taken     = min(needed, available);

            moves += taken * dist;
            balance[culpritIndex] += taken;

            dist++;
        }

        return moves;
    }
};



/************************************************************ JAVA *****************************************************/
//Approach (Using Greedy)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public long minMoves(int[] balance) {
        int n = balance.length;

        int culpritIndex = -1;
        long sum = 0;

        for (int i = 0; i < n; i++) {
            sum += balance[i];
            if (balance[i] < 0) {
                culpritIndex = i;
            }
        }

        if (culpritIndex == -1)
            return 0;

        if (sum < 0)
            return -1;

        long moves = 0;
        int dist = 1; // neighbour distance

        while (balance[culpritIndex] < 0) {
            int right = (culpritIndex + dist) % n;
            int left  = (culpritIndex - dist + n) % n;

            long available = (long) balance[left] + balance[right];
            if (left == right)
                available -= balance[right];

            long needed = -balance[culpritIndex];
            long taken = Math.min(needed, available);

            moves += taken * dist;
            balance[culpritIndex] += taken;

            dist++;
        }

        return moves;
    }
}
