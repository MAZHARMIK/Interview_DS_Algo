/*
    Company Tags  : Microsoft, Amazon
    Leetcode Link : https://leetcode.com/problems/gray-code/
*/

//Approach-1 (Using Simple Recursion)
/*
    Example : n = 2
    helper(n-1) calls-> helper(1)
    
    Now, helper(1) returns {"0", "1"}; Which is correct gray code sequence for n = 1 (# elements = 2^1)
    
    Now, juts append "0" to each element , you will get {"00", "01"} which is Gray code as well
    because each element differ in only 1 bit  ----> Result1
    
    Now, juts append "1" to each element , you will get {"10", "11"} which is Gray code as well
    because each element differ in only 1 bit  ----> Result2
    
    So, after combining Result1 and Result2 (for n = 2),  {"00", "01", "10", "11"}
    BUT, you notice that if we combine them, the 1st and 2nd string differ in 2 bits i.e. "01", "10"
    SO, 
    instead of combining them face to face, reverse the Result2 and then combine it with Result1.
    
    That's why my 2nd for loop below starts from i = temp.size()-1 and goes till i >=0 .
    
*/
class Solution {
public:
    vector<string> helper(int n) {
        if(n == 1) {
            return {"0", "1"};
        }
        
        vector<string> temp = helper(n-1); //To get the result of n, we fetch result from (n-1)
        
        vector<string> padded;
        
        for(int i = 0; i<temp.size(); i++) {
            padded.push_back("0" + temp[i]); //Just add "0" in the beginning
        }
        
        for(int i = temp.size()-1; i >= 0; i--) {
            padded.push_back("1" + temp[i]); //Just add "1" in the beginning
        }
        
        return padded;
    }
    
    vector<int> grayCode(int n) {
        vector<string> result = helper(n);
        
        vector<int> finalR;
        
        //Just convert them to integer and you got your answer
        for(string &s : result) {
            bitset<32> bt(s);
            finalR.push_back(bt.to_ulong());
        }
        return finalR;
    }
};

//Approach-2
class Solution {
public:
    vector<int> result;
    void helper(bitset<32>& bt, int n) {
        if(n == 0) {
            //It means we have generate all n elements
            result.push_back(bt.to_ulong());
            return;
        }
        
        //Generate the remaining (n-1) numbers from bt
        helper(bt, n-1);
        
        //flip the (n-1)th bit (to create a difference of just one bit)
        bt.flip(n-1);
        
        //Generate the remaining (n-1) numbers from bt but this time (n-1)th bit flipped (to create a difference of just one bit)
        helper(bt, n-1);
    }
    
    vector<int> grayCode(int n) {
        bitset<32> bt; //by default all bits are 0 i.e. {0000000.....000}
        
        result.clear();
        
        helper(bt, n);
        
        return result;
    }
};
