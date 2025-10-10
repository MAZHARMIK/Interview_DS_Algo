/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 - Recursion + Memoization
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int n;
    int K;

    int solve(int i, vector<int>& energy, vector<int>& t) {
        if (i >= n) 
            return 0;
        
        if (t[i] != INT_MIN)
            return t[i];

        // Take energy at i and then best from (i + k) onwards - Recursion leap of faith
        t[i] = energy[i] + solve(i + K, energy, t);
        
        return t[i];
    }

    int maximumEnergy(vector<int>& energy, int k) {
        n = energy.size();
        K = k;
        vector<int> t(n, INT_MIN);     // Initialize memoization array

        int maxEnergy = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxEnergy = max(maxEnergy, solve(i, energy, t));
        }

        return maxEnergy;
    }
};


//Approach-2 - Bottom Up
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();

        // Fill dp values from the back
        for (int i = n - 1; i >= 0; i--) { //see my video to understand why right to left traversal is needed here
            if(i + k < n)
                energy[i] += energy[i + k];
        }

        int maxEnergy = energy[0];
        for (int i = 1; i < n; i++) {
            maxEnergy = max(maxEnergy, energy[i]);
        }

        return maxEnergy;
    }
};




/**************************************************************** JAVA ****************************************************************/
// Approach-1 - Recursion + Memoization
// T.C : O(n)
// S.C : O(n)
class Solution {
    private int n;
    private int K;
    private int solve(int i, int[] energy, int[] t) {
        if (i >= n) return 0;

        if (t[i] != Integer.MIN_VALUE) return t[i]; // Already computed

        // Take energy at i and then best from (i + k) onwards
        t[i] = energy[i] + solve(i + K, energy, t);
        return t[i];
    }

    public int maximumEnergy(int[] energy, int k) {
        n = energy.length;
        K = k;
        int[] t = new int[n];
        Arrays.fill(t, Integer.MIN_VALUE);

        int maxEnergy = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            maxEnergy = Math.max(maxEnergy, solve(i, energy, t));
        }

        return maxEnergy;
    }
}


// Approach-2 - Bottom Up
// T.C : O(n)
// S.C : O(1) extra (modifies input array)
class Solution {
    public int maximumEnergy(int[] energy, int k) {
        int n = energy.length;

        for (int i = n - 1; i >= 0; i--) { // see my video to understand why right to left traversal is needed here
            if (i + k < n) {
                energy[i] += energy[i + k];
            }
        }

        int maxEnergy = energy[0];
        for (int i = 1; i < n; i++) {
            maxEnergy = Math.max(maxEnergy, energy[i]);
        }

        return maxEnergy;
    }
}
