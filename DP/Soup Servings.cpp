/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=BiA4x5Gj7io
      Company Tags                : GOOGLE
      Leetcode Link               : https://leetcode.com/problems/soup-servings/
*/

//Approach-1 (Recursion + Memoization) + Trick
class Solution {
public:
    vector<pair<int, int>> serves{{100, 0}, {75, 25}, {50, 50}, {25, 75}};
    vector<vector<double>> t;
    
    double solve(double A, double B) {
        if(A <= 0 && B <= 0)
            return 0.5;
        
        if(A <= 0)
            return 1.0;
        if(B <= 0)
            return 0.0;
        
        if(t[A][B] != -1.0)
            return t[A][B];
        
        double probability = 0.0;
        
        for(auto &p : serves) {
            
            double A_serve  = p.first;
            double B_serve  = p.second;
            
            probability += 0.25*solve(A-A_serve, B-B_serve);
            
        }
        
        return t[A][B] = probability;
    }
    
    double soupServings(int n) {
        
        if(n >= 5000)
            return 1.0;
        
        t.resize(n+1, vector<double>(n+1, -1.0));
        return solve(n, n);
    }
};


//Approach-2 (Bottom Up - Coming soon)
