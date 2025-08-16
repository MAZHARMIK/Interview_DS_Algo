/*           Scroll below to see JAVA code as well            */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=6dh1H5Hv4TI
    Company Tags                : Oracle (Phone Interview)
    Leetcode Link               : https://leetcode.com/problems/maximum-69-number/
*/



/********************************************************************** C++ **********************************************************************/
//Approach (Without converting to string)
//T.C : O(d) , d = number of dogits in num
//S.C : O(1)
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



/********************************************************************** JAVA **********************************************************************/
//Approach (Without converting to string)
//T.C : O(d) , d = number of dogits in num
//S.C : O(1)
class Solution {
    public int maximum69Number (int num) {
        int place = 0;
        int index = -1;
        int temp = num;
        
        while (temp > 0) {
            int remain = temp % 10;
            if (remain == 6) {
                index = place;
            }
            temp /= 10;
            place++;
        }
        
        if (index == -1) return num;
        
        return num + 3 * (int)Math.pow(10, index);
    }
}
