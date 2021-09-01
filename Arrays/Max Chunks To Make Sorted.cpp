/*
    Company Tags  : Amazon, Google
    Leetcode Link : https://leetcode.com/problems/max-chunks-to-make-sorted/
    
    Similar Qn    : Leetcode - 763 (https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/HashMap/Partition%20Labels.cpp)
*/

//Approach-1 (Time : O(n))
class Solution {
public:
    //Similar to Leetcode - 763 : Partition Labels
    int maxChunksToSorted(vector<int>& arr) {
        int n     = arr.size();
        int maxE  = arr[0];
        int count = 0;
        
        for(int i = 0; i<n; i++) {
            maxE = max(maxE, arr[i]);
            if(maxE == i)
                count++;
        }
        return count;
    }
};

//Approach-2 (Using map) (Time : O(n), Space : O(n))
//See below DISCUSS link for my explanation using Images : 
//https://leetcode.com/problems/max-chunks-to-make-sorted/discuss/1351097/c-2-approaches-clean-and-easy-to-follow/1068242
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) {
            mp[arr[i]]=i;
        }
        
        int count=0;
        int end = 0;
        while(end < n) {
            
            for(int start = end; start <= end; start++)
                end = max(end, mp[start]);
            end++;
            count++;
        }
        return count;
    }
};
