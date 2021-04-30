/*
    Company Tags  : Let me know when you get it :-)
    Leetcode Link : https://leetcode.com/problems/powerful-integers/
*/

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        
        //Max value of x^i can be bound-1 when y^0 = 1;
        //So we need not go beyond i (say bound_i) after which x exceeds bound
        //Same for y^j
        //There are two ways to find this bound_i and bound_j
        
        //Way-1 (Simply loop and find the last i which is valid)
        int bound_i = 0;
        int temp    = 1;
        while(x != 1 && temp<=bound) {
            temp *= x;
            bound_i++;
        }
        
        int bound_j = 0;
        temp        = 1;
        while(y != 1 && temp<=bound) {
            temp *= y;
            bound_j++;
        }
        
        //Way-2 (using maths)
        bound_i = x == 1 ? bound : log(bound)/log(x);
        bound_j = y == 1 ? bound : log(bound)/log(y);
        
        
        unordered_set<int> st;
        
        for(int i = 0; i<=bound_i; i++) {
            for(int j = 0; j<=bound_j; j++) {
                int n = pow(x, i) + pow(y, j);
                if(n <= bound)
                    st.insert(n);
                if(y == 1)
                    break;
            }
            if(x == 1)
                break;
        }
        
        vector<int> result(st.begin(), st.end());
        return result;
    }
};
