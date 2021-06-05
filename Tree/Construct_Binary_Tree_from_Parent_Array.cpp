/*
    Company Tags  : Amazon, Microsoft, Snapdeal
    Question Link : https://practice.geeksforgeeks.org/problems/construct-binary-tree-from-parent-array/1
*/

void createUtil(int i, int parent[], vector<Node*>& created, Node* &root) {
    if(created[i] != NULL)
        return;

    Node* temp = new Node(i);
    created[i] = temp;
    if(parent[i] == -1) {
        root = temp;
        return;
    }

    //create parent recursively
    if(created[parent[i]] == NULL) {
        createUtil(parent[i], parent, created, root);
    }

    Node* your_parent = created[parent[i]];
    if(your_parent->left == NULL)
        your_parent->left = temp;
    else
        your_parent->right = temp;
}

Node *createTree(int parent[], int n)
{
    vector<Node*> created(n, NULL);


    Node* root = NULL;
    for(int i = 0; i<n; i++) {
        if(created[i] == NULL) {
            createUtil(i, parent, created, root);
        }
    }
    return root;
}
