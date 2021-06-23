/*
    Company Tags  : Microsoft, Amazon
    Leetcode Link : https://leetcode.com/problems/implement-rand10-using-rand7/
*/

//Approach-1 (Rejection Sampling)
class Solution {
public:
    int rand10() {
        
        int row;
        int col;
        
        int num;
        do{
            row = rand7();
            col = rand7();

            num = (row-1)*7 + col;
        }while(num > 40);
            
        return ((num-1)%10) + 1;
    }
};

//Approach-2 (Intuitive approach)
class Solution {
public:
    int rand10() {
        int v1 = 11, v2 = 7;
        
        while(v1 > 5) {
            v1 = rand7();  //Looking only : 1, 2, 3, 4, 5
        }
        
        while(v2 == 7) {
            v2 = rand7();  //Looking only : 1, 2, 3, 4, 5, 6. Then divide (1, 2, 3) for [1,5] of rand10() and (4, 5, 6) for [6,10] of rand10()
        }
        
        if(v2 < 4) {
            return v1;
        }
        
        return v1+5;
    }
};
