/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=_tAArozuTwA
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum
*/


/************************************************************ C++ *****************************************************/
//Approach-1 (Brute Force)
//T.C : O(n^3)
//S.C : O(1)
class Solution {
public:
    const int M = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += arr[k];
                }
                if (sum % 2 != 0) {
                    count++;
                }
            }
        }
        
        return count % M;
    }
};

//Approach-2 (Better Brute Force)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    const int M = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                if (sum % 2 != 0) {
                    count = (count+1)%M;
                }
            }
        }
        
        return count % M;
    }
};


//Approach-3 (Optimal using prefix-sum array)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int M = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();

        vector<int> prefix(n, 0);
        prefix[0] = arr[0];

        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + arr[i];
        }

        int count = 0;
        int odd = 0;
        int even = 1;

        for(int i = 0; i < n; i++) {
            if(prefix[i]%2 == 0) { //odd + even = odd
                count = (count + odd) % M;
                even++;
            } else { //even + odd = odd
                count = (count + even) % M;
                odd++;
            }
        }

        return count;
    }
};

//Approach-4 (Optimal using constant space)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int M = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();

        int count = 0;
        int odd = 0;
        int even = 1;
        int sum = 0;

        for(int i = 0; i < n; i++) {
            sum += arr[i];

            if(sum%2 == 0) { //odd + even = odd
                count = (count + odd) % M;
                even++;
            } else { //even + odd = odd
                count = (count + even) % M;
                odd++;
            }
        }

        return count;
    }
};


/************************************************************ Java *****************************************************/
//Approach-1 (Brute Force)
//T.C : O(n^3)
//S.C : O(1)
class Solution {
    public int numOfSubarrays(int[] arr) {
        int n = arr.length;
        int count = 0;
        int M = (int)1e9 + 7;
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += arr[k];
                }
                if (sum % 2 != 0) {
                    count++;
                }
            }
        }
        
        return count % M;
    }
}

//Approach-2 (Better Brute Force)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
    public int numOfSubarrays(int[] arr) {
        int n = arr.length;
        int count = 0;
        int M = (int)1e9 + 7;
        
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                if (sum % 2 != 0) {
                    count = (count + 1) % M;
                }
            }
        }
        
        return count % M;
    }
}

//Approach-3 (Optimal using prefix-sum array)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int numOfSubarrays(int[] arr) {
        int n = arr.length;
        int M = (int)1e9 + 7;

        int[] prefix = new int[n];
        prefix[0] = arr[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }

        int count = 0;
        int odd = 0;
        int even = 1;

        for (int i = 0; i < n; i++) {
            if (prefix[i] % 2 == 0) { // odd + even = odd
                count = (count + odd) % M;
                even++;
            } else { // even + odd = odd
                count = (count + even) % M;
                odd++;
            }
        }

        return count;
    }
}

//Approach-4 (Optimal using constant space)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int numOfSubarrays(int[] arr) {
        int n = arr.length;
        int M = (int)1e9 + 7;

        int count = 0;
        int odd = 0;
        int even = 1;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            if (sum % 2 == 0) { // odd + even = odd
                count = (count + odd) % M;
                even++;
            } else { // even + odd = odd
                count = (count + even) % M;
                odd++;
            }
        }

        return count;
    }
}
