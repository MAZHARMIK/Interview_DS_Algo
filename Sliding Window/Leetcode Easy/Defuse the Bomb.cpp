/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn   : https://www.youtube.com/watch?v=Z4tH40wH6JA
    Company Tags                  : Will update soon
    Leetcode Link                 : https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k
    Similar Easy Version Problem  : https://www.youtube.com/watch?v=D2MbogiFXWU
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Brute Force)
//T.C : O(n*|k|)
//S.C : O(1)
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();

        vector<int> result(n, 0);
        if (k == 0) {
            return result;
        }

        for (int i = 0; i < n; i++) {
            if (k < 0) {
                for (int j = i - abs(k); j < i; j++) {
                    result[i] += code[(j + n) % n];
                }
            } else {
                for (int j = i + 1; j < i + k + 1; j++) {
                    result[i] += code[j % n];
                }
            }
        }
        return result;
    }
};


//Approach-2 (Sliding Window)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();

        vector<int> result(n, 0);
        if(k == 0) {
            return result; //{0, 0, 0,...}
        }

        int i = -1, j = -1;
        if(k > 0) {
            i = 1;
            j = k;
        } else {
            i = n - abs(k);
            j = n-1;
        }

        int windowSum = 0;
        for(int pointer = i; pointer <= j; pointer++) {
            windowSum += code[pointer];
        }

        for(int k = 0; k < n; k++) { //result[k]
            result[k] = windowSum;

            windowSum -= code[i % n];
            i++;

            windowSum += code[(j+1)%n];
            j++;
        }

        return result;

    }
};



/**************************************************************** JAVA ****************************************************************/
//Approach-1 (Brute Force)
//T.C : O(n*|k|)
//S.C : O(1)
class Solution {
    public int[] decrypt(int[] code, int k) {
        int n = code.length;
        int[] result = new int[n];

        if (k == 0) {
            return result;
        }

        for (int i = 0; i < n; i++) {
            if (k < 0) {
                for (int j = i - Math.abs(k); j < i; j++) {
                    result[i] += code[(j + n) % n];
                }
            } else {
                for (int j = i + 1; j < i + k + 1; j++) {
                    result[i] += code[j % n];
                }
            }
        }

        return result;
    }
}


//Approach-2 (Sliding Window)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int[] decrypt(int[] code, int k) {
        int n = code.length;
        int[] result = new int[n];
        
        if (k == 0) {
            return result; // {0, 0, 0, ...}
        }

        int i = -1, j = -1;
        if (k > 0) {
            i = 1;
            j = k;
        } else {
            i = n - Math.abs(k);
            j = n - 1;
        }

        int windowSum = 0;
        for (int pointer = i; pointer <= j; pointer++) {
            windowSum += code[pointer];
        }

        for (int x = 0; x < n; x++) { // result[x]
            result[x] = windowSum;

            windowSum -= code[i % n];
            i++;

            windowSum += code[(j + 1) % n];
            j++;
        }

        return result;
    }
}
