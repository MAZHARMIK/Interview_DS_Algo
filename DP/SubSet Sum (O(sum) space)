/*
  Company Tags : Amazon, Adobe, Drishti-Soft
  Question     : We generally solve subset sum problem using O(n*sum) space. This is a solution in which we do it using O(sum) space because if we notice, every row
                 depends the value of it's previous row only.
  Link to Qn   : https://www.geeksforgeeks.org/subset-sum-problem-osum-space/
*/

#include <iostream>
#include <vector>
using namespace std;

bool isSubSetSum(vector<int>& vec, int n, int sum) {
    vector<vector<bool>> t(2, vector<bool>(sum+1));

    for(int i = 0; i<n+1; i++) {
        for(int j = 0; j<sum+1; j++) {
            if(j == 0)
                t[i%2][j] = true;
            else if(i == 0)
                t[i%2][j] = false;
            else if(vec[i-1] <= j) {
                t[i%2][j] = t[(i+1)%2][j-vec[i-1]] || t[(i+1)%2][j];
            } else
                t[i%2][j] = t[(i+1)%2][j];
        }
    }

     for (int i = 0; i < 2; i++)
     {
       for (int j = 0; j <= sum; j++)
          cout << t[i][j] << " ";
       printf("\n");
     }

    return t[n%2][sum];
}

int main() {
    vector<int> vec{1, 2, 3};
    int sum = 4;
    int n = vec.size();
    cout << isSubSetSum(vec, n, sum);
    return 0;
}
