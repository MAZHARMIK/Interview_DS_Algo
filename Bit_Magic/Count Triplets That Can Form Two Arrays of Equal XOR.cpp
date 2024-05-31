/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=TgkxnZ6oPYU
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor
*/

/******************************************************** C++ ********************************************************/
//Approach (Better than brute force)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> prefixXor(begin(arr), end(arr));

        prefixXor.insert(prefixXor.begin(), 0); //initially the xor cumulative will be 0
        int n = prefixXor.size();

        for(int i = 1; i < n; i++) {
            prefixXor[i] ^= prefixXor[i-1];
        }

        int triplets = 0;

        for(int i = 0; i < n; i++) {
            for(int k = i+1; k < n; k++) {

                if(prefixXor[k] == prefixXor[i]) {
                    triplets += k-i-1;
                }

            }
        }

        return triplets;
    }
};


/******************************************************** JAVA ********************************************************/
//Approach (Better than brute force)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
    public int countTriplets(int[] arr) {
        int[] prefixXor = new int[arr.length + 1];
        
        // Initializing the first element to 0
        prefixXor[0] = 0;

        // Compute prefix XOR
        for (int i = 1; i <= arr.length; i++) {
            prefixXor[i] = prefixXor[i - 1] ^ arr[i - 1];
        }

        int triplets = 0;

        // Count the triplets
        for (int i = 0; i < prefixXor.length; i++) {
            for (int k = i + 1; k < prefixXor.length; k++) {
                if (prefixXor[k] == prefixXor[i]) {
                    triplets += k - i - 1;
                }
            }
        }

        return triplets;
    }
}
