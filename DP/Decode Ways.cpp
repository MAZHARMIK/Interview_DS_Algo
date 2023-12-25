/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=HW-y3gvQTVQ
    Company Tags                : Facebook, Uber, Google, Facebook, Microsoft
    Leetcode Link               : https://leetcode.com/problems/decode-ways/
    Four approaches             : Memoized, Top Down, Better Top Down, O(1) space DP
*/

/************************************************************************ C++ ***************************************************************/
//Approach-1 (Using Recursion + Memoization)
//T.C : O(n) after memoization (without memoization - O(2^n)
//S.C : O(101) ~= O(1)
class Solution {
public:
    int t[101];
    int solve(int i, string &s, int &n) {
        if(t[i] != -1) {
            return t[i];
        }

        if(i == n) {
            return t[i] = 1; //one valid split done
        }

        if(s[i] == '0') {
            return t[i] = 0; //not possible to split
        }

        int result     = solve(i+1, s, n);
        
        if(i+1 < n) {
            if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))
                result += solve(i+2, s, n);
        }

        
        return t[i] = result;

    }

    int numDecodings(string s) {
        int n = s.length();
        
        memset(t, -1, sizeof(t));
        return solve(0, s, n);
        

    }
};

//Approach-2 (Bottom Up Way-1)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int bottom_up_1(string&s, int n) {
        //simply simulate the memoized version
        vector<int> t(n+1, 0);
        //t[i] = ways to decode string from index i to n
        t[n] = 1;
        
        for(int i = n-1; i>=0; i--) {
            if(s[i] == '0')
                t[i] = 0;
            else {
                t[i] = t[i+1];
                if(i < n-1 && (s[i] == '1' || (s[i] == '2' && s[i+1] < '7')))
                    t[i] += t[i+2];
            }
        }
        return t[0];
    }
    
    int numDecodings(string &s) {
        int n = s.length();
        vector<int> t(n+1, -1);
        return bottom_up_1(s, n);
    }
};


//Approach-3 (Using Bottom Up Way-2)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int bottom_up_2(string&s, int n) {
        vector<int> t(n+1, 0);
        //t[i] = ways to decode string of length i
        t[0] = 1;
        t[1] = s[0]=='0'?0:1;
        
        for(int i = 2; i<=n; i++) {            
            if(s[i-1] != '0')
                t[i] += t[i-1];
                
            if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] < '7'))
                t[i] += t[i-2];
            
        }
        return t[n];
    }
    
    int numDecodings(string &s) {
        int n = s.length();
        vector<int> t(n+1, -1);
        return bottom_up_2(s, n);
    }
};

//Approach-4 
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if(n == 1)
            return s[0] == '0' ? 0 : 1;
        if(s[0] == '0')
            return 0;
        
        int last1 = 1, last2 = 1;
        
        for(int i = 1; i<n; i++) {
            int count = s[i] != '0' ? last1 : 0;
            
            if(s[i-1] == '1' || (s[i-1] == '2' && s[i] < '7'))
                count += last2;
            
            last2 = last1;
            last1  = count;
        }
        
        return last1;
    }
};



/************************************************************************ JAVA ***************************************************************/
//Approach-1 (Using Recursion + Memoization)
//T.C : O(n) after memoization (without memoization - O(2^n)
//S.C : O(101) ~= O(1)
public class Solution {
    private int[] t;

    public int solve(int i, String s, int n) {
        if (t[i] != -1) {
            return t[i];
        }

        if (i == n) {
            return t[i] = 1; // one valid split done
        }

        if (s.charAt(i) == '0') {
            return t[i] = 0; // not possible to split
        }

        int result = solve(i + 1, s, n);

        if (i + 1 < n) {
            if (s.charAt(i) == '1' || (s.charAt(i) == '2' && s.charAt(i + 1) <= '6'))
                result += solve(i + 2, s, n);
        }

        return t[i] = result;
    }

    public int numDecodings(String s) {
        int n = s.length();
        t = new int[101];
        Arrays.fill(t, -1);
        return solve(0, s, n);
    }
}


//Approach-2 (Bottom Up Way-1)
//T.C : O(n)
//S.C : O(n)
public class Solution {
    public int bottomUp1(String s, int n) {
        int[] t = new int[n + 1];
        ////t[i] = ways to decode string from index i to n
        Arrays.fill(t, 0);
        t[n] = 1;

        for (int i = n - 1; i >= 0; i--) {
            if (s.charAt(i) == '0') {
                t[i] = 0;
            } else {
                t[i] = t[i + 1];
                if (i < n - 1 && (s.charAt(i) == '1' || (s.charAt(i) == '2' && s.charAt(i + 1) < '7'))) {
                    t[i] += t[i + 2];
                }
            }
        }
        return t[0];
    }

    public int numDecodings(String s) {
        int n = s.length();
        return bottomUp1(s, n);
    }
}


//Approach-3 (Using Bottom Up Way-2)
//T.C : O(n)
//S.C : O(n)
public class Solution {
    public int bottomUp2(String s, int n) {
        int[] t = new int[n + 1];
        Arrays.fill(t, 0);
        t[0] = 1;
        t[1] = s.charAt(0) == '0' ? 0 : 1;

        for (int i = 2; i <= n; i++) {
            if (s.charAt(i - 1) != '0') {
                t[i] += t[i - 1];
            }

            if (s.charAt(i - 2) == '1' || (s.charAt(i - 2) == '2' && s.charAt(i - 1) < '7')) {
                t[i] += t[i - 2];
            }
        }
        return t[n];
    }

    public int numDecodings(String s) {
        int n = s.length();
        return bottomUp2(s, n);
    }
}


//Approach-4 
//T.C : O(n)
//S.C : O(1)
public class Solution {
    public int numDecodings(String s) {
        int n = s.length();
        if (n == 1) {
            return s.charAt(0) == '0' ? 0 : 1;
        }
        if (s.charAt(0) == '0') {
            return 0;
        }

        int last1 = 1, last2 = 1;

        for (int i = 1; i < n; i++) {
            int count = s.charAt(i) != '0' ? last1 : 0;

            if (s.charAt(i - 1) == '1' || (s.charAt(i - 1) == '2' && s.charAt(i) < '7')) {
                count += last2;
            }

            last2 = last1;
            last1 = count;
        }

        return last1;
    }
}
