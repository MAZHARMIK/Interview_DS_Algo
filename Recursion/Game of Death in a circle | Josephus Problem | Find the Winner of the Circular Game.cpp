/*      					Scroll down to see JAVA code also 					*/
/*
	MY YOUTUBE VIDEO ON THIS Qn : 
    	Company Tags 		    : NIL
        Leetcode Link		    : https://leetcode.com/problems/find-the-winner-of-the-circular-game
    	GFG Link      		    : https://www.geeksforgeeks.org/problems/game-of-death-in-a-circle1840/1
*/

/*************************************************************** C++ ***************************************************************/
//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
  public:
    void solve(int k, vector<int> arr, int& ans, int index) {
        if(arr.size() == 1) {
            ans = arr[0];
            return;
        }
        
        index = (index+k)%arr.size();
        arr.erase(arr.begin()+index);
        
        solve(k, arr, ans, index);
    }

    int safePos(int n, int k) {
        vector<int> arr(n);
	    int ans = -1;
	    for(int i = 0; i<n; i++) {
	        arr[i] = i+1;
	    }
        solve(k-1, arr, ans, 0);
        return ans;
    }
};


//Approach-2 (Optimal)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:

    int solve(int n, int k) {
        if(n == 1) {
            return 0;
        }

        return (solve(n-1, k) + k)%n;
    }

    int findTheWinner(int n, int k) {
        return solve(n, k)+1;
    }
};


/*************************************************************** JAVA ***************************************************************/
//T.C : O(n^2)
//S.C : O(n)
class Solution {
    public static void solve(int k, List<Integer> arr, int[] ans, int index) {
        if (arr.size() == 1) {
            ans[0] = arr.get(0);
            return;
        }

        index = (index + k) % arr.size();
        arr.remove(index);

        solve(k, arr, ans, index);
    }

    public static int safePos(int n, int k) {
        List<Integer> arr = new ArrayList<>();
        int[] ans = {-1};
        for (int i = 0; i < n; i++) {
            arr.add(i + 1);
        }
        solve(k - 1, arr, ans, 0);
        return ans[0];
    }
}


//Approach-2 (Optimal)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
    public int solve(int n, int k) {
        if (n == 1) {
            return 0;
        }

        return (solve(n - 1, k) + k) % n;
    }

    public int findTheWinner(int n, int k) {
        return solve(n, k) + 1;
    }
}
