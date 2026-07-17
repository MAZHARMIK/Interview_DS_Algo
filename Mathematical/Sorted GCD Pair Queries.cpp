/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/sorted-gcd-pair-queries/description/
*/

/*********************************************************** C++ **************************************************/
//Approach (Factorisation + Cumulative Sum + Binary Search)
//T.C : O(n·sqrt(M) + M·log M + Q·log M), M = maxVal
//S.C : O(M), M = maxVal
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int maxVal = *max_element(begin(nums), end(nums));

        vector<int> divisorFreq(maxVal+1, 0);
        for(int i = 0; i < n; i++) { //N*sqrt(maxVal)
            int num = nums[i]; //36

            for(int j = 1; j*j <= num; j++) {
                if(num % j == 0) {
                    divisorFreq[j]++;
                    if(num/j != j) {
                        divisorFreq[num/j]++;
                    }
                }
            }
        }

        vector<long long> pairsWithGcd(maxVal+1, 0);
        for(int g = maxVal; g >= 1; g--) {
            long long count = divisorFreq[g];
            //nC2
            pairsWithGcd[g] = count * (count-1)/2;

            //Correction time
            for(int mult = 2*g; mult <= maxVal; mult += g) {
                pairsWithGcd[g] -= pairsWithGcd[mult];
            }    
        }

        vector<long long> prefixCountGcd(maxVal+1, 0);
        for(int g = 1; g <= maxVal; g++) {
            prefixCountGcd[g] = prefixCountGcd[g-1] + pairsWithGcd[g];
        }

        vector<int> result;

        for(long long idx : queries) { //O(Q * log(maxVal))
            int l = 1;
            int r = maxVal;
            int temp = 1;
            while(l <= r) {
                int mid_gcd = l + (r-l)/2;

                if(prefixCountGcd[mid_gcd] > idx) {
                    temp = mid_gcd;
                    r = mid_gcd-1;
                } else {
                    l = mid_gcd+1;
                }
            }

            result.push_back(temp);
        }
        return result;
    }
};



/*********************************************************** JAVA **************************************************/
//Approach (Factorisation + Cumulative Sum + Binary Search)
//T.C : O(n·sqrt(M) + M·log M + Q·log M), M = maxVal
//S.C : O(M), M = maxVal
class Solution {
    public int[] gcdValues(int[] nums, long[] queries) {
        int n = nums.length;
        int maxVal = 0;
        for (int num : nums) {
            maxVal = Math.max(maxVal, num);
        }

        int[] divisorFreq = new int[maxVal + 1];
        for (int i = 0; i < n; i++) { // N*sqrt(maxVal)
            int num = nums[i]; // 36
            for (int j = 1; (long) j * j <= num; j++) {
                if (num % j == 0) {
                    divisorFreq[j]++;
                    if (num / j != j) {
                        divisorFreq[num / j]++;
                    }
                }
            }
        }

        long[] pairsWithGcd = new long[maxVal + 1];
        for (int g = maxVal; g >= 1; g--) {
            long count = divisorFreq[g];
            // nC2
            pairsWithGcd[g] = count * (count - 1) / 2;

            // Correction time
            for (int mult = 2 * g; mult <= maxVal; mult += g) {
                pairsWithGcd[g] -= pairsWithGcd[mult];
            }
        }

        long[] prefixCountGcd = new long[maxVal + 1];
        for (int g = 1; g <= maxVal; g++) {
            prefixCountGcd[g] = prefixCountGcd[g - 1] + pairsWithGcd[g];
        }

        int[] result = new int[queries.length];
        for (int q = 0; q < queries.length; q++) { // O(Q * log(maxVal))
            long idx = queries[q];
            int l = 1;
            int r = maxVal;
            int temp = 1;
            while (l <= r) {
                int mid_gcd = l + (r - l) / 2;

                if (prefixCountGcd[mid_gcd] > idx) {
                    temp = mid_gcd;
                    r = mid_gcd - 1;
                } else {
                    l = mid_gcd + 1;
                }
            }

            result[q] = temp;
        }
        return result;
    }
}
