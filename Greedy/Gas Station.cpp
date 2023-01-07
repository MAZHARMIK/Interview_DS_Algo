/*
    My YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=tcOcmNHFTTM
    
    This question is also popular as "Circular Tour"
    Company Tags                : Google, Amazon, Uber, Microsoft, FactSet, Morgan Stanley, Zoho, Flipkart
    Leetcode Link               : https://leetcode.com/problems/gas-station/
*/

//Approach-1 (Brute Force (O(n^2)) - TLE
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        for(int i = 0; i<n; i++) {
            
            if(gas[i] < cost[i])
                continue;
            
            int j = (i+1)%n;
            
            int currGas = gas[i];
                
            currGas = currGas - cost[i] + gas[j];
            
            while(j != i) {
                if(currGas < cost[j])
                    break;
                
                int costForMovingFromThisj = cost[j];
                
                //Let's move
                j = (j+1)%n;
                
                int gasEarnInNextStationj = gas[j];
                
                currGas = currGas - costForMovingFromThisj + gasEarnInNextStationj;

            }
            
            if(i == j)
                return i;
        }
        
        
        return -1; 
    }
};


//Approach-2 (Greedy O(n)) : Accepted
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int sumGas = accumulate(begin(gas), end(gas), 0);
        
        int sumCost = accumulate(begin(cost), end(cost), 0);
        
        if(sumGas < sumCost)
            return -1;
        
        int total  = 0;
        int result = 0;
        
        for(int i = 0; i<n; i++) {
            
            total += gas[i] - cost[i];
            
            if(total < 0) {
                total = 0;
                result = i+1;
            }
            
        }
        return result;
    }
};
