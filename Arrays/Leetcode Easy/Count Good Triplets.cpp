/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=wKrBZd2GAZM
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/count-good-triplets
*/

/*********************************************************** C++ **************************************************/
//Approach (Simple straight forward with slight improvements)
//T.C : O(n^3) 
//S.C : O(1)
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int count = 0;

        for(int i = 0; i <= n-3; i++) {
            for(int j = i+1; j <= n-2; j++) {

                if(abs(arr[i] - arr[j]) <= a) {
                    for(int k = j+1; k <= n-1; k++) {
                        if(abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
                            count++;
                        }
                    }
                }
            }
        }

        return count;

    }
};


/*********************************************************** JAVA **************************************************/
//Approach (Simple straight forward with slight improvements)
//T.C : O(n^3) 
//S.C : O(1)
class Solution {
    public int countGoodTriplets(int[] arr, int a, int b, int c) {
        int n = arr.length;
        int count = 0;

        for (int i = 0; i <= n - 3; i++) {
            for (int j = i + 1; j <= n - 2; j++) {
                if (Math.abs(arr[i] - arr[j]) <= a) {
                    for (int k = j + 1; k <= n - 1; k++) {
                        if (Math.abs(arr[j] - arr[k]) <= b && Math.abs(arr[i] - arr[k]) <= c) {
                            count++;
                        }
                    }
                }
            }
        }

        return count;
    }
}
