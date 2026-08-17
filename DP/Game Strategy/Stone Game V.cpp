/*         Scroll down to see JAVA code also                    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=zIy0DkjsNuI
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/stone-game-v
*/


/********************************************************************* C++ ****************************************************************/
//Approach-1 - Recursion + Memo
//T.C : O(n^3)
//S.C : O(n^2)
class Solution {
public:
    int t[501][501];
    int solve(int l, int r, vector<int>& cumSum) {
        if(l >= r) {
            return 0; //Zero score. No further division possible
        }

        if(t[l][r] != -1) {
            return t[l][r];
        }

        int score = 0;
        for(int mid = l; mid <= r-1; mid++) {
            int leftSum  = cumSum[mid] - (l-1 >= 0 ? cumSum[l-1] : 0); //[l..mid]
            int rightSum = cumSum[r] - cumSum[mid]; //mid+1, r

            if(leftSum < rightSum) {
                score = max(score, leftSum + solve(l, mid, cumSum));
            } else if(leftSum > rightSum) {
                score = max(score, rightSum + solve(mid+1, r, cumSum));
            } else {
                score = max({score, leftSum + solve(l, mid, cumSum), rightSum + solve(mid+1, r, cumSum)});
            }
        }

        return t[l][r] = score;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> cumSum(n, 0);
        cumSum[0] = stoneValue[0];
        for(int i = 1; i < n; i++) {
            cumSum[i] = cumSum[i-1] + stoneValue[i];
        }

        memset(t, -1, sizeof(t));
        return solve(0, n-1, cumSum);
    }
};



//Approach-2 - Recursion + Memo
//T.C : O(n^3)
//S.C : O(n^2)
class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> cumSum(n, 0);
        cumSum[0] = stoneValue[0];
        for (int i = 1; i < n; i++) {
            cumSum[i] = cumSum[i - 1] + stoneValue[i];
        }

        vector<vector<int>> t(n+1, vector<int>(n+1, 0));

        for(int l = n-1; l >= 0; l--) {
            for(int r = l+1; r < n; r++) {

                //l...r
                int score = 0;
                for(int mid = l; mid <= r-1; mid++) {
                    int leftSum  = cumSum[mid] - (l-1 >= 0 ? cumSum[l-1] : 0); //[l..mid]
                    int rightSum = cumSum[r] - cumSum[mid]; //mid+1, r

                    if(leftSum < rightSum) {
                        score = max(score, leftSum + t[l][mid]);
                    } else if(leftSum > rightSum) {
                        score = max(score, rightSum + t[mid+1][r]);
                    } else {
                        score = max({score, leftSum + t[l][mid], rightSum + t[mid+1][r]});
                    }
                }

                t[l][r] = score;
            }
        }

        return t[0][n-1];
    }
};



/********************************************************************* JAVA ****************************************************************/
//Approach-1 - Recursion + Memo
//T.C : O(n^3)
//S.C : O(n^2)
class Solution {
    int[][] t = new int[501][501];

    public int solve(int l, int r, int[] cumSum) {
        if(l >= r) {
            return 0; //Zero score. No further division possible
        }
        if(t[l][r] != -1) {
            return t[l][r];
        }
        int score = 0;
        for(int mid = l; mid <= r-1; mid++) {
            int leftSum  = cumSum[mid] - (l-1 >= 0 ? cumSum[l-1] : 0); //[l..mid]
            int rightSum = cumSum[r] - cumSum[mid]; //mid+1, r
            if(leftSum < rightSum) {
                score = Math.max(score, leftSum + solve(l, mid, cumSum));
            } else if(leftSum > rightSum) {
                score = Math.max(score, rightSum + solve(mid+1, r, cumSum));
            } else {
                score = Math.max(score, Math.max(leftSum + solve(l, mid, cumSum), rightSum + solve(mid+1, r, cumSum)));
            }
        }
        return t[l][r] = score;
    }

    public int stoneGameV(int[] stoneValue) {
        int n = stoneValue.length;
        int[] cumSum = new int[n];
        cumSum[0] = stoneValue[0];
        for(int i = 1; i < n; i++) {
            cumSum[i] = cumSum[i-1] + stoneValue[i];
        }
        for(int[] row : t) {
            Arrays.fill(row, -1);
        }
        return solve(0, n-1, cumSum);
    }
}

//Approach-2 - Bottom Up (Tabulation)
//T.C : O(n^3)
//S.C : O(n^2)
class Solution {
    public int stoneGameV(int[] stoneValue) {
        int n = stoneValue.length;
        int[] cumSum = new int[n];
        cumSum[0] = stoneValue[0];
        for (int i = 1; i < n; i++) {
            cumSum[i] = cumSum[i - 1] + stoneValue[i];
        }
        int[][] t = new int[n+1][n+1];
        for(int l = n-1; l >= 0; l--) {
            for(int r = l+1; r < n; r++) {
                //l...r
                int score = 0;
                for(int mid = l; mid <= r-1; mid++) {
                    int leftSum  = cumSum[mid] - (l-1 >= 0 ? cumSum[l-1] : 0); //[l..mid]
                    int rightSum = cumSum[r] - cumSum[mid]; //mid+1, r
                    if(leftSum < rightSum) {
                        score = Math.max(score, leftSum + t[l][mid]);
                    } else if(leftSum > rightSum) {
                        score = Math.max(score, rightSum + t[mid+1][r]);
                    } else {
                        score = Math.max(score, Math.max(leftSum + t[l][mid], rightSum + t[mid+1][r]));
                    }
                }
                t[l][r] = score;
            }
        }
        return t[0][n-1];
    }
}
