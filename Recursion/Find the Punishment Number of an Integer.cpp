/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=SmnRAvkkohA
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/find-the-punishment-number-of-an-integer
*/


/************************************************************ C++ ************************************************/
//Approach-1 : (Recursion + Memoization)
//T.C : O(n * 2^(log10(n^2)))
//S.C : O(n * log10(n^2))
class Solution {
public:
    bool check(int i, int currsum, string s, int num, vector<vector<int>>& t) {
        if (i == s.length()) {
            return currsum == num;
        }
        if (currsum > num) 
            return false;

        if (t[i][currsum] != -1) //we have repeating subproblems. Draw tree diagram of "1296"
            return t[i][currsum];

        bool possible = false;
        for (int j = i; j < s.length(); j++) {
            string currentString = s.substr(i, j - i + 1);
            int addend = stoi(currentString);

            possible = possible || check(j + 1, currsum + addend, s, num, t);
            if (possible == true) 
                return true;
        }

        return t[i][currsum] = possible;
    }

    int punishmentNumber(int n) {
        int punishmentNum = 0;
        for (int num = 1; num <= n; num++) {
            int squareNum = num * num;
            string s = to_string(squareNum);

            vector<vector<int>> t(s.size(), vector<int>(num + 1, -1));

            if (check(0, 0, s, num, t)) {
                punishmentNum += squareNum;
            }
        }
        return punishmentNum;
    }
};


//Approach-2 : (Recursion + Memoization)
//T.C : O(n * 2^(log10(n^2)))
//S.C : O(log10(n^2))
class Solution {
public:
    bool check(int num, int currnum, int target) {
        if(num == 0) {
            return currnum == target;
        }
        
        return check(num / 10, currnum + num % 10, target) ||
               check(num / 100, currnum + num % 100, target) ||
               check(num / 1000, currnum + num % 1000, target) ||
               check(num / 10000, currnum + num % 10000, target);
    }

    int punishmentNumber(int n) {
        int punishmentNum = 0;
        for (int currentNum = 1; currentNum <= n; currentNum++) {
            int squareNum = currentNum * currentNum;
            if (check(squareNum, 0, currentNum)) {
                punishmentNum += squareNum;
            }
        }
        return punishmentNum;
    }
};


/************************************************************ Java ************************************************/
// Approach-1 : (Recursion + Memoization)
// T.C : O(n * 2^(log10(n^2)))
// S.C : O(n * log10(n^2))
class Solution {
    public boolean check(int i, int currsum, String s, int num, int[][] t) {
        if (i == s.length()) {
            return currsum == num;
        }
        if (currsum > num) 
            return false;
        
        if (t[i][currsum] != -1) // we have repeating subproblems. Draw tree diagram of "1296"
            return t[i][currsum] == 1;
        
        boolean possible = false;
        for (int j = i; j < s.length(); j++) {
            String currentString = s.substring(i, j + 1);
            int addend = Integer.parseInt(currentString);
            
            possible = possible || check(j + 1, currsum + addend, s, num, t);
            if (possible) 
                return t[i][currsum] = 1;
        }
        
        return t[i][currsum] = 0;
    }

    public int punishmentNumber(int n) {
        int punishmentNum = 0;
        for (int num = 1; num <= n; num++) {
            int squareNum = num * num;
            String s = Integer.toString(squareNum);
            
            int[][] t = new int[s.length()][num + 1];
            for (int[] row : t) {
                java.util.Arrays.fill(row, -1);
            }
            
            if (check(0, 0, s, num, t)) {
                punishmentNum += squareNum;
            }
        }
        return punishmentNum;
    }
}

// Approach-2 : (Recursion + Memoization)
// T.C : O(n * 2^(log10(n^2)))
// S.C : O(log10(n^2))
class Solution {
    public boolean check(int num, int currnum, int target) {
        if (num == 0) {
            return currnum == target;
        }
        
        return check(num / 10, currnum + num % 10, target) ||
               check(num / 100, currnum + num % 100, target) ||
               check(num / 1000, currnum + num % 1000, target) ||
               check(num / 10000, currnum + num % 10000, target);
    }

    public int punishmentNumber(int n) {
        int punishmentNum = 0;
        for (int currentNum = 1; currentNum <= n; currentNum++) {
            int squareNum = currentNum * currentNum;
            if (check(squareNum, 0, currentNum)) {
                punishmentNum += squareNum;
            }
        }
        return punishmentNum;
    }
}
