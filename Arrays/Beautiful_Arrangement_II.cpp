/*
    Company Tags  : Google
    Leetcode Link : https://leetcode.com/problems/beautiful-arrangement-ii/
*/

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        //it's all about observing the pattern
        //For n = 6, k = 2
        //1, 3, 2, 4, 5, 6
        //l = 1, r = k+1 i.e. 3
        //Now, alternate add l and r and post that l++ and r-- until (l <= r)
        //So till now you get, 1, 3, 2  (Has 2 uniqye diffs |1-3| and |3-2|)
        //Now, We don't need more than k (i.e. 2 here) diffs
        //SO, simply add numbers with 1 diff starting from (k+2) until n
        //Why k+2 ?  because, you have taken l = 1 and r = k+1 already
        vector<int> result(n);
        int l = 1, r = k+1;
        int i = 0;
        
        while(l <= r) {
            if(i%2 == 0)
                result[i++] = l++;
            else
                result[i++] = r--;
        }
        
        for(int x = k+2; x<=n; x++)
            result[i++] = x;
        
        return result;
    }
};
