/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=OwEggxOnszA
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/max-chunks-to-make-sorted
*/

/**************************************************************** C++ ****************************************************************/
//Approach-1 (Using prefixMax and SuffixMin)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefixMax(begin(arr), end(arr));
        vector<int> suffixMin(begin(arr), end(arr));

        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], prefixMax[i]);
        }

        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i + 1], suffixMin[i]);
        }

        int chunksCount = 0;
        for (int i = 0; i < n; i++) {
            int pehleKaMax = i > 0 ? prefixMax[i - 1] : -1;
            int baadKaMin  = suffixMin[i];
            
            if(pehleKaMax < baadKaMin) {
                chunksCount++;
            }
        }

        return chunksCount;
    }
};


//Approach-2 (Using cumulative Sum)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int cumSum    = 0;
        int normalSum = 0;

        int chunksCount = 0;
        for(int i = 0; i < n; i++) {
            cumSum += arr[i];
            normalSum += i;

            if(cumSum == normalSum) {
                chunksCount++;
            }
        }

        return chunksCount;
    }
};


//Approach-3 (Using max check)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int maxTillNow = -1;

        int chunksCount = 0;
        for(int i = 0; i < n; i++) {
            maxTillNow = max(maxTillNow, arr[i]);

            if(maxTillNow == i) {
                chunksCount++;
            }
        }

        return chunksCount;
    }
};


/**************************************************************** JAVA ****************************************************************/
// Approach-1 (Using prefixMax and SuffixMin)
// T.C : O(n)
// S.C : O(n)
class Solution {
    public int maxChunksToSorted(int[] arr) {
        int n = arr.length;
        int[] prefixMax = arr.clone();
        int[] suffixMin = arr.clone();

        for (int i = 1; i < n; i++) {
            prefixMax[i] = Math.max(prefixMax[i - 1], prefixMax[i]);
        }

        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = Math.min(suffixMin[i + 1], suffixMin[i]);
        }

        int chunksCount = 0;
        for (int i = 0; i < n; i++) {
            int pehleKaMax = i > 0 ? prefixMax[i - 1] : -1;
            int baadKaMin = suffixMin[i];

            if (pehleKaMax < baadKaMin) {
                chunksCount++;
            }
        }

        return chunksCount;
    }
}


// Approach-2 (Using cumulative Sum)
// T.C : O(n)
// S.C : O(1)
class Solution {
    public int maxChunksToSorted(int[] arr) {
        int n = arr.length;
        int cumSum = 0;
        int normalSum = 0;

        int chunksCount = 0;
        for (int i = 0; i < n; i++) {
            cumSum += arr[i];
            normalSum += i;

            if (cumSum == normalSum) {
                chunksCount++;
            }
        }

        return chunksCount;
    }
}


// Approach-3 (Using max check)
// T.C : O(n)
// S.C : O(1)
class Solution {
    public int maxChunksToSorted(int[] arr) {
        int n = arr.length;
        int maxTillNow = -1;

        int chunksCount = 0;
        for (int i = 0; i < n; i++) {
            maxTillNow = Math.max(maxTillNow, arr[i]);

            if (maxTillNow == i) {
                chunksCount++;
            }
        }

        return chunksCount;
    }
}
