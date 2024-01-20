/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=HRQB7-D2bi0
    Company Tags                : Facebook, Amazon, Google
    Leetcode Link               : https://leetcode.com/problems/sum-of-subarray-minimums/
*/


/****************************************************************** C++ ******************************************************************/
//Approach-1 (Simple Brute Force) - TLE
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int M = 1e9 + 7;
    int sumSubarrayMins(std::vector<int>& arr) {
        int n = arr.size();
        long result = 0;

        for (int i = 0; i < n; i++) {
            int minVal = arr[i];

            for (int j = i; j < n; j++) {
                minVal = min(minVal, arr[j]);
                result = (result + minVal) % M;
            }
        }

        return result;
    }
};


    
/*
    First see the code and video to understand, then read this paragraph.
    
    Explanation on why we have done "strictly less" in one case and "non-strictly less"
    in another. (They can be interchanged but both can't be non-strictly less)
    
    Ans : This it to avoid repeated inclusion of same subarray
          s . . . m1 . . . . . m2 . . . s’
          ....r1 ...... r2 ........ r3

Basically we have A[s] is the PLE of A[m1] (strictly less), and all the elements in-between
which I denote by r1 is greater than A[m1]. A[m1] == A[m2], and all elements in-between
which I denote by r2 are greater, and A[s'] is the NLE of A[m2] (strictly less), and again all
elements in-between which I denote by r3 are greater.

If we used the strictly less definition for both PLE and NLE, then A[s] and A[s'] are the PLE
and NLE for both A[m1] and A[m2]. m1 will count [r1, r2] and m2 will count [r2, r3], but
both will count [r1, r3]. To avoid this, notice our definition of NLE is less than or equal.
So that means NLE of A[m1] is A[m2]. This means [r1, r3] is only counted once.
*/
*/

//Approach-2
//T.C : O(n)
//S.C : O(n)
typedef unsigned long long ll;
class Solution {
public:
    
    //This is just we are finding next smaller to each element to left
    //Similar : Leetcode-84
    vector<int> getNSL(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;
        
        for(int i = 0; i<n; i++) {
            if(st.empty()) {
                result[i] = -1;
            } else {
                while(!st.empty() && arr[st.top()] > arr[i]) //strictly less
                    st.pop();
                
                result[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        
        return result;
    }
    
    //This is just we are finding next smaller to each element to right
    //Similar : Leetcode-84
    vector<int> getNSR(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;
        
        for(int i = n-1; i>=0; i--) {
            if(st.empty()) {
                result[i] = n;
            } else {
                while(!st.empty() && arr[st.top()] >= arr[i]) //non-strictly less
                    st.pop();
                
                result[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }
        
        return result;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> NSL = getNSL(arr, n); //Next smaller to left
        vector<int> NSR = getNSR(arr, n); //Next smaller to right
        
        
        ll sum = 0;
        int M = 1e9+7;
        for(int i = 0; i<n; i++) {
            ll d1 = i - NSL[i]; //distance to nearest smaller to left from i
            
            ll d2 = NSR[i] - i; //distance to nearest smaller to right from i
            
            /*
                we have d1 numbers in the left and d2 numbers in the right
                i.e. We have d1 options to start from the left of arr[i] 
                and d2 options to end in the right of arr[i]
                so the total options to start and end are d1*d2
            */
            ll total_ways_for_i_min = d1*d2;
            ll sum_i_in_total_ways  = arr[i] * (total_ways_for_i_min);
            
            sum  = (sum + sum_i_in_total_ways)%M;
        }
        
        return sum;
        
    }
};



/****************************************************************** JAVA ******************************************************************/
//Approach-1 (Simple Brute Force) - TLE
//T.C : O(n^2)
//S.C : O(1)
class Solution {
    final int M = 1000000007;

    public int sumSubarrayMins(int[] arr) {
        int n = arr.length;
        long result = 0;

        for (int i = 0; i < n; i++) {
            int minVal = arr[i];

            for (int j = i; j < n; j++) {
                minVal = Math.min(minVal, arr[j]);
                result = (result + minVal) % M;
            }
        }

        return (int) result;
    }
}


//Approach-2
//T.C : O(n)
//S.C : O(n)
public class Solution {
    public int[] getNSL(int[] arr, int n) {
        int[] result = new int[n];
        Stack<Integer> st = new Stack<>();

        for (int i = 0; i < n; i++) {
            while (!st.isEmpty() && arr[st.peek()] > arr[i]) {
                st.pop();
            }

            result[i] = st.isEmpty() ? -1 : st.peek();
            st.push(i);
        }

        return result;
    }

    public int[] getNSR(int[] arr, int n) {
        int[] result = new int[n];
        Stack<Integer> st = new Stack<>();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.isEmpty() && arr[st.peek()] >= arr[i]) {
                st.pop();
            }

            result[i] = st.isEmpty() ? n : st.peek();
            st.push(i);
        }

        return result;
    }

    public int sumSubarrayMins(int[] arr) {
        int n = arr.length;

        int[] NSL = getNSL(arr, n);
        int[] NSR = getNSR(arr, n);

        long sum = 0;
        int M = 1000000007;

        for (int i = 0; i < n; i++) {
            long d1 = i - NSL[i];
            long d2 = NSR[i] - i;
            
            long totalWaysForIMin = d1 * d2;
            long sumIInTotalWays = arr[i] * totalWaysForIMin;

            sum = (sum + sumIInTotalWays) % M;
        }

        return (int) sum;
    }
}
