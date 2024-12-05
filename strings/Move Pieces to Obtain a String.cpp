/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/move-pieces-to-obtain-a-string
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Brute Force to check all possibilities)
//T.C : Exponential in the worst case due to exploring all possible swaps, though memoization reduces redundant computations.
//S.C : Memoization map to store all possible states. ~ O(n^2) states possible
class Solution {
public:
    int n;
    bool solve(string &start, string &target, unordered_map<string, bool>& mp) {
        if(start == target) {
            return true;
        }

        //Memoization
        if(mp.count(start)) {
            return mp[start];
        }

        for(int i = 0; i < start.length(); i++) {
            if(start[i] == 'L' && i > 0 && start[i-1] == '_') {
                swap(start[i], start[i-1]);
                if(solve(start, target, mp) == true) {
                    return true;
                }
                swap(start[i], start[i-1]);
            } else if(start[i] == 'R' && i < n-1 && start[i+1] == '_') {
                swap(start[i], start[i+1]);
                if(solve(start, target, mp) == true) {
                    return true;
                }
                swap(start[i], start[i+1]);
            }
        }

        return mp[start] = false;
    }

    bool canChange(string start, string target) {
        n = start.length();
        unordered_map<string, bool> mp;
        return solve(start, target, mp);
    }
};

//Approach-2 (Optimal using 2 pointers)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.length();
        int i = 0;
        int j = 0;

        while(i < n || j < n) {
            while(i < n && start[i] == '_') {
                i++;
            }

            while(j < n && target[j] == '_') {
                j++;
            }

            if(i == n || j == n) {
                return i == n && j == n;
            }

            if(start[i] != target[j]) {
                return false;
            }

            if(start[i] == 'L' && i < j) {
                return false;
            }

            if(start[i] == 'R' && i > j) {
                return false;
            }

            i++;
            j++;
            
        }

        return true;
    }
};



/**************************************************************** JAVA ****************************************************************/
//Approach-1 (Brute Force to check all possibilities)
//T.C : Exponential in the worst case due to exploring all possible swaps, though memoization reduces redundant computations.
//S.C : Memoization map to store all possible states. ~ O(n^2) states possible
public class Solution {
    public boolean canChange(String start, String target) {
        int n = start.length();
        Map<String, Boolean> memo = new HashMap<>();
        return solve(start, target, n, memo);
    }

    private boolean solve(String start, String target, int n, Map<String, Boolean> memo) {
        // Base case: if the start string matches the target
        if (start.equals(target)) {
            return true;
        }

        // Check if the result for this state is already memoized
        if (memo.containsKey(start)) {
            return memo.get(start);
        }

        // Try all possible valid swaps of 'L' and 'R' with '_'
        for (int i = 0; i < n; i++) {
            if (start.charAt(i) == 'L' && i > 0 && start.charAt(i - 1) == '_') {
                // Swap L with _
                String swapped = swap(start, i, i - 1);
                if (solve(swapped, target, n, memo)) {
                    return true;
                }
            } else if (start.charAt(i) == 'R' && i < n - 1 && start.charAt(i + 1) == '_') {
                // Swap R with _
                String swapped = swap(start, i, i + 1);
                if (solve(swapped, target, n, memo)) {
                    return true;
                }
            }
        }

        // Memoize the result for this state
        memo.put(start, false);
        return false;
    }

    // Utility function to swap characters at positions i and j in a string
    private String swap(String s, int i, int j) {
        char[] chars = s.toCharArray();
        char temp = chars[i];
        chars[i] = chars[j];
        chars[j] = temp;
        return new String(chars);
    }
}


//Approach-2 (Optimal using 2 pointers)
//T.C : O(n)
//S.C : O(1)
public class Solution {
    public boolean canChange(String start, String target) {
        int n = start.length();
        int i = 0, j = 0;

        while (i < n || j < n) {
            // Skip underscores in the start string
            while (i < n && start.charAt(i) == '_') {
                i++;
            }

            // Skip underscores in the target string
            while (j < n && target.charAt(j) == '_') {
                j++;
            }

            // Check if both pointers have reached the end
            if (i == n || j == n) {
                return i == n && j == n;
            }

            // If the characters at i and j are different, transformation is not possible
            if (start.charAt(i) != target.charAt(j)) {
                return false;
            }

            // Check for invalid moves
            if (start.charAt(i) == 'L' && i < j) {
                return false;  // 'L' can't move to the right
            }
            if (start.charAt(i) == 'R' && i > j) {
                return false;  // 'R' can't move to the left
            }

            // Move both pointers forward
            i++;
            j++;
        }

        return true;
    }
}
