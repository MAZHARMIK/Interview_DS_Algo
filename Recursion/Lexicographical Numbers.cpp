/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Bloomberg
    Leetcode Link               : https://leetcode.com/problems/lexicographical-numbers
*/


/************************************************************ C++ ************************************************/
//Approach (Simple Recursion - DFS)
//T.C : O(n) - We visit each number (1 to n) only once.
//S.C : O(d) - where d is the number of digits in n i.e. log10(n)
class Solution {
public:

    void solve(int curr, int n, vector<int>& result) {
        if(curr > n)
            return;
        
        result.push_back(curr);

        for(int nextDigit = 0; nextDigit <= 9; nextDigit++) {
            int nextnum = curr*10 + nextDigit;
            
            if(nextnum > n)
                return;
            
            solve(nextnum, n, result);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> result;
        
        for(int num = 1; num <= 9; num++)
            solve(num, n, result);
        
        return result;
    }
};




/************************************************************ JAVA ************************************************/
//Approach (Simple Recursion - DFS)
//T.C : O(n) - We visit each number (1 to n) only once.
//S.C : O(d) - where d is the number of digits in n i.e. log10(n)
class Solution {

    private void solve(int curr, int n, List<Integer> result) {
        if (curr > n) {
            return;
        }
        
        result.add(curr);  // Add current number to result
        
        // Generate the next number by appending digits 0 to 9
        for (int nextDigit = 0; nextDigit <= 9; nextDigit++) {
            int nextNum = curr * 10 + nextDigit;
            
            if (nextNum > n) {
                return;
            }
            
            solve(nextNum, n, result);  // Recursive call
        }
    }

    public List<Integer> lexicalOrder(int n) {
        List<Integer> result = new ArrayList<>();
        
        // Start from numbers 1 to 9
        for (int num = 1; num <= 9; num++) {
            solve(num, n, result);
        }
        
        return result;  // Return the result list
    }
}
