/*
	Company Tags : D-E Shaw, Google, Amazon, Paytm
*/

#include <iostream>
#include<vector>
#include <map>
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

void diagonalUtil(Node* root, map<int, vector<int>>& mp, int level) {
    if(!root)
        return;

    mp[level].push_back(root->data);
    populateDiagonal(root->left, mp, level+1);
    populateDiagonal(root->right, mp, level);
}

void diagonalPrint(Node* root) {
    map<int, vector<int>> mp;

    diagonalUtil(root, mp, 0);

    for(auto it:mp) {
        vector<int> vec = it.second;
        for(int i:vec)
            cout << i << " ";
        cout << endl;
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
