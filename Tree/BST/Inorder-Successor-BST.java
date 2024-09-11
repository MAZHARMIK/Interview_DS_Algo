//time complexity:O(n);
//space complexity:O(n);
//***********************************************(Brute Force Approach)*****************************************************
class Solution
{
    // returns the inorder successor of the Node x in BST (rooted at 'root')
	public Node inorderSuccessor(Node root,Node x)
         {
          if(root==null) return root;
          inorder(root);
          for(int i=0 ;i<arr.size() ;i++){
              if(arr.get(i).data>x.data) return arr.get(i);
          }
          return null;
         }
         
         private ArrayList<Node> arr=new ArrayList<>();
         private void inorder(Node root){
             if(root==null) return;
             inorder(root.left);
             arr.add(root);
             inorder(root.right);
         }
}


//*******************************************************(optimal approach)*******************************************************
//time complexity:O(n);
//space complexity:O(1);

class Solution
{
    // returns the inorder successor of the Node x in BST (rooted at 'root')
	public Node inorderSuccessor(Node root,Node x)
         {
          if(root==null) return root;
          inorder(root ,x);
          return ans;
         }
         
         private Node ans;
         private void inorder(Node root,Node x){
             if(root==null) return;
             inorder(root.left,x);
             if(root.data>x.data){
                 if(ans==null) ans=root;
             }
             inorder(root.right,x);
         }
}
