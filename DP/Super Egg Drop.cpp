/*
  Company Tags  : Amazon, D-E-Shaw, Goldman Sachs, Google, Hike, MakeMyTrip, MAQ Software, Myntra, nearbuy, Opera, Oracle, Philips, Samsung, ServiceNow, Unisys, VMWare
  Leetcode Link : https://leetcode.com/problems/super-egg-drop/
*/

//4 approaches with very easy to understand the code and logic

class Solution {
public:
    //Approach-1  Recursoin + Memoization (TLE)
    int t[101][10001];
    int solve(int e, int f) {
        if(e == 1 || f == 0 || f == 1)
            return f;
        
        int minAttempts = INT_MAX;
        if(t[e][f] != -1)
            return t[e][f];
        for(int i = 1; i<=f; i++) {
            int breaks = 0;
            int no_break = 0;
            if(t[e-1][i-1] != -1)
                breaks = t[e-1][i-1];
            else
                breaks = solve(e-1, i-1);
            
            if(t[e][f-i] != -1)
                no_break = t[e][f-i];
            else
                no_break = solve(e, f-i);
            
            int temp = 1 + max(breaks, no_break);
            
            minAttempts = min(minAttempts, temp);
        }
        
        return t[e][f] = minAttempts;
    }
    
    //Approach-2 DP(of APproach-1) (TLE)
    int solve_iter(int e, int f) {
        vector<vector<int>> t(e+1, vector<int>(f+1, 0));
        //t[i][j] = minAttempts to find critical floor when we have i eggs and j floors
        for(int row = 0; row<e+1; row++) {
            t[row][0] = 0; //when we have 0 floors, we have 0 attempts
        }
        
        for(int col = 0; col<f+1; col++) {
            t[0][col] = 0; //when we have 0 eggs, we have 0 attempts
        }
        
        for(int col = 0; col<f+1; col++) {
            t[1][col] = col; //when we have 1 egg, in worst case, we will have to make attempts equal to floor 
        }
        
        for(int row = 0; row<e+1; row++) {
            t[row][1] = 1; //when we have 1 floor, in worst case, we can make one attempt
        }
        
        for(int i = 2; i<e+1; i++) {
            for(int j = 2; j<f+1; j++) {
                t[i][j] = INT_MAX; //when we have i eggs and j floors
                
                ///i start dropping from 1st floor, then 2nd, then .... jth floor
                for(int k = 1; k<=j; k++) {
                    int temp = 1 + max(t[i-1][k-1], t[i][j-k]); //max(breaks, no_break)
                    
                    if(temp < t[i][j])
                        t[i][j] = temp;
                }
            }
        }
        
        return t[e][f];
    }
    
    //APproach-3 //Binary Search + Memoized (Accepted)
    int binarySearch(int e, int f) {
        if(e == 1 || f == 0 || f == 1)
            return f;
        
        if(t[e][f] != -1)
            return t[e][f];
        
        int l = 0, h = f;
        int minAttempts = INT_MAX;
        while(l <= h) {
            int mid = l + (h-l)/2;
            
            int breaks   = binarySearch(e-1, mid-1);
            int no_break = binarySearch(e, f-mid);
            int temp     = 1 + max(breaks, no_break);
            minAttempts  = min(minAttempts, temp);
            
            if(left == right)
                break;
            
            if(breaks < no_break)
                l = mid+1;
            else
                h = mid-1;
        }
        
        return t[e][f] = minAttempts;
    }
    
    //Approach-4 //Iterative Binary Search (Accepted)
    int binarySearchIterative(int e, int f) {
        vector<vector<int>> t(e+1, vector<int>(f+1));
        //t[i][j] = minAttempts to find critical floor when we have i eggs and j floors
        for(int row = 0; row<e+1; row++) {
            t[row][0] = 0; //when we have 0 floors, we have 0 attempts (writing this loop for completeness)
        }
        
        for(int col = 0; col<f+1; col++) {
            t[0][col] = 0; //when we have 0 eggs, we have 0 attempts (writing this loop for completeness)
        }
        
        for(int col = 0; col<f+1; col++) {
            t[1][col] = col; //when we have 1 egg, in worst case, we will have to make attempts equal to floor 
        }
        
        for(int row = 0; row<e+1; row++) {
            t[row][1] = 1; //when we have 1 floor, in worst case, we can make one attempt
        }
        
        for(int i = 2; i<e+1; i++) {
            for(int j = 2; j<f+1; j++) {
                int l = 0, h = j;
                t[i][j] = INT_MAX; //when we have i eggs and j floors
                while(l <= h) {
                    int mid = l + (h-l)/2;

                    int breaks   = t[i-1][mid-1];
                    int no_break = t[i][j-mid];
                    int temp     = 1 + max(breaks, no_break);
                    
                    t[i][j]  = min(t[i][j], temp); //we'll choose the best from worst

                    if(left == right)
                        break;

                    if(breaks < no_break) //Go towards the worst case
                        l = mid+1;
                    else
                        h = mid-1;        //Go towards the worst case
                }
            }
        }
        return t[e][f];
    }
    
    int superEggDrop(int e, int f) {
        memset(t, -1, sizeof(t));
        //return solve(e, f); //Recursoin + Memoization (TLE)
        
        //return solve_iter(e, f); //DP (TLE)
        
        //return binarySearch(e, f); //Binary Search + Memoized (Accepted)
        
        return binarySearchIterative(e, f); //Iterative Binary Search (Accepted)
    }
};
