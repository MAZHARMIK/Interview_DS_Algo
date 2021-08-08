/*
    Company Tags  : Facebook, Twitter, Flipkart, Microsoft, Samsung, Adobe, Facebook
    Leetcode Link : https://leetcode.com/problems/multiply-strings/
*/

/*
This is just a simulation of multiplication we used to do during primary school.
This same technique is used to find factorial of large numbers as well.
Link (Factorial Of Large Numbers) : https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Factorials%20of%20large%20numbers.cpp

								 1  2  3
								 1  2  1
								 -------
							    	1   2   3
							     2  4   6   x
						  	  1  2  3   x   x  (I call this symbol as cross. Notice how cross is increasing)
				    			  -----------------
			       			Ans:	  1  4  8   8  3

*/


class Solution {
public:
    string temp;
	//This function just does the multiplication of a digit of num1 with whole num2
    void multiplyNum(int& num, vector<int>& result, int& size, int cross) {
        int carry = 0;

        for(int i = temp.length()-1; i >= 0; i--) {
            int p            = (num*(temp[i]-'0')) + carry + result[cross];
            result[cross++]  = p%10;
            carry            = p/10;
        }
        
        while(carry) {
            result[cross++] = carry%10;
            carry          /= 10;
        }
        
        size = cross;
    }
    
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        int m = num1.length();
        int n = num2.length();
        //I will always choose to multiply smaller number to a larger number
        if(m > n) {
            return multiply(num2, num1);
        }
        
        vector<int> result(100000, 0);
        temp = num2;
        int size = 0;
        
        int cross = 0;
        for(int i = m-1; i>=0; i--) {
            int num = num1[i]-'0';
            multiplyNum(num, result, size, cross);
            cross++; //increasing cross position
        }
        
        string ans = "";
        for(int i = size-1; i>=0; i--)
            ans.push_back(result[i]+'0');
        
        return ans;
    }
};
