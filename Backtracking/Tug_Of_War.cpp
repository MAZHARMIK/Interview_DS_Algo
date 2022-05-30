/*
    Company Tags : Amazon, Samsung (variation of this question)
*/

/*
Qn : You are given an array of n integers. You have to divide these n integers into 2 subsets such that difference of sum of two subsets is
as minimum as possible. 
Constraints - 
a) If n is even, both subsets will contain exactly n/2 elements.
b) If n is odd, one of the subsets will contain (n-1)/2 elements and other will contain (n+1)/2 elements.

Example : 
n = 6
{1, 2, 3, 4, 5, 6}

Output:
{1, 3, 6} {2, 4, 5}
*/


/*
    Note :
    (1) If in the question above, the constraints (a) and (b) were not given then this question is nothing but "Minimum Sum Partition" problem.
        Link to it is : https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/DP/Minimum%20sum%20partition%20(Memoization%20and%20TopDown)
    (3) If we only had even number of elements always, this qn would be similar to Leetcode-2035 (Check it out in my Bit_Magic section)
    (2) You can also store the results (set1 and set2) which results in minimum difference and print them if asked by interviewer
*/


int minDiff = INT_MAX;
void solve(vector<int>& arr, int idx, int n, vector<int> set1, vector<int> set2, int sum1, int sum2) {
    if(idx == n) {
        minDiff = min(minDiff, abs(sum1-sum2));
        return;
    }
  
    //handles even and odd cases
    //This is acutually an optimmization
    if(set1.size() <= (n+1)/2) {
        set1.push_back(arr[idx]);
        solve(arr, idx+1, n, set1, set2, sum1+arr[idx], sum2);
        set1.pop_back();
    }
    
    //handles even and odd cases
    //This is acutually an optimmization
    if(set2.size() <= (n+1)/2) {
        set2.push_back(arr[idx]);
        solve(arr, idx+1, n, set1, set2, sum1, sum2+arr[idx]);
        set2.pop_back();
    }
}

int tugOfWar(vector<int>& arr) {
    int n = arr.size();
    vector<int> set1;
    vector<int> set2;

    int sum_set1 = 0;
    int sum_set2 = 0;

    solve(arr, 0, n, set1, set2, sum_set1, sum_set2);
    return minDiff;
}
