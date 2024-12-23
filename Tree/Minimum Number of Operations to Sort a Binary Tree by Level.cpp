/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level
*/


/****************************************************** C++ ***************************************************/
//Approach - Simple BFS with hidden problem
//T.C : O(n + level * wlogw), level = total levels, w = number of nodes in a level
//S.C : O(n)
class Solution {
public:
    int countMinSwapsToSort(vector<int>& vec) {
        int swaps = 0;
        vector<int> sortedVec(begin(vec), end(vec));
        
        sort(begin(sortedVec), end(sortedVec));

        unordered_map<int, int> mp; //nums[i] -> i
        for(int i = 0; i < vec.size(); i++) {
            mp[vec[i]] = i;
        }

        for(int i = 0; i < vec.size(); i++) {
            if(vec[i] == sortedVec[i])
                continue; //no swap required
            
            int currIdx = mp[sortedVec[i]];
            mp[vec[i]] = currIdx;
            mp[vec[currIdx]] = i;
            swap(vec[currIdx], vec[i]);
            swaps++;
        }

        return swaps;
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);

        int result = 0;

        while(!que.empty()) {
            int n = que.size(); //total nodes in current level
            vector<int> vec;

            while(n--) {
                TreeNode* temp = que.front();
                que.pop();
                vec.push_back(temp->val);

                if(temp->left) {
                    que.push(temp->left);
                }

                if(temp->right) {
                    que.push(temp->right);
                }
            }

            result += countMinSwapsToSort(vec);
        }

        return result;
    }
};


/****************************************************** JAVA *************************************************/
//Approach - Simple BFS with hidden problem
//T.C : O(n + level * wlogw), level = total levels, w = number of nodes in a level
//S.C : O(n)
class Solution {
    public int countMinSwapsToSort(List<Integer> vec) {
        int swaps = 0;
        List<Integer> sortedVec = new ArrayList<>(vec);
        Collections.sort(sortedVec);

        Map<Integer, Integer> mp = new HashMap<>(); // nums[i] -> i
        for (int i = 0; i < vec.size(); i++) {
            mp.put(vec.get(i), i);
        }

        for (int i = 0; i < vec.size(); i++) {
            if (vec.get(i).equals(sortedVec.get(i))) {
                continue; // no swap required
            }

            int currIdx = mp.get(sortedVec.get(i));
            mp.put(vec.get(i), currIdx);
            mp.put(vec.get(currIdx), i);
            Collections.swap(vec, currIdx, i);
            swaps++;
        }

        return swaps;
    }

    public int minimumOperations(TreeNode root) {
        Queue<TreeNode> que = new LinkedList<>();
        que.add(root);

        int result = 0;

        while (!que.isEmpty()) {
            int n = que.size(); // total nodes in the current level
            List<Integer> vec = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                TreeNode temp = que.poll();
                vec.add(temp.val);

                if (temp.left != null) {
                    que.add(temp.left);
                }

                if (temp.right != null) {
                    que.add(temp.right);
                }
            }

            result += countMinSwapsToSort(vec);
        }

        return result;
    }
}
