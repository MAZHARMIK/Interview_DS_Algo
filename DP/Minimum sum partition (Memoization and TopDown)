/*
  Company Tags  : Amazon, Samsung,  Tower Research, Uber 
  Question Link : https://practice.geeksforgeeks.org/problems/minimum-sum-partition/0
*/

//Two Approaches

#include <iostream>
#include <vector>
using namespace std;

int minSubsetDiffMemoized(vector<int>& arr, int n, int s1, int sum, vector<vector<int>>& t){
    if(t[n][s1] != -1)
        return t[n][s1];
    if(n == 0)
        return t[n][s1] = abs(sum-2*s1);
    
    return t[n][s1] = min(minSubsetDiffMemoized(arr, n-1, s1+arr[n-1], sum, t), minSubsetDiffMemoized(arr, n-1, s1, sum, t));
}

int minSubsetDiffTopDown(vector<int>& nums, int n, int sum) {
    vector<vector<bool>> t(n+1, vector<bool>((sum/2)+1));
    for(int col = 1; col<(sum/2)+1; col++) {
        t[0][col] = false;
    }
    for(int row = 0; row<n+1; row++) {
        t[row][0] = true;
    }
    
    for(int i = 1; i<n+1; i++) {
        for(int j = 1; j<(sum/2)+1; j++) {
            if(nums[i-1] <= j) {
                t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    int j = sum/2;
    for(; j>=0; j--) {
        if(t[n][j] == true)
            break;
    }
    return sum - 2*j;
}


int main() {
	int T, n;
	cin >> T;
	while(T--){
	    cin >> n;
    	vector<int> nums(n);
    	for(int i = 0; i<n; i++){
    	    cin >> nums[i];
    	}
    	int sum = 0;
        for(int i :nums)
            sum += i;
        vector<vector<int>> t(n+1, vector<int>(sum+1, -1));
        cout << minSubsetDiffMemoized(nums, n, 0, sum, t) << endl;
        cout << minSubsetDiffTopDown(nums, n, sum) << endl;
	}
	return 0;
}
