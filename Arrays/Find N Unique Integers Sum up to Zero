/*
    Company Tags  : NIL (If you get it, let me know please  :-) )
    Leetcode Link : https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
*/

//Logic :-
/*
    Let n = 7
    You need to take a number x, and fill
    -x, (-x)+1, (-x)+2 .... x (where x can't be 0)
    i.e. symmetrically fill from  [-x to +x] where x!=0

    What is x ?
    If you are filling symmetrically, then x should be half of n
    i.e. x = n/2;
    Now, what if n is odd
    In that case, append 0 in the front as it will not affect the sum
*/

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result(n);
        int i = 0;
        int x = -(n/2);
        if(n%2) //odd
            result[i++] = 0;
        
        //Fill symmetrically
        for(;i<n; i++) {
            if(x == 0) x++;
            result[i] = x++;
        }
        return result;
    }
};
