/*
    MY YOUTUBE VIDEO ON THIS Qn : <soon> 
    Company Tags                : Samsung
    Leetcode Link               : https://leetcode.com/problems/broken-calculator/
*/

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if(startValue >= target)
            return startValue-target;
        
        //even
        if(target%2 == 0) {
            return 1 + brokenCalc(startValue, target/2);
        }
        
        
        return 1 + brokenCalc(startValue, target+1);
    }
};
