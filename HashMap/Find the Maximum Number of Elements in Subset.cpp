/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/find-the-maximum-number-of-elements-in-subset/description/
*/

/*************************************************************** C++ ***************************************************************/
//T.C : O(n*logn(n))
//S.C : O(n)
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        long long result = 0;
        
        map<int, int> mp;
        //Why ordered map ?
        //We want to start from smallest to largest
        //Example : [14,14,196,196,38416,38416]
        
        for(auto &num: nums)
            mp[num]++;
        
        for(auto &it : mp) {

            long long val  = it.first;
            long long freq = it.second;
            
            long long length = 0;
            //Handling 1 separately because its square will be 1 only
            //example : [1,1,1,1,1,1,1,1,1,1,2,4,8,16,32,64,128,256,512,1024]
            if(val == 1) { 
                length += freq;
                mp[val] = 0; 
                if(length % 2 == 0)
                    length--;
                result = max(result, length);
                continue;
            } 
            
            while(val <= 1e9 && mp[val] > 0){
                length += 2;
                
                if(mp[val] == 1) //We need atleast 2
                    break; 
                
                mp[val] = 0;    // set to zero, so that we do not check for this sequence again
                
                val = val * val;
            }
            
            //Series length will be odd example : {2, 4, 2}, {2, 4, 16, 4, 2}
            length--;
            
            result = max(result, length);
        }
        return result;
    }
};

/*************************************************************** JAVA ***************************************************************/
//T.C : O(n*logn(n))
//S.C : O(n)
//Will soon update
