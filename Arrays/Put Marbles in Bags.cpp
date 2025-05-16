/*        Scroll below to see JAVA code as well        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=L-KWU8W3OqE
    Company Tags                : AMAZON
    Leetcode Link               : https://leetcode.com/problems/put-marbles-in-bags/
*/


/************************************************************ C++ **************************************************/
//T.C : O(nlog(n))
//S.C : O(n)
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        
        vector<int> pairSum(n-1, 0);
        
        for(int i = 0; i<n-1; i++) {
            pairSum[i] = weights[i] + weights[i+1];
        }
        
        sort(begin(pairSum), end(pairSum));
        long maxSum = 0;
        long minSum = 0;
        
        for(int i = 0; i<k-1; i++) {
            minSum += pairSum[i];
            maxSum += pairSum[n-i-2];
        }
        
        return maxSum-minSum;
    }
};


/************************************************************ JAVA **************************************************/
//T.C : O(nlog(n))
//S.C : O(n)
class Solution {
    public long putMarbles(int[] weights, int k) {
        int n = weights.length;
        
        List<Integer> pairSum = new ArrayList<>();
        
        for (int i = 0; i < n - 1; i++) {
            pairSum.add(weights[i] + weights[i + 1]);
        }
        
        Collections.sort(pairSum);
        long maxSum = 0;
        long minSum = 0;
        
        for (int i = 0; i < k - 1; i++) {
            minSum += pairSum.get(i);
            maxSum += pairSum.get(n - i - 2);
        }
        
        return maxSum - minSum;
    }
}
