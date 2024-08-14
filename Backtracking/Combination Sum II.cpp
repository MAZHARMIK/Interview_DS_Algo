/*         Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=bfKwLi6jtDk
    Company Tags                : Adobe, Amazon, Microsoft
    Leetcode Link               : https://leetcode.com/problems/combination-sum-ii/
*/


/******************************************************** C++ ********************************************************/
//Khaandani Template Backtracking
//T.C : O(2^n)
//S.C : O(n)
class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<int> curr, vector<vector<int>>& result, int idx) {
        if(target < 0)
            return;
        if(target == 0) {
            result.push_back(curr);
            return;
        }
        
        for(int i = idx; i<candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i-1])
                continue; //ignore duplicate elements
            curr.push_back(candidates[i]);
            solve(candidates, target-candidates[i], curr, result, i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(candidates.begin(), candidates.end()); //because we will ignore duplicate elements
        solve(candidates, target, curr, result, 0);
        return result;
    }
};



/******************************************************** JAVA ********************************************************/
//Khaandani Template Backtracking
//T.C : O(2^n)
//S.C : O(n)
class Solution {
    public void solve(int[] candidates, int target, List<Integer> curr, List<List<Integer>> result, int idx) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            result.add(new ArrayList<>(curr));
            return;
        }
        
        for (int i = idx; i < candidates.length; i++) {
            if (i > idx && candidates[i] == candidates[i - 1]) {
                continue; // Ignore duplicate elements
            }
            curr.add(candidates[i]);
            solve(candidates, target - candidates[i], curr, result, i + 1);
            curr.remove(curr.size() - 1);
        }
    }
    
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> curr = new ArrayList<>();
        Arrays.sort(candidates); // Sort to handle duplicates
        solve(candidates, target, curr, result, 0);
        return result;
    }
}
