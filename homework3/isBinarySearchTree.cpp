#include<iostream>

using namespace std;

struct node
{
	int inf;
	node* left;
	node* right;
};

bool isBST(node* root, node* min, node* max)
{
	if (!root) return true;
	if (min && root->inf <= min->inf || max && root->inf >= max->inf) return false;
		
	return (isBST(root->left, min, root) && isBST(root->right, root, max));
}

bool isBST(node* root)
{
	return isBST(root, NULL, NULL);
}
