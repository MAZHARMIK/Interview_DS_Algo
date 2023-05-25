/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=x19SmqQbhWk
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/new-21-game/
*/

//Approach-1 (Brute Force) - TLE
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> P(n + 1);
        //P[i] = probability of getting score = i
        
        P[0] = 1; //Since already initally she has score = 0, hence probability for scoring 0 is 1
        
        for (int i = 1; i <= n; i++) {
            
            for (int j = 1; j <= maxPts; j++) {
                
                if (i - j >= 0 && i - j < k) {
                    
                    //Probability of score j = 1/maxPts
                    //Remaining points = (i-j);
                    //So,  P[i] = Probability of j * Probability of remaining
                    //i.e. P[i] = 1/maxPts * P[i-j]
                    //Or, P[i] = P[i-j]/maxPts;
                    
                    P[i] += P[i - j] / maxPts;
                }
            }
        }
        return accumulate(P.begin() + k, P.end(), 0.0);
    }
};



//Approach-2 (Optimising above solution to use already solve subproblem)
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> P(n + 1, 0.0);
        //P[i] = probability of getting score = i
        
        P[0] = 1; //Since already initally she has score = 0, hence probability for scoring 0 is 1
        
        double currProbabSum = k > 0 ? 1 : 0;
        
        for (int i = 1; i <= n; i++) {
            
            P[i] = currProbabSum/maxPts;
            
            if(i < k) {
                currProbabSum += P[i];
            }
            
            if(i - maxPts >= 0 && i-maxPts < k) {
                currProbabSum -= P[i-maxPts];
            }
            
        }
        return accumulate(P.begin() + k, P.end(), 0.0);
    }
};
