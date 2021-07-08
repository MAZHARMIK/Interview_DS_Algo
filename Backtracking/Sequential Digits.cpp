/*
    Company Tags  : Let me know when you find it. Help me make this repository perfect :-)
    Leetcode Link : https://leetcode.com/problems/sequential-digits/
*/

//Approach-1 (Using Backtracking)
class Solution {
public:
    void backtrack(int low, int high, int start, vector<int>& result) {
        if(start == 9)
            return;
        if(start%10 < 9) {
            start = start * 10 + (start%10) + 1; 
            //example : start = 12 ,  now we need 123, so (12*10) + (12%10) + 1 = 123
            if(start>=low && start<=high)
                result.push_back(start);
            backtrack(low, high, start, result); //next, look for 1234
        } else {
            //if start = 123456789 , we need to go now for 23456789
            //Remeber that 123456789 would have started from start = 1
            //so for 23456789, we need to start from 2 i.e. (SD of start)+ 1
            //How to get MSD of 123456789   i.e. MSD = 1
            //If we divide 123456789 from pow(10, # digits -1)
            int num_digits = log10(start);
            int MSD = start/pow(10, num_digits);
            backtrack(low, high, MSD+1, result);
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        backtrack(low, high, 1, result);
        sort(result.begin(), result.end());
        return result;
    }
};

//Approach-2 (Using Simple Loop)
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        
        vector<int> result;
        for(int i = 0; i<9; i++) {
            for(int j = i+1; j<9; j++) {//why j = i+1 ? Bcz 10 <= low <= high <= 10^9 (No single digit)
                string temp = s.substr(i, j-i+1);
                
                int num = stoi(temp);
                if(num > high) break;
                
                if(num >= low && num <= high)
                    result.push_back(num);
            }
        }        
        
        
        sort(begin(result), end(result));
        return result;
    }
};
