/*       Scroll down to see JAVA code also      */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=cPaq3AABkLc
    Company Tags                : Apple
    Leetcode Link               : https://leetcode.com/problems/find-the-pivot-integer/
*/


/***************************************************************************** C++ ******************************************************************/
//Approach-1 (Using Brute Force)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int pivotInteger(int n) {
        if(n == 1)
            return 1;
        
        for(int pivot = 1; pivot <= n; pivot++) {
            
            int leftSum  = 0;
            int rightSum = 0;
            
            for(int j = 1; j <= pivot; j++) {
                leftSum += j;
            }
            
            for(int j = pivot; j <= n; j++) {
                rightSum += j;
            }
            
            
            if(leftSum == rightSum) {
                return pivot;
            } 
        }
        
        return -1;
    }
};


//Approach-2 (Optimising above using Maths)
class Solution {
public:
    int pivotInteger(int n) {
        if(n == 1)
            return 1;
        
        int totalSum = n * (n+1)/2;
        
        for(int pivot = 1; pivot <= n; pivot++) {
            
            int leftSum  = pivot * (pivot+1)/2;
            
            int rightSum = totalSum - leftSum + pivot;
            
            if(leftSum == rightSum)
                return pivot;
            
        }
        
        return -1;
    }
};

//Approach-3 (Using two pointer)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int pivotInteger(int n) {
        if(n == 1)
            return 1;
        
        int i = 1;
        int j = n;
        
        int frontSum = 1;
        int backSum  = n;

        
        while(i < j) {
            
            if(frontSum < backSum) {
                i++;
                frontSum += i;
            } else {
                j--;
                backSum += j;
            }

        }
        return frontSum == backSum ? i : -1;
    }
};


//Approach-4 (Using Binary Search)
//T.C : log(n)
//S.C : O(1)
class Solution {
public:
    int pivotInteger(int n) {
        if(n == 1)
            return 1;
        
        int totalSum = n * (n+1)/2;
        
        
        int left = 1, right = n;
        
        while(left <= right) {
            
            int mid_pivot = left + (right-left)/2;
            
            if(mid_pivot * mid_pivot == totalSum) {
                return mid_pivot;
            } else if(mid_pivot * mid_pivot < totalSum) {
                left = mid_pivot+1;
            } else {
                right = mid_pivot-1;
            } 
        }
        
        return -1;
    }
};


//Approach-5 (Using quick math)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    int pivotInteger(int n) {
        if(n == 1)
            return 1;
        
        int totalSum = n * (n+1)/2;
        
        int pivot = sqrt(totalSum);
        
        if(pivot*pivot == totalSum)
            return pivot;
        
        return -1;
        
    }
};


/***************************************************************************** JAVA ******************************************************************/
// Approach-1 (Using Brute Force)
// T.C: O(n^2)
// S.C: O(1)
class Solution {
    public int pivotInteger(int n) {
        if (n == 1)
            return 1;

        for (int pivot = 1; pivot <= n; pivot++) {
            int leftSum = 0;
            int rightSum = 0;

            for (int j = 1; j <= pivot; j++) {
                leftSum += j;
            }

            for (int j = pivot; j <= n; j++) {
                rightSum += j;
            }

            if (leftSum == rightSum) {
                return pivot;
            }
        }

        return -1;
    }
}

// Approach-2 (Optimizing above using Maths)
class Solution {
    public int pivotInteger(int n) {
        if (n == 1)
            return 1;

        int totalSum = n * (n + 1) / 2;

        for (int pivot = 1; pivot <= n; pivot++) {
            int leftSum = pivot * (pivot + 1) / 2;
            int rightSum = totalSum - leftSum + pivot;

            if (leftSum == rightSum)
                return pivot;
        }

        return -1;
    }
}

// Approach-3 (Using Two Pointer)
// T.C: O(n)
// S.C: O(1)
class Solution {
    public int pivotInteger(int n) {
        if (n == 1)
            return 1;

        int i = 1;
        int j = n;

        int frontSum = 1;
        int backSum = n;

        while (i < j) {
            if (frontSum < backSum) {
                i++;
                frontSum += i;
            } else {
                j--;
                backSum += j;
            }
        }
        return frontSum == backSum ? i : -1;
    }
}

// Approach-4 (Using Binary Search)
// T.C: log(n)
// S.C: O(1)
class Solution {
    public int pivotInteger(int n) {
        if (n == 1)
            return 1;

        int totalSum = n * (n + 1) / 2;

        int left = 1, right = n;

        while (left <= right) {
            int midPivot = left + (right - left) / 2;

            if (midPivot * midPivot == totalSum) {
                return midPivot;
            } else if (midPivot * midPivot < totalSum) {
                left = midPivot + 1;
            } else {
                right = midPivot - 1;
            }
        }

        return -1;
    }
}

// Approach-5 (Using Quick Math)
// T.C: O(1)
// S.C: O(1)
class Solution {
    public int pivotInteger(int n) {
        if (n == 1)
            return 1;

        int totalSum = n * (n + 1) / 2;

        int pivot = (int) Math.sqrt(totalSum);

        if (pivot * pivot == totalSum)
            return pivot;

        return -1;
    }
}
