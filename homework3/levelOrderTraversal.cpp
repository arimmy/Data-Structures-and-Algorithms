#include<iostream>
#include<queue>

using namespace std;

template <typename T>
struct node
{
	T inf;
	node<T> *left;
	node<T> *right;
};

template <typename T>
void BinTree<T>::levelOrderTraversal(node<T>* root)
{
	queue<node<T>*> q;
	
	q.push(root);

	while (!q.empty())
	{
		node<T>* vertex = q.front();
		cout << vertex->inf << " ";
		
		if (vertex->left != NULL) 
			q.push(vertex->left);
		
		if (vertex->right != NULL)
			q.push(vertex->right);

		q.pop();
	}
}

int main()
{
	BinTree<int> binTree;
	//the methods "Create", "print" and "GetRoot" are in the realisation of the class BinTree
	//which is part of the file "heightOfBinaryTree" in folder "homework3"
	binTree.Create();
	binTree.print();
	
	binTree.levelOrderTraversal(binTree.GetRoot());

	system("pause");
	return 0;
}
