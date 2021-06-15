/*
    Company Tags  : Microsoft, Amazon
    Leetcode Link : https://leetcode.com/problems/matchsticks-to-square/
*/

//This problem is nothing but "Partition to K Equal Sum Subsets" with k = 4
//Link (2 approaches) : https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Backtracking/Partition%20to%20K%20Equal%20Sum%20Subsets.cpp

/*Time Complexity : O(4^N)
    Bcause we have a total of N sticks and for each one of those matchsticks, we have 4 different possibilities
    for the subsets they might belong to or the side of the square they might be a part of.
*/
class Solution {
public:
    int n;
    int visited[16];
    
    bool possible(vector<int>& matchsticks, int numsIndex, int currSum, int& subsetSum, int k) {
        if(k == 1)
            return true;
        if(currSum == subsetSum) {
            return possible(matchsticks, n-1, 0, subsetSum, k-1);
        }
        
        for(int i = numsIndex; i>=0; i--) {
            if(visited[i] || currSum + matchsticks[i] > subsetSum)
                continue;
            
            visited[i] = 1;
            currSum   += matchsticks[i];
            
            if(possible(matchsticks, i+1, currSum, subsetSum, k))
                return true;
            
            visited[i] = 0;
            currSum   -= matchsticks[i];
        }
        
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(begin(matchsticks), end(matchsticks), 0);
        int k   = 4; //using concept of Leetcode Problem "Partition to K Equal Sum Subsets"
        /*
            If we are able to divide array in 4 parts each of which has equal sum (side of square)
            then it's possible to form the square with that equal subset sum as the side of square
        */
        
        if(sum%4 != 0)
            return false;
        
        memset(visited, 0, sizeof(visited));
        sort(begin(matchsticks), end(matchsticks));
	/*
		Why did I sort ?
		This will actually improve the DFS perofmance because we first put the
		largest matchstick in our subset and if it exceds the target subsetSum,
		then we discard this matchstick because it will further exceed.

		This gave me :
		Runtime: 0 ms, faster than 100.00% of C++ online submissions
	*/
	    
        n                   = matchsticks.size();
        int subsetSum       = sum/4;
        int numsIndex       = n-1;
        int currSum         = matchsticks[numsIndex];
        visited[numsIndex]  = 1;
        
        return possible(matchsticks, numsIndex, currSum, subsetSum, k);
    }
};
