/*
    Company Tags  : Amazon
    Leetcode Link : https://leetcode.com/problems/candy/
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> count(n, 1);
        
        //First comparing with only left neighbour
        for(int i = 1; i<n; i++) {
            if(ratings[i] > ratings[i-1])
                count[i] = max(count[i], count[i-1]+1);
        }
        
        //Then comparing with only right neighbour
        for(int i = n-2; i>=0; i--) {
            if(ratings[i] > ratings[i+1])
                count[i] = max(count[i], count[i+1]+1);
        }
        
        
        return accumulate(begin(count), end(count), 0);
    }
};

