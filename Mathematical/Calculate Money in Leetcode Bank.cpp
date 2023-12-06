/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=TAmv6Csq3Ss
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/calculate-money-in-leetcode-bank/
*/

/***************************************************************** C++ ******************************************************************************/
//Approach-1 (Just doing what Qn asks - simulation)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int totalMoney(int n) {
        int result = 0;
        
        int monday_money = 1;
        
        while(n > 0) {
            
            int money = monday_money;
            for(int day = 1; day <= min(n, 7); day++) {
                result += money++;
            }
            
            
            n            -= 7;
            monday_money += 1;
        }
        
        return result;
        
    }
};


//Approach-2 (Using Maths)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    int totalMoney(int n) {
        int items  = n / 7;
        int first  = 28;
        int last   = 28 + (items - 1) * 7; //Tn = a1 + (n-1)*d
        
        int arithmeticSum = items * (first + last) / 2; //Sn = n/2(a1 + an)
        
        //Final week remaining days
        int monday_money = 1 + items;
        int finalWeek    = 0;
        
        for (int day = 1; day <= (n % 7); day++) { //This loop will Never iterate more than 6 ~ O(1)
            finalWeek += monday_money++;
        }
        
        return arithmeticSum + finalWeek;
    }
};



/***************************************************************** JAVA ******************************************************************************/
//Approach-1 (Just doing what Qn asks - simulation)
//T.C : O(n)
//S.C : O(1)
public class Solution {
    public int totalMoney(int n) {
        int result = 0;
        
        int mondayMoney = 1;
        
        while (n > 0) {
            int money = mondayMoney;
            for (int day = 1; day <= Math.min(n, 7); day++) {
                result += money++;
            }
            
            n -= 7;
            mondayMoney += 1;
        }
        
        return result;
    }
}


//Approach-2 (Using Maths)
//T.C : O(1)
//S.C : O(1)
public class Solution {
    public int totalMoney(int n) {
        int items = n / 7;
        int first = 28;
        int last = 28 + (items - 1) * 7;

        int arithmeticSum = items * (first + last) / 2;

        // Final week remaining days
        int mondayMoney = 1 + items;
        int finalWeek = 0;

        for (int day = 1; day <= (n % 7); day++) {
            finalWeek += mondayMoney++;
        }

        return arithmeticSum + finalWeek;
    }
}
