/*
    Company Tags : Microsoft
    Qn Link      : https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1#
*/

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(struct Item a, struct Item b) {
        return (double)a.value / (double)a.weight > (double)b.value / (double)b.weight;
    }
 
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr+n, cmp);
        
        double profit = 0;
        for(int i = 0; i<n; i++) {
            double wt    = arr[i].weight;
            double val   = arr[i].value;
            double ratio = (double)val/(double)wt;
            if(wt <= W) {
                profit += val;
                W -= wt;
            } else {
                profit += ((double)val/(double)wt) * W;
                break;
            }
        }
        
        return profit;
    }
        
};
