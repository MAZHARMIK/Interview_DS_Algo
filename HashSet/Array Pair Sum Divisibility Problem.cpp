/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=FUPP7bHG9Dw
    Company Tags                : Amazon, Microsoft, Goldman Sachs, Directi
    Leetcode Link           : https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/
*/
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();

        // If the number of elements is odd, we can't pair all of them.
        if (n % 2 == 1) {
            return false;
        }

        unordered_multiset<int> st;

        for (int i = 0; i < n; i++) {
            // Compute the remainder of the current element.
            int r1 = arr[i] % k;
            if (r1 < 0) {
                r1 += k; // Ensure remainder is non-negative
            }

            // The other part of the pair should sum with r1 to be a multiple of k.
            int r2 = (k - r1) % k;

            // Check if the counterpart of this remainder exists in the multiset.
            auto it = st.find(r2);
            if (it != st.end()) {
                st.erase(it); // If found, remove one counterpart.
            } else {
                st.insert(r1); // Otherwise, add the current remainder.
            }
        }

        // If the multiset is empty, it means all pairs are correctly formed.
        return st.empty();
    }
};
