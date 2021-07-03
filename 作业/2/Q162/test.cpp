#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main() {
	int n;
	cpp::TreeNode *root = new cpp::TreeNode();
	int a;
	cin >> a;
	root->data = a;
	root->left = NULL;
	root->right = NULL;
	while (cin >> a) {
		cpp::TreeNode *node = new cpp::TreeNode();
		node->data = a;
		node->left = NULL;
		node->right = NULL;
		char b[100];
		cin >> b;
		int i = 0;
		cpp::TreeNode* temp = root;
		while (b[i + 1] != '\0') {
			if (b[i] == 'L') {
				temp = temp->left;
			}
			else {
				temp = temp->right;
			}
			i++;
		}
		if (b[i] == 'L') {

			temp->left = node;
		}
		else {
			temp->right = node;
		}
	}
	cpp::print_tree(root);
	return 0;
}