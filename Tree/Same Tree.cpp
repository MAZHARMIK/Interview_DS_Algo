/*                         Scroll downn to see JAVA code also                   */
/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=YtoibyDlzk0
      Company Tags                : Google, Adobe, Meta, Amazon, Uber, Bloomberg, MentorGraphics
      Leetcode Link               : https://leetcode.com/problems/same-tree/
*/

/********************************************************* C++ *********************************************************/
//Approach-1 (Using DFS)
//T.C : O(n)
//S.C : O(1) Auxiliary space, O(depth of tree) Recursion stack space
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        
        if(p == NULL || q == NULL)
            return false;
        
        if(p->val != q->val)
            return false;
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};


//Approach-2 (Using BFS)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;
        if(p == NULL || q == NULL)
            return false;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(p);
        q2.push(q);
        while(!q1.empty() && !q2.empty()) {
            TreeNode* first = q1.front();
            TreeNode* second = q2.front();
            q1.pop();
            q2.pop();
            if(first->val != second->val)
                return false;
          
            if(first->left && second->left) {
                q1.push(first->left);
                q2.push(second->left);
            } else if(first->left || second->left)
                return false;
          
            if(first->right && second->right) {
                q1.push(first->right);
                q2.push(second->right);
            } else if(first->right || second->right)
                return false;
        }
        return true; 
    }
};



/********************************************************* JAVA *********************************************************/
//Approach-1 (Using DFS)
//T.C : O(n)
//S.C : O(1) Auxiliary space, O(depth of tree) Recursion stack space
//Approach-1 (Using Recursion - Any traversal , PreOrder, InOrder or PostOrder will work)
class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null) {
            return true;
        }
        
        if (p == null || q == null) {
            return false;
        }
        
        if (p.val != q.val) {
            return false;
        }
        
        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
}



//Approach-2 (Using BFS)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null) {
            return true;
        }
        if (p == null || q == null) {
            return false;
        }

        Queue<TreeNode> q1 = new LinkedList<>();
        Queue<TreeNode> q2 = new LinkedList<>();
        q1.add(p);
        q2.add(q);

        while (!q1.isEmpty() && !q2.isEmpty()) {
            TreeNode first = q1.poll();
            TreeNode second = q2.poll();

            if (first.val != second.val) {
                return false;
            }

            if (first.left != null && second.left != null) {
                q1.add(first.left);
                q2.add(second.left);
            } else if (first.left != null || second.left != null) {
                return false;
            }

            if (first.right != null && second.right != null) {
                q1.add(first.right);
                q2.add(second.right);
            } else if (first.right != null || second.right != null) {
                return false;
            }
        }

        return true;
    }
}
