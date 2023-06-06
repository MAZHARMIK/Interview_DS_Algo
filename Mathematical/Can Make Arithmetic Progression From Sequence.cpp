/*
    MY YOUTUBE VIDEO ON THIS Qn : <soon>
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
*/

//Approach-1 (Using Sorting (O(nlogn))
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        
        sort(begin(arr), end(arr));
        
        int d = arrr[1] - arr[0];
        
        for(int i = 2; i<n; i++) {
            if(arr[i] - arr[i-1] != d)
                return false;
        }
        
        return true;
    }
};

//Approach-2 (Using Mathematival AP property - O(n) Time, O(n) Space))
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        
        unordered_set<int> st(begin(arr), end(arr));
        
        int min_el = *min_element(begin(arr), end(arr)); //a0
        int max_el = *max_element(begin(arr), end(arr)); //a0+(n-1)*d
        
        if((max_el - min_el)%(n-1))
            return false;
        
        int d = (max_el - min_el)/(n-1);
        
        int i = 0; 
        //a0 , a0+d , a0 + 2d
        
        while(i < n) {
            int num = min_el + i*d;
            if(st.find(num) == st.end())
                return false;
            
            i++;
        }
        
        return true;
    }
};


//Approach-3 (Using O(1) Space and O(n) Time)
//Kindly let me know if you want the solution for this as well. 
//I will make a video on this too
