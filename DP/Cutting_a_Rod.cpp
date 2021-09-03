/*
    Company Tags : Amazon
    Link to Qn   : https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
*/

// A Dynamic Programming solution for Rod cutting problem
#include<bits/stdc++.h>
using namespace std;

//Memoized Approach (Top Down)
int cutRod_memoization(vector<int>& prices, int n, vector<int>& t) {
    if(n <= 0)
        return 0;
    if(t[n] != -1)
        return t[n];

    int maxVal = -1;
    //Cutting in different sizes and looking for max
    for(int i = 0; i<n; i++) {
        maxVal = max(maxVal, prices[i] + cutRod_memoization(prices, n-i-1, t));
    }
    return t[n] = maxVal;
}

//Unbounded Knapsack (Bottom Up)
int cutRod_top_down(vector<int>& prices) {
    int n = prices.size();
    vector<int> length(n);
    for(int i = 0; i<n; i++) {
        length[i] = i+1;
    }

    vector<vector<int>> t(n+1, vector<int>(n+1)); //length of rod = n (similar to weight of knapsack  = W)
    for(int i = 0; i<n+1; i++) {
        for(int j = 0; j<n+1; j++) {
            if(i == 0 || j == 0)
                t[i][j] = 0;
            else if(length[i-1] <= j) {
                t[i][j] = max(prices[i-1] + t[i][j-length[i-1]], t[i-1][j]); //unbounded knapsack
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][n];
}

//Bottom UP
int cutRod_bottom_up(vector<int>& arr)
{
   int n = arr.size();
   vector<int> val(n+1);    //val[i] = max profit from selling a rod up until length i
   vector<int> prices(n+1); //Just for ease of understanding and solving
   for(int i = 1; i<n+1; i++) prices[i] = arr[i-1];
   val[0] = 0;
   int j, i;

   // Build the table val[] in bottom up manner and return the last entry
   // from the table
    for(int j = 1; j<=n; j++) {
        int maxVal = -1;
        //Try cutting the rod of length j in different lengths i of sizes (1, 2, 3, 4, ... j)
        //why <=j ? Because we can't cut a rod of size j more than its length
        for(int i = 1; i<=j; i++) {
            int cost_to_cut_i                   = prices[i];
            int remaining_rod_length            = j-i;
            int remaining_rod_length_max_Profit = val[remaining_rod_length]; //pre stored result from past
            maxVal = max(maxVal, cost_to_cut_i + remaining_rod_length_max_Profit);
        }
        val[j] = maxVal;
    }

   return val[n];
}

/* Driver program to test above functions */
int main()
{
    vector<int> arr{1, 5, 8, 9, 10, 17, 17, 20};
    cout << "Maximum Obtainable Value is = " <<  cutRod_bottom_up(arr)   << endl;
    cout << "Maximum Obtainable Value is = " <<  cutRod_top_down(arr)    << endl;
    vector<int> t(arr.size()+1, -1);
    cout << "Maximum Obtainable Value is = " <<  cutRod_memoization(arr, arr.size(), t) << endl;
    return 0;
}
