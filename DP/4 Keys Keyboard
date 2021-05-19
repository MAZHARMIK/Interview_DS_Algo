/*
    Company Tags  : Amazon, Google, Paytm
    Leetcode Link : https://leetcode.com/problems/4-keys-keyboard/
    Since , it's a premium question, here is the description below :
    Description
     Imagine you have a special keyboard with the following keys:
      Key 1: (A): Print one 'A' on screen.
      Key 2: (Ctrl-A): Select the whole screen.
      Key 3: (Ctrl-C): Copy selection to buffer.
      Key 4: (Ctrl-V): Print buffer on screen appending it after what has already been printed.
      Now, you can only press the keyboard for N times (with the above four keys), find out the maximum numbers of 'A' you can print on screen.
      
      Example 1:

      Input: N = 3
      Output: 3
      Explanation: 
      We can at most get 3 A's on screen by pressing following key sequence:
      A, A, A

      Example 2:

      Input: N = 7
      Output: 9
      Explanation: 
      We can at most get 9 A's on screen by pressing following key sequence:
      A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V

      Note:
      1 <= N <= 50
      Answers will be in the range of 32-bit signed integer.

*/

How to approach this question ?
/*
    Let, N = 7;
    We keep ctrlA, ctrlC, ctrlV in hand to paste all characters
    So, we have kept 3 operatiosn out of 7 for above.
    So, we have N = 7-3 = 4 operations
    Let's take 4 A's and see what we get
    AAAA = 4 times key_1 (we are left with 3 operations that we planned)
    So, lets F(4) = 4
    AAAA + ctrlA + ctrlC + ctrlV
    or, F(4) + ctrlA + ctrlC + F(4) = AAAAAAAA (8 A's) = F(4) * 2
    -----------------------
    What if we took 3 As in the beginning
    AAA + ctrlA + ctrlC + ctrlV = 6 steps
    Now,we are left with onyl one more step.
    So, we do ctrlV one more time
    We finally get
    AAA + ctrlA + ctrlC + ctrlV + ctrlV
    or, 
    F(3) + ctrlA + ctrlC + F(3) + F(3) = F(3) * 3
    -----------------------
    What if we took 2 As in the beginning
    AA + ctrlA + ctrlC + ctrlV = 5 steps
    Now,we are left with onyl 2 more steps.
    So, we do ctrlV two more times
    We finally get
    AA + ctrlA + ctrlC + ctrlV + ctrlV + ctrlV
    or, 
    F(2) + ctrlA + ctrlC + F(2) + F(2) + F(2) = F(2) * 4
    
    -----------------------
    Similarly, 
    F(1) + ctrlA + ctrlC + F(1) + F(1) + F(1) + F(1)  = F(1) * 5 
    
    We choose the max of them i.e. F(3) * 3 = 9 As
*/

//Appaorch-1 (Recursion + Memoized)
typedef long long ll;
class Solution{
public:
    int t[100];
    ll solve(ll n) {
        if(n <= 0)
            return -1;
        if(n <= 6)
            return n;
        if(t[n] != -1)
            return t[n];
        ll maxCount = 0;
        ll multiple = 2;
        
        for(ll i = n-3; i>=1; i--) {
            ll subProb = multiple*solve(i);
            maxCount = max(maxCount, subProb);
            multiple++;
        }
        
        return t[n] = maxCount;
    }
    ll optimalKeys(int N){
        memset(t, -1, sizeof(t));

        return solve(N);
    }
};

//Approach-2 (DP) (Just replica of above approach)
typedef long long ll;
class Solution{
public:
    ll optimalKeys(int n){
        if(n <= 6)
          return n;
        vector<int> t(n+1);
        //t[i] = max A's that can be obtained in 'i' steps
        t[0] = -1;
        t[1] = 1;
        t[2] = 2;
        t[3] = 3;
        t[4] = 4;
        t[5] = 5;
        t[6] = 6;
        
        for (int i = 7; i <= n; i++) {
            int multiple = 2;
            for(int j = i-3; j >= 1; j--) {
                t[i] = max(t[i], t[j]*multiple);
                multiple++;
            }
        }
        
        return t[n];
    }
};
