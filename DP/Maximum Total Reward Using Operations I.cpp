/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : Let me know if you need it. I will be happy to create one for this problem
    Company Tags                : Will soon update
    Leetcode Link               : https://leetcode.com/problems/maximum-total-reward-using-operations-i/description/
*/


/*************************************************************** C++ *************************************************/
//Approach-1 (Using Recursion + Memo)
//T.C : O(nlogn)
//S.C : size of t is constant 2001*4000
class Solution {
public:
    vector<vector<int>> t;
    int solve(int i, vector<int>& rewardValues, int x) {
        if(i >= rewardValues.size())
            return 0;

        if(t[i][x] != -1)
            return t[i][x];   
        
        int take = 0;
        if(x < rewardValues[i]) {
            take = rewardValues[i] + solve(i+1, rewardValues, x+rewardValues[i]); 
        }
        int skip = solve(i+1, rewardValues, x);

        return t[i][x] = max(take, skip);
    }

    int maxTotalReward(vector<int>& rewardValues)  {
        int n = rewardValues.size();

        sort(rewardValues.begin(),rewardValues.end());
        /*
            because we want to pick in order and get max also.
            For exampel : {6, 1, 3}
            If you pick 6 directly, then you won't be able to pick 1 or 3 because they are smaller than your current
            reward i.e. 6
            So,  it's better to sort the array and pick from smallest to largest
            So, we sort the array
            {1, 3, 6}
            Now, you can pick 1, and then 3 (total = 4)
            Now you can also pick 6 because 4 < 6
            So, total = 1 + 3 + 6 = 10

        */
        
        t.resize(2001,vector<int>(4000, -1));
        /*
            Assume, we picked the last elements = x
            The max possible value of reward before that we could pick will be x-1.
            This means total sum =  x + (x-1) = 2*x-1;
            As per constraints, max value of x = 2000, so at max we can get = 2*2000 -1 = 3999
            So I took 4000 as max constraint value for rewards
        */

        return solve(0, rewardValues, 0);
    }
};

//Approach-2 (Bottom Up)
//coming soon when I get some free time

/*************************************************************** JAVA *************************************************/
//Approach-1 (Using Recursion + Memo) - Might give TLE
//T.C : O(nlogn)
//S.C : size of t is constant 2001*4000
class Solution {
    private int[][] t;

    public int solve(int i, int[] rewardValues, int x) {
        if (i >= rewardValues.length)
            return 0;

        if (t[i][x] != -1)
            return t[i][x];

        int take = 0;
        if (x < rewardValues[i]) {
            take = rewardValues[i] + solve(i + 1, rewardValues, x + rewardValues[i]);
        }
        int skip = solve(i + 1, rewardValues, x);

        return t[i][x] = Math.max(take, skip);
    }

    public int maxTotalReward(int[] rewardValues) {
        int n = rewardValues.length;

        Arrays.sort(rewardValues);

        t = new int[2001][4000];
        for (int[] row : t) {
            Arrays.fill(row, -1);
        }

        return solve(0, rewardValues, 0);
    }
}


//Approach-2 (Bottom Up)
//coming soon when I get some free time
