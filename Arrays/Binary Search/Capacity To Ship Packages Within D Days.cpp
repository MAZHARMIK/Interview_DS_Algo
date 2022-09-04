/*
    Company Tags : Meta, Baidu, Google, Flipkart, D-E-Shaw, Amazon
    Leecode Link : https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/   
    Similar Qn   : Allocate Minimum Number Of Pages (https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1)
    
    Keywords to identify this Qn category : "(in the order given by weights/count)"
*/

class Solution {
private:

public:    
    bool possible(int weight, vector<int>& weights, int days) {
        int currDayCount  = 1;
        int currSumWeight = 0;
        for(int &w : weights) {
            currSumWeight += w;
            
            if(currSumWeight > weight) {
                currDayCount++;
                currSumWeight = w;
            }
            
        }
        
        return currDayCount<=days;
        /*
            Why currDayCount<=days ?
            Because it is mentioned in the question that all the packages
            need to be shipped "WITHIN" 'days' days
            So, even if I am able to transfer all the weights within
            days < (given days in input) I am good to go.
        */
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int n     = weights.size();
      
        int minWeight = accumulate(begin(weights), end(weights), 0);
        int maxWt = *max_element(begin(weights), end(weights));
        
          
        if(n < days)
            return -1; //not possible case
        
        if(days == 1)
            return minWeight;
        
        
        int high = minWeight;
        int low  = maxWt;      //weight cannot be less than maximum weight
        /*
            Why ?
            Because in worst case I will have to carry one weight per day.
            So, in that case my ship's capacity must not be less than the maximum weight.
        */

        while(low < high) {
            int mid = low + (high-low)/2;
            
            if(possible(mid, weights, days))
                high = mid;
            else
                low  = mid+1;
        }
        
        return high;
    }
};
