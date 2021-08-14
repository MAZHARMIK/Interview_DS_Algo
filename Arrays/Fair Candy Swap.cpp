/*
    Company Tags  : Fidessa
    Leetcode Link : https://leetcode.com/problems/fair-candy-swap/
*/

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sum_A = accumulate(begin(A), end(A), 0);
        int sum_B = accumulate(begin(B), end(B), 0);
        
        //According to question
        /*
            if we choose x from A and y from B
            sum_A - x + y = sum_B - y + x
            solve it:
            2*(y-x) = sum_B-sum_A;
            y - x   = (sum_B-sum_A)/2;
            
            So, if for any candy box 'x' in A, we have candy box
            y = (sum_B - sum_A)/2 + x; then we have the answer {x, y}
        */
        
        unordered_set<int> st(begin(B), end(B));
        int target = (sum_B - sum_A)/2;
        for(int &x : A) {
            if(st.count(target+x))
                return {x, target+x};
        }
        return {};
    }
};
