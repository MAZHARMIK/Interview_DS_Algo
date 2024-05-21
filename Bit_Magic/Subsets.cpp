/*                                       Scroll down to see JAVA code also                                      /*
/*
    IF YOU WANT ME TO MAKE A VIDEO ON THIS, FEEL FREE TO LET ME KNOW. THANK YOU :-)
    Company Tags  : Microsoft
    Leetcode Link : https://leetcode.com/problems/subsets/
*/


/************************************************************ C++ ************************************************************/
//Using Bit magic. You can also use Backtracking (See my Subsets II in Backtracking section)
//T.C : O(2^n * L), where L is the average length of each subset
//S.C : O(2^n * L), where L is the average length of each subset
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        
        int n    = nums.size();
        int limit = (1 << n);
        
        for(int mask = 0; mask < limit; mask++) {
            vector<int> temp;
            
            for(int i = 0; i<n; i++) {
                if( (mask & (1 << i)) != 0 ) {
                    temp.push_back(nums[i]);
                }
            }
            
            result.push_back(temp);
        }
        
        return result;
        
    }
};


/************************************************************ JAVA ************************************************************/
//Using Bit magic. You can also use Backtracking (See my Subsets II in Backtracking section)
//T.C : O(2^n * L), where L is the average length of each subset
//S.C : O(2^n * L), where L is the average length of each subset
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        
        int n = nums.length;
        int limit = (1 << n);
        
        for (int mask = 0; mask < limit; mask++) {
            List<Integer> temp = new ArrayList<>();
            
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) != 0) {
                    temp.add(nums[i]);
                }
            }
            
            result.add(temp);
        }
        
        return result;
    }
}
