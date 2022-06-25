/*
    Company Tags  : Google
    Leetcode Link : https://leetcode.com/problems/non-decreasing-array/
*/

//Approach-1
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        /*
            Example : 1
            {-1, 4, 2, 3}   ->  {-1, 2, 2, 3}
            The problem came when we saw nums[i] < nums[i+1]  (i.e. 4 < 2) 
            So, we modified nums[i] = nums[i+1];   -> case-A
            
            
            Example : 2
            {5, 8, 4, 10}   ->  {5, 8, 8, 10} 
            The problem came when we saw nums[i] < nums[i+1]  (i.e. 8 < 4) 
            
            So, we modified nums[i+1] = nums[i];   -> case-B
            
            
            case-A and case-B had same scenario but we did different modifications.
            
            In case-B, if you had modified nums[i], then you would have got {5, 4, 4, 10}  (Dayumm, that's a problem 5 < 4)  :-(
            
            So, we take decision based on nums[i-1]
            
            i.e. if(nums[i-1] < nums[i+1]) //Something we want (case-A)
                    nums[i] = nums[i+1];
                
                and if(nums[i-1] > nums[i+1]) //case-B
                    nums[i+1] = nums[i];
        */
        
        int modify = false;
        int n      = nums.size();
        
        for(int i = 0; i<n-1; i++) {
            if(nums[i] > nums[i+1]) {
                if(modify)
                    return false;
                
                modify = true;
                if(i > 0 && nums[i-1] > nums[i+1]) //why this condition first (example : {4, 2, 3} First element violates)
                    nums[i+1] = nums[i];
                else
                    nums[i] = nums[i+1];
            }
        }
        
        return true;
    }
};

//Approach-2
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        bool modify = false;
        int min = INT_MIN;
        for(int i = 0; i<n-1; i++) {
            if(nums[i] <= nums[i+1])
                min = nums[i];
            else {
                if(nums[i+1] < min) {
                    //For example : 3, 4, 1  (I would want to make 1 -> 4) i.e. (3, 4, 4)
                    //nums[i+1] = 1
                    //nums[i]   = 4
                    //min       = 3
                    nums[i+1] = nums[i];
                }
                if(modify)
                    return false;
                modify = true;
            }
        }
        
        return true;
    }
};

//Approach-3 (Greedy)
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        /*
            CASE-1
            
              Level(2)              (i-1)

              Level(1)     (i-2)
              Level(0)                     (i)
            
              For sure, I need to move (i)  -> (i-1)
              We get;
            
              Level(2)              (i-1)    (i)

              Level(1)     (i-2)
              
              
            CASE-2
            
              Level(2)              (i-1)

              Level(1)                     (i)
              Level(0)  (i-2)
              
              //I have two choices
                choice-1 : I can move (i-1)   -> (i)  (Safe : Because by decreasing (i-1), we are Greedily 
                                                       increasing our chances to get non-decreasing (>=) numbers in future)
                
                choice-2 : I can move (i) -> (i-1)    (Not Safe)
            
            So, 
              Level(2)              

              Level(1)               (i-1)    (i)
              Level(0)  (i-2)
            
        */
        
        int modify = false;
        int n      = nums.size();
        
        for(int i = 1; i<n; i++) {
            if(nums[i] < nums[i-1]) {
                
                if(i == 1 || nums[i-2] <= nums[i])
                    nums[i-1] = nums[i]; //case-2 : move (i-1)  -> (i)
                else
                    nums[i] = nums[i-1]; //case-1 : move (i)  -> (i-1)
                
                if(modify)
                    return false;
                modify = true;
            }
        }
        
        return true;
    }
};
