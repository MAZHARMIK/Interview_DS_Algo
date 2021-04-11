/*
    Company Tags  : Microsoft qn's variation
    Leetcode Link : https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
*/

//Solution-1
//Like Two Sum Problem
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        //if (a+b)%60 == 0 
        //Then,
        //((a%60) + (b%60)) % 60 = 0
        //i.e. Their remainder sum should also be equal to zero
        //i.e. (R1 + R2)%60 will be 0;
        
        //0 <= R1 < 60  - (i)
        //0 <= R2 < 60  - (ii)
        //So,
        //0 <= R1+R2 < 2*60
        
        //So, only valid values for (R1 + R2) to be divisible by 60 in range [0, 2*60) is 0 and 60
        map<int, int> mp;
        
        for(const int& x:time) {
            mp[x%60]++;
        }
        
        int result = 0;
        for(const int& x:time) {
            int R = x%60;
            
            if(mp.find(R) != mp.end()) {
                if(R == 30 || R == 0) {
                    int n   = mp[R];
                    result += (n*(n-1)/2);
                } else {
                    int diff  = 60-R;
                    result   += mp[R]*mp[diff];
                }
                mp.erase(R);
            }
        }
        return result;
    }
};

//Solution-2
//Without using map (making use of symmetric concept)
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> rem(60, 0); //Since, remainder will always lie between 0 and 59 i.e. 0 <= R < 60
        int n = time.size();
        int result = 0;
        
        for(int i = 0; i<n; i++)
            rem[time[i]%60]++;
        
        
        //Since, for remainder 0 and 30, they pair up with themselves
        int remain_zero   = rem[0];
        int remain_thirty = rem[30];
        
        result += remain_zero*(remain_zero-1)/2 + remain_thirty*(remain_thirty-1)/2;
        
        for(int i = 1; i<30; i++) {
            //Why < 30 ?
            //Because, pairs are complimentary to each other
            //For example :
            //20 will match with 40
            //10 will match with 50 and so on....
            //So, 30 is the mid point beyond which you'll get duplicate results
            
            result += rem[i]*rem[60-i];
        }
        return result;
    }
};
