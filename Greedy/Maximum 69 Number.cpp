/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=DMP2bqW6URA
    Company Tags                : Oracle (Phone Interview)
    Leetcode Link               : https://leetcode.com/problems/maximum-69-number/
*/

//Without converting to string
class Solution {
public:
    int maximum69Number (int num) {
        int place = 0;
        int index = -1;
        int temp = num;
        while(temp) {
            int remain = temp%10;
            if(remain == 6)
                index = place;
            
            temp = temp/10;
            place++;
        }
        
        if(index == -1) return num;
        
        return num + 3*pow(10, index);
        
    }
};
