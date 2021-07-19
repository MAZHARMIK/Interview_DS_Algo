/*
    Company Tags  : Bloomberg, Morgan Stanley, Amazon, Microsoft, Samsung, Snapdeal, FactSet, Hike, MakeMyTrip, Adobe, Qualcomm, Zillious,
                    Oxigen Wallet, Vizury Interactive Solutions
    Leetcode Link : https://leetcode.com/problems/next-greater-element-iii/
*/

//Approach-1 (Finding Next permutation without using C++ STL)
//Time [O(n)]
class Solution {
public:
    int nextGreaterElement(int n) {
        /*
            If you notice, it is nothing but giving the
            next permutation which is actually the next number just 
            lareger than current number
            
            Example : 
            For, n = 1342, output is 1423 and so is the next permutation
            For, n = 3412, output is 3421 and so is the next permutation
            So, just find the next permutation
        */
        
        //single digit can't have next permutation
        if(n < 10)
            return -1;
        
        string num = to_string(n);
        int l = num.length();
        int i = l-2;
        for(; i>=0; i--) {
            if(num[i] < num[i+1])
                break;
        }
        
        //we don't have next permutation
        if(i < 0)
            return -1;
        //Find first element just greater than num[i]
        for(int j = l-1; j>i; j--) {
            if(num[j] > num[i]) {
                swap(num[i], num[j]);
                break;
            }
        }

        //Now, sort remaining element from i+1 to l-1
        sort(num.begin()+i+1, num.end());
        
        unsigned long long nextGr = stoll(num);
        
        if(nextGr <= n || nextGr > INT_MAX)
            return -1;
        
        return nextGr;
    }
};

//Approach-1 (Finding Next permutation using C++ STL)
//Time [O(n)]
class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int l    = s.length();
        next_permutation(s.begin(), s.end());
        long long num = stoll(s);
        
        if(num <= n || num > INT_MAX)
            return -1;
        return num;
    }
};
