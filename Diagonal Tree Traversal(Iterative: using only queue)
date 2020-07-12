/*
Company Tags : Amazon, Paytm
*/
#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
	Node(int data) {
        this->data = data;
        this->left = this->right = NULL;
	}
};

Node* newNode(int data) {
	return new Node(data);
}


void diagonalPrint(Node* root) {
    if(!root)
        return;
    queue<Node*> que;
    que.push(root);
    que.push(NULL);

    while(!que.empty()) {
        Node* temp = que.front();
        que.pop();
        if(temp == NULL) {
            if(que.empty())
                return;
            cout << endl;
            que.push(NULL);
        } else {
            while(temp) {
                if(temp->left)
                    que.push(temp->left);
                cout << temp->data << " ";
                temp = temp->right;
            }
        }
    }
}

int main()
{
	Node* root = newNode(8);
	root->left = newNode(3);
	root->right = newNode(10);
	root->left->left = newNode(1);
	root->left->right = newNode(6);
	root->right->right = newNode(14);
	root->right->right->left = newNode(13);
	root->left->right->left = newNode(4);
	root->left->right->right = newNode(7);

	diagonalPrint(root);

	return 0;
}
