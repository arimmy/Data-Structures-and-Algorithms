#include<iostream>

using namespace std;

template <typename T>
struct node
{
	T inf;
	node<T> *left;
	node<T> *right;
};

template <typename T>
void BinTree<T>::swapKLevelNodes(node<T>* root, int level, int k)
{
	if (root == NULL || (root->left == NULL && root->right == NULL)) return;
		
	if ((level + 1) % k == 0)
	{
		node<T>* temp = root->left;
		root->left = root->right;
		root->right = temp;
	}

	swapKLevelNodes(root->left, level + 1, k);
	swapKLevelNodes(root->right, level + 1, k);
}

int main()
{
	BinTree<int> binTree;
	int k;
	cin >> k;
	//the methods "Create", "print" and "GetRoot" are in the realisation of the class BinTree
	//which is part of the file "heightOfBinaryTree" in folder "homework3"
	binTree.Create();
	binTree.print();
	cout << endl;

	binTree.swapKLevelNodes(binTree.GetRoot(), 1, k);
	binTree.print();

	system("pause");
	return 0;
}
