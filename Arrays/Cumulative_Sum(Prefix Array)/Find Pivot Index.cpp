/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Q0Qat25D6JE&list=PLpIkg8OmuX-K6A0sEPFxOSJh4_AjCGAFf&index=18
    Company Tags                : Amazon, Adobe, Coupang, Radius
    Leetcode Link               : https://leetcode.com/problems/find-pivot-index/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/equilibrium-point-1587115620/1/?page=1&curated[]=1&sortBy=submissions#
*/

//Approach-1 (Using O(n) space)
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array

    int equilibriumPoint(long long a[], int n) {
        if(n == 1)
            return 1; //if only 1 element, it's left and right are equal :-)
        else if(n == 2)
            return -1; //We can't have an equilibrium with only 2 elements :-(
        
        
        
        long long cumu_sum[n];
        cumu_sum[0]  = a[0];
        long long totalSum = a[0];
        
        for(int i = 1; i<n; i++) {
            totalSum += a[i];
            
            cumu_sum[i] = cumu_sum[i-1] + a[i];
        }
        
        /*
            Example :
            A[]      = {1, 3, 5,  2, 2 }
            cumu_sum = {1, 4, 9, 11, 13}
            TotalSum = 13
            
            For i = 1, cumu_sum = 4
            sum at the left of i = 1 : cumu_sum[i] - a[i] = 4-3 = 1.   (i.e. 1)
            
            sum at the right of i = 1 : TotalSum - left_sum - a[i] = 13 - 1 - 3 = 9. (i.e. 5 + 2 + 2)
            
        */
        for(int i = 1; i<n; i++) {
            int left_sum  = cumu_sum[i] - a[i];
            int right_sum = totalSum-left_sum-a[i];
            
            if(left_sum == right_sum)
                return i+1;
        }
        
        return -1;
    }

};



//Approach-2 (Using O(1) space)
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array

    int equilibriumPoint(long long a[], int n) {
        if(n == 1)
            return 1; //if only 1 element, it's left and right are equal :-)
        else if(n == 2)
            return -1; //We can't have an equilibrium with only 2 elements :-(
        
        
        
        long long left_sum = a[0];
        long long totalSum = 0;
        
        for(int i = 0; i<n; i++) {
            totalSum += a[i];
        }
        
        
        for(int i = 1; i<n; i++) {
            int right_sum = totalSum-left_sum-a[i]; //This logic is same as explained in Approach-1
            
            if(left_sum == right_sum)
                return i+1;
                
            left_sum += a[i];
        }
        
        return -1;
    }

};
