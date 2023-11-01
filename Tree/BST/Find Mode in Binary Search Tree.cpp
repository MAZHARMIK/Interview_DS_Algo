/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=tYoq7CMJP4A
    Company Tag                 : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/find-mode-in-binary-search-tree/
*/

/********************************************* C++ ************************************************************/
//Approach-1 (Using O(n) space)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    unordered_map<int, int> mp;
    
    void dfs(TreeNode* root) {
        if(!root)
            return;
        
        dfs(root->left);
        mp[root->val]++;
        dfs(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        
        vector<int> result;
        int maxFreq = 0;
        
        for(auto &it : mp) {
            if(it.second > maxFreq) {
                maxFreq = it.second;
                result = {};
                result.push_back(it.first);
            } else if (it.second == maxFreq) {
                result.push_back(it.first);
            }
        }
        
        return result;
        
    }
};


//Approach-2 (without Using extra space)
//T.C : O(n)
//S.C : O(1) (stack space is not considered)
class Solution {
public:
    int currNum    = 0;
    int currStreak = 0;
    int maxStreak  = 0;
    vector<int> result;
    
    void dfs(TreeNode* root) {
        if(!root)
            return;
        
        dfs(root->left);
        
        if(root->val == currNum) {
            currStreak++;
        } else {
            currNum    = root->val;
            currStreak = 1;
        }
        
        if(currStreak > maxStreak) {
            result = {};
            maxStreak = currStreak;
        }
        
        if(currStreak == maxStreak) {
            result.push_back(root->val);
        }
        
        dfs(root->right);
        
    }
    
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        
        return result;
    }
};

/********************************************* JAVA ************************************************************/
//Approach-1 (Using O(n) space)
//T.C : O(n)
//S.C : O(n)
public class Solution {
    private Map<Integer, Integer> mp = new HashMap<>();

    private void dfs(TreeNode root) {
        if (root == null) {
            return;
        }

        dfs(root.left);
        mp.put(root.val, mp.getOrDefault(root.val, 0) + 1);
        dfs(root.right);
    }

    public int[] findMode(TreeNode root) {
        dfs(root);

        List<Integer> resultList = new ArrayList<>();
        int maxFreq = 0;

        for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            int key = entry.getKey();
            int value = entry.getValue();

            if (value > maxFreq) {
                maxFreq = value;
                resultList.clear();
                resultList.add(key);
            } else if (value == maxFreq) {
                resultList.add(key);
            }
        }

        int[] result = new int[resultList.size()];
        for (int i = 0; i < resultList.size(); i++) {
            result[i] = resultList.get(i);
        }

        return result;
    }
}


//Approach-2 (without Using extra space)
//T.C : O(n)
//S.C : O(1) (stack space is not considered)
public class Solution {
    private int currNum = 0;
    private int currStreak = 0;
    private int maxStreak = 0;
    private List<Integer> result = new ArrayList<>();

    private void dfs(TreeNode root) {
        if (root == null) {
            return;
        }

        dfs(root.left);

        if (root.val == currNum) {
            currStreak++;
        } else {
            currNum = root.val;
            currStreak = 1;
        }

        if (currStreak > maxStreak) {
            result.clear();
            maxStreak = currStreak;
        }

        if (currStreak == maxStreak) {
            result.add(root.val);
        }

        dfs(root.right);
    }

    public int[] findMode(TreeNode root) {
        dfs(root);

        int[] resultArray = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            resultArray[i] = result.get(i);
        }

        return resultArray;
    }
}
