/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=AT_A8IcjRSg
    Company Tags                : will update soon
    GfG Link                    : https://www.geeksforgeeks.org/problems/count-digit-groupings-of-a-number1520/1
*/


/********************************************************************* C++ ********************************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : We are trying all possible substrings in worst case and iterating on those - O(n^3)
//S.C : O(n^2)
class Solution{
	public:
	int n;
	
	int t[101][10001];
	
	int solve(int idx, int prev_sum, string &str) {
	    if(idx >= n) {
	        return 1;
	    }
	    
	    if(t[idx][prev_sum] != -1) {
	        return t[idx][prev_sum];
	    }
	    
	    int result   = 0;
	    int curr_sum = 0;
	    for(int i = idx; i < n; i++) {
	        curr_sum += (str[i]-'0');
	        if(prev_sum <= curr_sum) {
	            result += solve(i+1, curr_sum, str);
	        }
	    }
	    
	    
	    return t[idx][prev_sum] = result;
	}
	
	int TotalCount(string str) {
	    n = str.length();
	    memset(t, -1, sizeof(t));
	    return solve(0, 0, str);
	}
};



//Approach-2 (Bottom Up)
//T.C : We are trying all possible substrings in worst case and iterating on those - O(n^3)
//S.C : O(n^2)
//Coming soon


/********************************************************************* JAVA ********************************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : We are trying all possible substrings in worst case and iterating on those - O(n^3)
//S.C : O(n^2)
class Solution
{
    private int n;
    private int[][] t;

    public int solve(int idx, int prev_sum, String str) {
        if (idx >= n) {
            return 1;
        }

        if (t[idx][prev_sum] != -1) {
            return t[idx][prev_sum];
        }

        int result = 0;
        int curr_sum = 0;
        for (int i = idx; i < n; i++) {
            curr_sum += (str.charAt(i) - '0');
            if (prev_sum <= curr_sum) {
                result += solve(i + 1, curr_sum, str);
            }
        }

        return t[idx][prev_sum] = result;
    }
    
    public int TotalCount(String str) {
        n = str.length();
        t = new int[101][10001];
        for (int[] row : t) {
            Arrays.fill(row, -1);
        }

        return solve(0, 0, str);
    }
}



//Approach-2 (Bottom Up)
//T.C : We are trying all possible substrings in worst case and iterating on those - O(n^3)
//S.C : O(n^2)
//Coming soon
