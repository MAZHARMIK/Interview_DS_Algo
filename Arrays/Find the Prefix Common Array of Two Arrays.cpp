/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=hVda-pNPiuA
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays
*/


/************************************************************ C++ *****************************************************/
//Approach-1 (Brute Force)
//T.C : O(n^3)
//S.C : O(1)
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> result(n);

        for(int i = 0 ; i < n; i++) {
            int count = 0;

            for(int x = 0; x <= i; x++) { //A
                //Find if we have A[x] in B or not till index i
                for(int y = 0; y <= i; y++) { //B
                    if(B[y] == A[x]) {
                        count++;
                        break;
                    }
                }
            }

            result[i] = count;

        }

        return result;
    }
};


//Approach-2 (Better Approach)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> result(n);

        vector<bool> isPresentA(n+1, false); //isPresent[i] = true, means i is present in A
        vector<bool> isPresentB(n+1, false); //....

        for(int i = 0; i < n; i++) {
            isPresentA[A[i]] = true;
            isPresentB[B[i]] = true;

            int count = 0;
            for(int num = 1; num <= n; num++) {
                if(isPresentA[num] == true && isPresentB[num] == true) {
                    count++;
                }
            }

            result[i] = count;
        }

        return result;
    }
};


//Approach-3 (Optimal Approach)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> result(n);

        unordered_map<int, int> mp;

        int count = 0;
        for(int i = 0; i < n; i++) {
            mp[A[i]]++;
            if(mp[A[i]] == 2) {
                count++;
            }

            mp[B[i]]++;
            if(mp[B[i]] == 2) {
                count++;
            }

            result[i] = count;
        }

        return result;
    }
};



/************************************************************ JAVA *****************************************************/
//Approach-1 (Brute Force)
//T.C : O(n^3)
//S.C : O(1)
class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n = A.length;

        int[] result = new int[n];

        for(int i = 0; i < n; i++) {
            int count = 0;

            for(int x = 0; x <= i; x++) {
                for(int y = 0; y <= i; y++) {
                    if(B[y] == A[x]) {
                        count++;
                        break;
                    }
                }
            }

            result[i] = count;
        }

        return result;

    }
}


//Approach-2 (Better Approach)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n = A.length;

        int[] result = new int[n];

        boolean[] isPresentA = new boolean[n+1];
        boolean[] isPresentB = new boolean[n+1];

        for(int i = 0; i < n; i++) {
            isPresentA[A[i]] = true;
            isPresentB[B[i]] = true;

            int count = 0;
            for(int num = 1; num <= n; num++) {
                if(isPresentA[num] == true && isPresentB[num] == true) {
                    count++;
                }
            }

            result[i] = count;
        }

        return result;
    }
}


//Approach-3 (Optimal Approach)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n = A.length;

        int[] result = new int[n];

        HashMap<Integer, Integer> mp = new HashMap();

        int count = 0;

        for(int i = 0; i < n; i++) {
            mp.put(A[i], mp.getOrDefault(A[i], 0) + 1); //mp[A[i]]++ ;
            if(mp.get(A[i]) == 2) {
                count++;
            }
            
            mp.put(B[i], mp.getOrDefault(B[i], 0) + 1); //mp[B[i]]++ ;
            if(mp.get(B[i]) == 2) {
                count++;
            }

            result[i] = count;

        }

        return result;
    }
}
